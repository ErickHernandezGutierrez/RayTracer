#ifndef MATERIAL_HPP_INCLUDED
#define MATERIAL_HPP_INCLUDED

#include "colour.hpp"

class material_t{
    public:
        colour kd;
        colour ks;
        float sh;

        material_t(){}
        material_t(colour kd, colour ks, float sh){
            this->kd = kd;
            this->ks = ks;
            this->sh = sh;
        }
        ~material_t(){}
};

#endif // MATERIAL_HPP_INCLUDED