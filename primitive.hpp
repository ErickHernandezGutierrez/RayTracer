#ifndef PRIMITIVE_HPP_INCLUDED
#define PRIMITIVE_HPP_INCLUDED

#include "material.hpp"
#include "ray.hpp"

class primitive_t{
    protected:
        material_t material;

    public:
        primitive_t(){}
        primitive_t(const material_t& material){
            this->material = material;
        }
        ~primitive_t(){}

        void setMaterial(const material_t& material){
            this->material = material;
        }

        material_t getMaterial(){
            return this->material;
        }

        virtual bool intersect(const ray_t& ray) = 0;
        virtual bool shadowIntersect(const ray_t& shadow_ray) = 0; 
};

#endif // PRIMITIVE_HPP_INCLUDED