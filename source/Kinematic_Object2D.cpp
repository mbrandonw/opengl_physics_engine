/* ---------------------------------------------------------------------------
 *
 *		Kinematic_Object class - Michael Brandon Williams
 *
 *		Kinematic_Object.h
 *
 * ---------------------------------------------------------------------------
 */


#include "Kinematic_Object2D.h"


// constructor for when no information is passed
Kinematic_Object2D::Kinematic_Object2D ()
{
	// starting position of the center of mass
	position.x = 0.0f;
	position.y = 0.0f;

	// starting orientation of the object
	orientation = 0.0f;

	// sine and cosine of orientation
	sine = 0.0f;
	cosine = 1.0f;

	// starting velocity of object
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	// starting acceleration of object
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;

	// starting angular velocity of object
	angular_velocity = 0.0f;

	// starting angular acceleration of object
	angular_acceleration = 0.0f;
}


// constructor for when you pass the starting position of the object
Kinematic_Object2D::Kinematic_Object2D (const float center_x, const float center_y)
{
	// starting position of the center of mass
	position.x = center_x;
	position.y = center_y;

	// starting orientation of the object
	orientation = 0.0f;

	// sine and cosine of orientation
	sine = 0.0f;
	cosine = 1.0f;

	// starting velocity of object
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	// starting acceleration of object
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;

	// starting angular velocity of object
	angular_velocity = 0.0f;

	// starting angular acceleration of object
	angular_acceleration = 0.0f;
}


// constructor for when you pass the starting position of the object
Kinematic_Object2D::Kinematic_Object2D (const Vector2D &center)
{
	// starting position of the center of mass
	position = center;

	// starting orientation of the object
	orientation = 0.0f;

	// sine and cosine of orientation
	sine = 0.0f;
	cosine = 1.0f;

	// starting velocity of object
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	// starting acceleration of object
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;

	// starting angular velocity of object
	angular_velocity = 0.0f;

	// starting angular acceleration of object
	angular_acceleration = 0.0f;
}

// copy constructor
Kinematic_Object2D::Kinematic_Object2D (const Kinematic_Object2D &K)
{
	*this = K;
}


// destructor
Kinematic_Object2D::~Kinematic_Object2D ()
{

}


// assignment
const Kinematic_Object2D& Kinematic_Object2D::operator = (const Kinematic_Object2D &K)
{
// starting position of the center of mass
	position = K.position;

	// starting orientation of the object
	orientation = K.orientation;

	// sine and cosine of orientation
	sine = sinf (orientation);
	cosine = cosf (orientation);

	// starting velocity of object
	velocity = K.velocity;

	// starting acceleration of object
	acceleration = K.acceleration;

	// starting angular velocity of object
	angular_velocity = K.angular_velocity;

	// starting angular acceleration of object
	angular_acceleration = K.angular_acceleration;

	return (*this);
}


// returns the vector of the object's position
Vector2D Kinematic_Object2D::Return_Position () const
{
	return (Vector2D (position));
}


// returns the vector of the object's velocity
Vector2D Kinematic_Object2D::Return_Velocity () const
{
	return (Vector2D (velocity));
}


// returns the vector of the object's acceleration
Vector2D Kinematic_Object2D::Return_Acceleration () const
{
	return (Vector2D (acceleration));
}


// returns the object's orientation
float Kinematic_Object2D::Return_Orientation () const
{
	return (orientation);
}


// returns the object's angular velocity
float Kinematic_Object2D::Return_Angular_Velocity () const
{
	return (angular_velocity);
}


// returns the object's angular acceleration
float Kinematic_Object2D::Return_Angular_Acceleration () const
{
	return (angular_acceleration);
}


// changes the position of the object to (x, y)
void Kinematic_Object2D::Reset_Position (const float x, const float y)
{
	position.x = x;
	position.y = y;
}


void Kinematic_Object2D::Reset_Position (const Vector2D &pos)
{
	position = pos;
}


// changes the orientation of the object to "rotation"
void Kinematic_Object2D::Reset_Orientation (const float rotation)
{
	orientation = rotation;
	Update_Trig ();
}


// changes the velocity of the center of mass
void Kinematic_Object2D::Reset_Velocity (const float vel_x, const float vel_y)
{
	velocity.x = vel_x;
	velocity.y = vel_y;
}


void Kinematic_Object2D::Reset_Velocity (const Vector2D &vel)
{
	velocity = vel;
}


// changes the acceleration of the center of mass
void Kinematic_Object2D::Reset_Acceleration (const float acc_x, const float acc_y)
{
	acceleration.x = acc_x;
	acceleration.y = acc_y;
}


void Kinematic_Object2D::Reset_Acceleration (const Vector2D &acc)
{
	acceleration = acc;
}


// changes the angular velocity of the object
void Kinematic_Object2D::Reset_Angular_Velocity (const float omega)
{
	angular_velocity = omega;
}


// changes the angular acceleration of the object
void Kinematic_Object2D::Reset_Angular_Acceleration (const float alpha)
{
	angular_acceleration = alpha;
}


// updates the sine and cosine of the orientation
void Kinematic_Object2D::Update_Trig ()
{
	sine = sinf (orientation);
	cosine = cosf (orientation);
}


// prints out the properties of the object
void Kinematic_Object2D::Kinematic_Object2D_Print (const char* name) const
{
	cout << "---------------------------------" << endl;

	cout << "Kinematic Object 2D : " << name << endl;

	position.Vector_Print     ("position    ");
	velocity.Vector_Print     ("velocity    ");
	acceleration.Vector_Print ("acceleration");

	cout << "orientation           = " << orientation << endl;
	cout << "angular velocity      = " << angular_velocity << endl;
	cout << "angular acceleration  = " << angular_acceleration << endl;

	cout << "---------------------------------" << endl;
}


// integrates object over a time step
void Kinematic_Object2D::Euler_Integrate (float delta_t)
{
	// change velocity due to acceleration
	velocity += acceleration * delta_t;

	// change position due to velocity
	position += velocity * delta_t;

	// change angular velocity due to angular acceleration
	angular_velocity += angular_acceleration * delta_t;

	// change orientation due to angular velocity
	orientation += angular_velocity * delta_t;

	// update the sine and cosine of the object
	this->Update_Trig ();
}


