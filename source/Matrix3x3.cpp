/* ---------------------------------------------------------------------------
 *
 *		Matrix2x2 class - Michael Brandon Williams
 *
 *		Matrix2x2.cpp
 *
 * ---------------------------------------------------------------------------
 */


#include "Matrix3x3.h"


Matrix3x3::Matrix3x3()
{
	elements[0][0] = 1;
	elements[0][1] = 0;
	elements[0][2] = 0;

	elements[1][0] = 0;
	elements[1][1] = 1;
	elements[1][2] = 0;

	elements[2][0] = 0;
	elements[2][1] = 0;
	elements[2][2] = 1;
}


// constructor for when this matrix is to be intialized with
// the same elements as another matrix
Matrix3x3::Matrix3x3 (const Matrix3x3 &M)
{
	elements[0][0] = M.elements[0][0];
	elements[0][1] = M.elements[0][1];
	elements[0][2] = M.elements[0][2];

	elements[1][0] = M.elements[1][0];
	elements[1][1] = M.elements[1][1];
	elements[1][2] = M.elements[1][2];

	elements[2][0] = M.elements[2][0];
	elements[2][1] = M.elements[2][1];
	elements[2][2] = M.elements[2][2];
}

Matrix3x3::~Matrix3x3()
{

}


// accessor
float Matrix3x3::_e (const int j, const int k) const
{
	return (elements[j][k]);
}


float Matrix3x3::operator () (const int j, const int k) const
{
	return (elements[j][k]);
}


// modifier
void Matrix3x3::set_e (const int j, const int k, const float e)
{
	elements[j][k] = e;
}


// assignment
const Matrix3x3& Matrix3x3::operator = (const Matrix3x3 &M)
{
	elements[0][0] = M.elements[0][0];
	elements[0][1] = M.elements[0][1];
	elements[0][2] = M.elements[0][2];

	elements[1][0] = M.elements[1][0];
	elements[1][1] = M.elements[1][1];
	elements[1][2] = M.elements[1][2];

	elements[2][0] = M.elements[2][0];
	elements[2][1] = M.elements[2][1];
	elements[2][2] = M.elements[2][2];

	return (*this);
}


// tests for equality
const bool Matrix3x3::operator == (const Matrix3x3 &M) const
{
	return ((elements[0][0] == M.elements[0][0]) && 
			(elements[0][1] == M.elements[0][1]) &&
			(elements[0][2] == M.elements[0][2]) &&
			(elements[1][0] == M.elements[1][0]) && 
			(elements[1][1] == M.elements[1][1]) &&
			(elements[1][2] == M.elements[1][2]) &&
			(elements[2][0] == M.elements[2][0]) && 
			(elements[2][1] == M.elements[2][1]) &&
			(elements[2][2] == M.elements[2][2]));
}


// tests for inequality
const bool Matrix3x3::operator != (const Matrix3x3 &M) const
{
	return ((elements[0][0] != M.elements[0][0]) && 
			(elements[0][1] != M.elements[0][1]) &&
			(elements[0][2] != M.elements[0][2]) &&
			(elements[1][0] != M.elements[1][0]) && 
			(elements[1][1] != M.elements[1][1]) &&
			(elements[1][2] != M.elements[1][2]) &&
			(elements[2][0] != M.elements[2][0]) && 
			(elements[2][1] != M.elements[2][1]) &&
			(elements[2][2] != M.elements[2][2]));
}


// checks if the matrix is a zero matrix
bool Matrix3x3::Zero_Matrix () const
{
	return ((elements[0][0] == 0.0f) && 
			(elements[0][1] == 0.0f) &&
			(elements[0][2] == 0.0f) &&
			(elements[1][0] == 0.0f) && 
			(elements[1][1] == 0.0f) &&
			(elements[1][2] == 0.0f) &&
			(elements[2][0] == 0.0f) && 
			(elements[2][1] == 0.0f) &&
			(elements[2][2] == 0.0f));
}


// checks if the matrix is an identity matrix
bool Matrix3x3::Identity_Matrix () const
{
	return ((elements[0][0] == 1.0f) && 
			(elements[0][1] == 0.0f) &&
			(elements[0][2] == 0.0f) &&
			(elements[1][0] == 0.0f) && 
			(elements[1][1] == 1.0f) &&
			(elements[1][2] == 0.0f) &&
			(elements[2][0] == 0.0f) && 
			(elements[2][1] == 0.0f) &&
			(elements[2][2] == 1.0f));
}


