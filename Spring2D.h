/* ---------------------------------------------------------------------------
 *
 *		Spring2D class - Michael Brandon Williams
 *
 *		Spring2D.h
 *
 * ---------------------------------------------------------------------------
 */


#ifndef _SPRING2D_H
#define _SPRING2D_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#pragma comment (lib, "glaux.lib")

#include "Particle.h"
#include "Rigid_Body2D.h"
#include "Force2D.h"
#include "Vector2D.h"


// datatypes the spring connects
enum SPRING_CONNECTIONS
{
	PARTICLE_CONNECTION,
	RIGID_BODY_CONNECTION
};



class Spring2D
{
	friend class Physical_Environment2D;

	public:

		// default constructor
		Spring2D ()
		{
			// datatypes the spring connects
			point1_type = PARTICLE_CONNECTION;
			point2_type = PARTICLE_CONNECTION;

			// indexes of the bodies the spring connects
			body1 = body2 = 0;

			// the points on the bodies that the spring connects
			point1 = Vector2D (0.0f, 0.0f);
			point2 = Vector2D (0.0f, 0.0f);

			// resting length of the spring
			resting_length = 0.0f;

			// constants of the spring
			spring_constant = 5.0f;
			spring_damping = 0.1f;
		}

		// constructor for when you have the spring constants
		Spring2D (float ks, float kd)
		{
			// datatypes the spring connects
			point1_type = PARTICLE_CONNECTION;
			point2_type = PARTICLE_CONNECTION;

			// indexes of the bodies the spring connects
			body1 = body2 = 0;

			// the points on the bodies that the spring connects
			point1 = Vector2D (0.0f, 0.0f);
			point2 = Vector2D (0.0f, 0.0f);

			// resting length of the spring
			resting_length = 0.0f;

			// constants of the spring
			spring_constant = ks;
			spring_damping = kd;
		}

		// constructor for when you have the indexes of the body, coordinates of the points on
		// the bodies that the spring connects, and the datatypes of the connections
		Spring2D (int b1, float x1, float y1, SPRING_CONNECTIONS connection1,
				  int b2, float x2, float y2, SPRING_CONNECTIONS connection2)
		{
			// datatypes the spring connects
			point1_type = connection1;
			point2_type = connection2;

			// indexes of the bodies the spring connects
			body1 = b1;
			body2 = b2;

			// the points on the bodies that the spring connects
			point1 = Vector2D (x1, y1);
			point2 = Vector2D (x2, y2);

			// resting length of the spring
			resting_length = 0.0f;

			// constants of the spring
			spring_constant = 5.0f;
			spring_damping = 0.1f;
		}


		// constructor for when you have the indexes of the body, coordinates of the points on
		// the bodies that the spring connects, and the datatypes of the connections
		Spring2D (int b1, const Vector2D &p1, SPRING_CONNECTIONS connection1,
				  int b2, const Vector2D &p2, SPRING_CONNECTIONS connection2)
		{
			// datatypes the spring connects
			point1_type = connection1;
			point2_type = connection2;

			// indexes of the bodies the spring connects
			body1 = b1;
			body2 = b2;

			// the points on the bodies that the spring connects
			point1 = p1;
			point2 = p2;

			// resting length of the spring
			resting_length = 0.0f;

			// constants of the spring
			spring_constant = 5.0f;
			spring_damping = 0.1f;
		}


		// constructor for when you have the indexes of the body, coordinates of the points on
		// the bodies that the spring connects, resting length of the spring, and the datatypes 
		// of the connections
		Spring2D (int b1, float x1, float y1, SPRING_CONNECTIONS connection1,
				  int b2, float x2, float y2, SPRING_CONNECTIONS connection2,
				  float length)
		{
			// datatypes the spring connects
			point1_type = connection1;
			point2_type = connection2;

			// indexes of the bodies the spring connects
			body1 = b1;
			body2 = b2;

			// the points on the bodies that the spring connects
			point1 = Vector2D (x1, y1);
			point2 = Vector2D (x2, y2);

			// resting length of the spring
			resting_length = length;

			// constants of the spring
			spring_constant = 5.0f;
			spring_damping = 0.1f;
		}


