#ifndef VEC3_HPP_INCLUDED
#define VEC3_HPP_INCLUDED

#include <math.h>

const float EPS = 1e-6;
const float PI  = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;

using namespace std;

class vec3{
	public:
		float x, y, z;

		vec3(){}
		vec3(float x, float y, float z){
			this->x = x;
			this->y = y;
			this->z = z;
		}
		~vec3(){}

		vec3 operator+(vec3 vector){
			return vec3(this->x + vector.x, this->y + vector.y, this->z + vector.z);
		}

		vec3 operator-(vec3 vector){
			return vec3(this->x - vector.x, this->y - vector.y, this->z - vector.z);
		}

		vec3 operator*(float scalar){
			return vec3(this->x * scalar, this->y * scalar, this->z * scalar);
		}

		bool operator==(vec3 vector){
			return fabsf(this->x - vector.x) < EPS && fabsf(this->y - vector.y) < EPS && fabsf(this->z - vector.z) < EPS;
		}

		float dot(vec3 vector){
			return this->x*vector.x + this->y*vector.y + this->z*vector.z;
		}

		vec3 cross(vec3 vector){
			return vec3(this->y*vector.z - this->z*vector.y, this->z*vector.x - this->x*vector.z, this->x*vector.y - this->y*vector.x);
		}

		float norm2() {
			return this->x*this->x + this->y*this->y + this->z*this->z;
		}

		float norm(){
			return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
		}

		void normalize(){
			float aux = this->x*this->x + this->y*this->y + this->z*this->z;

			if(aux != 0.0 && aux != 1.0)
				aux = 1.0 / sqrt(aux);

			this->x *= aux;
			this->y *= aux;
			this->z *= aux;
		}
};

#endif // VEC3_HPP_INCLUDED
