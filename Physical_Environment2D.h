/* ---------------------------------------------------------------------------
 *
 *		Physical_Environment2D class - Michael Brandon Williams
 *
 *		Physical_Environment2D.h
 *
 * ---------------------------------------------------------------------------
 */


#ifndef _PHYSICAL_ENVIRONMENT2D_H
#define _PHYSICAL_ENVIRONMENT2D_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

#include "NeHeGL.h"

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#pragma comment (lib, "glaux.lib")

#include <cmath>
#include <assert.h>

#include "Kinematic_Object2D.h"
#include "Particle.h"
#include "Rigid_Body2D.h"

#include "Vector2D.h"
#include "Matrix2x2.h"
#include "Array.h"

#include "Force2D.h"
#include "Spring2D.h"

#include "Math_Extras.h"



// two indexes of the vertices of a rigid body that make up an edge
typedef int edge[2];


// determines if the physical environment is paused or not
enum PHYSICAL_ENVIRONMENT_STATUS
{
	PLAYING,
	PAUSED
};




class Physical_Environment2D
{
	public:

		// default constructor
		Physical_Environment2D ();

		// constructor for when you know the outside force in the environment
		Physical_Environment2D (float force_x, float force_y);
		Physical_Environment2D (const Vector2D &F);

		// constructor for when you know the gravitational constant of the environment
		Physical_Environment2D (float gravitational_constant);

		// constructor for when you know the bounds of the environment
		Physical_Environment2D (float right, float left, float up, float down);

		// constructor for when you know everything about the environment
		Physical_Environment2D (float force_x, float force_y, float right, float left, float up, float down, float gravitational_constant);
		Physical_Environment2D (const Vector2D &F, float right, float left, float up, float down, float gravitational_constant);

		// destructor
		virtual ~Physical_Environment2D ();

		// reset the integration time step of the environment
		void Reset_Integration_Step (float dt);

		// methods for adding primitives to the environment

		// adds a triangle to the environment
		void Add_Triangle_Body (float x, float y, float base, float height, float p);
		void Add_Triangle_Body (const Vector2D &C, float base, float height, float p);

		// adds a square to the environment
		void Add_Square_Body (float x, float y, float side, float p);
		void Add_Square_Body (const Vector2D &C, float side, float p);

		// adds a diamond to the environment
		void Add_Diamond_Body (float x, float y, float side, float p);
		void Add_Diamond_Body (const Vector2D &C, float side, float p);

		// adds a rectangle to the environment
		void Add_Rectangle_Body (float x, float y, float width, float height, float p);
		void Add_Rectangle_Body (const Vector2D &C, float width, float height, float p);

		// adds an n-gon to the environment
		void Add_NGon_Body (float x, float y, int n, float radius, float p);
		void Add_NGon_Body (const Vector2D &C, int n, float radius, float p);

		// change the outside force
		void Change_Outside_Force (float force_x, float force_y);
		void Change_Outside_Force (const Vector2D &V);

		// change the outside acceleration
		void Change_Outside_Acceleration (float acc_x, float acc_y);
		void Change_Outside_Acceleration (const Vector2D &A);

		// renders the physical environment
		void Render_Environment ();
		void Render_Environment (int num_turns, float turn_mag, bool draw_boxes, bool draw_forces);

		// change whether or not the environment is playing or paused
		void Play ();
		void Pause ();
		void Toggle_Status ();

		// adds a kinematic object to the environment
		void Add_Kinematic_Object ();
		void Add_Kinematic_Object (float center_x, float center_y);
		void Add_Kinematic_Object (const Vector2D &center);
		void Add_Kinematic_Object (const Kinematic_Object2D &K);

		// adds a particle to the environment
		void Add_Particle (float center_x, float center_y);
		void Add_Particle (const Vector2D &center);
		void Add_Particle (float particle_mass);
		void Add_Particle (float center_x, float center_y, float particle_mass);
		void Add_Particle (const Vector2D &center, float particle_mass);
		void Add_Particle (float center_x, float center_y, float particle_mass, float damping, float restitution);
		void Add_Particle (const Vector2D &center, float particle_mass, float damping, float restitution);
		void Add_Particle (const Particle &P);

		// adds a rigid body to the environment
		void Add_Rigid_Body ();
		void Add_Rigid_Body (float p);
		void Add_Rigid_Body (float center_x, float center_y);
		void Add_Rigid_Body (const Vector2D &center);
		void Add_Rigid_Body (float center_x, float center_y, float p);
		void Add_Rigid_Body (const Vector2D &center, float p);
		void Add_Rigid_Body (float p, float linear_damping, float angular_damping, float restitution);
		void Add_Rigid_Body (float center_x, float center_y, float p, float linear_damping, float angular_damping, float restitution);
		void Add_Rigid_Body (const Vector2D &center, float p, float linear_damping, float angular_damping, float restitution);
		void Add_Rigid_Body (const Rigid_Body2D &R);

