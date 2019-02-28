#ifndef POINT3_HPP_INCLUDED
#define POINT3_HPP_INCLUDED

#include <math.h>
#include "utils.hpp"
#include "vector3.hpp"

using namespace std;

class point3_t{
	public:
		float x, y, z;

		point3_t(){}
		point3_t(float x, float y, float z){
			this->x = x;
			this->y = y;
			this->z = z;
		}
		~point3_t(){}

		/*point3_t operator+(const point3_t& vector){
			return point3_t(this->x + vector.x, this->y + vector.y, this->z + vector.z);
		}//*/

		vector3_t operator-(point3_t point){
			return vector3_t(this->x - point.x, this->y - point.y, this->z - point.z);
		}
};

#endif // POINT3_HPP_INCLUDED
