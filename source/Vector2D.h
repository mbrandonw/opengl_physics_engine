/* ---------------------------------------------------------------------------
 *
 *		Vector2D class - Michael Brandon Williams
 *
 *		Vector2D.h
 *
 * ---------------------------------------------------------------------------
 */

#ifndef _VECTOR2D_H
#define _VECTOR2D_H


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



class Vector2D  
{
	public:

		float x, y;

		// contructor and destructors

		Vector2D ()
		{
			x = 0.0f;
			y = 0.0f;
		}

		Vector2D (float vx, float vy)
		{
			x = vx;
			y = vy;
		}

		Vector2D (const Vector2D &V)
		{
			x = V.x;
			y = V.y;
		}

		virtual ~Vector2D ()
		{
		}

		// accessors
		inline float _x () const
		{
			return (x);
		}

		inline float _y () const
		{
			return (y);
		}

		// assignment
		const Vector2D& operator = (const Vector2D &V)
		{
			x = V.x;
			y = V.y;
			return (*this);
		}

		// boolean tests
		const bool operator == (const Vector2D &V) const
		{
			return ((x == V.x) && (y == V.y));
		}

		const bool operator != (const Vector2D &V) const
		{
			return ((x != V.x) && (y != V.y));
		}

		// tests if this vector is a zero vector
		inline bool Zero_Vector () const
		{
			return ((x == 0) && (y == 0));
		}

		// sets the components of the vector based on the angle and magnitude passed
		inline void Angle_Norm_Set (const float angle, const float norm)
		{
			x = norm * cosf (angle);
			y = norm * sinf (angle);
		}

		// addition
		const Vector2D operator + (const Vector2D &V) const
		{
			return (Vector2D ((x + V.x), (y + V.y)));
		}

		const Vector2D& operator += (const Vector2D &V)
		{
			x += V.x;
			y += V.y;
			return (*this);
		}

		// subtraction
		const Vector2D operator - (const Vector2D &V) const
		{
			return (Vector2D ((x - V.x), (y - V.y)));
		}

		const Vector2D& operator -= (const Vector2D &V)
		{
			x -= V.x;
			y -= V.y;
			return (*this);
		}

		// vector-vector multiplication
		const Vector2D operator * (const Vector2D &V) const
		{
			return (Vector2D ((x * V.x), (y * V.y)));
		}

		const Vector2D& operator *= (const Vector2D &V)
		{
			x *= V.x;
			y *= V.y;
			return (*this);
		}

		// vector-scalar multiplication
		const Vector2D operator * (const float s) const
		{
			return (Vector2D ((x * s), (y * s)));
		}

		const Vector2D& operator *= (const float s)
		{
			x *= s;
			y *= s;
			return (*this);
		}

		// vector-vector division
		const Vector2D operator / (const Vector2D &V) const
		{
			return (Vector2D ((x / V.x), (y / V.y)));
		}

		const Vector2D& operator /= (const Vector2D &V)
		{
			x /= V.x;
			y /= V.y;
			return (*this);
		}

		// vector-scalar division
		const Vector2D operator / (const float s) const
		{
			return (Vector2D ((x / s), (y / s)));
		}

		const Vector2D& operator /= (const float s)
		{
			x /= s;
			y /= s;
			return (*this);
		}

		// dot and cross product
		const float operator % (const Vector2D &V) const
		{
			return ((x * V.x) + (y * V.y));
		}

		const float operator ^ (const Vector2D &V) const
		{
			return ((x * V.y) - (y * V.x));
		}

		// returns the norm of the vector
		const float operator ! () const
		{
			return (sqrtf (x * x + y * y));
		}

		// sets the norm of the vector
		const Vector2D operator | (const float norm) const
		{
			return (*this * (norm / !*this));
		}

		const Vector2D& operator |= (const float norm)
		{
			return (*this = *this | norm);
		}

		// makes this vector a unit vector
		inline void Normalize ()
		{
			float norm = !*this;

			x /= norm;
			y /= norm;
		}

		// returns the unit vector of this vector
		inline const Vector2D Unit_Vector () const
		{
			Vector2D temp;
			float norm = !*this;

			temp.x = x / norm;
			temp.y = y / norm;

			return (temp);
		}

		// returns the cosine of the angle between two vectors
		inline const float Cosine_Angle (const Vector2D &V) const
		{
			return ((*this % V) / (!*this * !V));
		}

		// returns the sine of the angle between two vectors
		inline const float Sine_Angle (const Vector2D &V) const
		{
			return ((*this ^ V) / (!*this * !V));
		}

		// returns the parallel and perpendicular scalar projections
		const float operator > (const Vector2D &V) const
		{
			if (V.Zero_Vector ())
			{
				return (!*this);
			}

			return ((*this % V) / (!V));
		}

		const float operator < (const Vector2D &V) const
		{
			if (V.Zero_Vector ())
			{
				return (0.0f);
			}

			return (fabsf (*this ^ V) / (!V));
		}

		// returns the parallel and perpendicular vector projections
		const Vector2D operator >> (const Vector2D &V) const
		{
			if (V.Zero_Vector ())
			{
				return (*this);
			}

			return ((V | 1) * (*this > V));
		}

		const Vector2D operator << (const Vector2D &V) const
		{
			if (V.Zero_Vector ())
			{
				return (Vector2D (0.0f, 0.0f));
			}

			return (*this - (*this >> V));
		}

		bool operator || (const Vector2D &V)
		{
			if (fabsf (*this ^ V) <= 0.001f)
			{
				return (true);
			}

			return (false);
		}

		// returns the vector of this vector reflected over "N"
		inline const Vector2D Reflection (const Vector2D &N) const
		{
			return (*this - (*this << N) * 2.0f);
		}

		// returns this vector rotated around the origin by an angle. the
		// angle must be passed in terms of its sine and cosine
		inline const Vector2D Rotate (const float sine, const float cosine) const
		{
			Vector2D temp;

			temp.x = x * cosine - y * sine;
			temp.y = x * sine + y * cosine;

			return (temp);
		}

		// prints the properties of the object
		void Vector_Print (const char* name) const
		{
			cout << "Vector2D " << name << " = ( " << x << " , " << y << " )" << endl;
		}

		// draws the vector on the screen (uses Open GL)
		void Vector_Draw (const Vector2D &S) const
		{
			glBegin (GL_LINES);
			{
				glVertex3f (S.x, S.y, 0.0f);
				glVertex3f ((S.x + x), (S.y + y), 0.0f);
			}
			glEnd ();
		}

		// returns a perpendicular vector to this vector
		Vector2D Return_Perpendicular () const
		{
			return (Vector2D (-y, x));
		}

		// sets the components of the vector to random values
		void Random_Components (const int min, const int max)
		{
			Random_Number generator;

			x = float (generator.Random (min, max));
			y = float (generator.Random (min, max));
		}
};



#endif // _VECTOR2D_H



