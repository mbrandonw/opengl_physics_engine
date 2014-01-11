/* ---------------------------------------------------------------------------
 *
 *		Matrix class - Michael Brandon Williams
 *
 *		Matrix.h
 *
 * ---------------------------------------------------------------------------
 */


// UNFINISHED


#ifndef _MATRIX_H
#define _MATRIX_H

#include <cmath>
#include <iostream.h>

#include "Random_Number.h"


class Matrix  
{
	public:

		Matrix ();
		Matrix (const int n);
		virtual ~Matrix ();

	private:

		float *elements;
};

#endif

