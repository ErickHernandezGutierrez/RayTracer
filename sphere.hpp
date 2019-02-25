#ifndef SPHERE_HPP_INCLUDED
#define SPHERE_HPP_INCLUDED

#include <math.h>

#include "primitive.hpp"
#include "material.hpp"
#include "ray.hpp"

using namespace std;

class sphere_t : public primitive_t{
    private:
        vec3 center;
        float radius, radiusSquared, radiusInversed;

    public:
        sphere_t(){}
        sphere_t(const material_t& material, const vec3& center, float radius) : primitive_t(material) {
            this->center = center;
            this->radius = radius;
            this->radiusSquared  = radius*radius;
            this->radiusInversed = 1.0f / radius;
        }
        ~sphere_t(){}

        void setCenter(const vec3& center){
            this->center = center;
        }

        void setRadius(const float& radius){
            this->radius = radius;
            this->radiusSquared  = radius*radius;
            this->radiusInversed = 1.0f / radius;
        }

        vec3 getCenter(){
            return this->center;
        }

        float getRadius(){
            return this->radius;
        }

        float getRadiusSquared(){
            return this->radiusSquared;
        }

        float getRadiusInversed(){
            return this->radiusInversed;
        }

        virtual bool intersect(const ray_t& ray){
            return false;
        }
        virtual bool shadowIntersect(const ray_t& shadow_ray){
            return false;
        }
};

#endif // PRIMITIVE_HPP_INCLUDED