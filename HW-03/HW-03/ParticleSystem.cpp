// Course:  IGME 309
// Student Name:  Conor Race
// Assignment Number:  03

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "ParticleSystem.h"
#include <iostream>

ParticleSystem::ParticleSystem(int _numParticles)
{
	numParticles = _numParticles;	// Set the number of particles

	// Allocate memory for positions, velocities, colors, and lifetimes.
	positions = new float[numParticles * 3];
	velocities = new float[numParticles * 3];
	colors = new float[numParticles * 4];
	lifeTimes = new float[numParticles];

	for (int i = 0; i < numParticles; i++) {
		// Initialize the life times
		lifeTimes[i] = maxLifeTime - maxLifeTime * i / numParticles;

		/***************************/
		// Write your code below
		// Please add initializations for other arrays as you see appropriate.
		
		// Set initial positions for each point.
		positions[3 * i] = 0.0;			// X
		positions[3 * i + 1] = 0.0;		// Y
		positions[3 * i + 2] = 0.0;		// Z

		// Set initial velocities for each point.
		velocities[3 * i] = getRandomValue(minSpeedX, maxSpeedX);		// X
		velocities[3 * i + 1] = getRandomValue(minSpeedY, maxSpeedY);	// Y
		velocities[3 * i + 2] = getRandomValue(minSpeedZ, maxSpeedZ);	// Z

		// Set color for each point.
		colors[4 * i] = 0.88f;			// Red value
		colors[4 * i + 1] = 0.44f;		// Green value
		colors[4 * i + 2] = 0.04f;		// Blue value
		colors[4 * i + 3] = 1.0f;		// Alpha value
		/***************************/
	}
}

void ParticleSystem::update(float deltaTime)
{
	for (int i = 0; i < numParticles; i++) {
		/***************************/
		// Write your code below
		// Update lifetime, velocity, position, and color.
		// Reset particle states (positions, velocities, colors, and lifetimes) when the lifetime reaches the maxLifeTime

		// Apply Acceleration (Gravity)
		velocities[3 * i + 1] += (acceleration[1] * deltaTime);

		// Apply Velocity
		positions[3 * i] += (velocities[3 * i] * deltaTime);
		positions[3 * i + 1] +=	(velocities[3 * i + 1] * deltaTime);
		positions[3 * i + 2] +=	(velocities[3 * i + 2] * deltaTime);

		// Subtract from Lifetime
		lifeTimes[i] += deltaTime;

		// Change point's alpha value
		float percentLife = 1.0 - (lifeTimes[i] / maxLifeTime);
		colors[4 * i + 3] = percentLife;

		// Reset Point (if at end of life)
		if (lifeTimes[i] >= maxLifeTime) {
			lifeTimes[i] = 0.0;
			
			positions[3 * i] = 0.0;
			positions[3 * i + 1] = 0.0;
			positions[3 * i + 2] = 0.0;

			velocities[3 * i] = getRandomValue(minSpeedX, maxSpeedX);
			velocities[3 * i + 1] = getRandomValue(minSpeedY, maxSpeedY);
			velocities[3 * i + 2] = getRandomValue(minSpeedZ, maxSpeedZ);

			colors[4 * i + 3] = 1.0;
		}
		// Write your code above
		/***************************/
	}
}

void ParticleSystem::draw()
{
	/***************************/
	// Write your code below
	// Use GL_POINTS for rendering
	glPointSize(5.0);
	glBegin(GL_POINTS);

	for (int i = 0; i < numParticles; i++) {
		
		glColor4f(colors[4 * i], colors[4 * i + 1], colors[4 * i + 2], colors[4 * i + 3]);

		glVertex3f(positions[3 * i], positions[3 * i + 1], positions[3 * i + 2]);
	}

	glEnd();
	// Write your code above
	/***************************/
}

float ParticleSystem::getRandomValue(float min_value, float max_value)
{
	return min_value + (std::rand()) / (RAND_MAX / (max_value - min_value));;
}