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
	int getChislitel() const;
	int getZnamenatel() const;
	int compareTo(const Drobi &other) const;
	Drobi Add(Drobi other) const;
	Drobi copy();
	Drobi minus(const Drobi other);
	Drobi obratnoe() const;
	Drobi cut(const Drobi other);
	Drobi squer() const;
	Drobi multiplie(const Drobi other) const;
	string strChislitel() const;
	string strZnamenatel() const;
	string str() const;
	bool more(const Drobi other)const;
};

Drobi operator+(const Drobi &a, const Drobi &b);
Drobi operator-(const Drobi &a);
Drobi operator-(const Drobi &a, const Drobi &b);
Drobi operator*(const Drobi &a, const Drobi &b);
Drobi operator/(const Drobi &a, const Drobi &b);



