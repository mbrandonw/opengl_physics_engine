/* ---------------------------------------------------------------------------
 *
 *		Vector3D class - Michael Brandon Williams
 *
 *		Vector3D.h
 *
 * ---------------------------------------------------------------------------
 */

#ifndef _VECTOR3D_H
#define _VECTOR3D_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#pragma comment (lib, "glaux.lib")

#include <cmath>
#include <iostream.h>

#include "Random_Number.h"

#define PI (3.14159265359f)


class Vector3D
{
	public:

		float x, y, z;

		// constructors and destructors

		Vector3D ();
		Vector3D (const float vx, const float vy, const float vz);
		Vector3D (const Vector3D &V);
		virtual ~Vector3D ();

		// accessors

		inline float _x () const
		{
			return (x);
		}

		inline float _y () const
		{
			return (y);
		}

		inline float _z () const
		{
			return (z);
		}

		// assignment
		const Vector3D& operator = (const Vector3D &V);

		// boolean tests
		const bool operator == (const Vector3D &V) const;
		const bool operator != (const Vector3D &V) const;

		// boolean test for if the vector is a zero vector
		inline bool Zero_Vector () const
		{
			return ((x == 0) && (y == 0) && (z == 0));
		}

		// sets the components of the vector based on the spherical coordinates passed
		inline void Spherical_Set (const float p, const float theta, const float phi)
		{
			float sine_phi = sinf (phi);

			x = p * sine_phi * cosf (theta);
			y = p * sine_phi * sinf (theta);
			z = p * cosf (phi);
		}

		// sets the components of the vector based on the cylindrical coordinates passed
		inline void Cylindrical_Set (const float r, const float theta, const float z)
		{
			x = r * cosf (theta);
			y = r * sinf (theta);
			this->z = z;
		}

		// addition
		const Vector3D operator + (const Vector3D &V) const;
		const Vector3D& operator += (const Vector3D &V);

		// subtraction
		const Vector3D operator - (const Vector3D &V) const;
		const Vector3D& operator -= (const Vector3D &V);

		// vector-vector multiplication
		const Vector3D operator * (const Vector3D &V) const;
		const Vector3D& operator *= (const Vector3D &V);

		// vector-scalar multiplication
		const Vector3D operator * (const float s) const;
		const Vector3D& operator *= (const float s);

		// vector-vector division
		const Vector3D operator / (const Vector3D &V) const;
		const Vector3D& operator /= (const Vector3D &V);

		// vector-scalar division
		const Vector3D operator / (const float s) const;
		const Vector3D& operator /= (const float s);

		// dot product
		const float operator % (const Vector3D &V) const;

		// cross product
		const Vector3D operator ^ (const Vector3D &V) const;
		const Vector3D& operator ^= (const Vector3D &V);

		// returns the norm of the vector
		const float operator ! () const;

		// sets the norm of the vector
		const Vector3D operator | (const float norm) const;
		const Vector3D& operator |= (const float norm);

		// makes this vector a unit vector
		inline void Normalize ()
		{
			float norm = !*this;

			x /= norm;
			y /= norm;
			z /= norm;
		}

		// returns the unit vector of this vector
		inline const Vector3D Unit_Vector () const
		{
			Vector3D temp;
			float norm = !*this;

			temp.x = x / norm;
			temp.y = y / norm;
			temp.z = z / norm;

			return (temp);
		}

		// returns the cosine of the angle between two vectors
		inline const float Cosine_Angle (const Vector3D &V) const
		{
			return ((*this % V) / (!*this * !V));
		}

		// returns the sine of the angle between two vectors
		inline const float Sine_Angle (const Vector3D &V) const
		{
			return ((!(*this ^ V)) / (!*this * !V));
		}

		// returns the parallel and perpendicular scalar projections
		const float operator > (const Vector3D &V) const;
		const float operator < (const Vector3D &V) const;

		// returns the parallel and perpendicular vector projections
		const Vector3D operator >> (const Vector3D &V) const;
		const Vector3D operator << (const Vector3D &V) const;

		// returns the vector of this vector reflected over "N"
		inline const Vector3D Reflection (const Vector3D &N) const
		{
			return (*this - (*this << N) * 2.0f);
		}

		// rotates the vector by an angle around an axis. The angle must be
		// passed in terms of its sine and cosine
		inline const Vector3D Rotate (const float sine, const float cosine, const Vector3D &A) const
		{
			return (Vector3D (*this * cosine + ((A * *this) * (1.0f - cosine)) * A + (*this ^ A) * sine));
		}

		// prints the properties of the object
		void Vector_Print (const char* name) const;

		// draws the vector on the screen (uses Open GL)
		void Vector_Draw (const Vector3D &S) const;

		// sets the components of the vector to random values
		void Random_Components (const int min, const int max);
};


#endif

