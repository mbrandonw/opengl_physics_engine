/* ---------------------------------------------------------------------------
 *
 *		Rigid_Body2D class - Michael Brandon Williams
 *
 *		Rigid_Body2D.h
 *
 * ---------------------------------------------------------------------------
 */


#ifndef _RIGID_BODY2D_H
#define _RIGID_BODY2D_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

#include "NeHeGL.h"

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#pragma comment (lib, "glaux.lib")

#include <iostream.h>
#include <cmath>
#include <assert.h>

#include "Kinematic_Object2D.h"
#include "Particle.h"
#include "Vector2D.h"
#include "Matrix2x2.h"
#include "Force2D.h"
#include "Array.h"


// type of rigid body - default "kinetic"
enum RIGID_BODY_TYPE
{
	STATIC_RIGID_BODY,
	KINETIC_RIGID_BODY,
	KINETIC_STATIC_RIGID_BODY
};


// determines if we allow this rigid body to be checked for collisions with other objects
enum RIGID_BODY_COLLISION_TYPE
{
	RIGID_BODY_CAN_COLLIDE,
	RIGID_BODY_CANNOT_COLLIDE
};


// maybe calculate impulse methods


class Rigid_Body2D
{
	friend class Physical_Environment2D;

	public:

		// defualt constructor
		Rigid_Body2D ();

		// constructor for when you know the density of the body
		Rigid_Body2D (float p);

		// constructors for when the starting position of the object's
		// center of mass is passed
		Rigid_Body2D (float center_x, float center_y);
		Rigid_Body2D (const Vector2D &center);

		// constructors for when the starting position of the object's
		// center of mass is passed as well as the body's density
		Rigid_Body2D (float center_x, float center_y, float p);
		Rigid_Body2D (const Vector2D &center, float p);

		// constructor for when you know the constants of the body
		Rigid_Body2D (float p, float linear_damping, float angular_damping, float restitution);

		// constructor for when you know everything about the body
		Rigid_Body2D (float center_x, float center_y, float p, float linear_damping, float angular_damping, float restitution);
		Rigid_Body2D (const Vector2D &center, float p, float linear_damping, float angular_damping, float restitution);

		// copy constructor
		Rigid_Body2D (const Rigid_Body2D &R);

		// destructor
		virtual ~Rigid_Body2D ();

		// assignment
		const Rigid_Body2D& operator = (const Rigid_Body2D &R);

		// returns the state of the rigid body
		RIGID_BODY_TYPE Return_State () const;

		// resets the state of the rigid body
		void Reset_State (enum RIGID_BODY_TYPE new_state);

		// returns the collision state of the rigid body
		RIGID_BODY_COLLISION_TYPE Return_Collision_State ();

		// resets the state of the rigid body
		void Reset_Collision_State (enum RIGID_BODY_COLLISION_TYPE new_state);

		// add force to act on the body
		void Add_Force (const Force2D &F);
		void Add_Force (float force_x, float force_y, float position_x, float position_y, ID_TAG system);
		void Add_Force (const Vector2D &F, const Vector2D &P, ID_TAG system);

		// resets the nth force
		void Reset_Force (int n, const Force2D &F);
		void Reset_Force_Vector (int n, const Vector2D &F);
		void Reset_Force_Vector (int n, float force_x, float force_y);
		void Reset_Force_Position (int n, const Vector2D &P);
		void Reset_Force_Position (int n, float position_x, float position_y);
		void Reset_Force_ID (int n, ID_TAG system);

		// adds a vertex before the nth
		void Add_Vertex_Before (int n, float x, float y);
		void Add_Vertex_Before (int n, const Vector2D &V);

		// adds a vertex after the nth
		void Add_Vertex_After (int n, float x, float y);
		void Add_Vertex_After (int n, const Vector2D &V);

		// adds a vertex to the end
		void Push_Vertex (float x, float y);
		void Push_Vertex (const Vector2D &V);

		// removes vertices "n" through "n + num"
		void Remove_Vertices (int n, int num);

		// sets the nth vertex of the body
		void Reset_Vertex (int n, float x, float y);
		void Reset_Vertex (int n, const Vector2D &V);

		// returns the position of the nth vertex in the global coordinate system
		Vector2D Return_Global_Vertex_Position (int n);

