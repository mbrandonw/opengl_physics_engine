/* ---------------------------------------------------------------------------
 *
 *		Particle class - Michael Brandon Williams
 *
 *		Particle.cpp
 *
 * ---------------------------------------------------------------------------
 */

#include "Particle.h"



// default constructor
Particle::Particle ()
{
	// position of the object's center of mass
	position = Vector2D (0.0f, 0.0f);

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// mass of the object
	mass = 0.0f;

	// constants of the particle
	damping = 0.0f;
	restitution = 1.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_PARTICLE;

	// determines if the particle should be checked for collisions with other objects
	collision_state = PARTICLE_CAN_COLLIDE;
}


// constructor for when the starting position of the object's center
// of mass is passed as two floats
Particle::Particle (float center_x, float center_y) 
{
	// position of the object's center of mass
	position = Vector2D (center_x, center_y);

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// mass of the object
	mass = 0.0f;

	// constants of the particle
	damping = 0.0f;
	restitution = 1.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_PARTICLE;

	// determines if the particle should be checked for collisions with other objects
	collision_state = PARTICLE_CAN_COLLIDE;
}


// constructor for when the starting position of the object's center
// of mass is passed as a vector
Particle::Particle (const Vector2D &center) 
{
	// position of the object's center of mass
	position = center;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// mass of the object
	mass = 0.0f;

	// constants of the particle
	damping = 0.0f;
	restitution = 1.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_PARTICLE;

	// determines if the particle should be checked for collisions with other objects
	collision_state = PARTICLE_CAN_COLLIDE;
}


// constructor for when the mass of the particle is passed
Particle::Particle (float particle_mass)
{
	// position of the object's center of mass
	position = Vector2D (0.0f, 0.0f);

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// mass of the object
	mass = particle_mass;

	// constants of the particle
	damping = 0.0f;
	restitution = 1.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_PARTICLE;

	// determines if the particle should be checked for collisions with other objects
	collision_state = PARTICLE_CAN_COLLIDE;
}


// constructor for when the starting position of the object's center
// of mass is passed as two floats, as well as the particle's mass
Particle::Particle (float center_x, float center_y, float particle_mass)
{
	// position of the object's center of mass
	position = Vector2D (center_x, center_y);

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// mass of the object
	mass = particle_mass;

	// constants of the particle
	damping = 0.0f;
	restitution = 1.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_PARTICLE;

	// determines if the particle should be checked for collisions with other objects
	collision_state = PARTICLE_CAN_COLLIDE;
}


// constructor for when the starting position of the object's center
// of mass is passed as a vector, as well as the particle's mass
Particle::Particle (const Vector2D &center, float particle_mass)
{
	// position of the object's center of mass
	position = center;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// mass of the object
	mass = particle_mass;

	// constants of the particle
	damping = 0.0f;
	restitution = 1.0f;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_PARTICLE;

	// determines if the particle should be checked for collisions with other objects
	collision_state = PARTICLE_CAN_COLLIDE;
}


// constructor for when you know everything about the particle
Particle::Particle (float center_x, float center_y, float particle_mass, float damping, float restitution)
{
	// position of the object's center of mass
	position = Vector2D (center_x, center_y);

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// mass of the object
	mass = particle_mass;

	// constants of the particle
	damping = damping;
	restitution = restitution;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_PARTICLE;

	// determines if the particle should be checked for collisions with other objects
	collision_state = PARTICLE_CAN_COLLIDE;
}


// constructor for when you know everything about the particle
Particle::Particle (const Vector2D &center, float particle_mass, float damping, float restitution)
{
	// position of the object's center of mass
	position = center;

	// velocity of the center of mass
	velocity = Vector2D (0.0f, 0.0f);

	// acceleration of the center of mass
	acceleration = Vector2D (0.0f, 0.0f);

	// mass of the object
	mass = particle_mass;

	// constants of the particle
	damping = damping;
	restitution = restitution;

	// total force acting on the center of mass
	center_mass_force = Vector2D (0.0f, 0.0f);

	// determines whether the particle is kinetic or static
	state = KINETIC_PARTICLE;

	// determines if the particle should be checked for collisions with other objects
	collision_state = PARTICLE_CAN_COLLIDE;
}


// copy constructor
Particle::Particle (const Particle &P)
{
	*this = P;
}


// destructor
Particle::~Particle ()
{
}


// assignment
const Particle& Particle::operator = (const Particle &P)
{
	// starting position of the center of mass
	position = P.position;

	// starting velocity of object
	velocity = P.velocity;

	// starting acceleration of object
	acceleration = P.acceleration;

	// mass of the object
	mass = P.mass;

	// total force acting on the center of mass
	center_mass_force = P.center_mass_force;

	// list of forces acting on the particle
	force_list = P.force_list;

	// constants of the particle
	damping = P.damping;
	restitution = P.restitution;

	// particle state -- default "kinetic"
	state = P.state;

	// determines if the particle should be checked for collisions with other objects
	collision_state = P.collision_state;

	return (*this);
}


// returns the state of the particle
PARTICLE_TYPE Particle::Return_State () const
{
	return (state);
}


// sets what state the particle is in
void Particle::Reset_State (enum PARTICLE_TYPE new_state)
{
	state = new_state;
}


