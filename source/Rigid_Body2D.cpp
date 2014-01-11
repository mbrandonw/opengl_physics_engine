/* ---------------------------------------------------------------------------
 *
 *		Rigid_Body2D class - Michael Brandon Williams
 *
 *		Rigid_Body2D.h
 *
 * ---------------------------------------------------------------------------
 */


#include "Rigid_Body2D.h"


// default constructor
Rigid_Body2D::Rigid_Body2D ()
{
	// position of the object's center of mass
	position = Vector2D (0.0f, 0.0f);

	// orientation of the object
	orientation = 0.0f;

	// sine and cosine of the object's orientation
	sine = 0.0f;
	cosine = 1.0f;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// angular velocity of the object
	angular_velocity = 0.0f;

	// angular acceleration of the object
	angular_acceleration = 0.0f;

	// mass of the object
	mass = 0.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_RIGID_BODY;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = RIGID_BODY_CAN_COLLIDE;

	// numerical value of the bodies density (constant)
	density = 0.0f;

	// surface area of the object
	surface_area = 0.0f;

	// moment of inertia about the origin of the object
	moment_of_inertia = 0.0f;

	// total torque acting on the object
	torque = 0.0f;

	// body constants
	linear_damping = 0.0f;
	angular_damping = 0.0f;
	restitution = 1.0f;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = Vector2D (0.0f, 0.0f);
	bottom_right_box = Vector2D (0.0f, 0.0f);
}


// constructor for when you know the density of the body
Rigid_Body2D::Rigid_Body2D (float p)
{
	// position of the object's center of mass
	position = Vector2D (0.0f, 0.0f);

	// orientation of the object
	orientation = 0.0f;

	// sine and cosine of the object's orientation
	sine = 0.0f;
	cosine = 1.0f;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// angular velocity of the object
	angular_velocity = 0.0f;

	// angular acceleration of the object
	angular_acceleration = 0.0f;

	// mass of the object
	mass = 0.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_RIGID_BODY;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = RIGID_BODY_CAN_COLLIDE;

	// numerical value of the bodies density (constant)
	density = p;

	// surface area of the object
	surface_area = 0.0f;

	// moment of inertia about the origin of the object
	moment_of_inertia = 0.0f;

	// total torque acting on the object
	torque = 0.0f;

	// body constants
	linear_damping = 0.0f;
	angular_damping = 0.0f;
	restitution = 1.0f;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = Vector2D (0.0f, 0.0f);
	bottom_right_box = Vector2D (0.0f, 0.0f);
}


// constructor for when you know the starting position of the body's center of mass
Rigid_Body2D::Rigid_Body2D (float center_x, float center_y)
{
	// position of the object's center of mass
	position = Vector2D (center_x, center_y);

	// orientation of the object
	orientation = 0.0f;

	// sine and cosine of the object's orientation
	sine = 0.0f;
	cosine = 1.0f;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// angular velocity of the object
	angular_velocity = 0.0f;

	// angular acceleration of the object
	angular_acceleration = 0.0f;

	// mass of the object
	mass = 0.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_RIGID_BODY;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = RIGID_BODY_CAN_COLLIDE;

	// numerical value of the bodies density (constant)
	density = 0.0f;

	// surface area of the object
	surface_area = 0.0f;

	// moment of inertia about the origin of the object
	moment_of_inertia = 0.0f;

	// total torque acting on the object
	torque = 0.0f;

	// body constants
	linear_damping = 0.0f;
	angular_damping = 0.0f;
	restitution = 1.0f;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = Vector2D (0.0f, 0.0f);
	bottom_right_box = Vector2D (0.0f, 0.0f);
}


// constructor for when you know the starting position of the body's center of mass
Rigid_Body2D::Rigid_Body2D (const Vector2D &center)
{
	// position of the object's center of mass
	position = center;

	// orientation of the object
	orientation = 0.0f;

	// sine and cosine of the object's orientation
	sine = 0.0f;
	cosine = 1.0f;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// angular velocity of the object
	angular_velocity = 0.0f;

	// angular acceleration of the object
	angular_acceleration = 0.0f;

	// mass of the object
	mass = 0.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_RIGID_BODY;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = RIGID_BODY_CAN_COLLIDE;

	// numerical value of the bodies density (constant)
	density = 0.0f;

	// surface area of the object
	surface_area = 0.0f;

	// moment of inertia about the origin of the object
	moment_of_inertia = 0.0f;

	// total torque acting on the object
	torque = 0.0f;

	// body constants
	linear_damping = 0.0f;
	angular_damping = 0.0f;
	restitution = 1.0f;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = Vector2D (0.0f, 0.0f);
	bottom_right_box = Vector2D (0.0f, 0.0f);
}


