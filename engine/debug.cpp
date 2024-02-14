/**
 * Author:    Jens Heukers
 * Created:   13.02.2024
 *
 **/
#include "debug.h"
#include "math/vector3.h"

Debug* Debug::m_oInstance;

Debug* Debug::GetInstance() {
	if (!m_oInstance)
		m_oInstance = new Debug();

	return m_oInstance;
}

void Debug::Print(const char* pString) {
	std::cout << pString << std::endl;
}

void Debug::Print(std::string pString) {
	Print(pString.c_str());
}

void Debug::Print(float pFloat) {
	Print(std::to_string(pFloat));
}

void Debug::Print(const vector3 pVector) {
	Print(std::to_string(pVector.x) + "," + std::to_string(pVector.y) + "," + std::to_string(pVector.z).c_str());
}