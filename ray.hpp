#ifndef RAY_HPP_INCLUDED
#define RAY_HPP_INCLUDED

#include "vec3.hpp"

class ray{
	public:
		vec3 origin;
		vec3 direction;

		ray(){}
		constexpr ray(vec3 origin, vec3 direction){
			this->origin = origin;
			this->direction = direction;
		}
		~ray(){}
};

#endif // RAY_HPP_INCLUDED
