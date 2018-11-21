#include "Drobi.h"

using namespace std;


Drobi operator+(const Drobi &a, const Drobi &b) {
	int corpChislitel = a.getChislitel() * b.getZnamenatel() + b.getChislitel() * a.getZnamenatel();
	int corpZnamenatel = a.getZnamenatel() * b.getZnamenatel();
	return Drobi(corpChislitel, corpZnamenatel);
}

Drobi operator-(const Drobi &a) {
	return Drobi(-a.getChislitel(), a.getZnamenatel());
}

Drobi operator-(const Drobi &a, const Drobi &b) {
	return a + -b;
}

Drobi operator*(const Drobi &a, const Drobi &b) {
	return Drobi(a.getChislitel() * b.getChislitel(), a.getZnamenatel() * b.getZnamenatel());
}

Drobi operator/(const Drobi &a, const Drobi &b) {
	return Drobi(a.getChislitel() * b.getZnamenatel(), a.getZnamenatel() * b.getChislitel());
}

int Drobi::getChislitel() const {
	return chislitel;
}

int Drobi::getZnamenatel() const {
	return znamenatel;
}
int Drobi::compareTo(const Drobi &other) const {
	return getChislitel() * other.getZnamenatel() - getZnamenatel() * other.getZnamenatel();
}

Drobi Drobi::Add(Drobi other) const {
	Drobi a = *this + other;
	return a;
}
Drobi Drobi::copy() {
	Drobi a = *this;
	return a;
}
Drobi Drobi::minus(const Drobi other) {
	return *this - other;
}
Drobi Drobi::obratnoe() const {
	Drobi a(this->getZnamenatel(), this->getChislitel());
	return a;
}
Drobi Drobi::cut(const Drobi other) {
	return *this / other;
}
Drobi Drobi::squer() const {
	return *this * *this;
}
Drobi Drobi::multiplie(const Drobi other) const {
	return *this * other;
}
string Drobi::strChislitel() const {
	return to_string(this->getChislitel());
}
string Drobi::strZnamenatel() const {
	return to_string(this->getZnamenatel());
}
string Drobi::str() const {
	return this->strChislitel() + "/" + this->strZnamenatel();
}
bool Drobi::more(const Drobi other) const {
	Drobi a = *this - other;
	if (a.getChislitel() >= 0)
		return true;
	else
		return false;
}

