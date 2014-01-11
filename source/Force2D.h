/* ---------------------------------------------------------------------------
 *
 *		Linear_Force2D class - Michael Brandon Williams
 *
 *		Linear_Force2D.h
 *
 * ---------------------------------------------------------------------------
 */


#ifndef _FORCE2D_H
#define _FORCE2D_H


#include <iostream.h>

#include "Vector2D.h"


/*
 *
 *  used for determining what coordinate system the force is in
 *
 *  LOCAL means the force is defined relative to the body's center of mass
 *  and orientation.
 *
 *  BODY means the force is defined relative to the body's orientation
 *  but not its center of mass.
 *
 *  GLOBAL means the force is defined in the global coordinate system.
 *
 */


/*
 *
 *		Used for determining what coordinate system the force is held in
 *
 */
enum ID_TAG
{
	LOCAL,
	BODY,
	GLOBAL
};


class Force2D  
{
	friend class Physical_Environment2D;
	friend class Rigid_Body2D;
	friend class Particle;

	public:

		// default constructor
		Force2D ();

		// constructor for when the force vector, position vector, and 
		// coordinate system are passed
		Force2D (const Vector2D &F, const Vector2D &P, ID_TAG id_system);

		// constructor for when this force is the copy of another
		Force2D (const Force2D &F);

		// destructor
		virtual ~Force2D ();

		// assignment
		const Force2D& operator = (const Force2D &F);

		// accessors

		// returns the force vector of the force
		Vector2D Return_Force_Vector () const;
		
		// returns the position vector of the force
		Vector2D Return_Force_Position () const;

		// returns the coordinate system that the force is in
		ID_TAG Return_ID () const;

		// modifers

		// changes the force vector based on the components passed
		void Set_Force (float force_x, float force_y);

		// changes the force vector based on the vector passed
		void Set_Force (const Vector2D &F);

		// changes the position vector based on the components passed
		void Set_Position (float position_x, float position_y);

		// changes the position vector based on the vector passed
		void Set_Position (const Vector2D &P);

		// changes the ID of this force
		void Set_ID (ID_TAG id_system);

		// returns the linear force exerted on a rigid body by the force
		Vector2D Return_Linear_Force ();

		// returns the torque exerted on a rigid body by the force
		float Return_Torque (const Vector2D &CM);

		// prints the properties of the force
		void Force_Print (const char* name) const;

	private:

		// returns this force in the global coordinate system -- must pass the
		// sine and cosine of the body's orientation and the position of the center of mass
		Force2D To_Global (float sine, float cosine, const Vector2D &CM) const;

		// vectors that represent the position of the force (point of application)
		// and the direction and magnitude of the force
		Vector2D force, position;

		// ID - determines in what coordinate system the force is being held in.
		ID_TAG id;
};

#endif


