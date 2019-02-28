#ifndef COLOUR_HPP_INCLUDED
#define COLOUR_HPP_INCLUDED

#include <math.h>

#include "utils.hpp"
#include "bitmap/bitmap_image.hpp"

using namespace std;

class colour_t{
	public:
		float r, g, b;

		colour_t(){}
		colour_t(float r, float g, float b){
			this->r = r;
			this->g = g;
			this->b = b;
		}
		~colour_t(){}

		colour_t operator+(colour_t color){
			return colour_t(this->r + color.r, this->g + color.g, this->b + color.b);
		}

		colour_t operator-(colour_t color){
			return colour_t(this->r - color.r, this->g - color.g, this->b - color.b);
		}

		colour_t operator*(float scalar){
			return colour_t(this->r * scalar, this->g * scalar, this->b * scalar);
		}

		bool operator==(colour_t color){
			return fabsf(this->r - color.r) < EPS && fabsf(this->g - color.g) < EPS && fabsf(this->b - color.b) < EPS;
		}

		void operator+=(colour_t color){
			this->r += color.r;
			this->g += color.g;
			this->b += color.b;
		}

		void operator-=(colour_t color){
			this->r -= color.r;
			this->g -= color.g;
			this->b -= color.b;
		}

		void operator*=(float scalar){
			this->r *= scalar;
			this->g *= scalar;
			this->b *= scalar;
		}

		int getRGB(){
			int R = (int)(255.0f * fminf(1.0f, fmaxf(0.0f, r)));
			int G = (int)(255.0f * fminf(1.0f, fmaxf(0.0f, g)));
			int B = (int)(255.0f * fminf(1.0f, fmaxf(0.0f, b)));

			return ( (R<<16) | (G<<8) | B );
		}

		rgb_t get_rgb(){
			rgb_t rgb;

			rgb.red = (unsigned char)(255.0f * fminf(1.0f, fmaxf(0.0f, r)));
			rgb.green = (unsigned char)(255.0f * fminf(1.0f, fmaxf(0.0f, g)));
			rgb.blue = (unsigned char)(255.0f * fminf(1.0f, fmaxf(0.0f, b)));

			return rgb;
		}
};

#endif // COLOUR_HPP_INCLUDED
