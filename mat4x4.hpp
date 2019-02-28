#ifndef MAT4X4_HPP_INCLUDED
#define MAT4X4_HPP_INCLUDED

#include <math.h>
#include "vector3.hpp"
#include "point3.hpp"

using namespace std;

class mat4x4{
	public:
		float data[16];

		mat4x4(){}
		mat4x4(float m00, float m01, float m02, float m03,
			   float m10, float m11, float m12, float m13,
			   float m20, float m21, float m22, float m23,
			   float m30, float m31, float m32, float m33){
			this->data[0]  = m00; this->data[1]  = m01; this->data[2]  = m02; this->data[3]  = m03;
			this->data[4]  = m10; this->data[5]  = m11; this->data[6]  = m12; this->data[7]  = m13;
			this->data[8]  = m20; this->data[9]  = m21; this->data[10] = m22; this->data[11] = m23;
			this->data[12] = m30; this->data[13] = m31; this->data[14] = m32; this->data[15] = m33;
		}
		mat4x4(float* data){
			for(int i = 0; i < 16; i++)
				this->data[i] = data[i];
		}
		~mat4x4(){}

		mat4x4 operator+(mat4x4 matrix){
			return mat4x4(this->data[0]  + matrix.data[0],  this->data[1]  + matrix.data[1],  this->data[2]  + matrix.data[2],  this->data[3]  + matrix.data[3],
						  this->data[4]  + matrix.data[4],  this->data[5]  + matrix.data[5],  this->data[6]  + matrix.data[6],  this->data[7]  + matrix.data[7],
						  this->data[8]  + matrix.data[8],  this->data[9]  + matrix.data[9],  this->data[10] + matrix.data[10], this->data[11] + matrix.data[11],
						  this->data[12] + matrix.data[12], this->data[13] + matrix.data[13], this->data[14] + matrix.data[14], this->data[15] + matrix.data[15]);
		}

		mat4x4 operator-(mat4x4 matrix) {
			return mat4x4(this->data[0]  - matrix.data[0],  this->data[1]  - matrix.data[1],  this->data[2]  - matrix.data[2],  this->data[3]  - matrix.data[3],
						  this->data[4]  - matrix.data[4],  this->data[5]  - matrix.data[5],  this->data[6]  - matrix.data[6],  this->data[7]  - matrix.data[7],
						  this->data[8]  - matrix.data[8],  this->data[9]  - matrix.data[9],  this->data[10] - matrix.data[10], this->data[11] - matrix.data[11],
						  this->data[12] - matrix.data[12], this->data[13] - matrix.data[13], this->data[14] - matrix.data[14], this->data[15] - matrix.data[15]);
		}

		mat4x4 operator*(mat4x4 matrix) {
			float temp[16];

			for(int i = 0; i < 16; i+=4){
            	for(int j = 0; j < 4; j++){
                	temp[i + j] = 0.0;
                	for(int k = 0; k < 4; k++)
                    	temp[i + j] += this->data[i + k] * matrix.data[k*4 + j];
            	}
        	}

			return mat4x4(temp);
		}

		vector3_t operator*(vector3_t vector){
			return vector3_t(vector.x*this->data[0] + vector.y*this->data[1] + vector.z*this->data[2],
							 vector.x*this->data[4] + vector.y*this->data[5] + vector.z*this->data[6],
							 vector.x*this->data[8] + vector.y*this->data[9] + vector.z*this->data[10]);
		}

		point3_t operator*(point3_t point){
			return point3_t(point.x*this->data[0] + point.y*this->data[1] + point.z*this->data[2]  + this->data[3],
							point.x*this->data[4] + point.y*this->data[5] + point.z*this->data[6]  + this->data[7],
							point.x*this->data[8] + point.y*this->data[9] + point.z*this->data[10] + this->data[11]);
		}

		mat4x4 operator*(float scalar) {
			return mat4x4(data[0]  * scalar, data[1]  * scalar, data[2]  * scalar, data[3]  * scalar,
						  data[4]  * scalar, data[5]  * scalar, data[6]  * scalar, data[7]  * scalar,
						  data[8]  * scalar, data[9]  * scalar, data[10] * scalar, data[11] * scalar,
						  data[12] * scalar, data[13] * scalar, data[14] * scalar, data[15] * scalar);
		}

		void operator+=(mat4x4 matrix){
			for(int i = 0; i < 16; i++)
				this->data[i] += matrix.data[i];
		}

		void operator-=(mat4x4 matrix){
			for(int i = 0; i < 16; i++)
				this->data[i] -= matrix.data[i];
		}

		void operator*=(float scalar){
			for(int i = 0; i < 16; i++)
				this->data[i] *= scalar;
		}

		static mat4x4 getIdentity(){
			return mat4x4(1.0f, 0.0f, 0.0f, 0.0f,
                          0.0f, 1.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, 1.0f, 0.0f,
                          0.0f, 0.0f, 0.0f, 1.0f);
		}

		static mat4x4 createTranslationMatrix(float dx, float dy, float dz){
			return mat4x4(1.0f, 0.0f, 0.0f, dx,
                          0.0f, 1.0f, 0.0f, dy,
                          0.0f, 0.0f, 1.0f, dz,
                          0.0f, 0.0f, 0.0f, 1.0f);
		}

		static mat4x4 createScaleMatrix(float sx, float sy, float sz){
			return mat4x4(sx  , 0.0f, 0.0f, 0.0f,
                          0.0f, sy  , 0.0f, 0.0f,
                          0.0f, 0.0f, sz  , 0.0f,
                          0.0f, 0.0f, 0.0f, 1.0f);
		}

		static mat4x4 createRotationMatrix(float angle, char axis){
			angle = (angle*PI) / 180.0f;

			if(axis == 'x' || axis == 'X'){
				return mat4x4(1.0f, 0.0f      ,  0.0f      , 0.0f,
                              0.0f, cos(angle), -sin(angle), 0.0f,
                              0.0f, sin(angle),  cos(angle), 0.0f,
                              0.0f, 0.0f      ,  0.0f      , 1.0f);
			}
			else if(axis == 'y' || axis == 'Y'){
				return mat4x4(cos(angle) , 0.0f, sin(angle), 0.0f,
                              0.0f       , 1.0f, 0.0f      , 0.0f,
                              -sin(angle), 0.0f, cos(angle), 0.0f,
                              0.0f       , 0.0f, 0.0f      , 1.0f);
			}
			else if(axis == 'z' || axis == 'Z'){
				return mat4x4(cos(angle), -sin(angle), 0.0f, 0.0f,
                              sin(angle),  cos(angle), 0.0f, 0.0f,
                              0.0f      ,  0.0f      , 1.0f, 0.0f,
                              0.0f      ,  0.0f      , 0.0f, 1.0f);
			}
		}

		static mat4x4 createLookAtMatrix(vector3_t right, vector3_t up, vector3_t forward, point3_t position){
			return mat4x4(right.x, up.x, forward.x, position.x,
						  right.y, up.y, forward.y, position.y,
						  right.z, up.z, forward.z, position.z,
						  0.0f, 0.0f, 0.0f, 1.0f);
		}
};

#endif // MAT4X4_HPP_INCLUDED
