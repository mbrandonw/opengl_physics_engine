/* ---------------------------------------------------------------------------
 *
 *		String class - Michael Brandon Williams
 *
 *		String.cpp
 *
 * ---------------------------------------------------------------------------
 */

#include "String.h"


// default constructor for string
String::String ()
{
	length = 0;
	characters = new char[length + 1];
	characters[0] = NULL;
}


// constructor for when a char* star is passed to initialize the string
String::String (const char* str)
{
	// set the length of this string
	length = strlen (str);

	// create memory for characters of this string
	characters = new char[length + 1];

	// set the characters of this string
	for (int j = 0; j < length; j++)
	{
		characters[j] = str[j];
	}

	// null character
	characters[length] = NULL;
}


// constructor for when a string object is passed to initialize the string
String::String (const String &str)
{
	// set the length of this string
	length = str.Length ();

	// create memeory for the characters of this string
	characters = new char[length + 1];

	// set the characters of this string
	for (int j = 0; j < length; j++)
	{
		characters[j] = str[j];
	}

	// null character
	characters[length] = NULL;
}


// constructor for when an integer is passed for the length of the string
String::String (const int len)
{
	// set the length of this string
	length = len;

	// create memory for the characters of this string
	characters = new char[length + 1];

	// null character
	characters[length] = NULL;
}


// destructor for string
String::~String()
{
	delete [] characters;
}


// assignment to another string object
const String& String::operator = (const String &str)
{
	// make sure we are not setting a string equal to itself
	if (this != &str)
	{
		// set the length of this string
		length = str.Length ();

		// reallocate memory for characters
		characters = (char*) realloc (characters, (length + 1));

		// set the characters of this string
		for (int j = 0; j < length; j++)
		{
			characters[j] = str[j];
		}

		// null character
		characters[length] = NULL;
	}

	return (*this);
}


// assignment to a char*
const String& String::operator = (const char* str)
{
	// set the length of this string
	length = strlen (str);

	// reallocate memory for characters
	characters = (char*) realloc (characters, (length + 1));

	// set the characters of this string
	for (int j = 0; j < length; j++)
	{
		characters[j] = str[j];
	}

	// null character
	characters[length] = NULL;

	return (*this);
}

// elements = (datatype*) realloc (elements, (sizeof (datatype) * n));


// assignment to a char
const String& String::operator = (const char character)
{
	// set the length of this string
	length = 1;

	// reallocate memory for characters
	characters = (char*) realloc (characters, (length + 1));

	// set the character of this string
	characters[0] = character;

	// null character
	characters[1] = NULL;

	return (*this);
}


// returns the length of the string
int String::Length () const
{
	return (length);
}


// indexing
char String::operator [] (const int j) const
{
	if ((j >= 0) && (j < length))
	{
		return (characters[j]);
	}
	else
	{
		return (' ');
	}
}


// indexing
char& String::operator [] (const int j)
{
	// range checking
	assert ((j >= 0) && (j <= length));

	if (j < length)
	{
		return (characters[j]);
	}
	else
	{
		// we have fallen out of the array by one element so extend the array
		// to hold the extra element
		characters = (char*) realloc (characters, (length + 2));
		length++;
		characters[length] = NULL;
		return (characters[j]);
	}
}


// returns the index of the first occurence of the string passed
int String::Index_Of (const String &str) const
{
	// length of string we are looking for
	int str_length = str.Length ();

	// substring of this string that we will compare with "str"
	String sub_str;

	// loop through the characters of this string and look for "str"
	for (int j = 0; j < (length - str_length); j++)
	{
		// get substring from the current index to the length of "str"
		sub_str = this->Sub_String (j, str_length);

		// see if we have found a match
		if (sub_str == str)
		{
			// return the index where we found "str"
			return (j);
		}
	}

	// no match was found
	return (-1);
}


// returns the index of the first occurence of the char* passed
int String::Index_Of (const char* str) const
{
	String temp (str);

	return (this->Index_Of (temp));
}


// returns the index of the first occurence of the char passed
int String::Index_Of (const char character) const
{
	// loop through all the characters in this string to find "character"
	for (int j = 0; j < length; j++)
	{
		// check if we have found the character
		if (characters[j] == character)
		{
			// return the index where we found "character"
			return (j);
		}
	}

	// no match was found
	return (-1);
}


// returns the index of the last occurence of the string passed
int String::Last_Index_Of (const String &str) const
{
	// length of string we are looking for
	int str_length = str.Length ();

	// substring of this string that we will compare with "str"
	String sub_str;

	// loop through the characters of this string and look for "str"
	for (int j = (length - str_length); j >= 0; j--)
	{
		// get substring from the current index to the length of "str"
		sub_str = this->Sub_String (j, str_length);

		// see if we have found a match
		if (sub_str == str)
		{
			// return the index where we found "str"
			return (j);
		}
	}

	// no match was found
	return (-1);
}


