#ifndef _VECTOR_3_H_
#define _VECTOR_3_H_

class Vector3
{
public:
	float m_x, m_y, m_z;
public:
	Vector3();
	Vector3(float x, float y, float z);
	Vector3(float* Arrayheader);
	float getX();
	float getY();
	float getZ();
	void setX(float value);
	void setY(float value);
	void setZ(float value);
	void setValues(float x, float y, float z);
	float length();
	float lengthsqrt();
	void normalize();
	void getValueFromArray(float* Arrayheader);
	float dotproduct(Vector3 vector3);
	Vector3 crossproduct(Vector3 vector3);

	void operator= (Vector3 &vector3);
	void operator=(const Vector3 &vector3);
	Vector3 operator+ (Vector3 &vector3);
	Vector3 operator- (Vector3 &vector3);
	Vector3 operator-();
	Vector3 operator* (float &scaler);
	Vector3 operator* (Vector3 &vec3);
	Vector3 operator/ (float &scaler);
	void operator+= (Vector3 &vector3);
};

#endif