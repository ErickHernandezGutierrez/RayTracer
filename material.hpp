#ifndef MATERIAL_HPP_INCLUDED
#define MATERIAL_HPP_INCLUDED

#include "colour.hpp"

class material{
    public:
        colour kd;
        colour ks;
        float sh;

        material(){}
        material(colour kd, colour ks, float sh){
            this->kd = kd;
            this->ks = ks;
            this->sh = sh;
        }
        ~material(){}
};

#endif // MATERIAL_HPP_INCLUDED