// turns the matrix into an identity matrix
void Matrix3x3::Set_Identity_Matrix ()
{
	elements[0][0] = elements[1][1] = elements[2][2] = 1.0f;
	elements[0][1] = elements[0][2] = 0.0f;
	elements[1][0] = elements[1][2] = 0.0f;
	elements[2][0] = elements[2][1] = 0.0f;
}


// addition (+)
const Matrix3x3 Matrix3x3::operator + (const Matrix3x3 &M) const
{
	Matrix3x3 temp;

	temp.elements[0][0] = elements[0][0] + M.elements[0][0];
	temp.elements[0][1] = elements[0][1] + M.elements[0][1];
	temp.elements[0][2] = elements[0][2] + M.elements[0][2];

	temp.elements[1][0] = elements[1][0] + M.elements[1][0];
	temp.elements[1][1] = elements[1][1] + M.elements[1][1];
	temp.elements[1][2] = elements[1][2] + M.elements[1][2];

	temp.elements[2][0] = elements[2][0] + M.elements[2][0];
	temp.elements[2][1] = elements[2][1] + M.elements[2][1];
	temp.elements[2][2] = elements[2][2] + M.elements[2][2];

	return (temp);
}


// addition (+=)
const Matrix3x3& Matrix3x3::operator += (const Matrix3x3 &M)
{
	elements[0][0] += M.elements[0][0];
	elements[0][1] += M.elements[0][1];
	elements[0][2] += M.elements[0][2];

	elements[1][0] += M.elements[1][0];
	elements[1][1] += M.elements[1][1];
	elements[1][2] += M.elements[1][2];

	elements[2][0] += M.elements[2][0];
	elements[2][1] += M.elements[2][1];
	elements[2][2] += M.elements[2][2];

	return (*this);
}


// subtraction (-)
const Matrix3x3 Matrix3x3::operator - (const Matrix3x3 &M) const
{
	Matrix3x3 temp;

	temp.elements[0][0] = elements[0][0] - M.elements[0][0];
	temp.elements[0][1] = elements[0][1] - M.elements[0][1];
	temp.elements[0][2] = elements[0][2] - M.elements[0][2];

	temp.elements[1][0] = elements[1][0] - M.elements[1][0];
	temp.elements[1][1] = elements[1][1] - M.elements[1][1];
	temp.elements[1][2] = elements[1][2] - M.elements[1][2];

	temp.elements[2][0] = elements[2][0] - M.elements[2][0];
	temp.elements[2][1] = elements[2][1] - M.elements[2][1];
	temp.elements[2][2] = elements[2][2] - M.elements[2][2];

	return (temp);
}


// subtraction (-=)
const Matrix3x3& Matrix3x3::operator -= (const Matrix3x3 &M)
{
	elements[0][0] -= M.elements[0][0];
	elements[0][1] -= M.elements[0][1];
	elements[0][2] -= M.elements[0][2];

	elements[1][0] -= M.elements[1][0];
	elements[1][1] -= M.elements[1][1];
	elements[1][2] -= M.elements[1][2];

	elements[2][0] -= M.elements[2][0];
	elements[2][1] -= M.elements[2][1];
	elements[2][2] -= M.elements[2][2];

	return (*this);
}


// multiplication (*)
const Matrix3x3 Matrix3x3::operator * (const Matrix3x3 &M) const
{
	Matrix3x3 temp;

	temp.elements[0][0] = (elements[0][0] * M.elements[0][0]) + 
						  (elements[0][1] * M.elements[1][0]) +
						  (elements[0][2] * M.elements[2][0]);
	temp.elements[1][0] = (elements[1][0] * M.elements[0][0]) + 
						  (elements[1][1] * M.elements[1][0]) +
						  (elements[1][2] * M.elements[2][0]);
	temp.elements[2][0] = (elements[2][0] * M.elements[0][0]) + 
						  (elements[2][1] * M.elements[1][0]) +
						  (elements[2][2] * M.elements[2][0]);

	temp.elements[0][1] = (elements[0][0] * M.elements[0][1]) + 
						  (elements[0][1] * M.elements[1][1]) +
						  (elements[0][2] * M.elements[2][1]);
	temp.elements[1][1] = (elements[1][0] * M.elements[0][1]) + 
						  (elements[1][1] * M.elements[1][1]) +
						  (elements[1][2] * M.elements[2][1]);
	temp.elements[2][1] = (elements[2][0] * M.elements[0][1]) + 
						  (elements[2][1] * M.elements[1][1]) +
						  (elements[2][2] * M.elements[2][1]);

	temp.elements[0][2] = (elements[0][0] * M.elements[0][2]) + 
						  (elements[0][1] * M.elements[1][2]) +
						  (elements[0][2] * M.elements[2][2]);
	temp.elements[1][2] = (elements[1][0] * M.elements[0][2]) + 
						  (elements[1][1] * M.elements[1][2]) +
						  (elements[1][2] * M.elements[2][2]);
	temp.elements[2][2] = (elements[2][0] * M.elements[0][2]) + 
						  (elements[2][1] * M.elements[1][2]) +
						  (elements[2][2] * M.elements[2][2]);

	return (temp);
}


