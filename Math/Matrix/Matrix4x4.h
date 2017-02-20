#ifndef _MATRIX_4X4_H_
#define _MATRIX_4X4_H_
#include "../Vector/Vector3.h"
#include "../Vector/Vector4.h"
enum MatrixMode
{
	COL_MAJOR,
	ROW_MAJOR,
};

class Matrix4x4 
{
public: 
	MatrixMode m_mode = MatrixMode::COL_MAJOR;
	float m_value[4][4];
public:
	Matrix4x4();
	Matrix4x4(float *matrix);
	Matrix4x4(float x);
	Matrix4x4(
		float aa, float ab, float ac, float ad,
		float ba, float bb, float bc, float bd,
		float ca, float cb, float cc, float cd,
		float da, float db, float dc, float dd);
	//float* GetMatrix();
	void GetMatrix(float *m);
	void SetFromArray(float *m);
	Vector3 GetU();
	Vector3 GetV();
	Vector3 GetN();
	void SetU(Vector3 u);
	void SetV(Vector3 v);
	void SetN(Vector3 n);
	Vector3 GetPos();
	void SetPos(Vector3 pos);
	Matrix4x4 setValues(
		float aa = 0, float ab =0, float ac=0, float ad=0,
		float ba=0, float bb=0, float bc=0, float bd=0,
		float ca=0, float cb=0, float cc=0, float cd=0,
		float da=0, float db=0, float dc=0, float dd=0);
	Vector4 GetCol(int j);
	Vector4 GetRow(int i);
	void SetIdentity();
	float Determinant();
	Matrix4x4 Transpose();
	Matrix4x4 Inverse();
	

public:
	Matrix4x4 operator=(Matrix4x4 m);
	Matrix4x4 operator+(Matrix4x4 m);
	Vector3 operator*(Vector3 vector3);
	Vector4 operator*(Vector4 vector4);
	Matrix4x4 operator*(Matrix4x4 m);

};

#endif