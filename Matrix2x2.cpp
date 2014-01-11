/* ---------------------------------------------------------------------------
 *
 *		Matrix2x2 class - Michael Brandon Williams
 *
 *		Matrix2x2.cpp
 *
 * ---------------------------------------------------------------------------
 */

#include "Matrix2x2.h"


// constructor for when nothing is passed
Matrix2x2::Matrix2x2()
{
	elements[0][0] = 1;		elements[0][1] = 0;
	elements[1][0] = 0;		elements[1][1] = 1;
}


// constructor for when another matrix is passed to be copied into this
Matrix2x2::Matrix2x2  (const Matrix2x2 &M)
{
	elements[0][0] = M._e (0, 0);	elements[0][1] = M._e (0, 1);
	elements[1][0] = M._e (1, 0);	elements[1][1] = M._e (1, 1);
}


// constructor for when the sine and cosine of an angle are passed (for rotation matrices)
Matrix2x2::Matrix2x2 (const float sine, const float cosine)
{
	elements[0][0] = cosine;
	elements[0][1] = -sine;
	elements[1][0] = sine;
	elements[1][1] = cosine;
}


// destructor for object
Matrix2x2::~Matrix2x2()
{
	//delete [] elements;
}


// accessor
float Matrix2x2::_e (const int j, const int k) const
{
	return (elements[j][k]);
}

float Matrix2x2::operator () (const int j, const int k) const
{
	return (elements[j][k]);
}


// modifier
void Matrix2x2::set_e (const int j, const int k, const float e)
{
	elements[j][k] = e;
}


// assignment
const Matrix2x2& Matrix2x2::operator = (const Matrix2x2 &M)
{
	elements[0][0] = M.elements[0][0];	elements[0][1] = M.elements[0][1];
	elements[1][0] = M.elements[1][0];	elements[1][1] = M.elements[1][1];
	return (*this);
}


// test for equality
const bool Matrix2x2::operator == (const Matrix2x2 &M) const
{
	return ((elements[0][0] == M.elements[0][0]) &&
		    (elements[0][1] == M.elements[0][1]) &&
			(elements[1][0] == M.elements[1][0]) &&
			(elements[1][1] == M.elements[1][1]));
}


// test for inequality
const bool Matrix2x2::operator != (const Matrix2x2 &M) const
{
	return ((elements[0][0] != M.elements[0][0]) &&
		    (elements[0][1] != M.elements[0][1]) &&
			(elements[1][0] != M.elements[1][0]) &&
			(elements[1][1] != M.elements[1][1]));
}


// tests if all the elements in the matrix are zero
bool Matrix2x2::Zero_Matrix () const
{
	return ((elements[0][0] == 0) && (elements[0][1] == 0) &&
		    (elements[1][0] == 0) && (elements[1][1] == 0));
}


// tests if the matrix is an identity matrix
bool Matrix2x2::Identity_Matrix () const
{
	return ((elements[0][0] == 1) && (elements[0][1] == 0) &&
		    (elements[1][0] == 0) && (elements[1][1] == 1));
}


// turns this matrix into an identity matrix
void Matrix2x2::Set_Identity_Matrix ()
{
	elements[0][0] = 1;		elements[0][1] = 0;
	elements[1][0] = 0;		elements[1][1] = 1;
}


// addition (+)
const Matrix2x2 Matrix2x2::operator + (const Matrix2x2 &M) const
{
	Matrix2x2 temp;

	temp.elements[0][0] = elements[0][0] + M.elements[0][0];
	temp.elements[0][1] = elements[0][1] + M.elements[0][1];
	temp.elements[1][0] = elements[1][0] + M.elements[1][0];
	temp.elements[1][1] = elements[1][1] + M.elements[1][1];

	return (temp);
}


// addition (+=)
const Matrix2x2& Matrix2x2::operator += (const Matrix2x2 &M)
{
	elements[0][0] += M.elements[0][0];
	elements[0][1] += M.elements[0][1];
	elements[1][0] += M.elements[1][0];
	elements[1][1] += M.elements[1][1];

	return (*this);
}


// subtraction (-)
const Matrix2x2 Matrix2x2::operator - (const Matrix2x2 &M) const
{
	Matrix2x2 temp;

	temp.elements[0][0] = elements[0][0] - M.elements[0][0];
	temp.elements[0][1] = elements[0][1] - M.elements[0][1];
	temp.elements[1][0] = elements[1][0] - M.elements[1][0];
	temp.elements[1][1] = elements[1][1] - M.elements[1][1];

	return (temp);
}


// subtraction (-=)
const Matrix2x2& Matrix2x2::operator -= (const Matrix2x2 &M)
{
	elements[0][0] -= M.elements[0][0];
	elements[0][1] -= M.elements[0][1];
	elements[1][0] -= M.elements[1][0];
	elements[1][1] -= M.elements[1][1];

	return (*this);
}


// matrix-matrix multiplication (*)
const Matrix2x2 Matrix2x2::operator * (const Matrix2x2 &M) const
{
	Matrix2x2 temp;

	temp.elements[0][0] = (M.elements[0][0] * elements[0][0]) + (M.elements[1][0] * elements[0][1]);
	temp.elements[1][0] = (M.elements[0][0] * elements[1][0]) + (M.elements[1][0] * elements[1][1]);
	temp.elements[0][1] = (M.elements[0][1] * elements[0][0]) + (M.elements[1][1] * elements[0][1]);
	temp.elements[1][1] = (M.elements[0][1] * elements[1][0]) + (M.elements[1][1] * elements[1][1]);

	return (temp);
}


