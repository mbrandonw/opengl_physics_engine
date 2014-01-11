/* ---------------------------------------------------------------------------
 *
 *		Kinematic_Object class - Michael Brandon Williams
 *
 *		Kinematic_Object.h
 *
 * ---------------------------------------------------------------------------
 */

#ifndef _KINEMATIC_OBJECT_H
#define _KINEMATIC_OBJECT_H


#include "Vector2D.h"


class Kinematic_Object2D  
{
	friend class Physical_Environment2D;

	public:

		// constructor for when no information is given
		Kinematic_Object2D ();

		// constructors for when the starting position of the object's
		// center of mass is passed
		Kinematic_Object2D (const float center_x, const float center_y);
		Kinematic_Object2D (const Vector2D &center);

		// copy constructor
		Kinematic_Object2D (const Kinematic_Object2D &K);

		// destructor for object
		virtual ~Kinematic_Object2D ();

		// assignment
		const Kinematic_Object2D& operator = (const Kinematic_Object2D &K);

		// returns the vector of the object's position
		Vector2D Return_Position () const;

		// returns the vector of the object's velocity
		Vector2D Return_Velocity () const;

		// returns the vector of the object's acceleration
		Vector2D Return_Acceleration () const;

		// returns the object's orientation
		float Return_Orientation () const;

		// returns the object's angular velocity
		float Return_Angular_Velocity () const;

		// returns the object's angular acceleration
		float Return_Angular_Acceleration () const;

		// changes the position of the object to (x, y)
		void Reset_Position (const float x, const float y);
		void Reset_Position (const Vector2D &pos);

		// changes the orientation of the object to "rotation"
		void Reset_Orientation (const float rotation);

		// changes the velocity of the center of mass
		void Reset_Velocity (const float vel_x, const float vel_y);
		void Reset_Velocity (const Vector2D &vel);

		// changes the acceleration of the center of mass
		void Reset_Acceleration (const float acc_x, const float acc_y);
		void Reset_Acceleration (const Vector2D &acc);

		// changes the angular velocity of the object
		void Reset_Angular_Velocity (const float omega);

		// changes the angular acceleration of the object
		void Reset_Angular_Acceleration (const float alpha);

		// updates the sine and cosine of the orientation
		void Update_Trig ();

		// prints out the properties of the object
		void Kinematic_Object2D_Print (const char* name) const;

	private:

		// integrates object over a time step
		void Euler_Integrate (float delta_t);

		// position of the object's center of mass
		Vector2D position;

		// orientation of the object
		float orientation;

		// sine and cosine of the object's orientation
		float sine, cosine;

		// velocity of the center of mass
		Vector2D velocity;

		// acceleration of the center of mass
		Vector2D acceleration;

		// angular velocity of the object
		float angular_velocity;

		// angular acceleration of the object
		float angular_acceleration;
};


#endif