		// constructor for when you have the indexes of the body, coordinates of the points on
		// the bodies that the spring connects, resting length of the spring, and the datatypes 
		// of the connections
		Spring2D (int b1, const Vector2D &p1, SPRING_CONNECTIONS connection1,
				  int b2, const Vector2D &p2, SPRING_CONNECTIONS connection2,
				  float length)
		{
			// datatypes the spring connects
			point1_type = connection1;
			point2_type = connection2;

			// indexes of the bodies the spring connects
			body1 = b1;
			body2 = b2;

			// the points on the bodies that the spring connects
			point1 = p1;
			point2 = p2;

			// resting length of the spring
			resting_length = length;

			// constants of the spring
			spring_constant = 5.0f;
			spring_damping = 0.1f;
		}

		// constructor for when you know the resting length of the spring
		Spring2D (float length)
		{
			// datatypes the spring connects
			point1_type = PARTICLE_CONNECTION;
			point2_type = PARTICLE_CONNECTION;

			// indexes of the bodies the spring connects
			body1 = body2 = 0;

			// the points on the bodies that the spring connects
			point1 = Vector2D (0.0f, 0.0f);
			point2 = Vector2D (0.0f, 0.0f);

			// resting length of the spring
			resting_length = length;

			// constants of the spring
			spring_constant = 5.0f;
			spring_damping = 0.1f;
		}

		// constructor for when you know the resting length of the spring and the spring constants
		Spring2D (float length, float ks, float kd)
		{
			// datatypes the spring connects
			point1_type = PARTICLE_CONNECTION;
			point2_type = PARTICLE_CONNECTION;

			// indexes of the bodies the spring connects
			body1 = body2 = 0;

			// the points on the bodies that the spring connects
			point1 = Vector2D (0.0f, 0.0f);
			point2 = Vector2D (0.0f, 0.0f);

			// resting length of the spring
			resting_length = length;

			// constants of the spring
			spring_constant = ks;
			spring_damping = kd;
		}

		// constructor for when you know everything about the spring
		Spring2D (int b1, float x1, float y1, SPRING_CONNECTIONS connection1,
				  int b2, float x2, float y2, SPRING_CONNECTIONS connection2,
				  float length, float ks, float kd)
		{
			// datatypes the spring connects
			point1_type = connection1;
			point2_type = connection2;

			// indexes of the bodies the spring connects
			body1 = b1;
			body2 = b2;

			// the points on the bodies that the spring connects
			point1 = Vector2D (x1, y1);
			point2 = Vector2D (x2, y2);

			// resting length of the spring
			resting_length = length;

			// constants of the spring
			spring_constant = ks;
			spring_damping = kd;
		}

		// constructor for when you know everything about the spring
		Spring2D (int b1, const Vector2D &p1, SPRING_CONNECTIONS connection1,
				  int b2, const Vector2D &p2, SPRING_CONNECTIONS connection2,
				  float length, float ks, float kd)
		{
			// datatypes the spring connects
			point1_type = connection1;
			point2_type = connection2;

			// indexes of the bodies the spring connects
			body1 = b1;
			body2 = b2;

			// the points on the bodies that the spring connects
			point1 = p1;
			point2 = p2;

			// resting length of the spring
			resting_length = length;

			// constants of the spring
			spring_constant = ks;
			spring_damping = kd;
		}

		// destructor
		~Spring2D ()
		{
		}

		// resets the index of the bodies the spring connects
		void Reset_Body1 (int b1)
		{
			body1 = b1;
		}

		// resets the index of the bodies the spring connects
		void Reset_Body2 (int b2)
		{
			body2 = b2;
		}

		// resets the position of the point the spring connects to in the first body
		void Reset_Point_Body1 (float x, float y)
		{
			point1.x = x;
			point1.y = y;
		}

		// resets the position of the point the spring connects to in the first body
		void Reset_Point_Body1 (const Vector2D &p)
		{
			point1 = p;
		}

		// resets the position of the point the spring connects to in the first body
		void Reset_Point_Body2 (float x, float y)
		{
			point2.x = x;
			point2.y = y;
		}

		// resets the position of the point the spring connects to in the first body
		void Reset_Point_Body2 (const Vector2D &p)
		{
			point2 = p;
		}

		// resets the type of datatype the spring connects
		void Reset_Connection1 (SPRING_CONNECTIONS c1)
		{
			point1_type = c1;
		}

		// resets the type of datatype the spring connects
		void Reset_Connection2 (SPRING_CONNECTIONS c2)
		{
			point2_type = c2;
		}

		// resets the resting length of the spring
		void Reset_Length (float length)
		{
			resting_length = length;
		}

		// resets the spring constant
		void Reset_Spring_Constant (float ks)
		{
			spring_constant = ks;
		}