// matrix-matrix multiplication (*=)
const Matrix2x2& Matrix2x2::operator *= (const Matrix2x2 &M)
{
	Matrix2x2 temp;

	temp.elements[0][0] = (M.elements[0][0] * elements[0][0]) + (M.elements[1][0] * elements[0][1]);
	temp.elements[1][0] = (M.elements[0][0] * elements[1][0]) + (M.elements[1][0] * elements[1][1]);
	temp.elements[0][1] = (M.elements[0][1] * elements[0][0]) + (M.elements[1][1] * elements[0][1]);
	temp.elements[1][1] = (M.elements[0][1] * elements[1][0]) + (M.elements[1][1] * elements[1][1]);

	*this = temp;

	return (*this);
}


// matrix-scalar multiplication (*)
const Matrix2x2 Matrix2x2::operator * (const float s) const
{
	Matrix2x2 temp;

	temp.elements[0][0] = elements[0][0] * s;
	temp.elements[0][1] = elements[0][1] * s;
	temp.elements[1][0] = elements[1][0] * s;
	temp.elements[1][1] = elements[1][1] * s;

	return (temp);
}


// matrix-scalar multiplication (*=)
const Matrix2x2& Matrix2x2::operator *= (const float s)
{
	elements[0][0] *= s;
	elements[0][1] *= s;
	elements[1][0] *= s;
	elements[1][1] *= s;

	return (*this);
}


// matrix-vector multiplication (*)
const Vector2D Matrix2x2::operator * (const Vector2D &V) const
{
	Vector2D temp;

	temp.x = (elements[0][0] * V.x) + (elements[0][1] * V.y);
	temp.y = (elements[1][0] * V.x) + (elements[1][1] * V.y);

	return (temp);
}


// matrix-matrix division (/)
const Matrix2x2 Matrix2x2::operator / (const Matrix2x2 &M) const
{
	return (*this * M.Inverse ());
}


// matrix-matrix division (/=)
const Matrix2x2& Matrix2x2::operator /= (const Matrix2x2 &M)
{
	return (*this = *this * M.Inverse ());
}


// matrix-scalar division (/)
const Matrix2x2 Matrix2x2::operator / (const float s) const
{
	Matrix2x2 temp;

	temp.elements[0][0] = elements[0][0] / s;
	temp.elements[0][1] = elements[0][1] / s;
	temp.elements[1][0] = elements[1][0] / s;
	temp.elements[1][1] = elements[1][1] / s;

	return (temp);
}


// matrix-scalar division (/=)
const Matrix2x2& Matrix2x2::operator /= (const float s)
{
	elements[0][0] /= s;
	elements[0][1] /= s;
	elements[1][0] /= s;
	elements[1][1] /= s;

	return (*this);
}


// matrix to an integer power
const Matrix2x2 Matrix2x2::operator ^ (const int p) const
{
	Matrix2x2 temp;

	for (int j = 0; j < p; j++)
	{
		temp *= *this;
	}

	return (temp);
}


// fills the matrix with random elements
void Matrix2x2::Random_Elements (const int min, const int max)
{
	Random_Number generator;

	elements[0][0] = float (generator.Random (min, max));
	elements[1][0] = float (generator.Random (min, max));
	elements[0][1] = float (generator.Random (min, max));
	elements[1][1] = float (generator.Random (min, max));
}


// sets the elements of the matrix to create a rotation matrix
void Matrix2x2::Rotation_Matrix (const float sine, const float cosine)
{
	elements[0][0] = cosine;
	elements[0][1] = -sine;
	elements[1][0] = sine;
	elements[1][1] = cosine;
}


// returns the inverse of a orthonormal matrix
Matrix2x2 Matrix2x2::Orthonormal_Inverse () const
{
	return (this->Transpose ());
}


// returns the transpose of this matrix
Matrix2x2 Matrix2x2::Transpose () const
{
	Matrix2x2 temp;

	temp.elements[0][0] = elements[1][1];
	temp.elements[0][1] = elements[1][0];
	temp.elements[1][0] = elements[0][1];
	temp.elements[1][1] = elements[0][0];

	return (temp);
}


// returns the determinant of this matrix
const float Matrix2x2::operator ! () const
{
	return ((elements[0][0] * elements[1][1]) - (elements[0][1] * elements[1][0]));
}


// returns the inverse of this matrix
Matrix2x2 Matrix2x2::Inverse () const
{
	float one_over_det = 1 / (!*this);
	Matrix2x2 inverse;

	inverse.elements[0][0] =  one_over_det * elements[1][1];
	inverse.elements[0][1] = -one_over_det * elements[0][1];
	inverse.elements[1][0] = -one_over_det * elements[1][0];
	inverse.elements[1][1] =  one_over_det * elements[0][0];

	return (inverse);
}


// prints the properties of the maitrx
void Matrix2x2::Matrix_Print (const char* name) const
{
	cout << name << " :" << endl;
	cout << "[ " << elements[0][0] << "   " << elements[0][1] << " ]" << endl;
	cout << "[ " << elements[1][0] << "   " << elements[1][1] << " ]" << endl;
	cout << endl;
}


