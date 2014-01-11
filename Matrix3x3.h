/* ---------------------------------------------------------------------------
 *
 *		Matrix3x3 class - Michael Brandon Williams
 *
 *		Matrix3x3.h
 *
 * ---------------------------------------------------------------------------
 */


#ifndef _MATRIX3X3_H
#define _MATRIX3X3_H


#include <cmath>

#include <cmath>
#include <iostream.h>

#include "Vector3D.h"
#include "Random_Number.h"


typedef float Matrix_Elements3x3[3][3];


class Matrix3x3  
{
	public:

		Matrix_Elements3x3 elements;

		// constructors and destructors
		Matrix3x3 ();
		Matrix3x3 (const Matrix3x3 &M);
		virtual ~Matrix3x3 ();

		// accessor
		float _e (const int j, const int k) const;
		float operator () (const int j, const int k) const;

		// modifier
		void set_e (const int j, const int k, const float e);

		// assignment
		const Matrix3x3& operator = (const Matrix3x3 &M);

		// boolean tests
		const bool operator == (const Matrix3x3 &M) const;
		const bool operator != (const Matrix3x3 &M) const;
		bool Zero_Matrix () const;
		bool Identity_Matrix () const;

		// turns the matrix into an identity matrix
		void Set_Identity_Matrix ();

		// addition
		const Matrix3x3 operator + (const Matrix3x3 &M) const;
		const Matrix3x3& operator += (const Matrix3x3 &M);

		// subtraction
		const Matrix3x3 operator - (const Matrix3x3 &M) const;
		const Matrix3x3& operator -= (const Matrix3x3 &M);

		// matrix-matrix multiplication
		const Matrix3x3 operator * (const Matrix3x3 &M) const;
		const Matrix3x3& operator *= (const Matrix3x3 &M);

		// matrix-scalar multiplication
		const Matrix3x3 operator * (const float s) const;
		const Matrix3x3& operator *= (const float s);

		// matrix-vector multiplication
		const Vector3D operator * (const Vector3D &V) const;

		// matrix-matrix division
		const Matrix3x3 operator / (const Matrix3x3 &M) const;
		const Matrix3x3& operator /= (const Matrix3x3 &M);

		// matrix-scalar division
		const Matrix3x3 operator / (const float s) const;
		const Matrix3x3& operator /= (const float s);

		// matrix to an integer power
		const Matrix3x3 operator ^ (const int p) const;

		// fills the matrix with random elements
		void Random_Elements (const int min, const int max);

		// sets the elements of the matrix to create
		// a rotation matrix around the x-, y-, and z-axis
		void Rotation_Matrix_X (const float sine, const float cosine);
		void Rotation_Matrix_Y (const float sine, const float cosine);
		void Rotation_Matrix_Z (const float sine, const float cosine);

		// sets the elements of the matrix to create
		// a rotation matrix around an arbitrary axis
		void Rotation_Matrix_Axis (const float sine, const float cosine, const Vector3D &A);

		// returns the inverse of an orthonormal matrix
		Matrix3x3 Orthonormal_Inverse () const;

		// returns the transpose of this matrix
		Matrix3x3 Transpose () const;

		// returns the determinant of this matrix
		float operator ! () const;

		// returns the inverse of this matrix
		Matrix3x3 Inverse () const;

		// prints the properties of the matrix
		void Matrix_Print (const char* name) const;
};

#endif


/*
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




  */