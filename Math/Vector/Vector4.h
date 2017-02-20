#ifndef _VECTOR_4_H_
#define _VECTOR_4_H_

class Vector4
{
public:
	float m_x, m_y, m_z, m_w;
public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4(float* Arrayheader);
	float getX();
	float getY();
	float getZ();
	float getW();
	void setX(float value);
	void setY(float value);
	void setZ(float value);
	void setW(float value);
	float length();
	float lengthsqrt();
	void normalize();
	void getValueFromArray(float* Arrayheader);
	float dotproduct(Vector4 vector4);
	//Vector3 crossproduct(Vector3 vector3);

	void operator= (Vector4 &vector4);
	Vector4 operator+ (Vector4 &vector4);
	Vector4 operator- (Vector4 &vector4);
	Vector4 operator-();
	Vector4 operator* (float &scaler);
	Vector4 operator* (class Matrix4x4 *m);
	Vector4 operator/ (float &scaler);
	void operator+= (Vector4 &vector4);
};

#endif