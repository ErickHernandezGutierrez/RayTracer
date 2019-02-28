#include <iostream>
#include <vector>
#include <ctime>

#include "vector3.hpp"
#include "point3.hpp"
#include "mat4x4.hpp"
#include "ray.hpp"
#include "colour.hpp"
#include "material.hpp"
#include "scene.hpp"
#include "primitive.hpp"
#include "sphere.hpp"
#include "bitmap/bitmap_image.hpp"

using namespace std;

int main(int argc, char** argv){
    point3_t camera_position(0.0f, 0.0f, 5.0f);
    vector3_t forward(0.0f, 0.0f, 1.0f);
    vector3_t up(0.0f, 1.0f, 0.0f);
    vector3_t right(1.0f, 0.0f, 0.0f);
    mat4x4 look_at = mat4x4::createLookAtMatrix(right, up, forward, camera_position);
    
    material_t basic_material(colour_t(0.3f, 0.2f, 0.1f), colour_t(0.3f, 0.3f, 0.3f), 0.7);

    vector<primitive_t*> actors;
    actors.push_back(new sphere_t(basic_material, point3_t(0.0f, 0.0f, 0.0f), 1.0f));

    int width  = 500;
    int height = 500;
    float ratio = 1.0f;
    float fov = 45.0f;
    bitmap_image image(width, height);

    ray_t image_ray, scene_ray;

    colour_t pixel_color;

    scene_t scene(colour_t(0.5f, 0.5f, 0.5f), actors, 3);

    time_t start = clock();

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image_ray = ray_t::createSceneRay(i, j, width, height, ratio, fov);

            scene_ray.origin = look_at * image_ray.origin;
            scene_ray.direction = look_at * image_ray.direction;
            
            pixel_color = scene.trace(scene_ray, 0);
            
            image.set_pixel(j, i, pixel_color.get_rgb());
        }
    }

    time_t finish = clock();
    cout << (finish-start)/(double)(CLOCKS_PER_SEC) << endl;

    image.save_image("image.bmp");

    return 0;
}