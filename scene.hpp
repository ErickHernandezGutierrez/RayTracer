#ifndef SCENE_HPP_INCLUDED
#define SCENE_HPP_INCLUDED

#include <vector>

#include "colour.hpp"
#include "primitive.hpp"

using namespace std;

class scene_t{
	public:
		colour_t ambient_color;
		vector<primitive_t*> primitives;
        int max_depth;

		scene_t(){}
		scene_t(colour_t ambient_color, vector<primitive_t*> primitives, int max_depth){
			this->ambient_color = ambient_color;
            this->primitives = primitives;
            this->max_depth = max_depth;
		}
		~scene_t(){
            for(int i = 0; i < primitives.size(); i++)
                delete primitives[i];
        }

		colour_t trace(ray_t ray, int current_depth){
            colour_t pixel_color(0.0f, 0.0f, 0.0f);
            float distance = MAX_DISTANCE;
            primitive_t* nearest_primitive = 0;

            for(int i = 0; i < primitives.size(); i++){
                primitive_t* current_primitive = primitives[i];

                if(current_primitive->intersect(ray))
                    return colour_t(0.0f, 1.0f, 0.0f);
            }

            return colour_t(0.0f, 0.0f, 0.0f);
        }
};

#endif // SCENE_HPP_INCLUDED