// constructor for when you know the starting position of the body's center of mass
// as well as the density of the body
Rigid_Body2D::Rigid_Body2D (float center_x, float center_y, float p)
{
	// position of the object's center of mass
	position = Vector2D (center_x, center_y);

	// orientation of the object
	orientation = 0.0f;

	// sine and cosine of the object's orientation
	sine = 0.0f;
	cosine = 1.0f;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// angular velocity of the object
	angular_velocity = 0.0f;

	// angular acceleration of the object
	angular_acceleration = 0.0f;

	// mass of the object
	mass = 0.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_RIGID_BODY;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = RIGID_BODY_CAN_COLLIDE;

	// numerical value of the bodies density (constant)
	density = p;

	// surface area of the object
	surface_area = 0.0f;

	// moment of inertia about the origin of the object
	moment_of_inertia = 0.0f;

	// total torque acting on the object
	torque = 0.0f;

	// body constants
	linear_damping = 0.0f;
	angular_damping = 0.0f;
	restitution = 1.0f;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = Vector2D (0.0f, 0.0f);
	bottom_right_box = Vector2D (0.0f, 0.0f);
}


// constructor for when you know the starting position of the body's center of mass
// as well as the density of the body
Rigid_Body2D::Rigid_Body2D (const Vector2D &center, float p)
{
	// position of the object's center of mass
	position = center;

	// orientation of the object
	orientation = 0.0f;

	// sine and cosine of the object's orientation
	sine = 0.0f;
	cosine = 1.0f;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// angular velocity of the object
	angular_velocity = 0.0f;

	// angular acceleration of the object
	angular_acceleration = 0.0f;

	// mass of the object
	mass = 0.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_RIGID_BODY;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = RIGID_BODY_CAN_COLLIDE;

	// numerical value of the bodies density (constant)
	density = p;

	// surface area of the object
	surface_area = 0.0f;

	// moment of inertia about the origin of the object
	moment_of_inertia = 0.0f;

	// total torque acting on the object
	torque = 0.0f;

	// body constants
	linear_damping = 0.0f;
	angular_damping = 0.0f;
	restitution = 1.0f;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = Vector2D (0.0f, 0.0f);
	bottom_right_box = Vector2D (0.0f, 0.0f);
}


// constructor for when you know the constants of the body
Rigid_Body2D::Rigid_Body2D (float p, float linear_damping, float angular_damping, float restitution)
{
	// position of the object's center of mass
	position = Vector2D (0.0f, 0.0f);

	// orientation of the object
	orientation = 0.0f;

	// sine and cosine of the object's orientation
	sine = 0.0f;
	cosine = 1.0f;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// angular velocity of the object
	angular_velocity = 0.0f;

	// angular acceleration of the object
	angular_acceleration = 0.0f;

	// mass of the object
	mass = 0.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_RIGID_BODY;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = RIGID_BODY_CAN_COLLIDE;

	// numerical value of the bodies density (constant)
	density = p;

	// surface area of the object
	surface_area = 0.0f;

	// moment of inertia about the origin of the object
	moment_of_inertia = 0.0f;

	// total torque acting on the object
	torque = 0.0f;

	// body constants
	this->linear_damping = linear_damping;
	this->angular_damping = angular_damping;
	this->restitution = restitution;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = Vector2D (0.0f, 0.0f);
	bottom_right_box = Vector2D (0.0f, 0.0f);
}


// constructor for when you know everything about the body
Rigid_Body2D::Rigid_Body2D (float center_x, float center_y, float p, float linear_damping, float angular_damping, float restitution)
{
	// position of the object's center of mass
	position = Vector2D (center_x, center_y);

	// orientation of the object
	orientation = 0.0f;

	// sine and cosine of the object's orientation
	sine = 0.0f;
	cosine = 1.0f;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// angular velocity of the object
	angular_velocity = 0.0f;

	// angular acceleration of the object
	angular_acceleration = 0.0f;

	// mass of the object
	mass = 0.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_RIGID_BODY;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = RIGID_BODY_CAN_COLLIDE;

	// numerical value of the bodies density (constant)
	density = p;

	// surface area of the object
	surface_area = 0.0f;

	// moment of inertia about the origin of the object
	moment_of_inertia = 0.0f;

	// total torque acting on the object
	torque = 0.0f;

	// body constants
	this->linear_damping = linear_damping;
	this->angular_damping = angular_damping;
	this->restitution = restitution;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = Vector2D (0.0f, 0.0f);
	bottom_right_box = Vector2D (0.0f, 0.0f);
}


