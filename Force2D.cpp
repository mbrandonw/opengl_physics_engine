/* ---------------------------------------------------------------------------
 *
 *		Linear_Force2D class - Michael Brandon Williams
 *
 *		Linear_Force2D.cpp
 *
 * ---------------------------------------------------------------------------
 */

#include "Force2D.h"


// default constructor
Force2D::Force2D()
{
	force = Vector2D (0.0f, 0.0f);
	position = Vector2D (0.0f, 0.0f);
	id = LOCAL;
}


// constructor for when the force vector, position vector, and 
// coordinate system are passed
Force2D::Force2D (const Vector2D &F, const Vector2D &P, ID_TAG id_system)
{
	force = F;
	position = P;
	id = id_system;
}


// constructor for when this force is the copy of another
Force2D::Force2D (const Force2D &F)
{
	*this = F;
}


// destructor
Force2D::~Force2D()
{

}


// assignment
const Force2D& Force2D::operator = (const Force2D &F)
{
	force = F.force;
	position = F.position;
	id = F.id;
	return (*this);
}


// returns the force vector of the force
Vector2D Force2D::Return_Force_Vector () const
{
	return (Vector2D (force));
}


// returns the position vector of the force
Vector2D Force2D::Return_Force_Position () const
{
	return (Vector2D (position));
}


// returns the coordinate system the force is in
ID_TAG Force2D::Return_ID () const
{
	return (id);
}


// changes the force vector based on the components passed
void Force2D::Set_Force (float force_x, float force_y)
{
	force.x = force_x;
	force.y = force_y;
}


// changes the force vector based on the vector passed
void Force2D::Set_Force (const Vector2D &F)
{
	force.x = F.x;
	force.y = F.y;
}


// changes the position vector based on the components passed
void Force2D::Set_Position (float position_x, float position_y)
{
	position.x = position_x;
	position.y = position_y;
}


// changes the position vector based on the vector passed
void Force2D::Set_Position (const Vector2D &P)
{
	position.x = P.x;
	position.y = P.y;
}


// changes the ID of this force
void Force2D::Set_ID (ID_TAG id_system)
{
	id = id_system;
}


// returns this force in the global coordinate system -- must pass the
// sine and cosine of the body's orientation and the position of the center of mass
Force2D Force2D::To_Global (float sine, float cosine, const Vector2D &CM) const
{
	// global force that will be returned
	Force2D global_force (force, position, GLOBAL);

	// check for the current coordinate system of the force
	if (id == LOCAL)
	{
		// force is in the local coordinate system

		global_force.force = force.Rotate (sine, cosine);
		global_force.position = position.Rotate (sine, cosine) + CM;
	}
	else if (id == BODY)
	{
		// force is in the body coordinate system

		global_force.position = position.Rotate (sine, cosine) + CM;
	}

	// return the global force
	return (global_force);
}


// returns the linear force exerted on a rigid body by the force
Vector2D Force2D::Return_Linear_Force ()
{
	return (force);
}


// returns the torque exerted on a rigid body by the force
float Force2D::Return_Torque (const Vector2D &CM)
{
	return ((position - CM) ^ force);
}


// prints the properties of the force
void Force2D::Force_Print (const char* name) const
{
	cout << "---------------------------------" << endl;

	cout << "Force2D : " << name << endl;

	force.Vector_Print    ("force   ");
	position.Vector_Print ("position");

	switch (id)
	{
		case LOCAL:			cout << "LOCAL" << endl;
							break;

		case BODY:			cout << "BODY" << endl;
							break;

		case GLOBAL:		cout << "GLOBAL" << endl;
							break;

		default:			break;
	}

	cout << "---------------------------------" << endl;
}




