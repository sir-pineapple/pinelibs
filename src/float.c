#include <pinelibs/float.h>

typedef union {int i; float f;} size4;
typedef union {long l; double d;} size8;

int toInt(float f) {
	size4 s4;
	s4.f = f;
	return s4.i;
}

float toFloat(int i) {
	size4 s4;
	s4.i = i;
	return s4.f;
}

long toLong(double d) {
	size8 s8;
	s8.d = d;
	return s8.l;
}

double toDouble(long l) {
	size8 s8;
	s8.l = l;
	return s8.d;
}
