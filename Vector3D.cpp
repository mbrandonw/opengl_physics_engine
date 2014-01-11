/* ---------------------------------------------------------------------------
 *
 *		Vector3D class - Michael Brandon Williams
 *
 *		Vector3D.cpp
 *
 * ---------------------------------------------------------------------------
 */

#include "Vector3D.h"


// constructors and destructors


// constructor for when nothing is passed to the object
Vector3D::Vector3D ()
{
	x = 0;
	y = 0;
	z = 0;
}


// constructor for when two floating point numbers are passed
// for the components of the vector
Vector3D::Vector3D (const float vx, const float vy, const float vz)
{
	x = vx;
	y = vy;
	z = vz;
}


// constructor for when another Vector3D is passed and this vector
// is initialized to the same components as V
Vector3D::Vector3D (const Vector3D &V)
{
	x = V.x;
	y = V.y;
	z = V.z;
}


// destructor of object
Vector3D::~Vector3D ()
{

}


/*
// returns the x-component of this vector
float Vector3D::_x () const
{
	return (x);
}


// returns the y-component of this vector
float Vector3D::_y () const
{
	return (y);
}


// returns the z-component of this vector
float Vector3D::_z () const
{
	return (z);
}
*/


// assignment
const Vector3D& Vector3D::operator = (const Vector3D &V)
{
	x = V.x;
	y = V.y;
	z = V.z;
	return (*this);
}


// boolean test for equality
const bool Vector3D::operator == (const Vector3D &V) const
{
	return ((x == V.x) && (y == V.y) && (z == V.z));
}


// boolean test for inequality
const bool Vector3D::operator != (const Vector3D &V) const
{
	return ((x != V.x) && (y != V.y) && (z != V.z));
}


/*
// boolean test for checking if this vector is a zero vector
bool Vector3D::Zero_Vector () const
{
	return ((x == 0) && (y == 0) && (z == 0));
}
*/


/*
// sets the components of the vector based on the spherical coordinates passed
void Vector3D::Spherical_Set (const float p, const float theta, const float phi)
{
	float sine_phi = sinf (phi);

	x = p * sine_phi * cosf (theta);
	y = p * sine_phi * sinf (theta);
	z = p * cosf (phi);
}


// sets the components of the vector based on the cylindrical coordinates passed
void Vector3D::Cylindrical_Set (const float r, const float theta, const float z)
{
	x = r * cosf (theta);
	y = r * sinf (theta);
	this->z = z;
}
*/


// vector addition (+)
const Vector3D Vector3D::operator + (const Vector3D &V) const
{
	return (Vector3D ((x + V.x), (y + V.y), (z + V.z)));
}


// vector addition (+=)
const Vector3D& Vector3D::operator += (const Vector3D &V)
{
	x += V.x;
	y += V.y;
	z += V.z;
	return (*this);
}


// vector subtraction (-)
const Vector3D Vector3D::operator - (const Vector3D &V) const
{
	return (Vector3D ((x - V.x), (y - V.y), (z - V.z)));
}


// vector subtraction (-=)
const Vector3D& Vector3D::operator -= (const Vector3D &V)
{
	x -= V.x;
	y -= V.y;
	z -= V.z;
	return (*this);
}


// vector-vector multiplication (*)
const Vector3D Vector3D::operator * (const Vector3D &V) const
{
	return (Vector3D ((x * V.x), (y * V.y), (z * V.z)));
}


// vector-vector multiplication (*=)
const Vector3D& Vector3D::operator *= (const Vector3D &V)
{
	x *= V.x;
	y *= V.y;
	z *= V.z;
	return (*this);
}


// vector-scalar multiplication (*)
const Vector3D Vector3D::operator * (const float s) const
{
	return (Vector3D ((x * s), (y * s), (z * s)));
}


// vector-scalar multiplication (*=)
const Vector3D& Vector3D::operator *= (const float s)
{
	x *= s;
	y *= s;
	z *= s;
	return (*this);
}


// vector-vector division (/)
const Vector3D Vector3D::operator / (const Vector3D &V) const
{
	return (Vector3D ((x / V.x), (y / V.y), (z / V.z)));
}


// vector-vector division (/=)
const Vector3D& Vector3D::operator /= (const Vector3D &V)
{
	x /= V.x;
	y /= V.y;
	z /= V.z;
	return (*this);
}


