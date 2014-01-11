/* ---------------------------------------------------------------------------
 *
 *		Physical_Environment2D class - Michael Brandon Williams
 *
 *		Physical_Environment2D.cpp
 *
 * ---------------------------------------------------------------------------
 */



#include "Physical_Environment2D.h"




// default constructor
Physical_Environment2D::Physical_Environment2D ()
{
	// an outside force acting on the entire system
	outside_force = Vector2D (0.0f, 0.0f);

	// acceleration due to outside forces in the environment (for accelerations that
	// you do not want to depend on mass)
	outside_acceleration = Vector2D (0.0f, 0.0f);

	// gravitational constant of the environment
	G = 0.0f;

	// boundaries of the environment
	left_bound  = -10000.0f;
	right_bound =  10000.0f;
	upper_bound =  10000.0f;
	lower_bound = -10000.0f;

	// determines if the physical environment is paused or not
	environment_status = PLAYING;

	// integration time step of the environment
	delta_t = 0.0f;
}


// constructor for when you know the outside force in the environment
Physical_Environment2D::Physical_Environment2D (float force_x, float force_y)
{
	// an outside force acting on the entire system
	outside_force = Vector2D (force_x, force_y);

	// acceleration due to outside forces in the environment (for accelerations that
	// you do not want to depend on mass)
	outside_acceleration = Vector2D (0.0f, 0.0f);

	// gravitational constant of the environment
	G = 0.0f;

	// boundaries of the environment
	left_bound  = -10000.0f;
	right_bound =  10000.0f;
	upper_bound =  10000.0f;
	lower_bound = -10000.0f;

	// determines if the physical environment is paused or not
	environment_status = PLAYING;

	// integration time step of the environment
	delta_t = 0.0f;
}


// constructor for when you know the outside force in the environment
Physical_Environment2D::Physical_Environment2D (const Vector2D &F)
{
	// an outside force acting on the entire system
	outside_force = F;

	// acceleration due to outside forces in the environment (for accelerations that
	// you do not want to depend on mass)
	outside_acceleration = Vector2D (0.0f, 0.0f);

	// gravitational constant of the environment
	G = 0.0f;

	// boundaries of the environment
	left_bound  = -10000.0f;
	right_bound =  10000.0f;
	upper_bound =  10000.0f;
	lower_bound = -10000.0f;

	// determines if the physical environment is paused or not
	environment_status = PLAYING;

	// integration time step of the environment
	delta_t = 0.0f;
}


// constructor for when you know the gravitational constant of the environment
Physical_Environment2D::Physical_Environment2D (float gravitational_constant)
{
	// an outside force acting on the entire system
	outside_force = Vector2D (0.0f, 0.0f);

	// acceleration due to outside forces in the environment (for accelerations that
	// you do not want to depend on mass)
	outside_acceleration = Vector2D (0.0f, 0.0f);

	// gravitational constant of the environment
	G = gravitational_constant;

	// boundaries of the environment
	left_bound  = -10000.0f;
	right_bound =  10000.0f;
	upper_bound =  10000.0f;
	lower_bound = -10000.0f;

	// determines if the physical environment is paused or not
	environment_status = PLAYING;

	// integration time step of the environment
	delta_t = 0.0f;
}


// constructor for when you know the bounds of the environment
Physical_Environment2D::Physical_Environment2D (float right, float left, float up, float down)
{
	// an outside force acting on the entire system
	outside_force = Vector2D (0.0f, 0.0f);

	// acceleration due to outside forces in the environment (for accelerations that
	// you do not want to depend on mass)
	outside_acceleration = Vector2D (0.0f, 0.0f);

	// gravitational constant of the environment
	G = 0.0f;

	// boundaries of the environment
	left_bound  = left;
	right_bound = right;
	upper_bound = up;
	lower_bound = down;

	// determines if the physical environment is paused or not
	environment_status = PLAYING;

	// integration time step of the environment
	delta_t = 0.0f;
}


// constructor for when you know everything about the environment
Physical_Environment2D::Physical_Environment2D (float force_x, float force_y, float right, float left, float up, float down, float gravitational_constant)
{
	// an outside force acting on the entire system
	outside_force = Vector2D (force_x, force_y);

	// acceleration due to outside forces in the environment (for accelerations that
	// you do not want to depend on mass)
	outside_acceleration = Vector2D (0.0f, 0.0f);

	// gravitational constant of the environment
	G = gravitational_constant;

	// boundaries of the environment
	left_bound  = left;
	right_bound = right;
	upper_bound = up;
	lower_bound = down;

	// determines if the physical environment is paused or not
	environment_status = PLAYING;

	// integration time step of the environment
	delta_t = 0.0f;
}


// constructor for when you know everything about the environment
Physical_Environment2D::Physical_Environment2D (const Vector2D &F, float right, float left, float up, float down, float gravitational_constant)
{
	// an outside force acting on the entire system
	outside_force = F;

	// acceleration due to outside forces in the environment (for accelerations that
	// you do not want to depend on mass)
	outside_acceleration = Vector2D (0.0f, 0.0f);

	// gravitational constant of the environment
	G = gravitational_constant;

	// boundaries of the environment
	left_bound  = left;
	right_bound = right;
	upper_bound = up;
	lower_bound = down;

	// determines if the physical environment is paused or not
	environment_status = PLAYING;

	// integration time step of the environment
	delta_t = 0.0f;
}


// destructor
Physical_Environment2D::~Physical_Environment2D ()
{
}


// reset the integration time step of the environment
void Physical_Environment2D::Reset_Integration_Step (float dt)
{
	delta_t = dt;
}


// methods for adding primitives to the environment


// adds a triangle to the environment
void Physical_Environment2D::Add_Triangle_Body (float x, float y, float base, float height, float p)
{
	// number of rigid bodies in the environment now (so we know which body to add vertices to)
	int num = rigid_body_list.Length ();

	// add the new rigid body to the environment
	this->Add_Rigid_Body (x, y, p);

	// add the vertices on the rigid body
	this->Body_Push_Vertex (num, 0.0f,        0.0f);
	this->Body_Push_Vertex (num, base,        0.0f);
	this->Body_Push_Vertex (num, base / 2.0f, height);
}


// adds a triangle to the environment
void Physical_Environment2D::Add_Triangle_Body (const Vector2D &C, float base, float height, float p)
{
	this->Add_Triangle_Body (C.x, C.y, base, height, p);
}


// adds a square to the environment
void Physical_Environment2D::Add_Square_Body (float x, float y, float side, float p)
{
	// number of rigid bodies in the environment now (so we know which body to add vertices to)
	int num = rigid_body_list.Length ();

	// add the new rigid body to the environment
	this->Add_Rigid_Body (x, y, p);

	// add the vertices on the rigid body
	this->Body_Push_Vertex (num, 0.0f, 0.0f);
	this->Body_Push_Vertex (num, side, 0.0f);
	this->Body_Push_Vertex (num, side, side);
	this->Body_Push_Vertex (num, 0.0f, side);
}


// adds a square to the environment
void Physical_Environment2D::Add_Square_Body (const Vector2D &C, float side, float p)
{
	this->Add_Square_Body (C.x, C.y, side, p);
}


