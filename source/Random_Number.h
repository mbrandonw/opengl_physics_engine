/* ---------------------------------------------------------------------------
 *
 *		Random_Number class - Michael Brandon Williams
 *
 *		Random_Number.h
 *
 * ---------------------------------------------------------------------------
 */

#ifndef _RANDOM_NUMBER_H
#define _RANDOM_NUMBER_H


#include <time.h>
#include <stdlib.h>


class Random_Number  
{
	public:

		Random_Number()
		{
			time_t seconds;
			time (&seconds);
			srand ((unsigned int) seconds);
		}

		virtual ~Random_Number() {}

		int Random (const int min, const int max)
		{
			return (rand () % (max - min) + min);
		}

		float Random (const float min, const float max)
		{
			return (fmodf (float (rand ()), (max - min)) + min);
		}

		double Random (const double min, const double max)
		{
			return (fmod (double (rand ()), (max - min)) + min);
		}

		int operator () () const
		{
			return (rand ());
		}

	private:

		time_t seconds;
};

#endif