// multiplcation (*=)
const Matrix3x3& Matrix3x3::operator *= (const Matrix3x3 &M)
{
	Matrix3x3 temp;
	temp = *this * M;
	*this = temp;

	return (*this);
}


// scalar-multiplication (*)
const Matrix3x3 Matrix3x3::operator * (const float s) const
{
	Matrix3x3 M;

	M.elements[0][0] = elements[0][0] * s;
	M.elements[0][1] = elements[0][1] * s;
	M.elements[0][2] = elements[0][2] * s;

	M.elements[1][0] = elements[1][0] * s;
	M.elements[1][1] = elements[1][1] * s;
	M.elements[1][2] = elements[1][2] * s;

	M.elements[2][0] = elements[2][0] * s;
	M.elements[2][1] = elements[2][1] * s;
	M.elements[2][2] = elements[2][2] * s;

	return (M);
}


// scalar-multiplication (*=)
const Matrix3x3& Matrix3x3::operator *= (const float s)
{
	elements[0][0] *= s;
	elements[0][1] *= s;
	elements[0][2] *= s;

	elements[1][0] *= s;
	elements[1][1] *= s;
	elements[1][2] *= s;

	elements[2][0] *= s;
	elements[2][1] *= s;
	elements[2][2] *= s;

	return (*this);
}


// vector-multiplication (*)
const Vector3D Matrix3x3::operator * (const Vector3D &V) const
{
	Vector3D temp;

	temp.x = (V.x * elements[0][0]) + (V.y * elements[0][1]) + (V.z * elements[0][2]);
	temp.y = (V.x * elements[1][0]) + (V.y * elements[1][1]) + (V.z * elements[1][2]);
	temp.z = (V.x * elements[2][0]) + (V.y * elements[2][1]) + (V.z * elements[2][2]);

	return (temp);
}


// matrix-division (/)
const Matrix3x3 Matrix3x3::operator / (const Matrix3x3 &M) const
{
	return (*this * M.Inverse ());
}


// matrix-division (/=)
const Matrix3x3& Matrix3x3::operator /= (const Matrix3x3 &M)
{
	return (*this = *this * M.Inverse ());
}


// scalar-division (/)
const Matrix3x3 Matrix3x3::operator / (const float s) const
{
	Matrix3x3 temp;

	temp.elements[0][0] = elements[0][0] / s;
	temp.elements[0][1] = elements[0][1] / s;
	temp.elements[0][2] = elements[0][2] / s;

	temp.elements[1][0] = elements[1][0] / s;
	temp.elements[1][1] = elements[1][1] / s;
	temp.elements[1][2] = elements[1][2] / s;

	temp.elements[2][0] = elements[2][0] / s;
	temp.elements[2][1] = elements[2][1] / s;
	temp.elements[2][2] = elements[2][2] / s;

	return (temp);
}


// scalar-division (/=)
const Matrix3x3& Matrix3x3::operator /= (const float s)
{
	elements[0][0] /= s;
	elements[0][1] /= s;
	elements[0][2] /= s;

	elements[1][0] /= s;
	elements[1][1] /= s;
	elements[1][2] /= s;

	elements[2][0] /= s;
	elements[2][1] /= s;
	elements[2][2] /= s;

	return (*this);
}


// matrix to an integer power
const Matrix3x3 Matrix3x3::operator ^ (const int p) const
{
	Matrix3x3 temp;

	for (int j = 0; j < p; j++)
	{
		temp *= *this;
	}

	return (temp);
}


// fills the matrix with random elements
void Matrix3x3::Random_Elements (const int min, const int max)
{
	Random_Number generator;

	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			elements[j][k] = float (generator.Random (min, max));
		}
	}
}


// sets the elements of the matrix to create a rotation matrix around the x-axis
void Matrix3x3::Rotation_Matrix_X (const float sine, const float cosine)
{
	elements[0][0] = 1;
	elements[0][1] = 0;
	elements[0][2] = 0;

	elements[1][0] = 0;
	elements[1][1] = cosine;
	elements[1][2] = -sine;

	elements[2][0] = 0;
	elements[2][1] = sine;
	elements[2][2] = cosine;
}


