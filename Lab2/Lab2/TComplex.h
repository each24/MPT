#pragma once
#include <iostream>
#include <string>
#include <cmath>

#define Pi 3.141592653589793238462643383279

using namespace std;

class TComplex {
private:
	float deist;
	float mnim;
public:
	TComplex(float deist, float mnim) : deist(deist), mnim(mnim) {
		;
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