// constructor for when you know everything about the body
Rigid_Body2D::Rigid_Body2D (const Vector2D &center, float p, float linear_damping, float angular_damping, float restitution)
{
	// position of the object's center of mass
	position = center;

	// orientation of the object
	orientation = 0.0f;

	// sine and cosine of the object's orientation
	sine = 0.0f;
	cosine = 1.0f;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// angular velocity of the object
	angular_velocity = 0.0f;

	// angular acceleration of the object
	angular_acceleration = 0.0f;

	// mass of the object
	mass = 0.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_RIGID_BODY;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = RIGID_BODY_CAN_COLLIDE;

	// numerical value of the bodies density (constant)
	density = p;

	// surface area of the object
	surface_area = 0.0f;

	// moment of inertia about the origin of the object
	moment_of_inertia = 0.0f;

	// total torque acting on the object
	torque = 0.0f;

	// body constants
	this->linear_damping = linear_damping;
	this->angular_damping = angular_damping;
	this->restitution = restitution;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = Vector2D (0.0f, 0.0f);
	bottom_right_box = Vector2D (0.0f, 0.0f);
}


// copy constructor
Rigid_Body2D::Rigid_Body2D (const Rigid_Body2D &R)
{
	*this = R;
}


// destructor
Rigid_Body2D::~Rigid_Body2D ()
{
}


// assignment
const Rigid_Body2D& Rigid_Body2D::operator = (const Rigid_Body2D &R)
{
	// position of the object's center of mass
	position = R.position;

	// orientation of the object
	orientation = R.orientation;

	// sine and cosine of the object's orientation
	sine = R.sine;
	cosine = R.cosine;

	// velocity of the center of mass
	velocity = R.velocity;

	// acceleration of the center of mass
	acceleration = R.acceleration;

	// angular velocity of the object
	angular_velocity = R.angular_velocity;

	// angular acceleration of the object
	angular_acceleration = R.angular_acceleration;

	// mass of the object
	mass = R.mass;

	// list of forces acting on the particle
	force_list = R.force_list;

	// total force acting on the center of mass
	center_mass_force = R.center_mass_force;

	// determines whether the particle is kinetic or static
	state = R.state;

	// determines if the rigid body should be checked for collisions with other objects
	collision_state = R.collision_state;

	// numerical value of the bodies density (constant)
	density = R.density;

	// surface area of the object
	surface_area = R.surface_area;

	// moment of inertia about the origin of the object
	moment_of_inertia = R.moment_of_inertia;

	// total torque acting on the object
	torque = R.torque;

	// position of vertices in the global coordinate system
	global_vertices = R.global_vertices;

	// position of vertices in the body's local coordinate system
	local_vertices = R.local_vertices;

	// position of vertices in the body's local coordinate system with the center of mass at the origin
	local_vertices_centered = R.local_vertices_centered;

	// constants of the body
	restitution = R.restitution;
	linear_damping = R.linear_damping;
	angular_damping = R.angular_damping;

	// top-left and bottom-right corners of the bounding box in the body coordinate system
	top_left_box = R.top_left_box;
	bottom_right_box = R.bottom_right_box;

	return (*this);
}


// returns the state of the rigid body
RIGID_BODY_TYPE Rigid_Body2D::Return_State () const
{
	return (state);
}


// reset the state of the rigid body
void Rigid_Body2D::Reset_State (enum RIGID_BODY_TYPE new_state)
{
	state = new_state;
}


// returns the collision state of the rigid body
RIGID_BODY_COLLISION_TYPE Rigid_Body2D::Return_Collision_State ()
{
	return (collision_state);
}


// resets the state of the rigid body
void Rigid_Body2D::Reset_Collision_State (enum RIGID_BODY_COLLISION_TYPE new_state)
{
	collision_state = new_state;
}


// add force to act on the body
void Rigid_Body2D::Add_Force (const Force2D &F)
{
	force_list.Push (F);
}


// add force to act on the body
void Rigid_Body2D::Add_Force (float force_x, float force_y, float position_x, float position_y, ID_TAG system)
{
	force_list.Push (Force2D (Vector2D (force_x, force_y), Vector2D (position_x, position_y), system));
}


