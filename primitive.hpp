#ifndef PRIMITIVE_HPP_INCLUDED
#define PRIMITIVE_HPP_INCLUDED

#include "material.hpp"
#include "ray.hpp"

class primitive_t{
    public:
        material_t material;

        primitive_t(){}
        primitive_t(material_t material){
            this->material = material;
        }
        ~primitive_t(){}

        virtual bool intersect(ray_t ray) = 0;
        virtual bool shadowIntersect(ray_t shadow_ray) = 0;
};

#endif // PRIMITIVE_HPP_INCLUDED