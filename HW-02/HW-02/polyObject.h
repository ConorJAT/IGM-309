// Course:  IGME 309
// Student Name:  Conor Race
// Assignment Number:  02

#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/constants.hpp>

using namespace glm;
using namespace std;

class polyObject
{
	private:
		vector<vec2> vertices;			// All vertices in C++ vector.
		vec3 color;						// Color of polygon.

	public:
		polyObject();
		~polyObject();

		void addVertex(vec2 p_vert);	// Add vertex at end of vertex list.
		void setColor(vec3 p_color);	// Set the color of polygon.
		unsigned int getVertNum();		// Return number of vertices.
		void draw();					// Draw polygon (if completed).
		void draw(vec2 p_mousePos);		// Draw polygon (if being created).

		// Helper Function:
		void restart();					// Clears all verticies of the shape.
};