// adds a diamond to the environment
void Physical_Environment2D::Add_Diamond_Body (float x, float y, float side, float p)
{
	// number of rigid bodies in the environment now (so we know which body to add vertices to)
	int num = rigid_body_list.Length ();

	// add the new rigid body to the environment
	this->Add_Rigid_Body (x, y, p);

	// add the vertices on the rigid body
	this->Body_Push_Vertex (num,  side,  0.0f);
	this->Body_Push_Vertex (num,  0.0f,  side);
	this->Body_Push_Vertex (num, -side,  0.0f);
	this->Body_Push_Vertex (num,  0.0f, -side);
}


// adds a diamond to the environment
void Physical_Environment2D::Add_Diamond_Body (const Vector2D &C, float side, float p)
{
	this->Add_Diamond_Body (C.x, C.y, side, p);
}


// adds a rectangle to the environment
void Physical_Environment2D::Add_Rectangle_Body (float x, float y, float width, float height, float p)
{
	// number of rigid bodies in the environment now (so we know which body to add vertices to)
	int num = rigid_body_list.Length ();

	// add the new rigid body to the environment
	this->Add_Rigid_Body (x, y, p);

	// add the vertices on the rigid body
	this->Body_Push_Vertex (num, 0.0f,  0.0f);
	this->Body_Push_Vertex (num, width, 0.0f);
	this->Body_Push_Vertex (num, width, height);
	this->Body_Push_Vertex (num, 0.0f,  height);
}


// adds a rectangle to the environment
void Physical_Environment2D::Add_Rectangle_Body (const Vector2D &C, float width, float height, float p)
{
	this->Add_Rectangle_Body (C.x, C.y, width, height, p);
}


// adds an n-gon to the environment
void Physical_Environment2D::Add_NGon_Body (float x, float y, int n, float radius, float p)
{
	// number of rigid bodies in the environment now (so we know which body to add vertices to)
	int num = rigid_body_list.Length ();

	// position of a point on the body
	float vx, vy;

	// add the new rigid body to the environment
	this->Add_Rigid_Body (x, y, p);

	// add the vertices on the rigid body
	for (int j = 0; j < n; j++)
	{
		// calculate the position of the point on the rigid body
		vx = radius * cosf (2.0f * Math::pi * float (j) / float (n));
		vy = radius * sinf (2.0f * Math::pi * float (j) / float (n));

		// add the vertex to the body
		this->Body_Push_Vertex (num, vx, vy);
	}
}


// adds an n-gon to the environment
void Physical_Environment2D::Add_NGon_Body (const Vector2D &C, int n, float radius, float p)
{
	this->Add_NGon_Body (C.x, C.y, n, radius, p);
}


// change the outside force
void Physical_Environment2D::Change_Outside_Force (float force_x, float force_y)
{
	outside_force.x = force_x;
	outside_force.y = force_y;
}


// change the outside force
void Physical_Environment2D::Change_Outside_Force (const Vector2D &V)
{
	outside_force = V;
}


// change the outside acceleration
void Physical_Environment2D::Change_Outside_Acceleration (float acc_x, float acc_y)
{
	outside_acceleration.x = acc_x;
	outside_acceleration.y = acc_y;
}


// change the outside acceleration
void Physical_Environment2D::Change_Outside_Acceleration (const Vector2D &A)
{
	outside_acceleration = A;
}


// renders the physical environment
void Physical_Environment2D::Render_Environment ()
{
	this->Render_Environment (1, 0.0f, false, false);
}


// renders the physical environment
void Physical_Environment2D::Render_Environment (int num_turns, float turn_mag, bool draw_boxes, bool draw_forces)
{
	// used for indexing the rigid body, particle and spring arrays
	int j;

	// number of rigid bodies, particles and springs in the environment
	int num;

	// the two global points a spring connects
	Vector2D point1, point2;

	// get the number of particles in the environment
	num = particle_list.Length ();

	// loop through the particles to draw them and their forces
	for (j = 0; j < num; j++)
	{
		// draw the particle
		particle_list[j].Draw_Particle ();

		// check if the forces should be drawn
		if (draw_forces)
		{
			particle_list[j].Draw_Forces ();
		}
	}

	// get the number of rigid bodies in the environment
	num = rigid_body_list.Length ();

	// loop through the rigid bodies to draw them and their forces
	for (j = 0; j < num; j++)
	{
		// draw the rigid body
		rigid_body_list[j].Draw_Rigid_Body ();

		// check if the bounding box should be drawn
		if (draw_boxes)
		{
			rigid_body_list[j].Draw_Bounding_Box ();
		}

		// check if the forces should be drawn
		if (draw_forces)
		{
			rigid_body_list[j].Draw_Forces ();
		}
	}

	// get the number of springs in the environment
	num = spring_list.Length ();

	// loop through the springs in the environment and draw their connection
	for (j = 0; j < num; j++)
	{
		// check what type of datatypes are being connected with the spring
		if ((spring_list[j].point1_type == PARTICLE_CONNECTION) && (spring_list[j].point2_type == PARTICLE_CONNECTION))
		{
			// spring is connecting two particles

			// get the global position of the two points the spring connects
			point1 = particle_list[spring_list[j].body1].position;
			point2 = particle_list[spring_list[j].body2].position;

			// draw the spring
			spring_list[j].Draw_Spring (num_turns, turn_mag, point1.x, point1.y, point2.x, point2.y);
		}
		else if ((spring_list[j].point1_type == RIGID_BODY_CONNECTION) && (spring_list[j].point2_type == PARTICLE_CONNECTION))
		{
			// spring is connecting a rigid body with a particle

			// get the global position of the two points the spring connects
			point1 = rigid_body_list[spring_list[j].body1].Return_Global_Point_Position (spring_list[j].point1);
			point2 = particle_list[spring_list[j].body2].position;

			// draw the spring
			spring_list[j].Draw_Spring (num_turns, turn_mag, point1.x, point1.y, point2.x, point2.y);
		}
		else if ((spring_list[j].point1_type == PARTICLE_CONNECTION) && (spring_list[j].point2_type == RIGID_BODY_CONNECTION))
		{
			// spring is connecting a particle with a rigid body

			// get the global position of the two points the spring connects
			point1 = particle_list[spring_list[j].body1].position;
			point2 = rigid_body_list[spring_list[j].body2].Return_Global_Point_Position (spring_list[j].point2);

			// draw the spring
			spring_list[j].Draw_Spring (num_turns, turn_mag, point1.x, point1.y, point2.x, point2.y);
		}
		else
		{
			// spring is connecting two rigid bodies

			// get the global position of the two points the spring connects
			point1 = rigid_body_list[spring_list[j].body1].Return_Global_Point_Position (spring_list[j].point1);
			point2 = rigid_body_list[spring_list[j].body2].Return_Global_Point_Position (spring_list[j].point2);

			// draw the spring
			spring_list[j].Draw_Spring (num_turns, turn_mag, point1.x, point1.y, point2.x, point2.y);
		}
	}
}


// change whether or not the environment is playing or paused
void Physical_Environment2D::Play ()
{
	environment_status = PLAYING;
}


// change whether or not the environment is playing or paused
void Physical_Environment2D::Pause ()
{
	environment_status = PAUSED;
}


// change whether or not the environment is playing or paused
void Physical_Environment2D::Toggle_Status ()
{
	environment_status = (environment_status == PLAYING) ? PAUSED : PLAYING;
}


// adds a kinematic object to the environment
void Physical_Environment2D::Add_Kinematic_Object ()
{
	kinematic_object_list.Push (Kinematic_Object2D ());
}