		// returns the position of the nth vertex in the body coordinate system
		Vector2D Return_Body_Vertex_Position (int n);

		// returns the position of the point (x,y) in the global coordinate system
		Vector2D Return_Global_Point_Position (float x, float y);
		Vector2D Return_Global_Point_Position (const Vector2D &V);

		// returns the position of the point (x,y) in the body coordinate system
		Vector2D Return_Body_Point_Position (float x, float y);
		Vector2D Return_Body_Point_Position (const Vector2D &V);

		// returns the velocity of the nth vertex
		Vector2D Return_Vertex_Velocity (int n);

		// returns the velocity of a point in the body
		Vector2D Return_Point_Velocity (float x, float y);
		Vector2D Return_Point_Velocity (const Vector2D &P);

		// changes the density of the body
		void Reset_Density (float p);

		// returns the position of the center of mass
		Vector2D Return_Position ();

		// returns the velocity of the center of mass
		Vector2D Return_Velocity ();

		// returns the orientation of the body
		float Return_Orientation ();

		// returns the angular velocity of the center of mass
		float Return_Angular_Velocity ();

		// resets the position of the object
		void Reset_Position (float x, float y);
		void Reset_Position (const Vector2D &pos);

		// resets the orientation of the object
		void Reset_Orientation (float rotation);

		// resets the velocity of the center of mass
		void Reset_Velocity (float vel_x, float vel_y);
		void Reset_Velocity (const Vector2D &vel);

		// resets the angular velocity of the object
		void Reset_Angular_Velocity (float omega);

		// reset the constants of the body
		void Reset_Linear_Damping (float ld);
		void Reset_Angular_Damping (float ad);
		void Reset_Restitution (float r);

		// updates the sine and cosine of the orientation
		void Update_Trig ();

		// prints the properties of the rigid body
		void Rigid_Body2D_Print (const char* name) const;

		// draws the bounding box of the rigid body
		void Draw_Bounding_Box ();

		// draws the rigid body
		void Draw_Rigid_Body ();

		// draws the forces acting on the body
		void Draw_Forces ();

	//private:

		// MEMBER FUNCTIONS

		// integrates object over a time step
		void Euler_Integrate (float delta_t);

		// calculates the physical properties of the body (surface area, mass, center of mass, moment of inertia)
		void Calculate_Physical_Properties ();

		// individual functions for calculating the physical properties of the body
		void Calculate_Area ();
		Vector2D Calculate_Local_Center_Mass ();
		void Calculate_Mass ();
		void Calculate_Inertia ();

		// calculates the position of the local vertices so that the center
		// of mass is at the origin
		void Shift_Vertices ();

		// calculates the position of the global vertices
		void Calculate_Global_Vertices ();

		// calculates the total force acting on the body
		void Calculate_Forces ();

		// calculates the damping on the body
		void Calculate_Damping ();

		// calculates the linear and rotational acceleration of the body
		void Calculate_Acceleration ();

		// calculates the bounding box vertices in the global coordinate system
		void Calculate_Bounding_Box ();



		// DATA MEMBERS

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

		// mass of the object
		float mass;

		// list of forces acting on the particle
		Array <Force2D> force_list;

		// total force acting on the center of mass
		Vector2D center_mass_force;

		// determines whether the particle is kinetic or static
		RIGID_BODY_TYPE state;

		// determines if the rigid body should be checked for collisions with other objects
		RIGID_BODY_COLLISION_TYPE collision_state;

		// numerical value of the bodies density (constant)
		float density;

		// surface area of the object
		float surface_area;

		// moment of inertia about the origin of the object
		float moment_of_inertia;

		// total torque acting on the object
		float torque;

		// constants of the rigid body
		float linear_damping, angular_damping, restitution;

		// position of vertices in the global coordinate system
		Array<Vector2D> global_vertices;

		// position of vertices in the body's local coordinate system
		Array<Vector2D> local_vertices;

		// position of vertices in the body's local coordinate system with the center of mass at the origin
		Array<Vector2D> local_vertices_centered;

		// top-left and bottom-right corners of the bounding box in the body coordinate system
		Vector2D top_left_box, bottom_right_box;
};


#endif