// returns the index of the last occurence of the char* passed
int String::Last_Index_Of (const char* str) const
{
	String temp (str);

	return (this->Last_Index_Of (temp));
}


// returns the index of the last occurence of the char passed
int String::Last_Index_Of (const char character) const
{
	// loop through all the characters in this string to find "character"
	for (int j = (length - 1); j >= 0; j--)
	{
		// check if we have found the character
		if (characters[j] == character)
		{
			// return the index where we found "character"
			return (j);
		}
	}

	// no match was found
	return (-1);
}


// returns a substring from the index "start" to "start + length"
String String::Sub_String (int start, int len) const
{
	// substring that will be returned
	String sub (len + 1);

	// a few preliminary error checks
	if (start < 0)
	{
		// if the starting index is less than zero make the start at 0
		start = 0;
	}
	else if (start >= length)
	{
		// if starting index is greater than the length of this string
		// return an empty string
		return (String ());
	}

	// copy the characters into the substring
	for (int j = 0; j < len; j++)
	{
		sub[j] = characters[start + j];
	}

	// null characters
	sub[len] = NULL;

	return (sub);
}


// returns the char* equalivalent of the string
char* String::C_String () const
{
	return (characters);
}


// boolean test (equality)
bool String::operator == (const String &str) const
{
	return (strcmp (characters, str.C_String ()) == 0);
}


// boolean test (inequality)
bool String::operator != (const String &str) const
{
	return (! (*this == str));
}


// boolean test (less-than)
bool String::operator < (const String &str) const
{
	return (strcmp (characters, str.C_String ()) < 0);
}


// boolean test (less-than or equal to)
bool String::operator <= (const String &str) const
{
	return ((*this < str) || (*this == str));
}


// boolean test (greater-than)
bool String::operator > (const String &str) const
{
	return (str < *this);
}


// boolean test (greater-than or equal to)
bool String::operator >= (const String &str) const
{
	return (str <= *this);
}


// boolean test (equality)
bool String::operator == (const char* str) const
{
	return (strcmp (characters, str) == 0);
}


// boolean test (inequality)
bool String::operator != (const char* str) const
{
	return (! (*this == str));
}


// boolean test (less-than)
bool String::operator < (const char* str) const
{
	return (strcmp (characters, str) < 0);
}


// boolean test (less-than or equal to)
bool String::operator <= (const char* str) const
{
	return ((*this < str) || (*this == str));
}


// boolean test (greater-than)
bool String::operator > (const char* str) const
{
	//return (str < *this);
	return (! (*this < str));
}


// boolean test (greater-than or equal to)
bool String::operator >= (const char* str) const
{
	return ((*this > str) || (*this == str));
}


// changes all the characters to upper case
void String::To_Upper_Case ()
{
	for (int j = 0; j < length; j++)
	{
		// check if character is lower case
		if ((characters[j] >= 97) && (characters[j] <= 122))
		{
			characters[j] -= ' ';
		}
	}
}


// changes all the characters to lower case
void String::To_Lower_Case ()
{
	for (int j = 0; j < length; j++)
	{
		// check if character is upper case
		if ((characters[j] >= 65) && (characters[j] <= 90))
		{
			characters[j] += ' ';
		}
	}
}


// returns the concatenation of two string objects (+)
const String String::operator + (const String &str) const
{
	// length of concenated string
	int total_length = length + str.Length ();

	// string that will be returned
	String temp (total_length);

	for (int j = 0; j < total_length; j++)
	{
		if (j < length)
		{
			// index in this string
			temp[j] = characters[j];
		}
		else
		{
			// index in the "str" string
			temp[j] = str[j - length];
		}
	}

	return (temp);
}


// changes this string to the concatenation of this string and another (+=)
const String& String::operator += (const String &str)
{
	// concatenation of this string with "str"
	String temp;

	// concatenate this string and "str"
	temp = *this + str;

	// set this string to the concatenated string
	*this = temp;

	return (*this);
}


// returns the concatenation of a string and a char* (+)
const String String::operator + (const char* str) const
{
	String temp (str);

	return (*this + temp);
}


// changes this string to the concatenation of this string and a char* (+=)
const String& String::operator += (const char* str)
{
	// concatenation of this string with "str"
	String temp;

	// concatenate this string and "str"
	temp = *this + str;

	// set this string to the concatenated string
	*this = temp;

	return (*this);
}


// returns the string made from adding a character to the end of this string (+)
const String String::operator + (const char character) const
{
	// string that will be returned
	String temp (*this);

	// add on the extra character
	temp[length] = character;

	return (temp);
}


// changes this string to the string made from adding a character to the end (+=)
const String& String::operator += (const char character)
{
	characters = (char*) realloc (characters, (length + 2));
	length++;
	characters[length - 1] = character;
	characters[length] = NULL;

	return (*this);
}


// I/O interface
ostream& operator << (ostream &os, const String &str)
{
	return (os << str.C_String ());
}


istream& operator >> (istream &is, String &str)
{
	char temp[256];
	is >> temp;
	str = temp;
	return (is);
}






