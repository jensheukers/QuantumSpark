#ifndef QUANTUMSPARK_VECTOR3_H
#define QUANTUMSPARK_VECTOR3_H
#include <string>

struct vector3 {
	float x, y, z;

	vector3(float pX = 0, float pY = 0, float pZ = 0) {
		x = pX;
		y = pY;
		z = pZ;
	}

	vector3 vector3::operator +(const vector3& v) {
		return vector3(x + v.x, y + v.y, z + v.z);
	}

	vector3 vector3::operator -(const vector3& v) {
		return vector3(x - v.x, y - v.y, z - v.z);
	}

	vector3 vector3::operator *(const vector3& v) {
		return vector3(x * v.x, y * v.y, z * v.z);
	}

	vector3 vector3::operator /(const vector3& v) {
		return vector3(x / v.x, y / v.y, z / v.z);
	}

	vector3 vector3::operator +(const float t) {
		return vector3(x + t, y + t, z + t);
	}

	vector3 vector3::operator -(const float t) {
		return vector3(x - t, y - t, z - t);
	}

	vector3 vector3::operator *(const float t) {
		return vector3(x * t, y * t, z * t);
	}
	vector3 vector3::operator /(const float t) {
		return vector3(x / t, y / t, z / t);
	}
};

#endif // !QUANTUMSPARK_VECTOR_H