// add force to act on the body
void Rigid_Body2D::Add_Force (const Vector2D &F, const Vector2D &P, ID_TAG system)
{
	force_list.Push (Force2D (F, P, system));
}


// resets the nth force
void Rigid_Body2D::Reset_Force (int n, const Force2D &F)
{
	force_list[n] = F;
}


// resets the nth force
void Rigid_Body2D::Reset_Force_Vector (int n, const Vector2D &F)
{
	force_list[n].Set_Force (F);
}


// resets the nth force
void Rigid_Body2D::Reset_Force_Vector (int n, float force_x, float force_y)
{
	force_list[n].Set_Force (force_x, force_y);
}


// resets the nth force
void Rigid_Body2D::Reset_Force_Position (int n, const Vector2D &P)
{
	force_list[n].Set_Position (P);
}


// resets the nth force
void Rigid_Body2D::Reset_Force_Position (int n, float position_x, float position_y)
{
	force_list[n].Set_Position (position_x, position_y);
}


// resets the nth force
void Rigid_Body2D::Reset_Force_ID (int n, ID_TAG system)
{
	force_list[n].Set_ID (system);
}


// adds a vertex before the nth
void Rigid_Body2D::Add_Vertex_Before (int n, float x, float y)
{
	local_vertices.Insert_Before (n, Vector2D (x, y));
	this->Calculate_Physical_Properties ();
}


// adds a vertex before the nth
void Rigid_Body2D::Add_Vertex_Before (int n, const Vector2D &V)
{
	local_vertices.Insert_Before (n, V);
	this->Calculate_Physical_Properties ();
}


// adds a vertex after the nth
void Rigid_Body2D::Add_Vertex_After (int n, float x, float y)
{
	local_vertices.Insert_After (n, Vector2D (x, y));
	this->Calculate_Physical_Properties ();
}


// adds a vertex after the nth
void Rigid_Body2D::Add_Vertex_After (int n, const Vector2D &V)
{
	local_vertices.Insert_After (n, V);
	this->Calculate_Physical_Properties ();
}


// adds a vertex to the end
void Rigid_Body2D::Push_Vertex (float x, float y)
{
	local_vertices.Push (Vector2D (x, y));
	this->Calculate_Physical_Properties ();
}


// adds a vertex to the end
void Rigid_Body2D::Push_Vertex (const Vector2D &V)
{
	local_vertices.Push (V);
	this->Calculate_Physical_Properties ();
}


// removes the vertices "n" through "n + num"
void Rigid_Body2D::Remove_Vertices (int n, int num)
{
	local_vertices.Splice (n, num);
	this->Calculate_Physical_Properties ();
}


// sets the nth vertex of the body
void Rigid_Body2D::Reset_Vertex (int n, float x, float y)
{
	local_vertices[n] = Vector2D (x, y);
	this->Calculate_Physical_Properties ();
}


// sets the nth vertex of the body
void Rigid_Body2D::Reset_Vertex (int n, const Vector2D &V)
{
	local_vertices[n] = V;
	this->Calculate_Physical_Properties ();
}


// returns the position of the nth vertex in the global coordinate system
Vector2D Rigid_Body2D::Return_Global_Vertex_Position (int n)
{
	return (local_vertices_centered[n].Rotate (sine, cosine) + position);
}


// returns the position of the nth vertex in the body coordinate system
Vector2D Rigid_Body2D::Return_Body_Vertex_Position (int n)
{
	return (local_vertices_centered[n].Rotate (sine, cosine));
}


// returns the position of the point (x,y) in the global coordinate system
Vector2D Rigid_Body2D::Return_Global_Point_Position (float x, float y)
{
	return (Vector2D (x, y).Rotate (sine, cosine) + position);
}


// returns the position of the point (x,y) in the globa coordinate system
Vector2D Rigid_Body2D::Return_Global_Point_Position (const Vector2D &V)
{
	return (V.Rotate (sine, cosine) + position);
}


// returns the position of the point (x,y) in the body coordinate system
Vector2D Rigid_Body2D::Return_Body_Point_Position (float x, float y)
{
	return (Vector2D (x, y).Rotate (sine, cosine));
}


// returns the position of the point (x,y) in the body coordinate system
Vector2D Rigid_Body2D::Return_Body_Point_Position (const Vector2D &V)
{
	return (V.Rotate (sine, cosine));
}


// returns the velocity of the nth vertex
Vector2D Rigid_Body2D::Return_Vertex_Velocity (int n)
{
	return (local_vertices_centered[n].Rotate (sine, cosine).Return_Perpendicular () * (angular_velocity) + velocity);
}