// sets the elements of the matrix to create a rotation matrix around the y-axis
void Matrix3x3::Rotation_Matrix_Y (const float sine, const float cosine)
{
	elements[0][0] = cosine;
	elements[0][1] = 0;
	elements[0][2] = sine;

	elements[1][0] = 0;
	elements[1][1] = 1;
	elements[1][2] = 0;

	elements[2][0] = -sine;
	elements[2][1] = 0;
	elements[2][2] = cosine;
}


// sets the elements of the matrix to create a rotation matrix around the z-axis
void Matrix3x3::Rotation_Matrix_Z (const float sine, const float cosine)
{
	elements[0][0] = cosine;
	elements[0][1] = -sine;
	elements[0][2] = 0;

	elements[1][0] = sine;
	elements[1][1] = cosine;
	elements[1][2] = 0;

	elements[2][0] = 0;
	elements[2][1] = 0;
	elements[2][2] = 1;
}


// sets the elements of the matrix to create a rotation matrix around an arbitrary axis
void Matrix3x3::Rotation_Matrix_Axis (const float sine, const float cosine, const Vector3D &A)
{
	float t = 1 - cosine;

	elements[0][0] = t * A.x * A.x + cosine;
	elements[0][1] = t * A.x * A.y - sine * A.z;
	elements[0][2] = t * A.x * A.z + sine * A.y;

	elements[1][0] = t * A.y * A.x + sine * A.z;
	elements[1][1] = t * A.y * A.y + cosine;
	elements[1][2] = t * A.y * A.z - sine * A.x;

	elements[2][0] = t * A.z * A.x - sine * A.y;
	elements[2][1] = t * A.z * A.y + sine * A.x;
	elements[2][2] = t * A.z * A.z + cosine;
}


// returns the inverse of an orthonormal matrix
Matrix3x3 Matrix3x3::Orthonormal_Inverse () const
{
	return (this->Transpose ());
}


// returns the transpose of this matrix
Matrix3x3 Matrix3x3::Transpose () const
{
	Matrix3x3 temp;

	temp.elements[0][0] = elements[2][2];
	temp.elements[0][1] = elements[2][1];
	temp.elements[0][2] = elements[2][0];

	temp.elements[1][0] = elements[1][2];
	temp.elements[1][1] = elements[1][1];
	temp.elements[1][2] = elements[1][0];

	temp.elements[2][0] = elements[0][2];
	temp.elements[2][1] = elements[0][1];
	temp.elements[2][2] = elements[0][0];

	return (temp);
}


// returns the determinant of the matrix
float Matrix3x3::operator ! () const
{
	return ((elements[0][0] * (elements[1][1] * elements[2][2] - elements[1][2] * elements[2][1])) - 
			(elements[0][1] * (elements[1][0] * elements[2][2] - elements[1][2] * elements[2][0])) +
			(elements[0][2] * (elements[1][0] * elements[2][1] - elements[2][0] * elements[1][1])));
}


// returns the inverse of the matrix
Matrix3x3 Matrix3x3::Inverse () const
{
	float det = !*this;
	Matrix3x3 temp;

	temp.elements[0][0] =  (elements[1][1] * elements[2][2] - elements[1][2] * elements[2][1]) / det;
	temp.elements[0][1] = -(elements[0][1] * elements[2][2] - elements[2][1] * elements[0][2]) / det;
	temp.elements[0][2] =  (elements[0][1] * elements[1][2] - elements[1][1] * elements[0][2]) / det;

	temp.elements[1][0] = -(elements[1][0] * elements[2][2] - elements[1][2] * elements[2][0]) / det;
	temp.elements[1][1] =  (elements[0][0] * elements[2][2] - elements[2][0] * elements[0][2]) / det;
	temp.elements[1][2] = -(elements[0][0] * elements[1][2] - elements[1][0] * elements[0][2]) / det;

	temp.elements[2][0] =  (elements[1][0] * elements[2][1] - elements[2][0] * elements[1][1]) / det;
	temp.elements[2][1] = -(elements[0][0] * elements[2][1] - elements[2][0] * elements[0][1]) / det;
	temp.elements[2][2] =  (elements[0][0] * elements[1][1] - elements[0][1] * elements[1][0]) / det;

	return (temp);
}


// prints the properties of the maitrx
void Matrix3x3::Matrix_Print (const char* name) const
{
	cout << name << " :" << endl;
	cout << "[ " << elements[0][0] << "   " << elements[0][1] << "   " << elements[0][2] << " ]" << endl;
	cout << "[ " << elements[1][0] << "   " << elements[1][1] << "   " << elements[1][2] << " ]" << endl;
	cout << "[ " << elements[2][0] << "   " << elements[2][1] << "   " << elements[2][2] << " ]" << endl;
	cout << endl;
}


