#ifndef RAY_HPP_INCLUDED
#define RAY_HPP_INCLUDED

#include <math.h>

#include "point3.hpp"
#include "vector3.hpp"

class ray_t{
	public:
		point3_t origin;
		vector3_t direction;

		ray_t(){}
		ray_t(point3_t origin, vector3_t direction){
			this->origin = origin;
			this->direction = direction;
		}
		~ray_t(){}

		static ray_t createSceneRay(int pixel_posy, int pixel_posx, int image_width, int image_height, float ratio, float fov){
			float px = (2.0 * ((pixel_posx + 0.5) / image_width) - 1.0) * tan(fov / 2.0f * PI / 180.0f) * ratio;
			float py = (1.0 - 2.0 * ((pixel_posy + 0.5)/image_height)) * tan(fov / 2.0f * PI / 180.0f);

			point3_t  origin(0.0f, 0.0f, 0.0f);
			vector3_t direction(px, py, -1.0f);
			direction.normalize();

			return ray_t(origin, direction);
		}
};

#endif // RAY_HPP_INCLUDED