		// adds a spring to the environment
		void Add_Spring ();
		void Add_Spring (float ks, float kd);
		void Add_Spring (int b1, float x1, float y1, SPRING_CONNECTIONS connection1,
						 int b2, float x2, float y2, SPRING_CONNECTIONS connection2);
		void Add_Spring (int b1, const Vector2D &p1, SPRING_CONNECTIONS connection1,
						 int b2, const Vector2D &p2, SPRING_CONNECTIONS connection2);
		void Add_Spring (int b1, float x1, float y1, SPRING_CONNECTIONS connection1,
						 int b2, float x2, float y2, SPRING_CONNECTIONS connection2, float length);
		void Add_Spring (int b1, const Vector2D &p1, SPRING_CONNECTIONS connection1,
						 int b2, const Vector2D &p2, SPRING_CONNECTIONS connection2, float length);
		void Add_Spring (float length);
		void Add_Spring (float length, float ks, float kd);
		void Add_Spring (int b1, float x1, float y1, SPRING_CONNECTIONS connection1,
						 int b2, float x2, float y2, SPRING_CONNECTIONS connection2,
						 float length, float ks, float kd);
		void Add_Spring (int b1, const Vector2D &p1, SPRING_CONNECTIONS connection1,
						 int b2, const Vector2D &p2, SPRING_CONNECTIONS connection2,
						 float length, float ks, float kd);
		void Add_Spring (int b1, int v1, SPRING_CONNECTIONS connection1,
						 int b2, int v2, SPRING_CONNECTIONS connection2);
		void Add_Spring (int b1, int v1, SPRING_CONNECTIONS connection1,
						 int b2, int v2, SPRING_CONNECTIONS connection2, float length);
		void Add_Spring (int b1, int v1, SPRING_CONNECTIONS connection1,
						 int b2, int v2, SPRING_CONNECTIONS connection2,
						 float length, float ks, float kd);

		// changes the properties of the nth kinematic object
		void Kinematic_Reset_Position (int n, const float x, const float y);
		void Kinematic_Reset_Position (int n, const Vector2D &pos);
		void Kinematic_Reset_Orientation (int n, const float rotation);
		void Kinematic_Reset_Velocity (int n, const float vel_x, const float vel_y);
		void Kinematic_Reset_Velocity (int n, const Vector2D &vel);
		void Kinematic_Reset_Acceleration (int n, const float acc_x, const float acc_y);
		void Kinematic_Reset_Acceleration (int n, const Vector2D &acc);
		void Kinematic_Reset_Angular_Velocity (int n, const float omega);
		void Kinematic_Reset_Angular_Acceleration (int n, const float alpha);

		// changes the properties of the nth particle
		void Particle_Reset_State (int n, enum PARTICLE_TYPE new_state);
		void Particle_Add_Force (int n, const Vector2D &F);
		void Particle_Add_Force (int n, float force_x, float force_y);
		void Particle_Reset_Force_Vector (int n, int f, const Vector2D &F);
		void Particle_Reset_Force_Vector (int n, int f, float force_x, float force_y);
		void Particle_Remove_Force (int n, int f);
		void Particle_Reset_Mass (int n, float m);
		void Particle_Reset_Position (int n, float x, float y);
		void Particle_Reset_Position (int n, const Vector2D &pos);
		void Particle_Reset_Velocity (int n, float vel_x, float vel_y);
		void Particle_Reset_Velocity (int n, const Vector2D &vel);
		void Particle_Reset_Collision_State (int n, enum PARTICLE_COLLISION_TYPE new_state);