// adds a kinematic object to the environment
void Physical_Environment2D::Add_Kinematic_Object (float center_x, float center_y)
{
	kinematic_object_list.Push (Kinematic_Object2D (center_x, center_y));
}


// adds a kinematic object to the environment
void Physical_Environment2D::Add_Kinematic_Object (const Vector2D &center)
{
	kinematic_object_list.Push (Kinematic_Object2D (center));
}


// adds a kinematic object to the environment
void Physical_Environment2D::Add_Kinematic_Object (const Kinematic_Object2D &K)
{
	kinematic_object_list.Push (Kinematic_Object2D (K));
}


// adds a particle to the environment
void Physical_Environment2D::Add_Particle (float center_x, float center_y)
{
	particle_list.Push (Particle (center_x, center_y));
}


// adds a particle to the environment
void Physical_Environment2D::Add_Particle (const Vector2D &center)
{
	particle_list.Push (Particle (center));
}


// adds a particle to the environment
void Physical_Environment2D::Add_Particle (float particle_mass)
{
	particle_list.Push (Particle (particle_mass));
}


// adds a particle to the environment
void Physical_Environment2D::Add_Particle (float center_x, float center_y, float particle_mass)
{
	particle_list.Push (Particle (center_x, center_y, particle_mass));
}


// adds a particle to the environment
void Physical_Environment2D::Add_Particle (const Vector2D &center, float particle_mass)
{
	particle_list.Push (Particle (center, particle_mass));
}


// adds a particle to the environment
void Physical_Environment2D::Add_Particle (float center_x, float center_y, float particle_mass, float damping, float restitution)
{
	particle_list.Push (Particle (center_x, center_y, particle_mass, damping, restitution));
}


// adds a particle to the environment
void Physical_Environment2D::Add_Particle (const Vector2D &center, float particle_mass, float damping, float restitution)
{
	particle_list.Push (Particle (center, particle_mass, damping, restitution));
}


