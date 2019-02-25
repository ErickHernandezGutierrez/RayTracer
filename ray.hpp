#ifndef RAY_HPP_INCLUDED
#define RAY_HPP_INCLUDED

#include "vec3.hpp"

class ray_t{
	public:
		vec3 origin;
		vec3 direction;

		ray_t(){}
		ray_t(const vec3& origin, const vec3& direction){
			this->origin = origin;
			this->direction = direction;
		}
		~ray_t(){}
};

#endif // RAY_HPP_INCLUDED
