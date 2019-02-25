#ifndef MAT4X4_HPP_INCLUDED
#define MAT4X4_HPP_INCLUDED

class mat4x4 {
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
			return mat4x4();
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
			/*data[0]  += matrix.data[0];  data[1]  += matrix.data[1];  data[2]  += matrix.data[2];  data[3]  += matrix.data[3];
			data[4]  += matrix.data[4];  data[5]  += matrix.data[5];  data[6]  += matrix.data[6];  data[7]  += matrix.data[7];
			data[8]  += matrix.data[8];  data[9]  += matrix.data[9];  data[10] += matrix.data[10]; data[11] += matrix.data[11];
			data[12] += matrix.data[12]; data[13] += matrix.data[13]; data[14] += matrix.data[14]; data[15] += matrix.data[15];//*/
		}

		void operator-=(mat4x4 matrix){
			for(int i = 0; i < 16; i++)
				this->data[i] -= matrix.data[i];
			/*data[0] -= matrix.data[0]; data[1] =- matrix.data[1]; data[2] =- matrix.data[2]; data[3] =- matrix.data[3];
			data[4] -= matrix.data[4]; data[5] =- matrix.data[5]; data[6] =- matrix.data[6]; data[7] =- matrix.data[7];
			data[8] -= matrix.data[8]; data[9] =- matrix.data[9]; data[10] =- matrix.data[10]; data[11] =- matrix.data[11];
			data[12] -= matrix.data[12]; data[13] =- matrix.data[13]; data[14] =- matrix.data[14]; data[15] =- matrix.data[15];//*/
		}

		void operator*=(float scalar){
			for(int i = 0; i < 16; i++)
				this->data[i] *= scalar;
			/*data[0] *= scalar; data[1] *= scalar; data[2] *= scalar; data[3] *= scalar;
			data[4] *= scalar; data[5] *= scalar; data[6] *= scalar; data[7] *= scalar;
			data[8] *= scalar; data[9] *= scalar; data[10] *= scalar; data[11] *= scalar;
			data[12] *= scalar; data[13] *= scalar; data[14] *= scalar; data[15] *= scalar;//*/
		}
};

#endif // MAT4X4_HPP_INCLUDED