// adds a particle to the environment
void Physical_Environment2D::Add_Particle (const Particle &P)
{
	particle_list.Push (Particle (P));
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body ()
{
	rigid_body_list.Push (Rigid_Body2D ());
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body (float p)
{
	rigid_body_list.Push (Rigid_Body2D (p));
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body (float center_x, float center_y)
{
	rigid_body_list.Push (Rigid_Body2D (center_x, center_y));
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body (const Vector2D &center)
{
	rigid_body_list.Push (Rigid_Body2D (center));
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body (float center_x, float center_y, float p)
{
	rigid_body_list.Push (Rigid_Body2D (center_x, center_y, p));
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body (const Vector2D &center, float p)
{
	rigid_body_list.Push (Rigid_Body2D (center, p));
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body (float p, float linear_damping, float angular_damping, float restitution)
{
	rigid_body_list.Push (Rigid_Body2D (p, linear_damping, angular_damping, restitution));
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body (float center_x, float center_y, float p, float linear_damping, float angular_damping, float restitution)
{
	rigid_body_list.Push (Rigid_Body2D (center_x, center_y, p, linear_damping, angular_damping, restitution));
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body (const Vector2D &center, float p, float linear_damping, float angular_damping, float restitution)
{
	rigid_body_list.Push (Rigid_Body2D (center, p, linear_damping, angular_damping, restitution));
}


// adds a rigid body to the environment
void Physical_Environment2D::Add_Rigid_Body (const Rigid_Body2D &R)
{
	rigid_body_list.Push (Rigid_Body2D (R));
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring ()
{
	spring_list.Push (Spring2D ());
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (float ks, float kd)
{
	spring_list.Push (Spring2D (ks, kd));
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (int b1, float x1, float y1, SPRING_CONNECTIONS connection1,
										 int b2, float x2, float y2, SPRING_CONNECTIONS connection2)
{
	spring_list.Push (Spring2D (b1, x1, y1, connection1, b2, x2, y2, connection2));
}

// adds a spring to the environment
void Physical_Environment2D::Add_Spring (int b1, const Vector2D &p1, SPRING_CONNECTIONS connection1,
										 int b2, const Vector2D &p2, SPRING_CONNECTIONS connection2)
{
	spring_list.Push (Spring2D (b1, p1, connection1, b2, p2, connection2));
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (int b1, float x1, float y1, SPRING_CONNECTIONS connection1,
										 int b2, float x2, float y2, SPRING_CONNECTIONS connection2, float length)
{
	spring_list.Push (Spring2D (b1, x1, y1, connection1, b2, x2, y2, connection2, length));
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (int b1, const Vector2D &p1, SPRING_CONNECTIONS connection1,
										 int b2, const Vector2D &p2, SPRING_CONNECTIONS connection2, float length)
{
	spring_list.Push (Spring2D (b1, p1, connection1, b2, p2, connection2, length));
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (float length)
{
	spring_list.Push (Spring2D (length));
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (float length, float ks, float kd)
{
	spring_list.Push (Spring2D (length, ks, kd));
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (int b1, float x1, float y1, SPRING_CONNECTIONS connection1,
										 int b2, float x2, float y2, SPRING_CONNECTIONS connection2,
										 float length, float ks, float kd)
{
	spring_list.Push (Spring2D (b1, x1, y1, connection1, b2, x2, y2, connection2, length, ks, kd));
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (int b1, const Vector2D &p1, SPRING_CONNECTIONS connection1,
										 int b2, const Vector2D &p2, SPRING_CONNECTIONS connection2,
										 float length, float ks, float kd)
{
	spring_list.Push (Spring2D (b1, p1, connection1, b2, p2, connection2, length, ks, kd));
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (int b1, int v1, SPRING_CONNECTIONS connection1,
										 int b2, int v2, SPRING_CONNECTIONS connection2)
{
	if (connection1 == PARTICLE_CONNECTION)
	{
		if (connection2 == PARTICLE_CONNECTION)
		{
			// particle - particle
			spring_list.Push (Spring2D (b1, particle_list[b1].position, connection1, b2, particle_list[b2].position, connection2));
		}
		else
		{
			// particle - rigid body
			spring_list.Push (Spring2D (b1, particle_list[b1].position, connection1, b2, rigid_body_list[b2].local_vertices_centered[v2], connection2));
		}
	}
	else
	{
		if (connection2 == PARTICLE_CONNECTION)
		{
			// rigid body - particle
			spring_list.Push (Spring2D (b1, rigid_body_list[b1].local_vertices_centered[v1], connection1, b2, particle_list[b2].position, connection2));
		}
		else
		{
			// rigid body - rigid body
			spring_list.Push (Spring2D (b1, rigid_body_list[b1].local_vertices_centered[v1], connection1, b2, rigid_body_list[b2].local_vertices_centered[v2], connection2));
		}
	}
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (int b1, int v1, SPRING_CONNECTIONS connection1,
										 int b2, int v2, SPRING_CONNECTIONS connection2, float length)
{
	if (connection1 == PARTICLE_CONNECTION)
	{
		if (connection2 == PARTICLE_CONNECTION)
		{
			// particle - particle
			spring_list.Push (Spring2D (b1, particle_list[b1].position, connection1, b2, particle_list[b2].position, connection2, length));
		}
		else
		{
			// particle - rigid body
			spring_list.Push (Spring2D (b1, particle_list[b1].position, connection1, b2, rigid_body_list[b2].local_vertices_centered[v2], connection2, length));
		}
	}
	else
	{
		if (connection2 == PARTICLE_CONNECTION)
		{
			// rigid body - particle
			spring_list.Push (Spring2D (b1, rigid_body_list[b1].local_vertices_centered[v1], connection1, b2, particle_list[b2].position, connection2, length));
		}
		else
		{
			// rigid body - rigid body
			spring_list.Push (Spring2D (b1, rigid_body_list[b1].local_vertices_centered[v1], connection1, b2, rigid_body_list[b2].local_vertices_centered[v2], connection2, length));
		}
	}
}


// adds a spring to the environment
void Physical_Environment2D::Add_Spring (int b1, int v1, SPRING_CONNECTIONS connection1,
										 int b2, int v2, SPRING_CONNECTIONS connection2,
										 float length, float ks, float kd)
{
	// check for what datatype the spring connects so we know where to take the position of the vertices from
	if (connection1 == PARTICLE_CONNECTION)
	{
		if (connection2 == PARTICLE_CONNECTION)
		{
			// particle - particle
			spring_list.Push (Spring2D (b1, particle_list[b1].position, connection1, 
										b2, particle_list[b2].position, connection2, 
										length, ks, kd));
		}
		else
		{
			// particle - rigid body
			spring_list.Push (Spring2D (b1, particle_list[b1].position, connection1, 
										b2, rigid_body_list[b2].local_vertices_centered[v2], connection2, 
										length, ks, kd));
		}
	}
	else
	{
		if (connection2 == PARTICLE_CONNECTION)
		{
			// rigid body - particle
			spring_list.Push (Spring2D (b1, rigid_body_list[b1].local_vertices_centered[v1], connection1, 
										b2, particle_list[b2].position, connection2, length, ks, kd));
		}
		else
		{
			// rigid body - rigid body
			spring_list.Push (Spring2D (b1, rigid_body_list[b1].local_vertices_centered[v1], connection1, 
										b2, rigid_body_list[b2].local_vertices_centered[v2], connection2, 
										length, ks, kd));
		}
	}
}


// changes the properties of the nth kinematic object
void Physical_Environment2D::Kinematic_Reset_Position (int n, const float x, const float y)
{
	kinematic_object_list[n].Reset_Position (x, y);
}


// changes the properties of the nth kinematic object
void Physical_Environment2D::Kinematic_Reset_Position (int n, const Vector2D &pos)
{
	kinematic_object_list[n].Reset_Position (pos);
}


// changes the properties of the nth kinematic object
void Physical_Environment2D::Kinematic_Reset_Orientation (int n, const float rotation)
{
	kinematic_object_list[n].Reset_Orientation (rotation);
}


// changes the properties of the nth kinematic object
void Physical_Environment2D::Kinematic_Reset_Velocity (int n, const float vel_x, const float vel_y)
{
	kinematic_object_list[n].Reset_Velocity (vel_x, vel_y);
}


// changes the properties of the nth kinematic object
void Physical_Environment2D::Kinematic_Reset_Velocity (int n, const Vector2D &vel)
{
	kinematic_object_list[n].Reset_Velocity (vel);
}


// changes the properties of the nth kinematic object
void Physical_Environment2D::Kinematic_Reset_Acceleration (int n, const float acc_x, const float acc_y)
{
	kinematic_object_list[n].Reset_Acceleration (acc_x, acc_y);
}


// changes the properties of the nth kinematic object
void Physical_Environment2D::Kinematic_Reset_Acceleration (int n, const Vector2D &acc)
{
	kinematic_object_list[n].Reset_Acceleration (acc);
}


// changes the properties of the nth kinematic object
void Physical_Environment2D::Kinematic_Reset_Angular_Velocity (int n, const float omega)
{
	kinematic_object_list[n].Reset_Angular_Velocity (omega);
}


// changes the properties of the nth kinematic object
void Physical_Environment2D::Kinematic_Reset_Angular_Acceleration (int n, const float alpha)
{
	kinematic_object_list[n].Reset_Angular_Acceleration (alpha);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Reset_State (int n, enum PARTICLE_TYPE new_state)
{
	particle_list[n].Reset_State (new_state);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Add_Force (int n, const Vector2D &F)
{
	particle_list[n].Add_Force (F);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Add_Force (int n, float force_x, float force_y)
{
	particle_list[n].Add_Force (force_x, force_y);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Reset_Force_Vector (int n, int f, const Vector2D &F)
{
	particle_list[n].Reset_Force_Vector (f, F);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Reset_Force_Vector (int n, int f, float force_x, float force_y)
{
	particle_list[n].Reset_Force_Vector (f, force_x, force_y);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Remove_Force (int n, int f)
{
	particle_list[n].Remove_Force (f);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Reset_Mass (int n, float m)
{
	particle_list[n].Reset_Mass (m);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Reset_Position (int n, float x, float y)
{
	particle_list[n].Reset_Position (x, y);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Reset_Position (int n, const Vector2D &pos)
{
	particle_list[n].Reset_Position (pos);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Reset_Velocity (int n, float vel_x, float vel_y)
{
	particle_list[n].Reset_Velocity (vel_x, vel_y);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Reset_Velocity (int n, const Vector2D &vel)
{
	particle_list[n].Reset_Velocity (vel);
}


// changes the properties of the nth particle
void Physical_Environment2D::Particle_Reset_Collision_State (int n, enum PARTICLE_COLLISION_TYPE new_state)
{
	particle_list[n].Reset_Collision_State (new_state);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_State (int n, enum RIGID_BODY_TYPE new_state)
{
	rigid_body_list[n].state = new_state;
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Add_Force (int n, const Force2D &F)
{
	rigid_body_list[n].Add_Force (F);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Add_Force (int n, float force_x, float force_y, float position_x, float position_y, ID_TAG system)
{
	rigid_body_list[n].Add_Force (force_x, force_y, position_x, position_y, system);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Add_Force (int n, const Vector2D &F, const Vector2D &P, ID_TAG system)
{
	rigid_body_list[n].Add_Force (F, P, system);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Force (int n, int f, const Force2D &F)
{
	rigid_body_list[n].Reset_Force (f, F);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Force_Vector (int n, int f, const Vector2D &F)
{
	rigid_body_list[n].Reset_Force_Vector (f, F);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Force_Vector (int n, int f, float force_x, float force_y)
{
	rigid_body_list[n].Reset_Force_Vector (f, force_x, force_y);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Force_Position (int n, int f, const Vector2D &P)
{
	rigid_body_list[n].Reset_Force_Position (f, P);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Force_Position (int n, int f, float position_x, float position_y)
{
	rigid_body_list[n].Reset_Force_Position (f, position_x, position_y);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Force_ID (int n, int f, ID_TAG system)
{
	rigid_body_list[n].Reset_Force_ID (f, system);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Add_Vertex_Before (int n, int v, float x, float y)
{
	rigid_body_list[n].Add_Vertex_Before (v, x, y);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Add_Vertex_Before (int n, int v, const Vector2D &V)
{
	rigid_body_list[n].Add_Vertex_Before (v, V);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Add_Vertex_After (int n, int v, float x, float y)
{
	rigid_body_list[n].Add_Vertex_After (v, x, y);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Add_Vertex_After (int n, int v, const Vector2D &V)
{
	rigid_body_list[n].Add_Vertex_After (v, V);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Push_Vertex (int n, float x, float y)
{
	rigid_body_list[n].Push_Vertex (x, y);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Push_Vertex (int n, const Vector2D &V)
{
	rigid_body_list[n].Push_Vertex (V);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Remove_Vertices (int n, int v, int num)
{
	rigid_body_list[n].Remove_Vertices (v, num);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Vertex (int n, int v, float x, float y)
{
	rigid_body_list[n].Reset_Vertex (v, x, y);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Vertex (int n, int v, const Vector2D &V)
{
	rigid_body_list[n].Reset_Vertex (v, V);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Density (int n, float p)
{
	rigid_body_list[n].Reset_Density (p);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Position (int n, float x, float y)
{
	rigid_body_list[n].Reset_Position (x, y);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Position (int n, const Vector2D &pos)
{
	rigid_body_list[n].Reset_Position (pos);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Orientation (int n, float rotation)
{
	rigid_body_list[n].Reset_Orientation (rotation);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Velocity (int n, float vel_x, float vel_y)
{
	rigid_body_list[n].Reset_Velocity (vel_x, vel_y);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Velocity (int n, const Vector2D &vel)
{
	rigid_body_list[n].Reset_Velocity (vel);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Angular_Velocity (int n, float omega)
{
	rigid_body_list[n].Reset_Angular_Velocity (omega);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Linear_Damping (int n, float ld)
{
	rigid_body_list[n].Reset_Linear_Damping (ld);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Angular_Damping (int n, float ad)
{
	rigid_body_list[n].Reset_Angular_Damping (ad);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Restitution (int n, float r)
{
	rigid_body_list[n].Reset_Restitution (r);
}


// changes the properties of the nth rigid body
void Physical_Environment2D::Body_Reset_Collision_State (int n, enum RIGID_BODY_COLLISION_TYPE new_state)
{
	rigid_body_list[n].Reset_Collision_State (new_state);
}


// changes the properties of the nth spring
void Physical_Environment2D::Remove_Spring (int n)
{
	spring_list.Splice (n, 1);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Body1 (int n, int body1)
{
	spring_list[n].Reset_Body1 (body1);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Body2 (int n, int body2)
{
	spring_list[n].Reset_Body2 (body2);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Vertex1 (int n, int vertex1)
{
	if (spring_list[n].point1_type == PARTICLE_CONNECTION)
	{
		spring_list[n].Reset_Point_Body1 (particle_list[vertex1].position);
	}
	else
	{
		spring_list[n].Reset_Point_Body1 (rigid_body_list[vertex1].position);
	}
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Vertex2 (int n, int vertex2)
{
	if (spring_list[n].point2_type == PARTICLE_CONNECTION)
	{
		spring_list[n].Reset_Point_Body2 (particle_list[vertex2].position);
	}
	else
	{
		spring_list[n].Reset_Point_Body2 (rigid_body_list[vertex2].position);
	}
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Vertex1 (int n, float x, float y)
{
	spring_list[n].Reset_Point_Body1 (x, y);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Vertex1 (int n, const Vector2D &V)
{
	spring_list[n].Reset_Point_Body1 (V);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Vertex2 (int n, float x, float y)
{
	spring_list[n].Reset_Point_Body2 (x, y);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Vertex2 (int n, const Vector2D &V)
{
	spring_list[n].Reset_Point_Body2 (V);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Connection1 (int n, SPRING_CONNECTIONS connection1)
{
	spring_list[n].Reset_Connection1 (connection1);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Connection2 (int n, SPRING_CONNECTIONS connection2)
{
	spring_list[n].Reset_Connection2 (connection2);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Length (int n, float length)
{
	spring_list[n].Reset_Length (length);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Constant (int n, float ks)
{
	spring_list[n].Reset_Spring_Constant (ks);
}


// changes the properties of the nth spring
void Physical_Environment2D::Spring_Reset_Damping (int n, float kd)
{
	spring_list[n].Reset_Spring_Damping (kd);
}


// integrates system over a time step to find the newest positions of the objects
void Physical_Environment2D::Simulate ()
{
	// check if the environment is playing or not
	if (environment_status == PLAYING)
	{
		// environment is playing

		// do euler integration to find the newest positions of the objects
		this->Euler_Integrate ();

		// collision check and handle
		this->Environment_Collision_Check ();
	}
	else
	{
		// environment is paused

		glColor3f (8.0f, 0.1f, 0.1f);
		glRasterPos2f (0.0f, 0.0f);
		glPrint ("PAUSED \n Press Space to Continue");
	}
}


// Euler integration scheme
void Physical_Environment2D::Euler_Integrate ()
{
	// calculates the acceleration of all objects in the environment
	this->Calculate_Accelerations ();

	// number of kinematic objects, particles and rigid bodies in the environment
	int num;

	// used for indexing the rigid body and particle arrays
	int j;

	// get the number of particles in the environment
	num = particle_list.Length ();

	// loop through every particle and integrate over the time step
	for (j = 0; j < num; j++)
	{
		particle_list[j].Euler_Integrate (delta_t);

		if (particle_list[j].position.x >= right_bound)	particle_list[j].position.x = left_bound;
		if (particle_list[j].position.x <= left_bound)	particle_list[j].position.x = right_bound;
		if (particle_list[j].position.y >= upper_bound)		particle_list[j].position.y = lower_bound;
		if (particle_list[j].position.y <= lower_bound)	particle_list[j].position.y = upper_bound;
	}

	// get the number of rigid bodies in the environment
	num = rigid_body_list.Length ();

	// loop through every rigid body and integrate over the time step
	for (j = 0; j < num; j++)
	{
		rigid_body_list[j].Euler_Integrate (delta_t);

		if (rigid_body_list[j].position.x > right_bound)		rigid_body_list[j].position.x = left_bound;
		if (rigid_body_list[j].position.x < left_bound)		rigid_body_list[j].position.x = right_bound;
		if (rigid_body_list[j].position.y > upper_bound)		rigid_body_list[j].position.y = lower_bound;
		if (rigid_body_list[j].position.y < lower_bound)	rigid_body_list[j].position.y = upper_bound;
	}

	// get the number of kinematic objects in the environment
	num = kinematic_object_list.Length ();

	// loop through every kinematic object and integrate over the time step
	for (j = 0; j < num; j++)
	{
		kinematic_object_list[j].Euler_Integrate (delta_t);
	}
}


// totals up all forces and calculates the acceleration of every particle and rigid body
void Physical_Environment2D::Calculate_Accelerations ()
{
	// number of particles and rigid bodies in the environment
	int num;

	// calculate all the forces acting on the objects in the environment
	this->Calculate_Total_Forces ();

	// get the number of particles in the environment
	num = particle_list.Length ();

	// loop through the particles and calculate their acceleration
	for (int j = 0; j < num; j++)
	{
		particle_list[j].acceleration = particle_list[j].center_mass_force / particle_list[j].mass + outside_acceleration;
	}

	// number of rigid bodies in the environment
	num = rigid_body_list.Length ();

	// loop through the rigid bodies and calculate their linear and angular acceleration
	for (int k = 0; k < num; k++)
	{
		rigid_body_list[k].acceleration = rigid_body_list[k].center_mass_force / rigid_body_list[k].mass + outside_acceleration;
		rigid_body_list[k].angular_acceleration = rigid_body_list[k].torque / rigid_body_list[k].moment_of_inertia;
	}
}


// resets all the forces in the system to zero for the new summation
void Physical_Environment2D::Reset_Forces ()
{
	// number of particles and rigid bodies in the environment
	int num;

	// get the number of particles
	num = particle_list.Length ();

	// loop through all the particles and reset the total force acting on the center of mass
	for (int j = 0; j < num; j++)
	{
		particle_list[j].center_mass_force = outside_force;
	}

	// get the number of rigid bodies
	num = rigid_body_list.Length ();

	// loop through all the rigid bodies and reset the total force and torque acting on the body
	for (int k = 0; k < num; k++)
	{
		rigid_body_list[k].center_mass_force = outside_force;
		rigid_body_list[k].torque = 0.0f;
	}
}


// calculates all the forces acting on the particles in the environment except for springs
void Physical_Environment2D::Calculate_Particle_Forces ()
{
	// number of particles in the environment
	int num_particles = particle_list.Length ();

	// loop through the particles in the environment and calculate the total force acting on them
	for (int j = 0; j < num_particles; j++)
	{
		particle_list[j].Calculate_Forces ();
	}
}


// calculates all the forces acting on the rigid bodies in the environment except for springs
void Physical_Environment2D::Calculate_Rigid_Body_Forces ()
{
	// number of rigid bodies in the environment
	int num_rigid_bodies = rigid_body_list.Length ();

	// loop through all the bodies in the environment and calculate the forces acting them
	for (int j = 0; j < num_rigid_bodies; j++)
	{
		rigid_body_list[j].Calculate_Forces ();
	}
}


// calculates the spring forces acting on the rigid bodies and particles
void Physical_Environment2D::Calculate_Spring_Forces ()
{
	// number of springs in the environment
	int num_springs = spring_list.Length ();

	// vectors for the difference in the objects' position and velocity
	Vector2D delta_position, delta_velocity;

	// force vector of the spring acting on the objects
	Vector2D force;

	// global position of points the spring connects
	Vector2D point1, point2;

	// velocities of the points
	Vector2D velocity1, velocity2;

	// indexes of the objects the spring connects
	int b1, b2;

	// loop through the springs in the environment to calculate the forces they exert
	// on the particles and rigid bodies they are connected to
	for (int j = 0; j < num_springs; j++)
	{
		// indexes of the objects the spring connects
		b1 = spring_list[j].body1;
		b2 = spring_list[j].body2;

		// check what two datatypes the spring connects to get the point and velocity of the points
		if ((spring_list[j].point1_type == PARTICLE_CONNECTION) && (spring_list[j].point2_type == PARTICLE_CONNECTION))
		{
			// -------------------------------------------
			// spring connects two particles
			// -------------------------------------------

			// get the position and velocity of the points the spring conencts
			point1 = particle_list[b1].position;
			point2 = particle_list[b2].position;
			velocity1 = particle_list[b1].velocity;
			velocity2 = particle_list[b2].velocity;

			// calculate the force acting on the objects
			force = spring_list[j].Calculate_Spring_Force (point1, velocity1, point2, velocity2);

			// apply force to objects
			particle_list[b1].center_mass_force += force;
			particle_list[b2].center_mass_force -= force;
		}
		else if ((spring_list[j].point1_type == RIGID_BODY_CONNECTION) && (spring_list[j].point2_type == PARTICLE_CONNECTION))
		{
			// -------------------------------------------
			// spring connects a rigid body and a particle
			// -------------------------------------------

			// get the position and velocity of the points the spring conencts
			point1 = rigid_body_list[b1].Return_Global_Point_Position (spring_list[j].point1);
			point2 = particle_list[b2].position;
			velocity1 = rigid_body_list[b1].Return_Point_Velocity (spring_list[j].point1);
			velocity2 = particle_list[b2].velocity;

			// calculate the force acting on the objects
			force = spring_list[j].Calculate_Spring_Force (point1, velocity1, point2, velocity2);

			// apply force to objects
			rigid_body_list[b1].center_mass_force += force;
			rigid_body_list[b1].torque += rigid_body_list[b1].Return_Body_Point_Position (spring_list[j].point1) ^ force;
			particle_list[b2].center_mass_force -= force;

		}
		else if ((spring_list[j].point1_type == PARTICLE_CONNECTION) && (spring_list[j].point2_type == RIGID_BODY_CONNECTION))
		{
			// -------------------------------------------
			// spring connects a particle and a rigid body
			// -------------------------------------------

			// get the position and velocity of the points the spring conencts
			point1 = particle_list[b1].position;
			point2 = rigid_body_list[b2].Return_Global_Point_Position (spring_list[j].point2);
			velocity1 = particle_list[b1].velocity;
			velocity2 = rigid_body_list[b2].Return_Point_Velocity (spring_list[j].point2);

			// calculate the force acting on the objects
			force = spring_list[j].Calculate_Spring_Force (point1, velocity1, point2, velocity2);

			// apply force to objects
			particle_list[b1].center_mass_force += force;
			rigid_body_list[b2].center_mass_force -= force;
			rigid_body_list[b2].torque -= rigid_body_list[b2].Return_Body_Point_Position (spring_list[j].point2) ^ force;
		}
		else
		{
			// -------------------------------------------
			// spring connects two rigid bodies
			// -------------------------------------------

			// get the position and velocity of the points the spring conencts
			point1 = rigid_body_list[b1].Return_Global_Point_Position (spring_list[j].point1);
			point2 = rigid_body_list[b2].Return_Global_Point_Position (spring_list[j].point2);
			velocity1 = rigid_body_list[b1].Return_Point_Velocity (spring_list[j].point1);
			velocity2 = rigid_body_list[b2].Return_Point_Velocity (spring_list[j].point2);

			// calculate the force acting on the objects
			force = spring_list[j].Calculate_Spring_Force (point1, velocity1, point2, velocity2);

			// apply force to objects
			rigid_body_list[b1].center_mass_force += force;
			rigid_body_list[b1].torque += rigid_body_list[b1].Return_Body_Point_Position (spring_list[j].point1) ^ force;
			rigid_body_list[b2].center_mass_force -= force;
			rigid_body_list[b2].torque -= rigid_body_list[b2].Return_Body_Point_Position (spring_list[j].point2) ^ force;
		}
	}
}


// calculates the gravitational force between all the bodies and forces
void Physical_Environment2D::Calculate_Gravitational_Forces ()
{
	// only do calculations if the gravitational constant is not zero
	if (G != 0.0f)
	{
		// number of particles and rigid bodies in the environment
		int num_particles = particle_list.Length ();
		int num_rigid_bodies = rigid_body_list.Length ();

		// used for indexing the rigid body and particle arrays
		int j, k;

		// direction vector from one object to the other
		Vector2D direction;

		// distance between objects
		float distance;

		// gravitational force
		float force;

		// loop through all the particles to apply the gravitational force
		for (j = 0; j < num_particles; j++)
		{
			// check this particle with every other particle
			for (k = (j + 1); k < num_particles; k++)
			{
				// calculate the direction vector from one object to the other
				direction = particle_list[k].position - particle_list[j].position;

				// calculate distance between objects
				distance = ! direction;

				// calculate the force due to gravity acting on the two objects
				force = G * particle_list[j].mass * particle_list[k].mass / (distance * distance);

				// exert the force on the two objects
				particle_list[j].center_mass_force += direction * (force / distance);
				particle_list[k].center_mass_force -= direction * (force / distance);
			}

			// check this particle with every rigid body
			for (k = 0; k < num_rigid_bodies; k++)
			{
				// calculate the direction vector from one object to the other
				direction = rigid_body_list[k].position - particle_list[j].position;

				// calculate distance between objects
				distance = ! direction;

				// calculate the force due to gravity acting on the two objects
				force = G * particle_list[j].mass * rigid_body_list[k].mass / (distance * distance);

				// exert the force on the two objects
				particle_list[j].center_mass_force += direction * (force / distance);
				rigid_body_list[k].center_mass_force -= direction * (force / distance);
			}
		}

		// loop through all the rigid bodies to apply the gravitational force
		for (j = 0; j < num_rigid_bodies; j++)
		{
			// check this rigid body with every other rigid body
			for (k = (j + 1); k < num_rigid_bodies; k++)
			{
				// calculate the direction vector from one object to the other
				direction = rigid_body_list[k].position - rigid_body_list[j].position;

				// calculate distance between objects
				distance = ! direction;

				// calculate the force due to gravity acting on the two objects
				force = G * rigid_body_list[j].mass * rigid_body_list[k].mass / (distance * distance);

				// exert the force on the two objects
				rigid_body_list[j].center_mass_force += direction * (force / distance);
				rigid_body_list[k].center_mass_force -= direction * (force / distance);
			}
		}
	}
}



// sums all the forces in the entire environment
void Physical_Environment2D::Calculate_Total_Forces ()
{
	Reset_Forces ();
	Calculate_Particle_Forces ();
	Calculate_Rigid_Body_Forces ();
	Calculate_Spring_Forces ();
	Calculate_Gravitational_Forces ();
}



void Physical_Environment2D::Environment_Collision_Check ()
{
	int num = rigid_body_list.Length ();
	float accuracy = 20.0f;
	float dt = -delta_t / accuracy;
	Array <int> body_info, edges;
	Vector2D normal;
	int i = 0;

	for (int j = 0; j < num; j++)
	{
		if (rigid_body_list[j].collision_state == RIGID_BODY_CAN_COLLIDE)
		{
			for (int k = (j + 1); k < num; k++)
			{
				if (rigid_body_list[k].collision_state == RIGID_BODY_CAN_COLLIDE)
				{
					if (Body_Body_Bounding_Box_Test (j, k))
					{
						if (Body_Edge_Intersection_Test (j, k))
						{
							i = 0;
							while (Body_Edge_Intersection_Test (j, k) || (Body_Body_Collision_Test (j, k) > -1) || (Body_Body_Collision_Test (k, j) > -1))
							{
								rigid_body_list[j].Euler_Integrate (dt);
								rigid_body_list[k].Euler_Integrate (dt);
								i++;

								if (i >= 20)
								{
									break;
								}
							}

							rigid_body_list[j].Euler_Integrate (-dt);
							rigid_body_list[k].Euler_Integrate (-dt);

							body_info = this->Find_Colliding_Vertex (j, k);
							edges = this->Find_Colliding_Edge (rigid_body_list[body_info[0]].global_vertices[body_info[2]], body_info[1]);

							normal = rigid_body_list[body_info[1]].global_vertices[edges[1]] - rigid_body_list[body_info[1]].global_vertices[edges[0]];
							normal = normal.Return_Perpendicular () | (-1.0f);

							rigid_body_list[j].Euler_Integrate (dt);
							rigid_body_list[k].Euler_Integrate (dt);

							this->Body_Body_Collision_Handle (body_info[0], body_info[1], normal, rigid_body_list[body_info[0]].global_vertices[body_info[2]]);

							rigid_body_list[j].Euler_Integrate (delta_t);
							rigid_body_list[k].Euler_Integrate (delta_t);
						}
					}
				}
			}
		}
	}
}


// checks if the bounding boxes of two rigid bodies are overlapping
bool Physical_Environment2D::Body_Body_Bounding_Box_Test (int j, int k)
{
	// position of the top and bottom corners of the two rigid bodies we are checking
	Vector2D top1 (rigid_body_list[j].top_left_box);
	Vector2D bottom1 (rigid_body_list[j].bottom_right_box);
	Vector2D top2 (rigid_body_list[k].top_left_box);
	Vector2D bottom2 (rigid_body_list[k].bottom_right_box);

	// check if the vertices of the jth rigid body's bounding box are in the kth rigid body's box
	if (Math::Point_Bounding_Box_Test (top1.x,    top1.y,    top2.x, top2.y, bottom2.x, bottom2.y) ||
		Math::Point_Bounding_Box_Test (top1.x,    bottom1.y, top2.x, top2.y, bottom2.x, bottom2.y) ||
		Math::Point_Bounding_Box_Test (bottom1.x, bottom1.y, top2.x, top2.y, bottom2.x, bottom2.y) ||
		Math::Point_Bounding_Box_Test (bottom1.x, top1.y,    top2.x, top2.y, bottom2.x, bottom2.y))
	{
		return (true);
	}

	// check if the vertices of the kth rigid body's bounding box are in the jth rigid body's box
	if (Math::Point_Bounding_Box_Test (top2.x,    top2.y,    top1.x, top1.y, bottom1.x, bottom1.y) ||
		Math::Point_Bounding_Box_Test (top2.x,    bottom2.y, top1.x, top1.y, bottom1.x, bottom1.y) ||
		Math::Point_Bounding_Box_Test (bottom2.x, bottom2.y, top1.x, top1.y, bottom1.x, bottom1.y) ||
		Math::Point_Bounding_Box_Test (bottom2.x, top2.y,    top1.x, top1.y, bottom1.x, bottom1.y))
	{
		return (true);
	}

	// no overlapping bounding boxes
	return (false);
}


// checks if a point is in the bounding box of a rigid body
bool Physical_Environment2D::Point_Body_Bounding_Box_Test (const Vector2D &V, int n)
{
	// check if the point is in the nth rigid body's bounding box
	if (Math::Point_Bounding_Box_Test (V, rigid_body_list[n].top_left_box, rigid_body_list[n].bottom_right_box))
	{
		return (true);
	}

	return (false);
}


// does a full collision test between two rigid bodies
int Physical_Environment2D::Body_Body_Collision_Test (int j, int k)
{
	// number of vertices in the rigid bodies
	int num_vertices1 = rigid_body_list[j].global_vertices.Length ();

	// array of vertices that are in the bounding box area of the rigid body
	Array <int> bounding_box_vertices;

	// number of vertices in a bounding box area
	int num_bounding_box_vertices = 0;

	// iterator
	int n;

	// ---------------------------------------------------------
	// CHECK J'S VERTICES WITH THAT OF K'S
	// ---------------------------------------------------------

	// find the vertices in the jth rigid body that are in the kth rigid body's bounding box
	for (n = 0; n < num_vertices1; n++)
	{
		// check if the vertex is in the rigid body's bounding box
		if (this->Point_Body_Bounding_Box_Test (rigid_body_list[j].global_vertices[n], k))
		{
			// keep track of which vertices are in the bounding box
			bounding_box_vertices.Push (n);
		}
	}

	// get the number of vertices that were in the bounding box
	num_bounding_box_vertices = bounding_box_vertices.Length ();

	// test the vertices that are in the bounding box for collision
	for (n = 0; n < num_bounding_box_vertices; n++)
	{
		// check if the vertices is in the rigid body's area
		if (this->Point_Body_Collision_Test (rigid_body_list[j].global_vertices[bounding_box_vertices[n]], k))
		{
			return (bounding_box_vertices[n]);
		}
	}

	return (-1);
}


// checks if a point is inside a rigid body
bool Physical_Environment2D::Point_Body_Collision_Test (const Vector2D &V, int n)
{
	// temporary variable used for indexing the vertices array
	int k;

	// keep track of the number of intersections with the edges of the rigid body
	int num_intersections = 0;

	// number of vertices in the rigid body
	int num_vertices = rigid_body_list[n].global_vertices.Length ();

	// the x-position of any intersections
	float intersection_x = 0.0f;

	// x- and y-position of the global vertices
	float x1, y1, x2, y2;

	float slope;

	// loop through the vertices to check if the point is inside the edges of the rigid body
	for (int j = 0; j < num_vertices; j++)
	{
		// index of the next vertex in the vertices array
		k = (j + 1) % num_vertices;

		// x- and y-position of the global vertices
		x1 = rigid_body_list[n].global_vertices[j].x;
		y1 = rigid_body_list[n].global_vertices[j].y;
		x2 = rigid_body_list[n].global_vertices[k].x;
		y2 = rigid_body_list[n].global_vertices[k].y;

		//
		if ((V.y > Math::Minimum (y1, y2)) && (V.y <= Math::Maximum (y1, y2)) && (V.x <= Math::Maximum (x1, x2)) && (y1 != y2))
		{
			// calculate the x-position of the intersection
			if ((x2 - x1) != 0.0f)		slope = (y2 - y1) / (x2 - x1);
			else						slope = (y2 - y1) / Math::epsilon;

			intersection_x = (V.y - y1) / slope + x1;

			// check if the intersection fell on the edge
			if ((x1 == x2) || (V.x <= intersection_x))
			{
				// keep track of the number of intersections
				num_intersections++;
			}
		}
	}

	// check if the point is inside the object or not
	if ((num_intersections % 2) == 0)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}


// checks if the edges of two rigid bodies are overlapping
bool Physical_Environment2D::Body_Edge_Intersection_Test (int j, int k)
{
	// number of edges in each rigid body
	int num_edges1 = rigid_body_list[j].global_vertices.Length ();
	int num_edges2 = rigid_body_list[k].global_vertices.Length ();

	// indexes of the vertices of the rigid bodies
	int j1, j2, k1, k2;

	// loop through the jth rigid body's edges ad test if they intersect the edges of the kth rigid body
	for (j1 = 0; j1 < num_edges1; j1++)
	{
		// next vertex in the rigid body
		j2 = (j1 + 1) % num_edges1;

		// check this edge with the edges of the other rigid body
		for (k1 = 0; k1 < num_edges2; k1++)
		{
			// next vertex in the rigid body
			k2 = (k1 + 1) % num_edges2;

			if (Math::Line_Intersection_Test (rigid_body_list[j].global_vertices[j1], rigid_body_list[j].global_vertices[j2],
											  rigid_body_list[k].global_vertices[k1], rigid_body_list[k].global_vertices[k2]))
			{
				return (true);
			}
		}
	}

	return (false);
}


// first  element in the array returned:  body with the collidiing vertex
// second element in the array returned:  the other body
// third  element in the array returned:  the index of the colliding vertex
Array<int> Physical_Environment2D::Find_Colliding_Vertex (int j, int k)
{
	int colliding_vertex;
	Array<int> r (3);

	colliding_vertex = this->Body_Body_Collision_Test (j, k);

	if (colliding_vertex > -1)
	{
		// j's vertex is colliding with k
		r[0] = j;
		r[1] = k;
		r[2] = colliding_vertex;
		return (r);
	}
	else
	{
		// k's vertex is colliding with j
		r[0] = k;
		r[1] = j;
		r[2] = Body_Body_Collision_Test (k, j);
		return (r);
	}
}


// returns the indexes to the rigid nth rigid body's edge that is colliding with the point V
Array<int> Physical_Environment2D::Find_Colliding_Edge (const Vector2D &V, int n)
{
	Array <int> a (2);
	float smallest = 100000.0f;
	float temp;

	int j, k;

	int num_vertices = rigid_body_list[n].global_vertices.Length ();

	for (j = 0; j < num_vertices; j++)
	{
		k = (j + 1) % num_vertices;

		temp = Math::Point_Line_Distance (V, rigid_body_list[n].global_vertices[j], rigid_body_list[n].global_vertices[k]);

		if (fabsf (temp) < fabsf (smallest))
		{
			smallest = temp;

			a[0] = j;
			a[1] = k;
		}
	}

	return (a);
}


// handles the collision between two bodies
// j is the body that has the colliding vertex and k is the other body
// N is the normal of collision and P is the point of collision
void Physical_Environment2D::Body_Body_Collision_Handle (int j, int k, const Vector2D &N, const Vector2D &P)
{
	// get the point of collision relative to the two bodies
	Vector2D point1 (P - rigid_body_list[j].position);
	Vector2D point2 (P - rigid_body_list[k].position);

	// rotate the point into the bodies' coordinate system
	Vector2D temp_point1 (point1.Rotate (-rigid_body_list[j].sine, rigid_body_list[j].cosine));
	Vector2D temp_point2 (point2.Rotate (-rigid_body_list[k].sine, rigid_body_list[k].cosine));

	// get the velocity of the colliding points in each of the bodies
	Vector2D vel1 (rigid_body_list[j].Return_Point_Velocity (temp_point1));
	Vector2D vel2 (rigid_body_list[k].Return_Point_Velocity (temp_point2));

	// relative velocity of the colliding points of the body
	Vector2D relative_velocity (vel1 - vel2);

	// perpendicular vectors of the velocities
	Vector2D perp1 (point1.Return_Perpendicular ());
	Vector2D perp2 (point2.Return_Perpendicular ());

	// terms in the impulse equation
	float impulse1, impulse2, impulse_numerator1, impulse_numerator2, impulse_denominator;

	// mass and moment of inertia of the two colliding bodies
	float m1 = rigid_body_list[j].mass;
	float m2 = rigid_body_list[k].mass;
	float I1 = rigid_body_list[j].moment_of_inertia;
	float I2 = rigid_body_list[k].moment_of_inertia;

	// calculate the numerator of the impulse equation for each body
	impulse_numerator1   = (relative_velocity * (-1 - rigid_body_list[j].restitution)) % N;
	impulse_numerator2   = (relative_velocity * (-1 - rigid_body_list[k].restitution)) % N;

	// calculate the denominator of the impulse equation
	impulse_denominator = (N % N) * (1 / m1 + 1 / m2) + 
						  ((perp1 % N) * (perp1 % N)) / I1 + 
						  ((perp2 % N) * (perp2 % N)) / I2;

	// calculate the total impulse acting on the bodies
	impulse1 = impulse_numerator1 / impulse_denominator;
	impulse2 = impulse_numerator2 / impulse_denominator;

	// change the bodies' velocity due to the impulse
	rigid_body_list[j].velocity += N * (impulse1 / m1);
	rigid_body_list[k].velocity -= N * (impulse2 / m2);

	// change the bodies' angular velocity due to the impulse
	rigid_body_list[j].angular_velocity += (perp1 % (N * impulse1)) / I1;
	rigid_body_list[k].angular_velocity -= (perp2 % (N * impulse2)) / I2;
}




