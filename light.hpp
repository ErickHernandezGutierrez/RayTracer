#ifndef LIGHT_HPP_INCLUDED
#define LIGHT_HPP_INCLUDED

#include "colour.hpp"
#include "vector3.hpp"
#include "point3.hpp"

class light_t{
    public:
        colour_t color;
        point3_t position;
        float intensity;
        colour_t irradiance;

        light_t(){}
        light_t(colour_t color, point3_t position, float intensity){
            this->color = color;
            this->position = position;
            this->intensity = intensity;
            this->irradiance = color * intensity;
        }
        ~light_t(){}
};

#endif // LIGHT_HPP_INCLUDED