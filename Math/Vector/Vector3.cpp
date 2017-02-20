#include "Vector3.h"
#include <cmath>
Vector3::Vector3() 
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}
Vector3::Vector3(float x, float y, float z) 
{
	m_x = x;
	m_y = y;
	m_z = z;
}
Vector3::Vector3(float *arrayheader) 
{
	m_x = arrayheader[0];
	m_y = arrayheader[1];
	m_z = arrayheader[2];
}

float Vector3::getX() { return m_x; }

float Vector3::getY() { return m_y; }

float Vector3::getZ() { return m_z; }

void Vector3::setX(float x) { m_x = x; }

void Vector3::setY(float y) { m_y = y; }

void Vector3::setZ(float z) { m_z = z; }

void Vector3::setValues(float x, float y, float z) 
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void Vector3::getValueFromArray(float* Arrayheader)
{
	m_x = Arrayheader[0];
	m_y = Arrayheader[1];
	m_z = Arrayheader[2];
}

float Vector3::length() { return m_x*m_x + m_y*m_y + m_z*m_z; }

float Vector3::lengthsqrt() { return sqrt(length()); }

void Vector3::normalize() 
{
	float m_lengthsqrt = lengthsqrt();
	m_x /= m_lengthsqrt;
	m_y /= m_lengthsqrt;
	m_z /= m_lengthsqrt;
}



float Vector3::dotproduct(Vector3 vector3) 
{
	return (m_x*vector3.m_x+ m_y*vector3.m_y+ m_z*vector3.m_z);
}

Vector3 Vector3::crossproduct(Vector3 vector3) 
{
	return Vector3(m_y*vector3.m_z - m_z*vector3.m_y,
		m_z*vector3.m_x - m_x*vector3.m_z,
		m_x*vector3.m_y - m_y*vector3.m_x);
}

void Vector3::operator= (Vector3 &vector3) 
{
	m_x = vector3.m_x;
	m_y = vector3.m_y;
	m_z = vector3.m_z;
}
void Vector3::operator=(const Vector3 &vector3)
{
	m_x = vector3.m_x;
	m_y = vector3.m_y;
	m_z = vector3.m_z;
}
Vector3 Vector3::operator+ (Vector3 &vector3) 
{
	return Vector3(m_x + vector3.m_x, m_y + vector3.m_y, m_z + vector3.m_z);
}
Vector3 Vector3::operator- (Vector3 &vector3) 
{
	return Vector3(m_x - vector3.m_x, m_y - vector3.m_y, m_z - vector3.m_z);
}
Vector3 Vector3::operator-() 
{
	return Vector3(-m_x,-m_y,-m_z);
}
Vector3 Vector3::operator* (float &scaler) 
{
	return Vector3(m_x * scaler, m_y*scaler, m_z * scaler);
}
Vector3 Vector3::operator* (Vector3 &vec3) 
{
	return Vector3(m_x*vec3.getX(), m_y*vec3.getY(), m_z*vec3.getZ());
}
Vector3 Vector3::operator/ (float &scaler) 
{
	return Vector3(m_x / scaler, m_y/scaler, m_z / scaler);
}

void Vector3::operator+= (Vector3 &vector3)
{
	m_x += vector3.m_x;
	m_y += vector3.m_y;
	m_z += vector3.m_z;
}