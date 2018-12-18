#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <string>
#include <vector>

#define Pi 3.141592653589793238462643383279

using namespace std;

class TPNumber {
private:
	double a;
	int b;
	int c;
public:
	TPNumber(double A, int B, int C) : a(A), b(B), c(C) {
		if (C < 0 || B < 2 || B > 16)
			throw exception("error");
	}
	TPNumber(string A, string B, string C) : a(atof(A.c_str())), b(int(atof(B.c_str()))), c(int(atof(C.c_str()))) {
		if (c < 0 || b < 2 || b > 16)
			throw exception("error");
	}
	TPNumber(double a, int b) :a(a), b(b), c(0) {
		if (b < 2 || b > 16)
			throw exception("error");
	}
	TPNumber(string A, string B) : a(atof(A.c_str())), b(int(atof(B.c_str()))), c(0) {
		if (b < 2 || b > 16)
			throw exception("error");
	}
	double getA();
	int getB();
	int getC();
	TPNumber Add(TPNumber other);
	TPNumber copy();
	TPNumber minus(TPNumber other);
	TPNumber cut(TPNumber other);
	TPNumber squer();
	TPNumber multiplie(TPNumber other);
	TPNumber obratnoe();
	string strN();
	string strB();
	string strC();
	void setB(int B);
	void setB(string B);
	void setC(int C);
	void setC(string C);
};