// returns the collision state of the particle
PARTICLE_COLLISION_TYPE Particle::Return_Collision_State ()
{
	return (collision_state);
}


// sets the collision state of the particle
void Particle::Reset_Collision_State (enum PARTICLE_COLLISION_TYPE new_state)
{
	collision_state = new_state;
}


// adds a force to act on the particle
void Particle::Add_Force (const Vector2D &F)
{
	force_list.Push (F);
}


// adds a force to act on the particle
void Particle::Add_Force (float force_x, float force_y)
{
	force_list.Push (Vector2D (force_x, force_y));
}


// changes the nth force
void Particle::Reset_Force_Vector (int n, const Vector2D &F)
{
	force_list[n] = F;
}


// changes the nth force
void Particle::Reset_Force_Vector (int n, float force_x, float force_y)
{
	force_list[n] = Vector2D (force_x, force_y);
}


// removes the nth force
void Particle::Remove_Force (int n)
{
	force_list.Splice (n, 1);
}


// changes the mass of the particle
void Particle::Reset_Mass (float m)
{
	mass = m;
}


// returns the position
Vector2D Particle::Return_Position ()
{
	return (Vector2D (position));
}


// returns the velocity of the particle
Vector2D Particle::Return_Velocity ()
{
	return (Vector2D (velocity));
}


// resets the position of the object
void Particle::Reset_Position (float x, float y)
{
	position.x = x;
	position.y = y;
}


// resets the position of the object
void Particle::Reset_Position (const Vector2D &pos)
{
	position = pos;
}


// resets the velocity of the center of mass
void Particle::Reset_Velocity (float vel_x, float vel_y)
{
	velocity.x = vel_x;
	velocity.y = vel_y;
}


// resets the velocity of the center of mass
void Particle::Reset_Velocity (const Vector2D &vel)
{
	velocity = vel;
}


// calculates the total linear force acting on the center of mass
void Particle::Calculate_Forces ()
{
	// reset the center of mass force to a zero vector
	//center_mass_force.x = 0.0f;
	//center_mass_force.y = 0.0f;

	// sum all the forces acting on the particle
	for (int j = 0; j < force_list.Length (); j++)
	{
		center_mass_force += force_list[j];
	}

	// calculate the damping of the particle
	this->Calculate_Damping ();
}


// calculates the damping on the body
void Particle::Calculate_Damping ()
{
	// take away some force due to damping
	center_mass_force += velocity * (-damping);
}


// calculates the total linear acceleration acting on the center of mass
void Particle::Calculate_Acceleration ()
{
	// calculate the force acting on the center of mass
	this->Calculate_Forces ();

	// calculate the acceleration of the particle
	acceleration.x = center_mass_force.x / mass;
	acceleration.y = center_mass_force.y / mass;
}


// prints the properties of the object
void Particle::Particle_Print (const char* name) const
{
	cout << "---------------------------------" << endl;

	cout << "Particle : " << name << endl;

	position.Vector_Print     ("position    ");
	velocity.Vector_Print     ("velocity    ");
	acceleration.Vector_Print ("acceleration");

	cout << "mass                  = " << mass << endl;
	center_mass_force.Vector_Print ("Center Force");

	switch (state)
	{
		case STATIC_PARTICLE:		cout << "STATIC PARTICLE" << endl;
								break;

		case KINETIC_PARTICLE:		cout << "KINETIC PARTICLE" << endl;
								break;

		default:				break;
	}

	cout << "---------------------------------" << endl;
}


// draw the particle
void Particle::Draw_Particle ()
{
	float size = 0.2f;

	// draw a small square for the particle
	glBegin (GL_QUADS);
	{
		glColor3f (1.0f, 1.0f, 1.0f);
		glVertex3f (position.x - size, position.y - size, 0.0f);
		glVertex3f (position.x + size, position.y - size, 0.0f);
		glVertex3f (position.x + size, position.y + size, 0.0f);
		glVertex3f (position.x - size, position.y + size, 0.0f);
	}
	glEnd ();

	glBegin (GL_POINTS);
	{
		glVertex3f (position.x, position.y, 0.0f);
	}
	glEnd ();
}


// draw the forces acting on the particle
void Particle::Draw_Forces ()
{
	// number of forces acting on the particle
	int num_forces = force_list.Length ();

	// start open gl for drawing lines for the forces
	glBegin (GL_LINES);
	{
		glColor3f (0.1f, 0.8f, 0.3f);

		// loop through the forces and draw the forces
		for (int j = 0; j < num_forces; j++)
		{
			glVertex3f (position.x, position.y, 0.0f);
			glVertex3f (position.x + force_list[j].x, position.y + force_list[j].y, 0.0f);
		}
	}
	glEnd ();
}


// integrates object over a time step
void Particle::Euler_Integrate (float delta_t)
{
	// check if you should integrate or not
	if (state == KINETIC_PARTICLE)
	{
		// change velocity due to acceleration
		velocity += acceleration * delta_t;

		// change the position due to velocity
		position += velocity * delta_t;
	}
	else
	{
		// velocity is zero because the particle is static
		velocity.x = velocity.y = 0.0f;
	}
}






