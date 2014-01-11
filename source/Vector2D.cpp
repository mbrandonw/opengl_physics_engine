/* ---------------------------------------------------------------------------
 *
 *		Vector2D class - Michael Brandon Williams
 *
 *		Vector2D.cpp
 *
 * ---------------------------------------------------------------------------
 */

#include "Vector2D.h"

/*
// constructors and destructors


// constructor for when nothing is passed to the object
Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}


// constructor for when two floating point numbers are passed
// for the components of the vector
Vector2D::Vector2D (float vx, float vy)
{
	x = vx;
	y = vy;
}


// constructor for when another Vector2D is passed and this vector
// is initialized to the same components as V
Vector2D::Vector2D (const Vector2D &V)
{
	x = V.x;
	y = V.y;
}


// destructor of object
Vector2D::~Vector2D()
{

}



// returns the x-component of this vector
float Vector2D::_x () const
{
	return (x);
}


// returns the y-component of this vector
float Vector2D::_y () const
{
	return (y);
}



// assignment
const Vector2D& Vector2D::operator = (const Vector2D &V)
{
	x = V.x;
	y = V.y;
	return (*this);
}


// boolean test for equality
const bool Vector2D::operator == (const Vector2D &V) const
{
	return ((x == V.x) && (y == V.y));
}


// boolean test for inequality
const bool Vector2D::operator != (const Vector2D &V) const
{
	return ((x != V.x) && (y != V.y));
}



// returns a boolean value determining whether or not this vector is a zero vector
bool Vector2D::Zero_Vector () const
{
	return ((x == 0) && (y == 0));
}




// sets the components of the vector based on the angle and norm passed
void Vector2D::Angle_Norm_Set (const float angle, const float norm)
{
	x = norm * cosf (angle);
	y = norm * sinf (angle);
}



// vector addition (+)
const Vector2D Vector2D::operator + (const Vector2D &V) const
{
	return (Vector2D ((x + V.x), (y + V.y)));
}


// vector addition (+=)
const Vector2D& Vector2D::operator += (const Vector2D &V)
{
	x += V.x;
	y += V.y;
	return (*this);
}


// vector subtraction (-)
const Vector2D Vector2D::operator - (const Vector2D &V) const
{
	return (Vector2D ((x - V.x), (y - V.y)));
}


// vector subtraction (-=)
const Vector2D& Vector2D::operator -= (const Vector2D &V)
{
	x -= V.x;
	y -= V.y;
	return (*this);
}


// vector-vector multiplication (*)
const Vector2D Vector2D::operator * (const Vector2D &V) const
{
	return (Vector2D ((x * V.x), (y * V.y)));
}


// vector-vector multiplication (*=)
const Vector2D& Vector2D::operator *= (const Vector2D &V) 
{
	x *= V.x;
	y *= V.y;
	return (*this);
}


// vector-scalar multiplication (*)
const Vector2D Vector2D::operator * (const float s) const
{
	return (Vector2D ((x * s), (y * s)));
}


// vector-scalar multiplication (*=)
const Vector2D& Vector2D::operator *= (const float s)
{
	x *= s;
	y *= s;
	return (*this);
}


// vector-vector division (/)
const Vector2D Vector2D::operator / (const Vector2D &V) const
{
	return (Vector2D ((x / V.x), (y / V.y)));
}


// vector-vector division (/=)
const Vector2D& Vector2D::operator /= (const Vector2D &V)
{
	x /= V.x;
	y /= V.y;
	return (*this);
}


// vector-scalar division (/)
const Vector2D Vector2D::operator / (const float s) const
{
	return (Vector2D ((x / s), (y / s)));
}


// vector-scalar_division (/=)
const Vector2D& Vector2D::operator /= (const float s)
{
	x /= s;
	y /= s;
	return (*this);
}


// dot product
const float Vector2D::operator % (const Vector2D &V) const
{
	return ((x * V.x) + (y * V.y));
}


// cross product
const float Vector2D::operator ^ (const Vector2D &V) const
{
	return ((x * V.y) - (V.x * y));
}


// returns the norm of the vector
const float Vector2D::operator ! () const
{
	return (sqrtf ((x * x) + (y * y)));
}


// sets the norm of this vector
const Vector2D Vector2D::operator | (const float norm) const
{
	return (*this * (norm / !*this));
}


// sets the norm of this vector
const Vector2D& Vector2D::operator |= (const float norm)
{
	return (*this = *this | norm);
}



// makes this vector a unit vector
void Vector2D::Normalize ()
{
	float norm = !*this;

	x /= norm;
	y /= norm;
}




// returns the unit vector of this vector
const Vector2D Vector2D::Unit_Vector () const
{
	Vector2D temp;
	float norm = !*this;

	temp.x = x / norm;
	temp.y = y / norm;

	return (temp);
}




// returns the cosine of the angle between the two vectors
const float inline Vector2D::Cosine_Angle (const Vector2D &V) const
{
	return ((*this % V) / (!*this * !V));
}


// returns the sine of the angle between the two vectors
const float inline Vector2D::Sine_Angle (const Vector2D &V) const
{
	return ((*this ^ V) / (!*this * !V));
}



// returns the parallel scalar projection of this vector onto V
const float Vector2D::operator > (const Vector2D &V) const
{
	if (V.Zero_Vector ())
	{
		return (!*this);
	}

	return ((*this % V) / (!V));
}


// returns the perpendicular scalar projection of this vector onto V
const float Vector2D::operator < (const Vector2D &V) const
{
	if (V.Zero_Vector ())
	{
		return (0);
	}

	return (fabsf (*this ^ V) / (!V));
}


// returns the parallel vector projection of this vector onto V
const Vector2D Vector2D::operator >> (const Vector2D &V) const
{
	if (V.Zero_Vector ())
	{
		return (*this);
	}

	return ((V | 1) * (*this > V));
}


// returns the perpendicular vector projection of this vector onto V
const Vector2D Vector2D::operator << (const Vector2D &V) const
{
	if (V.Zero_Vector ())
	{
		return (Vector2D (0, 0));
	}

	return (*this - (*this >> V));
}



// returns the vector of this vector reflected over "N"
//const Vector2D inline Vector2D::Reflection (const Vector2D &N) const
inline const Vector2D Vector2D::Reflection (const Vector2D &N) const
{
	return (*this - (*this << N) * 2.0f);
}




// returns this vector rotated around the origin by an angle. the
// angle must be passed in terms of its sine and cosine
inline const Vector2D Vector2D::Rotate (const float sine, const float cosine) const
{
	Vector2D temp;

	temp.x = x * cosine - y * sine;
	temp.y = x * sine + y * cosine;

	return (temp);
}



// prints the properties of the vector
void Vector2D::Vector_Print (const char* name) const
{
	cout << "Vector2D " << name << " = ( " << x << " , " << y << " )" << endl;
}


// draws the vector on the screen (uses Open GL)
void Vector2D::Vector_Draw (const Vector2D &S) const
{
	glBegin (GL_LINES);
	{
		glVertex3f (S.x, S.y, 0.0f);
		glVertex3f ((S.x + x), (S.y + y), 0.0f);
	}
	glEnd ();
}


// sets the components of the vector to random numbers
void Vector2D::Random_Components (const int min, const int max)
{
	Random_Number generator;

	x = float (generator.Random (min, max));
	y = float (generator.Random (min, max));
}


*/