// returns the velocity of a point in the body
Vector2D Rigid_Body2D::Return_Point_Velocity (float x, float y)
{
	return (Vector2D (x, y).Rotate (sine, cosine).Return_Perpendicular () * (angular_velocity) + velocity);
}


// returns the velocity of a point in the body
Vector2D Rigid_Body2D::Return_Point_Velocity (const Vector2D &P)
{
	return (P.Rotate (sine, cosine).Return_Perpendicular () * (angular_velocity) + velocity);
}


// changes the density of the body
void Rigid_Body2D::Reset_Density (float p)
{
	density = p;
	this->Calculate_Physical_Properties ();
}


// returns the position of the center of mass
Vector2D Rigid_Body2D::Return_Position ()
{
	return (position);
}


// returns the velocity of the center of mass
Vector2D Rigid_Body2D::Return_Velocity ()
{
	return (velocity);
}


// returns the orientation of the body
float Rigid_Body2D::Return_Orientation ()
{
	return (orientation);
}


// returns the angular velocity of the center of mass
float Rigid_Body2D::Return_Angular_Velocity ()
{
	return (angular_velocity);
}


// resets the position of the object
void Rigid_Body2D::Reset_Position (float x, float y)
{
	position.x = x;
	position.y = y;
	this->Calculate_Global_Vertices ();
	this->Calculate_Bounding_Box ();
}


// resets the position of the object
void Rigid_Body2D::Reset_Position (const Vector2D &pos)
{
	position = pos;
	this->Calculate_Global_Vertices ();
	this->Calculate_Bounding_Box ();
}


// resets the orientation of the object
void Rigid_Body2D::Reset_Orientation (float rotation)
{
	orientation = rotation;
	this->Update_Trig ();
	this->Calculate_Global_Vertices ();
	this->Calculate_Bounding_Box ();
}


// resets the velocity of the center of mass
void Rigid_Body2D::Reset_Velocity (float vel_x, float vel_y)
{
	velocity.x = vel_x;
	velocity.y = vel_y;
}


// resets the velocity of the center of mass
void Rigid_Body2D::Reset_Velocity (const Vector2D &vel)
{
	velocity = vel;
}


// resets the angular velocity of the object
void Rigid_Body2D::Reset_Angular_Velocity (float omega)
{
	angular_velocity = omega;
}


// reset the constants of the body
void Rigid_Body2D::Reset_Linear_Damping (float ld)
{
	linear_damping = ld;
}


// reset the constants of the body
void Rigid_Body2D::Reset_Angular_Damping (float ad)
{
	angular_damping = ad;
}


// reset the constants of the body
void Rigid_Body2D::Reset_Restitution (float r)
{
	restitution = r;
}


// updates the sine and cosine of the orientation
void Rigid_Body2D::Update_Trig ()
{
	sine = sinf (orientation);
	cosine = cosf (orientation);
}


// prints the properties of the rigid body
void Rigid_Body2D::Rigid_Body2D_Print (const char* name) const
{
	cout << "---------------------------------" << endl;

	cout << "Rigid Body 2D : " << name << endl;

	position.Vector_Print     ("position    ");
	velocity.Vector_Print     ("velocity    ");
	acceleration.Vector_Print ("acceleration");

	cout << "orientation           = " << orientation << endl;
	cout << "angular velocity      = " << angular_velocity << endl;
	cout << "angular acceleration  = " << angular_acceleration << endl;

	cout << "density               = " << density << endl;
	cout << "surface area          = " << surface_area << endl;
	cout << "mass                  = " << mass << endl;
	cout << "moment of inertia     = " << moment_of_inertia << endl;
	cout << "torque                = " << torque << endl;
	center_mass_force.Vector_Print ("Center Force");

	cout << "---------------------------------" << endl;
}


// draws the bounding box of the rigid body
void Rigid_Body2D::Draw_Bounding_Box ()
{
	glColor3f (0.5f, 0.5f, 0.5f);

	glBegin (GL_LINES);
	{
		glVertex3f (top_left_box.x,     top_left_box.y, 0.0f);
		glVertex3f (top_left_box.x,     bottom_right_box.y, 0.0f);

		glVertex3f (top_left_box.x,     bottom_right_box.y, 0.0f);
		glVertex3f (bottom_right_box.x, bottom_right_box.y, 0.0f);

		glVertex3f (bottom_right_box.x, bottom_right_box.y, 0.0f);
		glVertex3f (bottom_right_box.x, top_left_box.y, 0.0f);

		glVertex3f (bottom_right_box.x, top_left_box.y, 0.0f);
		glVertex3f (top_left_box.x,     top_left_box.y, 0.0f);
	}
	glEnd ();
}


