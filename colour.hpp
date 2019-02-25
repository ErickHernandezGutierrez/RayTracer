#ifndef COLOUR_HPP_INCLUDED
#define COLOUR_HPP_INCLUDED

#include <math.h>

const float EPS = 1e-6;

using namespace std;

class colour_t{
	public:
		float r, g, b;

		colour_t(){}
		constexpr colour_t(const float& x, const float& y, const float& z){
			this->r = r;
			this->g = g;
			this->b = b;
		}
		~colour_t(){}

		colour_t operator+(colour_t color){
			return colour_t(this->r + color.r, this->g + color.g, this->b + color.b);
		}

		colour_t operator-(colour_t vector){
			return colour_t(this->r - color.r, this->g - color.g, this->b - color.b);
		}

		colour_t operator*(float scalar){
			return colour_t(this->r * scalar, this->g * scalar, this->b * scalar);
		}

		bool operator==(colour_t vector){
			return fabsf(this->r - color.r) < EPS && fabsf(this->g - color.g) < EPS && fabsf(this->b - color.b) < EPS;
		}

		void operator+=(colour_t color){
			this->r += color.r;
			this->g += color.g;
			this->b += color.b;
		}

		void operator-=(colour_t vector){
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
