#ifndef INTERDATA_HPP_INCLUDED
#define INTERDATA_HPP_INCLUDED

#include "colour.hpp"
#include "vector3.hpp"
#include "point3.hpp"
#include "material.hpp"

class interdata_t{
    public:
        point3_t interpoint;
        vector3_t normal;
        material_t material;
        float u, v;

        interdata_t(){}
        interdata_t(point3_t interpoint, vector3_t normal, material_t material){
            this->interpoint = interpoint;
            this->normal = normal;
            this->material = material;
        }
        ~interdata_t(){}
};

#endif // INTERDATA_HPP_INCLUDED