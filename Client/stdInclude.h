#pragma once
#include <iostream>
#include <cstdint>

#define ASSERTIONS_ENABLED

#ifdef _DEBUG

#define debugBreak() asm { int 3 }
// checks the expression and prints Message if it's false 
#define ASSERT(expr, failMessage) \
 if (!expr) \
 {\
	 std::cerr << "Assertion from file: " << __FILE__ << " at line: " << __LINE__ << " failed! Context: " << failMessage << std::endl;\
 }
#else
#define ASSERT(expr, context) // evaluates to nothing
#endif
