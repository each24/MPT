#pragma once
#include <iostream>
#include <string>

using namespace std;

class Drobi {
private:
	int chislitel;
	int znamenatel;
	int gcd(int chislitel, int znamenatel) {
		while (chislitel != 0 && znamenatel != 0) {
			if (abs(chislitel) > abs(znamenatel))
				chislitel = abs(chislitel) % abs(znamenatel);
			else
				znamenatel = abs(znamenatel) % abs(chislitel);
		}
		return (abs(znamenatel) + abs(chislitel));
	}
	void simply() {
		int del = gcd(chislitel, znamenatel);
		chislitel /= del;
		znamenatel /= del;
		if (znamenatel < 0) {
			chislitel *= (-1);
			znamenatel *= (-1);
		}
	}
public:
	Drobi(int chislitel, int znamenatel) : chislitel(chislitel), znamenatel(znamenatel) {
		if (this->znamenatel == 0) throw logic_error("Деление на нуль!!!");
		simply();
	}
	Drobi() : chislitel(0), znamenatel(1) {}
	Drobi(int value) : chislitel(value), znamenatel(1) {}
	Drobi(string a) {
		int pos = a.find("/");
		if (pos != std::string::npos) {
			this->chislitel = atol(a.substr(0, pos).c_str());
			this->znamenatel = atol(a.substr(pos + 1).c_str());
		}
		else {
			this->chislitel = atol(a.c_str());
			this->znamenatel = 1;
		}
	}
	int getChislitel();
	int getZnamenatel();
	int compareTo(Drobi &other);
	Drobi Add(Drobi other);
	Drobi copy();
	Drobi minus(Drobi other);
	Drobi obratnoe();
	Drobi cut(Drobi other);
	Drobi squer();
	Drobi multiplie(Drobi other);
	string strChislitel();
	string strZnamenatel();
	string str();
	bool more(Drobi other);
	Drobi operator+(Drobi &b) {
		Drobi a = *this;
		int corpChislitel = a.getChislitel() * b.getZnamenatel() + b.getChislitel() * a.getZnamenatel();
		int corpZnamenatel = a.getZnamenatel() * b.getZnamenatel();
		return Drobi(corpChislitel, corpZnamenatel);
	}
	Drobi operator-() {
		Drobi a = *this;
		return Drobi(-a.getChislitel(), a.getZnamenatel());
	}
	Drobi operator-(Drobi &b) {
		Drobi a = *this;
		b = -b;
		return a + b;
	}
	Drobi operator*(Drobi &b) {
		Drobi a = *this;
		return Drobi(a.getChislitel() * b.getChislitel(), a.getZnamenatel() * b.getZnamenatel());
	}
	Drobi operator/(Drobi &b) {
		Drobi a = *this;
		return Drobi(a.getChislitel() * b.getZnamenatel(), a.getZnamenatel() * b.getChislitel());
	}
	//bool operator < (const Drobi &b);
};

bool operator < (const Drobi &a, const Drobi &b);
bool operator == (const Drobi &a, const Drobi &b);
/*
Drobi operator+(Drobi &a);
Drobi operator-(void);
Drobi operator-(Drobi &a);
Drobi operator*(Drobi &a);
Drobi operator/(Drobi &a);
*/