// draws the rigid body
void Rigid_Body2D::Draw_Rigid_Body ()
{
	// number of vertices in the rigid body
	int num_vertices = global_vertices.Length ();

	// index of the next vertex
	int k;

	glColor3f (0.0f, 0.0f, 1.0f);

	// start Open GL to draw lines
	glBegin (GL_LINES);
	{
		// loop through the vertices and connect them with lines
		for (int j = 0; j < num_vertices; j++)
		{
			// index of the next vertex
			k = (j + 1) % num_vertices;

			// connect the vertices
			glVertex3f (global_vertices[j].x, global_vertices[j].y, 0.0f);
			glVertex3f (global_vertices[k].x, global_vertices[k].y, 0.0f);
		}
	}
	glEnd ();

	// draw a small square at the center of mass
	glBegin (GL_QUADS);
	{
		glVertex3f (position.x - 0.1f, position.y - 0.1f, 0.0f);
		glVertex3f (position.x + 0.1f, position.y - 0.1f, 0.0f);
		glVertex3f (position.x + 0.1f, position.y + 0.1f, 0.0f);
		glVertex3f (position.x - 0.1f, position.y + 0.1f, 0.0f);
	}
	glEnd ();
}


// draws the forces acting on the body
void Rigid_Body2D::Draw_Forces ()
{
	// number of forces acting on the body
	int num_forces = force_list.Length ();

	// force in global coordinates
	Force2D global_force;

	// loop through the forces and draw them
	for (int j = 0; j < num_forces; j++)
	{
		// set the color depending on what type of force
		if      (force_list[j].id == LOCAL)			glColor3f (1.0f, 0.0f, 0.0f);
		else if (force_list[j].id == BODY)			glColor3f (0.0f, 1.0f, 0.0f);
		else if (force_list[j].id == GLOBAL)		glColor3f (1.0f, 1.0f, 0.0f);

		// get the force in global coordinates
		global_force = force_list[j].To_Global (sine, cosine, position);

		// draw the force
		glBegin (GL_LINES);
		{
			glVertex3f (global_force.position.x,  global_force.position.y, 0.0f);
			glVertex3f (global_force.position.x + global_force.force.x,
						global_force.position.y + global_force.force.y, 0.0f);
		}
		glEnd ();
	}
}


// integrates object over a time step
void Rigid_Body2D::Euler_Integrate (float delta_t)
{
	// check what properties should be update
	if (state == KINETIC_RIGID_BODY)
	{
		// change velocity due to acceleration
		velocity += acceleration * delta_t;

		// change position due to velocity
		position += velocity * delta_t;

		// change angular velocity due to angular acceleration
		angular_velocity += angular_acceleration * delta_t;

		// change orientation due to angular velocity
		orientation += angular_velocity * delta_t;

		// update the sine and cosine of the body
		this->Update_Trig ();

		// update the array that holds the global vertices of the body
		this->Calculate_Global_Vertices ();

		// calculate the bounding box of the body
		this->Calculate_Bounding_Box ();
	}
	else if (state == KINETIC_STATIC_RIGID_BODY)
	{
		// change angular velocity due to angular acceleration
		angular_velocity += angular_acceleration * delta_t;

		// changes orientation due to angular velocity
		orientation += angular_velocity * delta_t;

		// no linear velocity
		velocity.x = velocity.y = 0.0f;

		// update the sine and cosine of the body
		this->Update_Trig ();

		// update the array that holds the global vertices of the body
		this->Calculate_Global_Vertices ();

		// calculate the bounding box of the body
		this->Calculate_Bounding_Box ();
	}
	else
	{
		// no linear or angular velocity
		velocity.x = velocity.y = 0.0f;
		angular_velocity = 0.0f;
	}
}


void Rigid_Body2D::Calculate_Physical_Properties ()
{
	// update the physical properties of the object only if there are enough vertices
	if (local_vertices.Length () >= 3)
	{
		// calculate the surface area of the body
		this->Calculate_Area ();

		// calculate the mass of the body
		this->Calculate_Mass ();

		// calculate the position of the vertices when the center of mass is at the origin
		this->Shift_Vertices ();

		// calculate the moment of inertia of the body
		this->Calculate_Inertia ();

		// get the global position of all vertices
		this->Calculate_Global_Vertices ();

		// get the bounding box of the rigid body
		this->Calculate_Bounding_Box ();
	}
	else
	{
		// not enough vertices for it to be a rigid body
		surface_area = 0.0f;
		mass = 0.0f;
		moment_of_inertia = 0.0f;
	}
}