		// changes the properties of the nth rigid body
		void Body_Reset_State (int n, enum RIGID_BODY_TYPE new_state);
		void Body_Add_Force (int n, const Force2D &F);
		void Body_Add_Force (int n, float force_x, float force_y, float position_x, float position_y, ID_TAG system);
		void Body_Add_Force (int n, const Vector2D &F, const Vector2D &P, ID_TAG system);
		void Body_Reset_Force (int n, int f, const Force2D &F);
		void Body_Reset_Force_Vector (int n, int f, const Vector2D &F);
		void Body_Reset_Force_Vector (int n, int f, float force_x, float force_y);
		void Body_Reset_Force_Position (int n, int f, const Vector2D &P);
		void Body_Reset_Force_Position (int n, int f, float position_x, float position_y);
		void Body_Reset_Force_ID (int n, int f, ID_TAG system);
		void Body_Add_Vertex_Before (int n, int v, float x, float y);
		void Body_Add_Vertex_Before (int n, int v, const Vector2D &V);
		void Body_Add_Vertex_After (int n, int v, float x, float y);
		void Body_Add_Vertex_After (int n, int v, const Vector2D &V);
		void Body_Push_Vertex (int n, float x, float y);
		void Body_Push_Vertex (int n, const Vector2D &V);
		void Body_Remove_Vertices (int n, int v, int num);
		void Body_Reset_Vertex (int n, int v, float x, float y);
		void Body_Reset_Vertex (int n, int v, const Vector2D &V);
		void Body_Reset_Density (int n, float p);
		void Body_Reset_Position (int n, float x, float y);
		void Body_Reset_Position (int n, const Vector2D &pos);
		void Body_Reset_Orientation (int n, float rotation);
		void Body_Reset_Velocity (int n, float vel_x, float vel_y);
		void Body_Reset_Velocity (int n, const Vector2D &vel);
		void Body_Reset_Angular_Velocity (int n, float omega);
		void Body_Reset_Linear_Damping (int n, float ld);
		void Body_Reset_Angular_Damping (int n, float ad);
		void Body_Reset_Restitution (int n, float r);
		void Body_Reset_Collision_State (int n, enum RIGID_BODY_COLLISION_TYPE new_state);

		// changes the properties of the nth spring
		void Remove_Spring (int n);
		void Spring_Reset_Body1 (int n, int body1);
		void Spring_Reset_Body2 (int n, int body2);
		void Spring_Reset_Vertex1 (int n, int vertex1);
		void Spring_Reset_Vertex2 (int n, int vertex2);
		void Spring_Reset_Vertex1 (int n, float x, float y);
		void Spring_Reset_Vertex1 (int n, const Vector2D &V);
		void Spring_Reset_Vertex2 (int n, float x, float y);
		void Spring_Reset_Vertex2 (int n, const Vector2D &V);
		void Spring_Reset_Connection1 (int n, SPRING_CONNECTIONS connection1);
		void Spring_Reset_Connection2 (int n, SPRING_CONNECTIONS connection2);
		void Spring_Reset_Length (int n, float length);
		void Spring_Reset_Constant (int n, float ks);
		void Spring_Reset_Damping (int n, float kd);

		// integrates system over a time step to find the newest positions of the objects
		void Simulate ();

	//private:

		// integration methods
		void Euler_Integrate ();

		// totals up all forces and calculates the acceleration of every particle and rigid body
		void Calculate_Accelerations ();

		// handles all the forces acting in the system
		void Reset_Forces ();
		void Calculate_Particle_Forces ();
		void Calculate_Rigid_Body_Forces ();
		void Calculate_Spring_Forces ();
		void Calculate_Gravitational_Forces ();
		void Calculate_Total_Forces ();

		// does the collision detection and handling for the entire environment
		void Environment_Collision_Check ();
		inline bool Body_Body_Bounding_Box_Test (int j, int k);
		inline bool Point_Body_Bounding_Box_Test (const Vector2D &V, int n);
		inline int  Body_Body_Collision_Test (int j, int k);
		inline bool Point_Body_Collision_Test (const Vector2D &V, int n);
		inline bool Body_Edge_Intersection_Test (int j, int k);
		inline Array<int>  Find_Colliding_Vertex (int j, int k);
		Array<int>  Find_Colliding_Edge (const Vector2D &V, int n);

		void Body_Body_Collision_Handle (int j, int k, const Vector2D &N, const Vector2D &P);



		// list of kinematic objects in the environment
		Array <Kinematic_Object2D> kinematic_object_list;

		// list of particles in the environment
		Array <Particle> particle_list;

		// list of rigid bodies in the environment
		Array <Rigid_Body2D> rigid_body_list;

		// list of springs acting on the particles and rigid bodies in the environment
		Array <Spring2D> spring_list;

		// an outside force acting on the entire system
		Vector2D outside_force;

		// acceleration due to outside forces in the environment (for accelerations that
		// you do not want to depend on mass)
		Vector2D outside_acceleration;

		// gravitational constant of the environment
		float G;

		// boundaries of the environment
		float left_bound, right_bound, upper_bound, lower_bound;

		// determines if the physical environment is paused or not
		PHYSICAL_ENVIRONMENT_STATUS environment_status;

		// integration time step of the environment
		float delta_t;

		bool collision_occuring;
};


#endif




