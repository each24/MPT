#include "stdafx.h"
#include "TComplex.h"

using namespace std;


float step(float a, int n) {
	float c = 1.0;
	for (int i = 0; i < n; i++) {
		c *= a;
	}
	return c;
}

float TComplex::getReal() {
	return deist;
}

float TComplex::getMnim() {
	return mnim;
}


TComplex TComplex::Add(TComplex other) {
	TComplex a(((*this).deist + other.deist), (*this).mnim + other.mnim);
	return a;
}
TComplex TComplex::copy() {
	TComplex a = *this;
	return a;
}
TComplex TComplex::minus(TComplex other) {
	TComplex a(((*this).deist - other.deist), (*this).mnim - other.mnim);
	return a;
}

TComplex TComplex::cut(TComplex b) {
	TComplex a = *this;
	TComplex c((a.deist*b.deist + a.mnim*b.mnim) / (b.mnim*b.mnim + b.deist*b.deist), (b.deist*a.mnim - a.deist*b.mnim) / (b.deist*b.deist + b.mnim*b.mnim));
	return c;
}
TComplex TComplex::squer() {
	TComplex a = *this;
	TComplex c(a.deist*a.deist - a.mnim*a.mnim, 2 * a.deist*a.mnim);
	return c;
}
TComplex TComplex::multiplie(const TComplex b) {
	TComplex a = *this;
	TComplex c(a.deist*b.deist - b.mnim*b.mnim,a.deist*b.mnim + b.deist*a.mnim);
	return c;
}
TComplex TComplex::obratnoe(){
	TComplex c = *this;
	TComplex a(c.deist / (c.deist*c.deist + c.mnim* c.mnim), -c.mnim / (c.deist*c.deist + c.mnim*c.mnim));
	return a;
}
string TComplex::strReal(){
	return to_string(this->getReal());
}
string TComplex::strMnim(){
	return to_string(this->getMnim());
}
string TComplex::str() {
	return this->strReal() + "+i*" + this->strMnim();
}
float TComplex::ugolG() {
	return 180 / M_PI * (*this).ugolR();
}

TComplex TComplex::minus() {
	TComplex a(-this->getReal(), this->getMnim());
	return a;
}

TComplex TComplex::Step(int n) {
	TComplex a = *this;
	float r = sqrtf(a.deist * a.deist + a.mnim * a.mnim);
	r = step(r, n);
	TComplex c(r*cos(a.ugolR()*n), r*sin(a.ugolR()*n));
	return c;
}

TComplex TComplex::Squer(int n, int k) {
	if (k >= 0 && k < n) {
		TComplex a = *this;
		float r = sqrtf(a.deist * a.deist + a.mnim * a.mnim);
		r = powf(r, float(1 / n));
		TComplex c(r * cos(a.ugolR() + 2 * M_PI*k / n), sin(a.ugolR() + 2 * k*M_PI / n));
		return c;
	}
	else {
		throw logic_error("K за пределами допустимого!!!");
	}
}
bool TComplex::Equal(TComplex a) {
	TComplex b = *this;
	if (a.mnim == b.mnim && b.deist == a.deist)
		return true;
	else
		return false;
}
float TComplex::ugolR() {
	TComplex a = *this;
	if (a.deist >= 0)
		if (a.deist == 0)
			if (a.mnim < 0)
				return M_PI / 2;
			else
				if (a.mnim == 0)
					return 0;
				else
					return -M_PI / 2;
		else 
			return float(atan(a.mnim / a.deist));
	else 
		return float(atan(a.mnim / a.deist) + M_PI);
}
bool TComplex::more(TComplex other) {
	TComplex b = *this;
	TComplex a = b.minus(other);
	if (a.getReal() >= 0)
		return true;
	else
		return false;
}