// vector-scalar division (/)
const Vector3D Vector3D::operator / (const float s) const
{
	return (Vector3D ((x / s), (y / s), (z / s)));
}


// vector-scalar division (/=)
const Vector3D& Vector3D::operator /= (const float s)
{
	x /= s;
	y /= s;
	z /= s;
	return (*this);
}


// dot product
const float Vector3D::operator % (const Vector3D &V) const
{
	return ((x * V.x) + (y * V.y) + (z * V.z));
}


// cross product (^)
const Vector3D Vector3D::operator ^ (const Vector3D &V) const
{
	return (Vector3D (((y * V.z) - (z * V.y)),
					  ((z * V.x) - (x * V.z)),
					  ((x * V.y) - (y * V.x))));
}


// cross product (^=)
const Vector3D& Vector3D::operator ^= (const Vector3D &V)
{
	Vector3D temp (0, 0, 0);

	temp.x = (y * V.z) - (z * V.y);
	temp.y = (z * V.x) - (x * V.z);
	temp.z = (x * V.y) - (y * V.x);

	*this = temp;

	return (*this);

	//return (*this);
}


// returns the norm of the vector
const float Vector3D::operator ! () const
{
	return (sqrtf ((x * x) + (y * y) + (z * z)));
}

// sets the norm of the vector (|)
const Vector3D Vector3D::operator | (const float norm) const
{
	return (*this * (norm / !*this));
}


// sets the norm of the vector (|=)
const Vector3D& Vector3D::operator |= (const float norm)
{
	return (*this = *this | norm);
}


/*
// makes this vector a unit vector
void Vector3D::Normalize ()
{
	float norm = !*this;

	x /= norm;
	y /= norm;
	z /= norm;
}

// returns the unit vector of this vector
const Vector3D Vector3D::Unit_Vector () const
{
	Vector3D temp;
	float norm = !*this;

	temp.x = x / norm;
	temp.y = y / norm;
	temp.z = z / norm;

	return (temp);
}
*/


/*
// returns the cosine of the angle between two vectors
const float inline Vector3D::Cosine_Angle (const Vector3D &V) const
{
	return ((*this % V) / (!*this * !V));
}


// returns the sine of the angle between two vectors
const float inline Vector3D::Sine_Angle (const Vector3D &V) const
{
	return ((!(*this ^ V)) / (!*this * !V));
}
*/


// returns the parallel scalar projection of this vector onto V
const float Vector3D::operator > (const Vector3D &V) const
{
	if (V.Zero_Vector ())
	{
		return (!*this);
	}

	return ((*this % V) / (!V));
}


// returns the perpendicular scalar projection of this vector onto V
const float Vector3D::operator < (const Vector3D &V) const
{
	if (V.Zero_Vector ())
	{
		return (0);
	}

	return (fabsf ((!(*this ^ V)) / (!V)));
}


// returns the parallel vector projection of this vector onto V
const Vector3D Vector3D::operator >> (const Vector3D &V) const
{
	if (V.Zero_Vector ())
	{
		return (*this);
	}

	return ((V | 1) * (*this > V));
}


// returns the perpendicular vector projection of this vector onto V
const Vector3D Vector3D::operator << (const Vector3D &V) const
{
	if (V.Zero_Vector ())
	{
		return (Vector3D (0, 0, 0));
	}

	return (*this - (*this >> V));
}


/*
// rotates the vector by an angle around an axis. The angle must be
// passed in terms of its sine and cosine
const Vector3D Vector3D::Rotate (const float sine, const float cosine, const Vector3D &A) const
{
	return (Vector3D (*this * cosine + ((A * *this) * (1.0f - cosine)) * A + (*this ^ A) * sine));
}
*/


// prints the properties of the object
void Vector3D::Vector_Print (const char* name) const
{
	cout << "Vector3D " << name << " = ( " << x << " , " << y << " , " << z << ")" << endl;
}


// draws the vector on the screen (uses Open GL)
void Vector3D::Vector_Draw (const Vector3D &S) const
{
	/*
	glBegin (GL_LINES);
	{
		glVertex3f (S.x, S.y, S.z);
		glVertex3f ((S.x + x), (S.y + y), (S.z + z));
	}
	glEnd ();
	*/
}


// sets the components of the vector to random values
void Vector3D::Random_Components (const int min, const int max)
{
	Random_Number generator;

	x = float (generator.Random (min, max));
	y = float (generator.Random (min, max));
	z = float (generator.Random (min, max));
}


