/* ---------------------------------------------------------------------------
 *
 *		Shape class - Michael Brandon Williams
 *
 *		Shape.h
 *
 * ---------------------------------------------------------------------------
 */

#ifndef _SHAPE_H
#define _SHAPE_H


#include "Vector2D.h"
#include "Array.h"

class Shape2D  
{
	public:

		// default constructor
		Shape2D ();

		// constructor for when you know the number of vertices
		// in your shape
		Shape2D (int num_vertices)
		{
			vertices.Resize (num_vertices);
		}

		// copy constructor
		Shape2D (const Shape2D &S)
		{
			*this = S;
		}

		// destructor
		virtual ~Shape2D ();

		// assignment
		const Shape2D& operator = (const Shape2D &S)
		{
			vertices = S.vertices;
		}

		// sets the nth vertex
		void Set_Vertex (int n, float x, float y)
		{
			vertices[n] = Vector2D (x, y);
		}

		// removes vertices "n" through "n + num"
		void Remove_Vertices (int n, int num)
		{
			vertices.Splice (n, num);
		}

		// removes the nth vertex
		void Remove_Vertex (int n)
		{
			vertices.Splice (n, 1);
		}

	private:

		// position of vertices
		Array<Vector2D> vertices;
};

#endif

