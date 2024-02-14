/**
 * Author:    Jens Heukers
 * Created:   13.02.2024
 *
 **/
#ifndef QUANTUMSPARK_DEBUG_H
#define QUANTUMSPARK_DEBUG_H
#include <iostream>
#include <string>

class vector3; // fwd declare

class Debug {
private:
	static Debug* m_oInstance;

public:
	Debug* GetInstance();

	static void Print(const char* pString);
	static void Print(std::string pString);
	static void Print(float pFloat);
	static void Print(const vector3 pVector);
};


#endif // !QUANTUMSPARK_DEBUG_H