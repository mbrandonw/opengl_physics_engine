/* ---------------------------------------------------------------------------
 *
 *		Array class - Michael Brandon Williams
 *
 *		Array.cpp
 *
 * ---------------------------------------------------------------------------
 */


#include "Array.h"


/*
#ifndef _ARRAY_H
#define _ARRAY_H


#include <stdlib.h>
#include <iostream.h>
#include <stdarg.h>


template <class datatype> class Array  
{
	public:

		// constructor for an array with zero elements
		Array ()
		{
			elements = NULL;
			length = 0;
		}

		// constructor for an array with n elements
		Array (const int n)
		{
			elements = new datatype[n];
			length = n;
		}

		// constructor for an array with n elements initialized to "value"
		Array (const int n, const datatype &value)
		{
			elements = new datatype[n];
			length = n;

			// initialize elements to zero
			for (int j = 0; j < n; j++)
			{
				elements[j] = value;
			}
		}

		// copy constructor
		Array (const Array<datatype> &a)
		{
			elements = new datatype[a.Length ()];
			length = a.Length ();

			// initialize elements
			for (int j = 0; j < length; j++)
			{
				elements[j] = a.Return (j);
			}
		}

		// destructor for array
		virtual ~Array ()
		{
			//delete [] elements;
		}

		// returns the length of the array
		int Length () const
		{
			return (length);
		}

		// index of array
		datatype operator [] (const int n) const
		{
			if (n >= length)
			{
				this->Resize (n+1);
			}

			return (elements[n]);
		}

		datatype& operator [] (const int n)
		{
			if (n >= length)
			{
				this->Resize (n+1);
			}

			return (elements[n]);
		}

		// modifier
		void Set (const int n, const datatype &element)
		{
			if (n >= length)
			{
				this->Resize (n+1);
			}

			elements[n] = element;
		}

		// accessor
		const datatype Return (const int n) const
		{
			return (elements[n]);
		}

		// assignment
		const Array<datatype>& operator = (const Array<datatype> &a)
		{
			// make sure we are not setting an object equal to itself
			if (this != &a)
			{
				// change the length of this array
				length = a.Length ();

				// create memory for this array
				elements = new datatype[length];

				// loop through all of the elements of this array
				// and set them equal to the elements in "a"
				for (int j = 0; j < length; j++)
				{
					elements[j] = a.Return (j);
				}
			}

			return (*this);
		}

		// concatenates two arrays together (+)
		const Array<datatype> operator + (const Array<datatype> &a) const
		{
			// array that will be returned
			Array<datatype> temp (length + a.Length ());

			// loop through all the elements of this array and "a"
			// to set the elements of "temp"
			for (int j = 0; j < temp.Length (); j++)
			{
				// first elements of "temp" belong to this array
				if (j < length)
				{
					temp[j] = elements[j];
				}
				else
				{
					// last elements of "temp" belong to "a"
					temp[j] = a.Return (j - length);
				}
			}

			return (temp);
		}

		// concatenates "a" to this array
		const Array<datatype>& operator += (const Array<datatype> &a)
		{
			// length of this array before resize
			int before_length = length;

			// resize this array to hold the elements of "a" too
			this->Resize (length + a.Length ());

			// set the new elements of this array to a's elements
			for (int j = before_length; j < length; j++)
			{
				elements[j] = a.Return (j - before_length);
			}

			return (*this);
		}

		// resizes the array to n elements
		void Resize (const int n)
		{
			datatype* temp = new datatype[n];
			int num_to_copy = (n < length) ? n : length;

			for (int k = 0; k < num_to_copy; k++)
			{
				temp[k] = elements[k];
			}

			length = n;
			elements = temp;
		}

		// puts the item passed at the end of the array
		void Push (const datatype &element)
		{
			this->Resize (length + 1);
			elements[length - 1] = element;
		}

		// removes the last element from the array and returns its value
		datatype Pop ()
		{
			// element to be returned
			datatype data;
			data = elements[length - 1];

			// resize the array
			this->Resize (length - 1);

			// return the element
			return (data);
		}

		// prints the elements of the array
		void Array_Print (const char* name) const
		{
			cout << "Array: " << name << " = [ ";
			for (int j = 0; j < length; j++)
			{
				cout << elements[j];
				if (j != (length - 1))	cout << ", ";
				else					cout << " ";
			}
			cout << "]" << endl;
		}

		// removes the first element of the array and returns the value
		datatype Shift ()
		{
			// value that will be returned
			datatype temp = elements[0];

			for (int j = 1; j < length; j++)
			{
				elements[j - 1] = elements[j];
			}

			this->Resize (length - 1);

			return (temp);
		}

		// inserts a new element at the beginning of the array
		void Unshift (const datatype &element)
		{
			Array<datatype> temp (length + 1);

			temp[0] = element;

			for (int j = 1; j < (length + 1); j++)
			{
				temp[j] = elements[j - 1];
			}

			*this = temp;
		}

		// returns the array from index "j" to index "k"
		Array<datatype> Slice (const int j, const int k) const
		{
			Array<datatype> temp (k - j);

			for (int i = 0; i < (k - j); i++)
			{
				temp[i] = elements[i + j];
			}

			return (temp);
		}

		// removes elements from the array between "start" and "start + num_delete"
		void Splice (const int start, const int num_delete)
		{
			for (int j = start; j < (start + num_delete); j++)
			{
				elements[j] = elements[j + num_delete];
			}

			this->Resize (length - num_delete);
		}

		// inserts an element before the nth element
		void Insert_Before (const int n, const datatype &element)
		{
			this->Resize (length + 1);

			for (int j = (length - 1); j > n; j--)
			{
				elements[j] = elements[j - 1];
			}

			elements[n] = element;
		}

		// inserts an element after the nth element
		void Insert_After (const int n, const datatype &element)
		{
			this->Resize (length + 1);

			for (int j = (length - 1); j > (n + 1); j--)
			{
				elements[j] = elements[j - 1];
			}

			elements[n + 1] = element;
		}

		// reverses the elements in the array
		void Reverse ()
		{
			int condition = int (length / 2);
			datatype temp;

			for (int j = 0; j < condition; j++)
			{
				temp = elements[j];
				elements[j] = elements[length - j - 1];
				elements[length - j - 1] = temp;
			}
		}

		// sorts the array
		void Sort ()
		{
			int j, k;
			bool exchange_made = true;
			datatype temp;

			k = 0;

			while ((k < length - 1) && exchange_made)
			{
				exchange_made = false;
				k++;

				for (j = 0; j < length - k; j++)
				{
                    if (elements[j] > elements[j + 1])
                    {
    					temp = elements[j];
    					elements[j] = elements[j + 1];
    					elements[j + 1] = temp;
    					exchange_made = true;
                    }
				}
			}
		}

	private:

		datatype* elements;
		int length;
};

#endif


*/