#ifndef QUANTUMSPARK_VECTOR_H
#define QUANTUMSPARK_VECTOR_H
#include <string>

struct vector {
	float x, y, z;

	std::string ToString() {
		return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z);
	}

	void FromString(std::string pString) {
		// TODO 
	}
};

#endif // !QUANTUMSPARK_VECTOR_H