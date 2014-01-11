/* ---------------------------------------------------------------------------
 *
 *		Camera class - Michael Brandon Williams
 *
 *		Camera.h
 *
 * ---------------------------------------------------------------------------
 */

#ifndef _CAMERA_H
#define _CAMERA_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#pragma comment (lib, "glaux.lib")

#include <math.h>

#include "Vector3D.h"
#include "Matrix3x3.h"


class Camera  
{
	public:

		// default constructor
		Camera ()
		{
			side = base_side = Vector3D (1.0f, 0.0f, 0.0f);
			up = base_up = Vector3D (0.0f, 1.0f, 0.0f);
			out = base_out = Vector3D (0.0f, 0.0f, 1.0f);
			position = Vector3D (0.0f, 0.0f, 0.0f);
		}

		// constructor for when you know the position of the camera
		Camera (const Vector3D &P)
		{
			side = base_side = Vector3D (1.0f, 0.0f, 0.0f);
			up = base_up = Vector3D (0.0f, 1.0f, 0.0f);
			out = base_out = Vector3D (0.0f, 0.0f, 1.0f);
			position = P;
		}

		// constructor for when you know the basis of the camera
		Camera (const Vector3D &X, const Vector3D &Y, const Vector3D &Z)
		{
			side = base_side = X.Unit_Vector ();
			up = base_up = Y.Unit_Vector ();
			out = base_out = Z.Unit_Vector ();
			position = Vector3D (0.0f, 0.0f, 0.0f);
		}

		// constructor for when you know the basis and position of the camera
		Camera (const Vector3D &X, const Vector3D &Y, const Vector3D &Z, const Vector3D &P)
		{
			side = base_side = X.Unit_Vector ();
			up = base_up = Y.Unit_Vector ();
			out = base_out = Z.Unit_Vector ();
			position = P;
		}

		// destructor
		virtual ~Camera ()
		{
		}

		// sets the position of the camera
		void Set_Position (const Vector3D &P)
		{
			position = P;
		}

		// sets the x-position of the camera
		void Set_Position_X (float x)
		{
			position.x = x;
		}

		// sets the y-position of the camera
		void Set_Position_Y (float y)
		{
			position.y = y;
		}

		// sets the z-position of the camera
		void Set_Position_Z (float z)
		{
			position.z = z;
		}

		// translates the camera by the vector T
		void Translate (const Vector3D &T)
		{
			position += T;
		}

		// translates the camera along the x-axis by t
		void Translate_X (float t)
		{
			position.x += t;
		}

		// translates the camera along the y-axis by t
		void Translate_Y (float t)
		{
			position.y += t;
		}

		// translates the camera along the z-axis by t
		void Translate_Z (float t)
		{
			position.z += t;
		}

		// moves the camera in the direction of the "side" vector
		void Move_Sideways (float t)
		{
			position += side * t;
		}

		// moves the camera in the direction of the "up" vector
		void Move_Upwards (float t)
		{
			position += up * t;
		}

		// moves the camera in the direction of the "out" vector
		void Move_Forwards (float t)
		{
			position += out * t;
		}

		// side up out

		// rotates the "up" and "out" vectors about the "side" vector
		void Rotate_Around_Side (float sine, float cosine)
		{
			up  =  up.Rotate (sine, cosine, side);
			out = out.Rotate (sine, cosine, side);
		}

		// rotates the "side" and "out" vectors about the "up" vector
		void Rotate_Around_Up (float sine, float cosine)
		{
			side = side.Rotate (sine, cosine, up);
			out  =  out.Rotate (sine, cosine, up);
		}

		// rotates the "side" and "up" vectors about the "out" vector
		void Rotate_Around_Out (float sine, float cosine)
		{
			side = side.Rotate (sine, cosine, out);
			up   =   up.Rotate (sine, cosine, out);
		}

		// rotates the camera around the axis passed
		void Rotate (float sine, float cosine, const Vector3D &A)
		{
			side = side.Rotate (sine, cosine, A);
			up   =   up.Rotate (sine, cosine, A);
			out  =  out.Rotate (sine, cosine, A);
		}

		// sets the Open GL matrix for this camera
		void Set_OpenGL_Matrix ()
		{
			// clear the current matrix
			glLoadIdentity ();

			float *m;

			m = new GLfloat[16];

			m[0] = side.x;	m[4] = side.y;	m[8] = side.z;	m[12] = 0.0f;
			m[1] = up.x;	m[5] = up.y;	m[9] = up.z;	m[13] = 0.0f;
			m[2] = out.x;	m[6] = out.y;	m[10] = out.z;	m[14] = 0.0f;
			m[3] = 0.0f;	m[7] = 0.0f;	m[11] = 0.0f;	m[15] = 1.0f;

			glLoadMatrixf (m);

			glTranslatef (-position.x, -position.y, -position.z);

			delete [] m;
		}

	private:

		// the basis vectors of the camera (side, up, out)
		Vector3D side, up, out;

		// the base vectors that you will rotate from in the "Set_Rotation..." methods
		Vector3D base_side, base_up, base_out;

		// the position of the camera
		Vector3D position;
};

#endif

