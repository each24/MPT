#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>



using namespace std;

class TComplex {
private:
	float deist;
	float mnim;
public:
	TComplex(float deist, float mnim) : deist(deist), mnim(mnim) {
		;
	}
	TComplex() : deist(0), mnim(0) {
		;
	}
	TComplex(string number) {
		int pos, k;
		if (number.find("+i") != string::npos) {
			pos = number.find("+i*");
			k = 1;
		}
		else {
			pos = number.find("-i*");
			k = -1;
		}
		if (pos == string::npos) {
			deist = stod(number);
			mnim = 0;
		}
		else {
			deist = stod(number.substr(0, pos));
			mnim = std::stod(number.substr(pos + 3)) * k;
		}
	}
	float getReal();
	float getMnim();
	float ugolG();
	float ugolR();
	TComplex Add(TComplex other);
	TComplex copy();
	TComplex minus(TComplex other);
	TComplex cut(TComplex other);
	TComplex squer();
	TComplex multiplie(TComplex other);
	TComplex obratnoe();
	string strReal();
	string strMnim();
	string str();
	TComplex minus();
	TComplex Step(int n);
	TComplex Squer(int n, int k);
	bool Equal(TComplex a);
	bool more(TComplex other);
};