// calculates the area of the rigid body
void Rigid_Body2D::Calculate_Area ()
{
	// temporary variable used for indexing the vertices array
	int k = 0;

	// reset the surface area of the object to zero
	surface_area = 0.0f;

	// number of vertices
	int num_vertices = local_vertices.Length ();

	// loop through the vertices array to calculate the area
	for (int j = 0; j < num_vertices; j++)
	{
		// index of the next vertex in the vertices array
		k = (j + 1) % num_vertices;

		// summation to find the area of the body
		surface_area += (local_vertices[j].x * local_vertices[k].y) - 
						(local_vertices[k].x * local_vertices[j].y);
	}

	// last step in calculating the area
	surface_area *= 0.5f * (fabsf (surface_area) / surface_area);
}


// returns the vector point to the center of mass in the local coordinate system when the
// origin is not at the center of mass (local_vertices array)
Vector2D Rigid_Body2D::Calculate_Local_Center_Mass ()
{
	// position of the center of mass
	Vector2D center (0.0f, 0.0f);

	// terms in the center of mass equation
	float term1, term2, term3;

	// temporary variable used for indexing the vertices array
	int k = 0;

	// number of vertices
	int num_vertices = local_vertices.Length ();

	// loop through the vertices array to calculate the position of the center of mass
	for (int j = 0; j < num_vertices; j++)
	{
		// index of the next vertex in the array
		k = (j + 1) % num_vertices;

		// calculations for the x-position of the center of mass

		// calculate the terms of the center of mass equation
		term1 = local_vertices[j].x * local_vertices[k].x;
		term2 = local_vertices[k].x * local_vertices[k].x;
		term3 = local_vertices[j].x * local_vertices[j].x;

		// summation to find the x-position of the center of mass
		center.x += (1.0f / 3.0f) * (term1 + term2 + term3) * (local_vertices[k].y - local_vertices[j].y);

		// calculations for the y-position of the center of mass

		// calculate the terms of the center of mass equation
		term1 = local_vertices[j].y * local_vertices[k].y;
		term2 = local_vertices[k].y * local_vertices[k].y;
		term3 = local_vertices[j].y * local_vertices[j].y;

		// summation to find the y-position of the center of mass
		center.y += (1.0f / 3.0f) * (term1 + term2 + term3) * (local_vertices[k].x - local_vertices[j].x);
	}

	// last step in calculating the center of mass
	center.x /=  2.0f * surface_area;
	center.y /= -2.0f * surface_area;

	// return the center of mass vector
	return (center);
}


// calculates the mass of the rigid body
void Rigid_Body2D::Calculate_Mass ()
{
	mass = surface_area * density;
}


// calculates the moment of inertia of the rigid body
void Rigid_Body2D::Calculate_Inertia ()
{
	// moment of inertia about the x- and y-axis
	float inertia_x = 0.0f, inertia_y = 0.0f;

	// terms in the moment of inertia equation
	float term1, term2, term3, term4;

	// temporary variable used for indexing the vertices array
	int k = 0;

	// number of vertices
	int num_vertices = local_vertices_centered.Length ();

	// loop through the vertices array to calculate the moment of inertia about the x- and y-axis
	for (int j = 0; j < num_vertices; j++)
	{
		// index of the next vertex in the vertices array
		k = (j + 1) % num_vertices;

		// calculate the moment of inertia about the x-axis

		// calculate the terms of the moment of inertia equation
		term1 = local_vertices_centered[k].y * local_vertices_centered[k].y * local_vertices_centered[k].y;
		term2 = local_vertices_centered[j].y * local_vertices_centered[k].y * local_vertices_centered[k].y;
		term3 = local_vertices_centered[j].y * local_vertices_centered[j].y * local_vertices_centered[k].y;
		term4 = local_vertices_centered[j].y * local_vertices_centered[j].y * local_vertices_centered[j].y;

		// summation to find the moment of inertia about the x-axis
		inertia_x += (1.0f / 4.0f) * (term1 + term2 + term3 + term4) * (local_vertices_centered[k].x - local_vertices_centered[j].x);

		// calculate the moment of inertia about the y-axis

		// calculate the terms of the moment of inertia equation
		term1 = local_vertices_centered[k].x * local_vertices_centered[k].x * local_vertices_centered[k].x;
		term2 = local_vertices_centered[j].x * local_vertices_centered[k].x * local_vertices_centered[k].x;
		term3 = local_vertices_centered[j].x * local_vertices_centered[j].x * local_vertices_centered[k].x;
		term4 = local_vertices_centered[j].x * local_vertices_centered[j].x * local_vertices_centered[j].x;

		// summation to find the moment of inertia about the y-axis
		inertia_y += (1.0f / 4.0f) * (term1 + term2 + term3 + term4) * (local_vertices_centered[k].y - local_vertices_centered[j].y);
	}

	// last step in calculating the moments of inertia about the x- and y-axis
	inertia_x *= -density / 3.0f;
	inertia_y *=  density / 3.0f;

	// calculate the moment of inertia about the origin
	moment_of_inertia = fabsf (inertia_x + inertia_y);
}


