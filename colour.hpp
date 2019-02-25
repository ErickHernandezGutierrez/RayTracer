#ifndef COLOUR_HPP_INCLUDED
#define COLOUR_HPP_INCLUDED

#include <math.h>

const float EPS = 1e-6;

using namespace std;

class colour{
	public:
		float r, g, b;

		colour(){}
		constexpr colour(float x, float y, float z){
			this->r = r;
			this->g = g;
			this->b = b;
		}
		~colour(){}

		constexpr colour operator+(colour color){
			return colour(this->r + color.r, this->g + color.g, this->b + color.b);
		}

		constexpr colour operator-(colour vector){
			return colour(this->r - color.r, this->g - color.g, this->b - color.b);
		}

		constexpr colour operator*(float scalar){
			return colour(this->r * scalar, this->g * scalar, this->b * scalar);
		}

		bool operator==(colour vector){
			return fabsf(this->r - color.r) < EPS && fabsf(this->g - color.g) < EPS && fabsf(this->b - color.b) < EPS;
		}

		void operator+=(colour color){
			this->r += color.r;
			this->g += color.g;
			this->b += color.b;
		}

		void operator-=(colour vector){
			this->r -= color.r;
			this->g -= color.g;
			this->b -= color.b;
		}

		void operator*=(float scalar){
			this->r *= scalar;
			this->g *= scalar;
			this->b *= scalar;
		}
};

#endif // COLOUR_HPP_INCLUDED
