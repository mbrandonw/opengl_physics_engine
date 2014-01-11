/* ---------------------------------------------------------------------------
 *
 *		Particle class - Michael Brandon Williams
 *
 *		Particle.h
 *
 * ---------------------------------------------------------------------------
 */



#ifndef _PARTICLE_H
#define _PARTICLE_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#pragma comment (lib, "glaux.lib")

#include "Kinematic_Object2D.h"
#include "Array.h"
#include "Vector2D.h"


// type of particle: static or kinetic -- default "kinetic"
enum PARTICLE_TYPE
{
	STATIC_PARTICLE,
	KINETIC_PARTICLE,
};



// determines if we allow this particle to be checked for collisions with other objects
enum PARTICLE_COLLISION_TYPE
{
	PARTICLE_CAN_COLLIDE,
	PARTICLE_CANNOT_COLLIDE
};



class Particle
{
	friend class Physical_Environment2D;

	public:

		// defualt constructor
		Particle ();

		// constructors for when the starting position of the object's
		// center of mass is passed
		Particle (float center_x, float center_y);
		Particle (const Vector2D &center);

		// constructors for when the starting position of the object's 
		// center of mass is passed as well as the particle's mass
		Particle (float particle_mass);
		Particle (float center_x, float center_y, float particle_mass);
		Particle (const Vector2D &center, float particle_mass);

		// constructor for when you know everything about the particle
		Particle (float center_x, float center_y, float particle_mass, float damping, float restitution);
		Particle (const Vector2D &center, float particle_mass, float damping, float restitution);

		// copy constructor
		Particle (const Particle &P);

		// destructor
		virtual ~Particle ();

		// assignment
		const Particle& operator = (const Particle &P);

		// returns the state of the particle
		PARTICLE_TYPE Return_State () const;

		// sets what state the particle is in
		void Reset_State (enum PARTICLE_TYPE new_state);

		// returns the collision state of the particle
		PARTICLE_COLLISION_TYPE Return_Collision_State ();

		// sets the collision state of the particle
		void Reset_Collision_State (enum PARTICLE_COLLISION_TYPE new_state);

		// adds a force to act on the particle
		void Add_Force (const Vector2D &F);
		void Add_Force (float force_x, float force_y);

		// changes the nth force
		void Reset_Force_Vector (int n, const Vector2D &F);
		void Reset_Force_Vector (int n, float force_x, float force_y);

		// removes the nth force
		void Remove_Force (int n);

		// changes the mass of the particle
		void Reset_Mass (float m);

		// returns the position of the particle
		Vector2D Return_Position ();

		// returns the velocity of the particle
		Vector2D Return_Velocity ();

		// resets the position of the object
		void Reset_Position (float x, float y);
		void Reset_Position (const Vector2D &pos);

		// resets the velocity of the center of mass
		void Reset_Velocity (float vel_x, float vel_y);
		void Reset_Velocity (const Vector2D &vel);

		// prints the properties of the object
		void Particle_Print (const char* name) const;

		// draw the particle
		void Draw_Particle ();

		// draw the forces acting on the particle
		void Draw_Forces ();

	private:

		// integrates object over a time step
		void Euler_Integrate (float delta_t);

		// calculates the total linear force acting on the center of mass
		void Calculate_Forces ();

		// calculates the damping on the body
		void Calculate_Damping ();

		// calculates the total linear acceleration acting on the center of mass
		void Calculate_Acceleration ();



		// position of the object's center of mass
		Vector2D position;

		// velocity of the center of mass
		Vector2D velocity;

		// acceleration of the center of mass
		Vector2D acceleration;

		// mass of the object
		float mass;

		// constants of the particle
		float damping, restitution;

		// list of forces acting on the particle
		Array <Vector2D> force_list;

		// total force acting on the center of mass
		Vector2D center_mass_force;

		// determines whether the particle is kinetic or static
		PARTICLE_TYPE state;

		// determines if the particle should be checked for collisions with other objects
		PARTICLE_COLLISION_TYPE collision_state;
};

#endif

