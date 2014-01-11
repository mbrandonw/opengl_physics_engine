/* ---------------------------------------------------------------------------
 *
 *		Matrix2x2 class - Michael Brandon Williams
 *
 *		Matrix2x2.h
 *
 * ---------------------------------------------------------------------------
 */


#ifndef _MATRIX2X2_H
#define _MATRIX2X2_H


#include <cmath>
#include <iostream.h>

#include "Vector2D.h"
#include "Random_Number.h"


typedef float Matrix_Elements2x2[2][2];


class Matrix2x2
{
	public:

		Matrix_Elements2x2 elements;

		// constructors and destructors
		Matrix2x2 ();
		Matrix2x2 (const float sine, const float cosine);
		Matrix2x2 (const Matrix2x2 &M);
		virtual ~Matrix2x2();

		// accessor
		float _e (const int j, const int k) const;
		float operator () (const int j, const int k) const;

		// modifier
		void set_e (const int j, const int k, const float e);

		// assignment
		const Matrix2x2& operator = (const Matrix2x2 &M);

		// boolean tests
		const bool operator == (const Matrix2x2 &M) const;
		const bool operator != (const Matrix2x2 &M) const;
		bool Zero_Matrix () const;
		bool Identity_Matrix () const;

		// turns the matrix into an identity matrix
		void Set_Identity_Matrix ();

		// addition
		const Matrix2x2 operator + (const Matrix2x2 &M) const;
		const Matrix2x2& operator += (const Matrix2x2 &M);

		// subtraction
		const Matrix2x2 operator - (const Matrix2x2 &M) const;
		const Matrix2x2& operator -= (const Matrix2x2 &M);

		// matrix-matrix multiplication
		const Matrix2x2 operator * (const Matrix2x2 &M) const;
		const Matrix2x2& operator *= (const Matrix2x2 &M);

		// matrix-scalar multiplication
		const Matrix2x2 operator * (const float s) const;
		const Matrix2x2& operator *= (const float s);

		// matrix-vector multiplication
		const Vector2D operator * (const Vector2D &V) const;

		// matrix-matrix division
		const Matrix2x2 operator / (const Matrix2x2 &M) const;
		const Matrix2x2& operator /= (const Matrix2x2 &M);

		// matrix-scalar division
		const Matrix2x2 operator / (const float s) const;
		const Matrix2x2& operator /= (const float s);

		// matrix to an integer power
		const Matrix2x2 operator ^ (const int p) const;

		// fills the matrix with random elements
		void Random_Elements (const int min, const int max);

		// sets the elements of the matrix to create a rotation matrix
		void Rotation_Matrix (const float sine, const float cosine);

		// returns the inverse of a orthonormal matrix
		Matrix2x2 Orthonormal_Inverse () const;

		// returns the transpose of this matrix
		Matrix2x2 Transpose () const;

		// returns the determinant of this matrix
		const float operator ! () const;

		// returns the inverse of this matrix
		Matrix2x2 Inverse () const;

		// prints the properties of the matrix
		void Matrix_Print (const char* name) const;
};

#endif


