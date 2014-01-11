/* ---------------------------------------------------------------------------
 *
 *		Extra math functions - Michael Brandon Williams
 *
 *		Math_Extras.h
 *
 * ---------------------------------------------------------------------------
 */



#ifndef _MATH_EXTRAS_H
#define _MATH_EXTRAS_H


#include "Vector2D.h"
#include "Vector3D.h"

#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix.h"




namespace Math
{
	// math constants
	const float pi      = 3.14159265358f;
	const float e       = 2.71828182846f;
	const float trans   = PI / 180.0f;
	const float epsilon = 0.000011f;


	// function prototypes

	inline float To_Degrees (float radians);
	inline float To_Radians (float degrees);
	inline int Maximum (int a, int b);
	inline float Maximum (float a, float b);
	inline double Maximum (double a, double b);
	inline int Minimum (int a, int b);
	inline float Minimum (float a, float b);
	inline double Minimum (double a, double b);
	inline int Square (int x);
	inline float Square (float x);
	inline double Square (double x);
	inline float Point_Line_Distance (float x1, float y1, float x2, float y2, float x3, float y3);
	inline float Point_Line_Distance (const Vector2D &P, const Vector2D &L1, const Vector2D &L2);
	inline Vector2D Line_Intersection (float P_x1, float P_y1, float P_x2, float P_y2,
									   float R_x1, float R_y1, float R_x2, float R_y2);
	inline Vector2D Line_Intersection (const Vector2D &P1, const Vector2D &P2,
									   const Vector2D &R1, const Vector2D &R2);
	inline bool Line_Intersection_Test (float P_x1, float P_y1, float P_x2, float P_y2,
										float R_x1, float R_y1, float R_x2, float R_y2);
	inline bool Line_Intersection_Test (const Vector2D &P1, const Vector2D &P2,
										const Vector2D &R1, const Vector2D &R2);
	inline bool Point_Bounding_Box_Test (float x, float y, float top_x, float top_y, float bottom_x, float bottom_y);
	inline bool Point_Bounding_Box_Test (const Vector2D &P, const Vector2D &T, const Vector2D &B);


	// function implementations


	// when passed an angle in radians it will return the angle in degrees
	inline float To_Degrees (float radians)
	{
		return (radians / trans);
	}

	// when passed an angle in degrees it will return the angle in radians
	inline float To_Radians (float degrees)
	{
		return (degrees * trans);
	}

	// returns the larger of two numbers (ints)
	inline int Maximum (int a, int b)
	{
		return ((a >= b) ? a : b);
	}

	// returns the larger of two numbers (floats)
	inline float Maximum (float a, float b)
	{
		return ((a >= b) ? a : b);
	}

	// returns the larger of two numbers (doubles)
	inline double Maximum (double a, double b)
	{
		return ((a >= b) ? a : b);
	}

	// returns the smaller of two numbers (ints)
	inline int Minimum (int a, int b)
	{
		return ((a <= b) ? a : b);
	}

	// returns the smaller of two numbers (floats)
	inline float Minimum (float a, float b)
	{
		return ((a <= b) ? a : b);
	}

	// returns the smaller of two numbers (doubles)
	inline double Minimum (double a, double b)
	{
		return ((a <= b) ? a : b);
	}

	// squares an int
	inline int Square (int x)
	{
		return (x * x);
	}

	// squares a float
	inline float Square (float x)
	{
		return (x * x);
	}

	// squares a double
	inline double Square (double x)
	{
		return (x * x);
	}

	// distance from point (x1, y1) to line from (x2,y2) to (x3,y3)
	inline float Point_Line_Distance (float x1, float y1, float x2, float y2, float x3, float y3)
	{
		float delta_x = x3 - x2;
		float delta_y = y3 - y2;

		return ((delta_x * (y1 - y2) - delta_y * (x1 - x2)) / sqrtf (delta_x * delta_x + delta_y * delta_y));
	}

	// distance from point P to line from L1 to L2
	inline float Point_Line_Distance (const Vector2D &P, const Vector2D &L1, const Vector2D &L2)
	{
		float delta_x = L2.x - L1.x;
		float delta_y = L2.y - L1.y;

		return ((delta_x * (P.y - L1.y) - delta_y * (P.x - L1.x)) / sqrtf (delta_x * delta_x + delta_y * delta_y));
	}

