#ifndef PLANE_HPP_INCLUDED
#define PLANE_HPP_INCLUDED

#include <cmath>

#include "primitive.hpp"
#include "vector3.hpp"
#include "point3.hpp"
#include "utils.hpp"

using namespace std;

class plane_t : public primitive_t{
	public:
        vector3_t normal;
		float distance;

		plane_t(){}
		plane_t(material_t material, vector3_t normal, float distance) : primitive_t(material){
			this->normal = normal.normalized();
			this->distance = distance;
		}
		~plane_t(){}

        virtual float raycast(const ray_t& ray){
            point3_t O = ray.origin;
            float DPN = normal.dot(ray.direction);

            if(DPN < 0.0f){
                float t = -(O.dot(normal) + distance) / DPN;

                return t; //intersection
            }

            return -1.0f; //no intersection
        }

        virtual interdata_t interdata(const ray_t& ray, const float& t){
            point3_t  o = ray.origin;
	        vector3_t d = ray.direction;

            point3_t interpoint = o + (d*t);

            return interdata_t(interpoint, normal, material);
        }

        virtual bool shadowIntersect(ray_t shadow_ray){
            return false;
        }
};

#endif // PLANE_HPP_INCLUDED
