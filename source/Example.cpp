

#include <windows.h>											// Header File For Windows
#include <gl\gl.h>												// Header File For The OpenGL32 Library
#include <gl\glu.h>												// Header File For The GLu32 Library
#include <gl\glaux.h>											// Header File For The GLaux Library

#include "NeHeGL.h"

#pragma comment (lib, "opengl32.lib")							// Search For OpenGL32.lib While Linking
#pragma comment (lib, "glu32.lib")								// Search For GLu32.lib While Linking
#pragma comment (lib, "glaux.lib")								// Search For GLaux.lib While Linking

#ifndef CDS_FULLSCREEN											// CDS_FULLSCREEN Is Not Defined By Some
#define CDS_FULLSCREEN 4										// Compilers. By Defining It This Way,
#endif															// We Can Avoid Errors



#include "Physical_Environment2D.h"
#include "Math_Extras.h"
#include "Camera.h"
#include "Vector3D.h"
#include "Keys.h"
#include "Random_Number.h"


GL_Window*	g_window;
Keys*		g_keys;


// User Defined Variables

// dimensions of the grid the simulation takes place in
float grid_dim = 50.0f;

// spacing of the lines in the grid
float grid_space = 2.0f;

// the physical environment the simulation will take place in
Physical_Environment2D world (grid_dim, -grid_dim, grid_dim, -grid_dim);

// the camera to view the environment through
Camera cam (Vector3D (1.0f, 0.0f, 0.0f), Vector3D (0.0f, 1.0f, 0.0f), Vector3D (0.0f, 0.0f, 1.0f), Vector3D (0.0f, 0.0f, 50.0f));

float zoom = -50.0f;
float translate_x = 0.0f;
float translate_y = 0.0f;
float angle_y = 0.0f;
float angle_x = 0.0f;


BOOL Initialize (GL_Window* window, Keys* keys)					// Any GL Init Code & User Initialiazation Goes Here
{
	g_window	= window;
	g_keys		= keys;

	// Start Of User Initialization

	// set the integration step of the world
	world.delta_t = 0.03f;

	// create a rectagular rigid body at the origin
	world.Add_Rectangle_Body (0.0f, 0.0f, 8.0f, 1.0f, 4.0f);

	// make it so that the body can only rotate but not translate
	world.Body_Reset_State (0, KINETIC_STATIC_RIGID_BODY);

	// create two diamond bodies to the sides of the rectangle body
	world.Add_Diamond_Body ( 10.0f, 0.0f, 2.0f, 1.0f);
	world.Add_Diamond_Body (-10.0f, 0.0f, 2.0f, 1.0f);

	// connect the rectangle body to the diamonds with two springs
	world.Add_Spring (0,  3.0f, 0.0f, RIGID_BODY_CONNECTION, 1, -1.5f, 0.0f, RIGID_BODY_CONNECTION, 5.5f, 20.0f, 2.0f);
	world.Add_Spring (0, -3.0f, 0.0f, RIGID_BODY_CONNECTION, 2,  1.5f, 0.0f, RIGID_BODY_CONNECTION, 5.5f, 20.0f, 2.0f);

	// change the acceleration due to gravity in the environment
	world.Change_Outside_Acceleration (0.0f, -2.0f);


	glClearColor (0.0f, 0.0f, 0.0f, 0.5f);						// Black Background
	glClearDepth (1.0f);										// Depth Buffer Setup
	glDepthFunc (GL_LEQUAL);									// The Type Of Depth Testing (Less Or Equal)
	glEnable (GL_DEPTH_TEST);									// Enable Depth Testing
	glShadeModel (GL_SMOOTH);									// Select Smooth Shading
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Set Perspective Calculations To Most Accurate
	BuildFont (window->hDC);

	return TRUE;												// Return TRUE (Initialization Successful)
}


void Deinitialize (void)										// Any User DeInitialization Goes Here
{
	KillFont ();
}


void Update (DWORD milliseconds)								// Perform Motion Updates Here
{
	if (g_keys->keyDown [VK_ESCAPE] == TRUE)
	{
		// Terminate The Program
		TerminateApplication (g_window);
	}

	if (g_keys->keyDown[VK_SPACE] == TRUE)
	{
		// pause / unpause simulation
		world.Toggle_Status ();
	}

	float inc = 0.25f;


	// get the position of the mouse
	POINT mouse;
	GetCursorPos (&mouse);

	// reset the position of the mouse
	SetCursorPos (400, 300);
	ShowCursor (false);

	// get the camera's rotation angles from the position of the mouse
	angle_x += (mouse.x - 400 - angle_x) / 7.0f;
	angle_y += (mouse.y - 300 - angle_y) / 7.0f;

	// get the sine and cosine of the rotation angles
	float sine_x   = sinf (angle_x / 500.0f);
	float cosine_x = cosf (angle_x / 500.0f);
	float sine_y   = sinf (angle_y / 500.0f);
	float cosine_y = cosf (angle_y / 500.0f);

	// move side to side
	if		(g_keys->keyDown[Key::A])	cam.Move_Sideways (-inc);
	else if (g_keys->keyDown[Key::D])	cam.Move_Sideways ( inc);

	// move in the direction the camera is pointing
	if		(g_keys->keyDown[Key::W])	cam.Move_Forwards (-inc);
	else if (g_keys->keyDown[Key::S])	cam.Move_Forwards ( inc);

	// move up and down along the z-axis
	if		(g_keys->keyDown[Key::Z])	cam.Translate_Z (-inc);
	else if (g_keys->keyDown[Key::Q])	cam.Translate_Z ( inc);

	// rotate the camera
	cam.Rotate_Around_Side (sine_y, cosine_y);
	cam.Rotate (sine_x, cosine_x, Vector3D (0.0f, 0.0f, 1.0f));

	// simulate the world
	world.Simulate ();	
}


inline void Draw_Grid (float grid_size, float space)
{
	float z = -0.1f;

	glBegin (GL_LINES);
	{
		glColor3f (0.3f, 0.3f, 0.3f);

		for (float j = -grid_size; j <= grid_size; j += space)
		{
			glVertex3f (-grid_size, j, z);
			glVertex3f ( grid_size, j, z);

			glVertex3f (j, -grid_size, z);
			glVertex3f (j,  grid_size, z);
		}
	}
	glEnd ();
}


void Draw (void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();

	// set the opengl matrix from the orientation and position of the camera
	cam.Set_OpenGL_Matrix ();

	// draw the grid
	Draw_Grid (grid_dim, grid_space);

	// render the environment
	world.Render_Environment (7, 0.2f, false, false);

	glFlush ();
}


