#ifndef SPHERE_HPP_INCLUDED
#define SPHERE_HPP_INCLUDED

#include <math.h>

#include "primitive.hpp"
#include "material.hpp"
#include "vector3.hpp"
#include "point3.hpp"
#include "ray.hpp"

using namespace std;

class sphere_t : public primitive_t{
    public:
        point3_t center;
        float radius, radiusSquared, radiusInversed;

        sphere_t(){}
        sphere_t(material_t material, point3_t center, float radius) : primitive_t(material) {
            this->center = center;
            this->radius = radius;
            this->radiusSquared  = radius*radius;
            this->radiusInversed = 1.0f / radius;
        }
        ~sphere_t(){}

        virtual bool intersect(ray_t ray){
            point3_t  o = ray.origin;
	        vector3_t d = ray.direction;

	        vector3_t l = center - o;
	        float s = l.dot(d);
	        float ll = l.dot(l);

	        if(s < 0.0f && ll > radiusSquared){
                //data.setIntersected(false);
                return false;
	        }

	        float mm = ll - s*s;

	        if(mm > radiusSquared){
                //data.setIntersected(false);
                return false;
	        }

	        float q = sqrt(radiusSquared - mm);
	        float t = ll > radiusSquared ? s-q : s+q;

            /*data.setIntersected(true);
            data.setPoint(o.add(d.multiply(t)));
            Vector sphereNormal = (data.getPoint()).subtract(center).multiply(-1.0);
            sphereNormal.normalize();
            data.setNormal(sphereNormal);
            data.setDistance(t);
            data.setMaterial(material);
        
            double phi = Math.atan2(sphereNormal.getY(), sphereNormal.getX());
	        if(phi < 0.0)
                phi = phi + 2.0*Math.PI;
	        double theta = Math.acos(sphereNormal.getZ());
        
            data.setU(phi/(2.0*Math.PI));
	        data.setV((Math.PI - theta)/Math.PI);
        
            return data; //*/
            
            return true;
        }

        virtual bool shadowIntersect(ray_t shadow_ray){
            return false;
        }
};

#endif // SPHERE_HPP_INCLUDED