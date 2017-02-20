#include "Matrix4x4.h"
#include <stdio.h>
#include <cstring>
Matrix4x4::Matrix4x4() 
{
	memset(m_value, 0, sizeof(float)*16);
}
Matrix4x4::Matrix4x4(float* matrix) 
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			m_value[i][j] = matrix[i + j*4];
		}
	}
}
Matrix4x4::Matrix4x4(float x) 
{
	memset(m_value, 0, sizeof(float)*16);
	for (int i = 0; i < 4; i++) 
	{
		m_value[i][i] = x;
	}
}

Matrix4x4::Matrix4x4(
	float aa, float ab, float ac, float ad,
	float ba, float bb, float bc, float bd,
	float ca, float cb, float cc, float cd,
	float da, float db, float dc, float dd) 
{// col major
	m_value[0][0] = aa; m_value[1][0] = ab; m_value[2][0] = ac; m_value[3][0] = ad;
	m_value[0][1] = ba; m_value[1][1] = bb; m_value[2][1] = bc; m_value[3][1] = bd;
	m_value[0][2] = ca; m_value[1][2] = cb; m_value[2][2] = cc; m_value[3][2] = cd;
	m_value[0][3] = da; m_value[1][3] = db; m_value[2][3] = dc; m_value[3][3] = dd;
}

// float* Matrix4x4::GetMatrix() 
// {
// 	return &m_value[0][0];
// }

void Matrix4x4::GetMatrix(float *m) 
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			m[i+ j*4] = this->m_value[i][j];
		}
	}
}

void Matrix4x4::SetFromArray(float *m)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_value[i][j] = m[i  + j * 4];
		}
	}
}

Vector3 Matrix4x4::GetU() 
{
	return Vector3(m_value[0][0], m_value[1][0], m_value[2][0]);
}
Vector3 Matrix4x4::GetV()
{
	return Vector3(m_value[0][1], m_value[1][1], m_value[2][1]);
}
Vector3 Matrix4x4::GetN()
{
	return Vector3(m_value[0][2], m_value[1][2], m_value[2][2]);
}

Vector3 Matrix4x4::GetPos() 
{
	return Vector3(m_value[0][3], m_value[1][3], m_value[2][3]);
}

void Matrix4x4::SetU(Vector3 u) 
{
	m_value[0][0] = u.getX();
	m_value[0][1] = u.getY();
	m_value[0][2] = u.getZ();
}
void Matrix4x4::SetV(Vector3 u)
{
	m_value[1][0] = u.getX();
	m_value[1][1] = u.getY();
	m_value[1][2] = u.getZ();
}
void Matrix4x4::SetN(Vector3 u)
{
	m_value[2][0] = u.getX();
	m_value[2][1] = u.getY();
	m_value[2][2] = u.getZ();
}
void Matrix4x4::SetPos(Vector3 pos) 
{
	m_value[3][0] = pos.getX();
	m_value[3][1] = pos.getY();
	m_value[3][2] = pos.getZ();
}
Matrix4x4 Matrix4x4::setValues(
	float aa, float ab, float ac, float ad,
	float ba, float bb, float bc, float bd,
	float ca, float cb, float cc, float cd,
	float da, float db, float dc, float dd) 
{
	return Matrix4x4(
		aa, ab, ac, ad,
		ba, bb, bc, bd,
		ca, cb, cc, cd,
		da, db, dc, dd);
}
Vector4 Matrix4x4::GetCol(int i) 
{
	return Vector4(m_value[0][i], m_value[1][i], m_value[2][i], m_value[3][i]);
}
Vector4 Matrix4x4::GetRow(int j) 
{
	return Vector4(m_value[j][0], m_value[j][1], m_value[j][2], m_value[j][3]);
}


void Matrix4x4::SetIdentity() 
{
	memset(m_value, 0, sizeof(float) * 16);
	for (int i = 0; i < 4; i++)
	{
		m_value[i][i] = 1.0;
	}
}

Matrix4x4 Matrix4x4::operator=(Matrix4x4 m)
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			m_value[i][j] = m.m_value[i][j];
		}
	}
	return m;
}

Matrix4x4 Matrix4x4::operator+(Matrix4x4 m) 
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			m_value[i][j] += m.m_value[i][j];
		}
	}
	return Matrix4x4(&m_value[0][0]);
}

Vector3 Matrix4x4::operator*(Vector3 vector3) 
{
	float x, y, z, w;
	x = m_value[0][0] * vector3.m_x + m_value[0][1] * vector3.m_y + m_value[0][2] * vector3.m_z + m_value[0][3];
	y = m_value[1][0] * vector3.m_x + m_value[1][1] * vector3.m_y + m_value[1][2] * vector3.m_z + m_value[1][3];
	z = m_value[2][0] * vector3.m_x + m_value[2][1] * vector3.m_y + m_value[2][2] * vector3.m_z + m_value[2][3];
	w = m_value[3][0] * vector3.m_x + m_value[3][1] * vector3.m_y + m_value[3][2] * vector3.m_z + m_value[3][3];
	return Vector3(x / w, y / w, z / w);
}

Vector4 Matrix4x4::operator*(Vector4 vector4)
{
	float x, y, z, w;
	x = m_value[0][0] * vector4.m_x + m_value[0][1] * vector4.m_y + m_value[0][2] * vector4.m_z + m_value[0][3] * vector4.m_w;
	y = m_value[1][0] * vector4.m_x + m_value[1][1] * vector4.m_y + m_value[1][2] * vector4.m_z + m_value[1][3] * vector4.m_w;
	z = m_value[2][0] * vector4.m_x + m_value[2][1] * vector4.m_y + m_value[2][2] * vector4.m_z + m_value[2][3] * vector4.m_w;
	w = m_value[3][0] * vector4.m_x + m_value[3][1] * vector4.m_y + m_value[3][2] * vector4.m_z + m_value[3][3] * vector4.m_w;
	return Vector4(x, y, z, w);
}

Matrix4x4 Matrix4x4::operator*(Matrix4x4 m)
{
	Matrix4x4 matrix;
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			matrix.m_value[i][j] = GetRow(i).dotproduct(m.GetCol(j));
		}
	}
	return matrix;
}