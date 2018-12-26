#include "Drobi.h"

using namespace std;

bool operator < (const Drobi &a,const Drobi &b) {
	Drobi rigth = b;
	Drobi left = a;
	//Drobi a = *this - other;
	if (left.getChislitel() * rigth.getZnamenatel() < rigth.getChislitel() * left.getZnamenatel())
		return true;
	else
		return false;
}

/*
Drobi Drobi::operator+(Drobi &b) {
	Drobi a = *this;
	int corpChislitel = a.getChislitel() * b.getZnamenatel() + b.getChislitel() * a.getZnamenatel();
	int corpZnamenatel = a.getZnamenatel() * b.getZnamenatel();
	return Drobi(corpChislitel, corpZnamenatel);
}
Drobi Drobi::operator-() {
	Drobi a = *this;
	return Drobi(-a.getChislitel(), a.getZnamenatel());
}
Drobi Drobi::operator-(Drobi &b) {
	Drobi a = *this;
	return a + -b;
}
Drobi Drobi::operator*(Drobi &b) {
	Drobi a = *this;
	return Drobi(a.getChislitel() * b.getChislitel(), a.getZnamenatel() * b.getZnamenatel());
}
Drobi Drobi::operator/(Drobi &b) {
	Drobi a = *this;
	return Drobi(a.getChislitel() * b.getZnamenatel(), a.getZnamenatel() * b.getChislitel());
}
*/
/*
bool operator == (const Drobi &a, const Drobi &b) {
	if (a.getChislitel() != b.getChislitel() || b.getZnamenatel() != a.getZnamenatel())
		return false;
	else
		return true;
}*/

int Drobi::getChislitel() {
	return chislitel;
}

int Drobi::getZnamenatel() {
	return znamenatel;
}
int Drobi::compareTo(Drobi &other) {
	return getChislitel() * other.getZnamenatel() - getZnamenatel() * other.getZnamenatel();
}

Drobi Drobi::Add(Drobi other) {
	Drobi a = *this + other;
	return a;
}
Drobi Drobi::copy() {
	Drobi a = *this;
	return a;
}
Drobi Drobi::minus(Drobi other) {
	return *this - other;
}
Drobi Drobi::obratnoe() {
	Drobi a(this->getZnamenatel(), this->getChislitel());
	return a;
}
Drobi Drobi::cut(Drobi other) {
	return *this / other;
}
Drobi Drobi::squer() {
	return *this * *this;
}
Drobi Drobi::multiplie(Drobi other) {
	return *this * other;
}
string Drobi::strChislitel() {
	return to_string(this->getChislitel());
}
string Drobi::strZnamenatel() {
	return to_string(this->getZnamenatel());
}
string Drobi::str() {
	return this->strChislitel() + "/" + this->strZnamenatel();
}
bool Drobi::more(Drobi other) {
	Drobi a = *this - other;
	if (a.getChislitel() >= 0)
		return true;
	else
		return false;
}