		// returns the point two lines intersect at
	inline Vector2D Line_Intersection (float P_x1, float P_y1, float P_x2, float P_y2,
									   float R_x1, float R_y1, float R_x2, float R_y2)
	{
		// slope of lines
		float slope1 = (P_y1 - P_y2) / (((P_x1 - P_x2) == 0.0f) ? epsilon : (P_x1 - P_x2));
		float slope2 = (R_y1 - R_y2) / (((R_x1 - R_x2) == 0.0f) ? epsilon : (R_x1 - R_x2));

		// point of intersection
		Vector2D P;

		// make sure they are not parallel lines
		if (slope1 != slope2)
		{
			// calculate x-position of the point of intersection
			P.x = (R_y1 - P_y1 + slope1 * P_x1 - slope2 * R_x1) / (slope1 - slope2);

			// plug into the equation that is not an infinite slope for the y-position
			if (P_x1 != P_x2)
			{
				P.y = slope1 * (P.x - P_x1) + P_y1;
			}
			else
			{
				P.y = slope2 * (P.x - R_x1) + R_y1;
			}
		}

		return (P);
	}

	// returns the point two lines intersect at
	inline Vector2D Line_Intersection (const Vector2D &P1, const Vector2D &P2,
									   const Vector2D &R1, const Vector2D &R2)
	{
		// slope of lines
		float slope1 = (P1.y - P2.y) / ((P1.x == P2.x) ? epsilon : (P1.x - P2.x));
		float slope2 = (R1.y - R2.y) / ((R1.x == R2.x) ? epsilon : (R1.x - R2.x));

		// point of intersection
		Vector2D P;

		// make sure they are not parallel lines
		if (slope1 != slope2)
		{
			// calculate x-position of the point of intersection
			P.x = (R1.y - P1.y + slope1 * P1.x - slope2 * R1.x) / (slope1 - slope2);

			// plug into the equation that is not an infinite slope for the y-position
			if (P1.x != P2.x)
			{
				P.y = slope1 * (P.x - P1.x) + P1.y;
			}
			else
			{
				P.y = slope2 * (P.x - R1.x) + R1.y;
			}
		}

		return (P);
	}

	// tests if two lines intersect at a point that falls on both lines
	inline bool Line_Intersection_Test (float P_x1, float P_y1, float P_x2, float P_y2,
										float R_x1, float R_y1, float R_x2, float R_y2)
	{
		// point of intersection
		Vector2D P (Line_Intersection (P_x1, P_y1, P_x2, P_y2, R_x1, R_y1, R_x2, R_y2));

		// check if the point of intersection falls on both lines
		if (Point_Bounding_Box_Test (P.x, P.y, Minimum (P_x1, P_x2), Maximum (P_y1, P_y2), Maximum (P_x1, P_x2), Minimum (P_y1, P_y2)) &&
			Point_Bounding_Box_Test (P.x, P.y, Minimum (R_x1, R_x2), Maximum (R_y1, R_y2), Maximum (R_x1, R_x2), Minimum (R_y1, R_y2)))
		{
			return (true);
		}

		// point fell on neither line
		return (false);
	}

	// tests if two lines intersect at a point that falls on both lines
	inline bool Line_Intersection_Test (const Vector2D &P1, const Vector2D &P2,
										const Vector2D &R1, const Vector2D &R2)
	{
		// point of intersection
		Vector2D P (Line_Intersection (P1, P2, R1, R2));

		// check if the point of intersection falls on both lines
		if (Point_Bounding_Box_Test (P.x, P.y, Minimum (P1.x, P2.x), Maximum (P1.y, P2.y), Maximum (P1.x, P2.x), Minimum (P1.y, P2.y)) &&
            Point_Bounding_Box_Test (P.x, P.y, Minimum (R1.x, R2.x), Maximum (R1.y, R2.y), Maximum (R1.x, R2.x), Minimum (R1.y, R2.y)))
		{
			return (true);
		}

		// point fell on neither line
		return (false);
	}

	// tests whether or not a point is in a bounding box
	inline bool Point_Bounding_Box_Test (float x, float y, float top_x, float top_y, float bottom_x, float bottom_y)
	{
		// check if the point is in the box
		if ((x >= top_x) && (x <= bottom_x) && (y >= bottom_y) && (y <= top_y))
		{
			// point is in box
			return (true);
		}

		// point is outside box
		return (false);
	}

	// tests whether or not a point is in a bounding box
	inline bool Point_Bounding_Box_Test (const Vector2D &P, const Vector2D &T, const Vector2D &B)
	{
		// check if the point is in the box
		if ((P.x >= T.x) && (P.x <= B.x) && (P.y >= B.y) && (P.y <= T.y))
		{
			// point is in box
			return (true);
		}

		// point is outside box
		return (false);
	}
}


#endif



