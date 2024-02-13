/**
 * Author:    Jens Heukers
 * Created:   13.02.2024
 *
 **/
#ifndef QUANTUMSPARK_DEBUG_H
#define QUANTUMSPARK_DEBUG_H
#include <iostream>
#include <string>

class Debug {
private:
	static Debug* m_oInstance;

public:
	Debug* GetInstance();

	static void Print(const char* pString);
	static void Print(std::string pString);
};


#endif // !QUANTUMSPARK_DEBUG_H