		// resets the spring damping
		void Reset_Spring_Damping (float kd)
		{
			spring_damping = kd;
		}

		// returns the force exerted by the spring
		Vector2D Calculate_Spring_Force (float x1, float y1, float vel_x1, float vel_y1, float x2, float y2, float vel_x2, float vel_y2)
		{
			// vector difference in position and velocity
			Vector2D delta_position ((x1 - x2), (y1 - y2));
			Vector2D delta_velocity ((vel_x1 - vel_x2), (vel_y1 - vel_y2));

			// distance between the two points
			float distance = ! delta_position;

			// terms in the spring equation
			float term1 = (distance - resting_length) * spring_constant;
			float term2 = ((delta_velocity % delta_position) * spring_damping) / distance;

			// force exerted by the spring
			Vector2D force (delta_position * (1.0f / distance));
			force *= -(term1 + term2);

			// return the spring force
			return (force);
		}

		// returns the force exerted by the spring
		Vector2D Calculate_Spring_Force (const Vector2D &p1, const Vector2D &v1, const Vector2D &p2, const Vector2D &v2)
		{
			// vector difference in position and velocity
			Vector2D delta_position (p1 - p2);
			Vector2D delta_velocity (v1 - v2);

			// distance between the two points
			float distance = ! delta_position;

			// terms in the spring equation
			float term1 = (distance - resting_length) * spring_constant;
			float term2 = ((delta_velocity % delta_position) * spring_damping) / distance;

			// force exerted by the spring
			Vector2D force (delta_position * (1.0f / distance));
			force *= -(term1 + term2);

			// return the spring force
			return (force);
		}


/*

			// spring connects two particles together

			// vector difference in position and velocity
			delta_position = particle_list[b1].Return_Vertex_Position (v1) - particle_list[b2].Return_Vertex_Position (v2);
			delta_velocity = particle_list[b1].Return_Vertex_Velocity (v1) - particle_list[b2].Return_Vertex_Velocity (v2);

			// distance between the two objects
			distance = ! delta_position;

			// first and second term in the spring equation
			term1 = (distance - spring_list[j].resting_length) * spring_list[j].spring_constant;
			term2 = (delta_velocity % delta_position * spring_list[j].spring_damping) / distance;

			// force exerted by the spring
			force = delta_position * (1.0f / distance);
			force *= -(term1 + term2);

			// force acting on the two objects by the spring
			particle_list[b1].center_mass_force += force;
			particle_list[b2].center_mass_force -= force;

*/

		// draw the spring
		void Draw_Spring (int num_turns, float turn_mag, float x1, float y1, float x2, float y2)
		{
			// distance between points
			float distance = sqrtf ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

			// increment down the spring to step
			float increment = distance / float (num_turns);

			// components of normal unit vector to direction vector
			float norm_x = -(y2 - y1) / distance;
			float norm_y =  (x2 - x1) / distance;

			// determing which way the spring turns at a certain interval
			float dir;
			
			// position of point on the spring
			float x, y;
			
			// the parameter of a parametric line from (x1,y1) to (x2,y2)
			float t;
			
			// last position of a point on the spring
			float ox = x1, oy = y1;

			// start open gl to draw lines that make the spring
			glBegin (GL_LINES);
			{
				glColor3f (0.5f, 1.0f, 0.5f);

				// loop through each turn and draw spring structure
				for (int j = 1; j <= num_turns; j++)
				{
					// determine what direction of the line you should turn
					dir = float (pow (-1, j));

					// determine where along the line from (x1,y1) to (x2,y2) we are
					t = float (j) / float (num_turns);

					// calculate the position of the point on the spring
					x = x1 + (x2 - x1) * t + norm_x * dir * turn_mag;
					y = y1 + (y2 - y1) * t + norm_y * dir * turn_mag;

					glVertex3f (ox, oy, 0.0f);

					if (j == num_turns)
					{
						glVertex3f (x2, y2, 0.0f);
					}
					else
					{
						glVertex3f (x, y, 0.0f);
					}

					// last position on the spring
					ox = x;
					oy = y;
				}
			}
			glEnd ();
		}

	private:

		// datatypes the spring connects
		SPRING_CONNECTIONS point1_type;
		SPRING_CONNECTIONS point2_type;

		// indexes of the bodies that the spring connects
		int body1, body2;

		// points on the bodies that the spring connects
		Vector2D point1, point2;

		// resting length of the spring
		float resting_length;

		// spring constants
		float spring_constant, spring_damping;
};


#endif



