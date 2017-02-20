#include "Vector4.h"
#include "../Matrix/Matrix4x4.h"
#include <cmath>
Vector4::Vector4()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_w = 0;
}
Vector4::Vector4(float x, float y, float z, float w)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_w = w;
}
Vector4::Vector4(float *arrayheader)
{
	m_x = arrayheader[0];
	m_y = arrayheader[1];
	m_z = arrayheader[2];
	m_w = arrayheader[3];
}

float Vector4::getX() { return m_x; }

float Vector4::getY() { return m_y; }

float Vector4::getZ() { return m_z; }

float Vector4::getW() { return m_w; }

void Vector4::setX(float x) { m_x = x; }

void Vector4::setY(float y) { m_y = y; }

void Vector4::setZ(float z) { m_z = z; }

void Vector4::setW(float w) { m_w = w; }

void Vector4::getValueFromArray(float* Arrayheader)
{
	m_x = Arrayheader[0];
	m_y = Arrayheader[1];
	m_z = Arrayheader[2];
	m_w = Arrayheader[3];
}

float Vector4::length() { return (m_x*m_x + m_y*m_y + m_z*m_z + m_w*m_w); }

float Vector4::lengthsqrt() { return sqrt(length()); }

void Vector4::normalize()
{
	float m_lengthsqrt = lengthsqrt();
	m_x /= m_lengthsqrt;
	m_y /= m_lengthsqrt;
	m_z /= m_lengthsqrt;
	m_w /= m_lengthsqrt;
}



float Vector4::dotproduct(Vector4 vector4)
{
	return (m_x*vector4.m_x+ m_y*vector4.m_y+ m_z*vector4.m_z+ m_w*vector4.m_w);
}

/*Vector3 Vector3::crossproduct(Vector3 vector3)
{
	return Vector3(m_y*vector3.m_z - m_z*vector3.m_y,
		m_z*vector3.m_x - m_x*vector3.m_z,
		m_x*vector3.m_y - m_y*vector3.m_x);
}*/

void Vector4::operator= (Vector4 &vector4)
{
	m_x = vector4.m_x;
	m_y = vector4.m_y;
	m_z = vector4.m_z;
	m_w = vector4.m_w;
}
Vector4 Vector4::operator+ (Vector4 &vector4)
{
	return Vector4(m_x + vector4.m_x, m_y + vector4.m_y, m_z + vector4.m_z, m_w + vector4.m_w);
}
Vector4 Vector4::operator- (Vector4 &vector4)
{
	return Vector4(m_x - vector4.m_x, m_y - vector4.m_y, m_z - vector4.m_z, m_w - vector4.m_w);
}
Vector4 Vector4::operator-()
{
	return Vector4(-m_x, -m_y, -m_z, -m_w);
}
Vector4 Vector4::operator* (float &scaler)
{
	return Vector4(m_x * scaler, m_y*scaler, m_z * scaler, m_w*scaler);
}

Vector4 Vector4::operator* (Matrix4x4 *m) 
{
	Vector4 res;
	res.setX(this->dotproduct(m->GetCol(0)));
	res.setY(this->dotproduct(m->GetCol(1)));
	res.setZ(this->dotproduct(m->GetCol(2)));
	res.setW(this->dotproduct(m->GetCol(3)));
	return res;
}

Vector4 Vector4::operator/ (float &scaler)
{
	return Vector4(m_x / scaler, m_y/scaler, m_z / scaler, m_w/scaler);
}

void Vector4::operator+= (Vector4 &vector4)
{
	m_x += vector4.m_x;
	m_y += vector4.m_y;
	m_z += vector4.m_z;
	m_w += vector4.m_w;
}