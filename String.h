/* ---------------------------------------------------------------------------
 *
 *		String class - Michael Brandon Williams
 *
 *		String.h
 *
 * ---------------------------------------------------------------------------
 */


#ifndef _STRING_H
#define _STRING_H


#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


class String  
{
	public:

		// default constructor for string
		String ();

		// constructor for when a char* star is passed to initialize the string
		String (const char* str);

		// constructor for when a string object is passed to initialize the string
		String (const String &str);

		// constructor for when an integer is passed for the length of the string
		String (const int len);

		// destructor for string
		virtual ~String ();

		// assignment to another string object
		const String& operator = (const String &str);

		// assignment to a char*
		const String& operator = (const char* str);

		// assignment to a char
		const String& operator = (const char character);

		// returns the length of the string
		int Length () const;

		// indexing
		char operator [] (const int j) const;
		char& operator [] (const int j);

		// returns the index of the first occurence of the string, char*, or character passed
		int Index_Of (const String &str) const;
		int Index_Of (const char* str) const;
		int Index_Of (const char character) const;

		// returns the index of the last occurence of the string, char*, or character passed
		int Last_Index_Of (const String &str) const;
		int Last_Index_Of (const char* str) const;
		int Last_Index_Of (const char character) const;

		// returns a substring from the index "start" to "start + length"
		String Sub_String (int start, int len) const;

		// returns the concatenation of two string objects (+)
		const String operator + (const String &str) const;

		// changes this string to the concatenation of this string and another (+=)
		const String& operator += (const String &str);

		// returns the concatenation of a string and a char* (+)
		const String operator + (const char* str) const;
		
		// changes this string to the concatenation of this string and a char* (+=)
		const String& operator += (const char* str);

		// returns the string made from adding a character to the end of this string (+)
		const String operator + (const char character) const;

		// changes this string to the string made from adding a character to the end (+=)
		const String& operator += (const char character);

		// returns the char* equalivalent of the string
		char* C_String () const;

		// boolean tests
		bool operator == (const String &str) const;
		bool operator != (const String &str) const;
		bool operator <  (const String &str) const;
		bool operator <= (const String &str) const;
		bool operator >  (const String &str) const;
		bool operator >= (const String &str) const;

		bool operator == (const char* str) const;
		bool operator != (const char* str) const;
		bool operator <  (const char* str) const;
		bool operator <= (const char* str) const;
		bool operator >  (const char* str) const;
		bool operator >= (const char* str) const;

		// changes all the characters to upper case
		void To_Upper_Case ();

		// changes all the characters to lower case
		void To_Lower_Case ();

	private:

		char* characters;
		int length;
};


// I/O interface
ostream& operator << (ostream &os, const String &str);
istream& operator >> (istream &is, String &str);

#endif