// calculates the position of the local vertices so that the center of mass is at the origin
void Rigid_Body2D::Shift_Vertices ()
{
	// center of mass vector
	Vector2D center (this->Calculate_Local_Center_Mass ());

	// number of vertices
	int num_vertices = local_vertices.Length ();

	// reset the array holding the vertices with the center of mass at the origin
	local_vertices_centered = Array<Vector2D> (num_vertices);

	// loop through the vertices and shift them so that the center of mass is at the origin
	for (int j = 0; j < num_vertices; j++)
	{
		local_vertices_centered[j] = local_vertices[j] - center;
	}
}


// calculates the position of the global vertices
void Rigid_Body2D::Calculate_Global_Vertices ()
{
	// number of vertices in the rigid body
	int num = local_vertices_centered.Length ();

	// loop through the vertices and calculate their position in the global coordinate system
	for (int j = 0; j < num; j++)
	{
		// rotate and translate to get into the global coordinate system
		global_vertices[j] = local_vertices_centered[j].Rotate (sine, cosine) + position;
	}
}


// calculates the total force acting on the body
void Rigid_Body2D::Calculate_Forces ()
{
	// reset the vector that represents the total force acting on the center of mass
	//center_mass_force = Vector2D (0.0f, 0.0f);

	// reset the scalar that represents the total amount of torque acting on the body
	torque = 0.0f;

	// force in the global coordinate system
	Force2D global_force;

	// number of forces
	int num_forces = force_list.Length ();

	// loop through all of the forces acting on the body to calculate the total
	// linear force and torque on the body
	for (int j = 0; j < num_forces; j++)
	{
		// if the force is ever a zero vector then skip the calculations
		if (! force_list[j].Return_Force_Vector ().Zero_Vector ())
		{
			// force vector is not a zero vector

			// force in the global coordinate system
			global_force = force_list[j].To_Global (sine, cosine, position);

			// calculate the linear force exerted on the body
			center_mass_force += global_force.Return_Linear_Force ();

			// calculate the torque exerted on the body
			torque += global_force.Return_Torque (position);
		}
	}

	// calculate the damping of the body
	this->Calculate_Damping ();
}


// calculates the damping on the body
void Rigid_Body2D::Calculate_Damping ()
{
	// take away some force and torque due to damping
	center_mass_force += velocity * (-linear_damping);
	torque += angular_velocity * (-angular_damping);
}


// calculates the linear and rotational acceleration of the body
void Rigid_Body2D::Calculate_Acceleration ()
{
	// calculate the total force and torque acting on the body
	this->Calculate_Forces ();

	// calculate the linear and angular acceleration of the object
	acceleration = center_mass_force / mass;
	angular_acceleration = torque / moment_of_inertia;
}


// calculates the bounding box vertices in the global coordinate system
void Rigid_Body2D::Calculate_Bounding_Box ()
{
	// number of vertices in the body
	int num = local_vertices_centered.Length ();

	// arrays of the x- and y-position of the vertices
	Array<float> vertex_x (num);
	Array<float> vertex_y (num);

	// loop through the vertices and put their position in the arrays
	for (int j = 0; j < num; j++)
	{
		vertex_x[j] = global_vertices[j].x;
		vertex_y[j] = global_vertices[j].y;
	}

	// sort the arrays so we can find out which vertices are maximum and minimum
	vertex_x.Sort ();
	vertex_y.Sort ();

	// get the top-left and bottom-right coordinates of the box
	top_left_box.x = vertex_x[0];
	top_left_box.y = vertex_y[num-1];
	bottom_right_box.x = vertex_x[num-1];
	bottom_right_box.y = vertex_y[0];
}



