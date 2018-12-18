#include "stdafx.h"
#include "TPNumber.h"


using namespace std;

float step(float a, int n) {
	float c = 1.0;
	for (int i = 0; i < n; i++) {
		c *= a;
	}
	return c;
}

double TPNumber::getA() {
	return a;
}

int TPNumber::getB() {
	return b;
}

int TPNumber::getC() {
	return c;
}

TPNumber TPNumber::Add(TPNumber other) {
	if (other.b == (*this).b && other.c == (*this).c) {
		TPNumber S(((*this).a + other.a), (*this).b, (*this).c);
		return S;
	}
	else
		throw exception("not addable");
}
TPNumber TPNumber::copy() {
	TPNumber a = *this;
	return a;
}
TPNumber TPNumber::minus(TPNumber other) {
	if (other.b == (*this).b && other.c == (*this).c) {
		TPNumber S(((*this).a - other.a), (*this).b, (*this).c);
		return S;
	}
	else
		throw exception("not addable");
}

TPNumber TPNumber::cut(TPNumber other) {
	if (other.b == (*this).b && other.c == (*this).c) {
		TPNumber S(((*this).a / other.a), (*this).b, (*this).c);
		return S;
	}
	else
		throw exception("not addable");
}
TPNumber TPNumber::squer() {
	TPNumber A = *this;
	TPNumber C(A.a*A.a,A.b,A.c);
	return C;
}
TPNumber TPNumber::multiplie(const TPNumber other) {
	if (other.b == (*this).b && other.c == (*this).c) {
		TPNumber S(((*this).a * other.a), (*this).b, (*this).c);
		return S;
	}
	else
		throw exception("not addable");
}
TPNumber TPNumber::obratnoe(){
	TPNumber A = *this;
	TPNumber b(1.0 / A.a, A.b, A.c);
	return b;
}
string TPNumber::strN(){
	string NUM;
	double A = abs((*this).a);
	if (A - int(A) == 0.0) {
		int t = int(A);
		vector<int> out;
		while (t > 0) {
			out.push_back(t%b);
			t /= b;
		}
		for (int i = out.size() - 1; i >= 0; i--) {
			if (out[i] > 9) {
				char temp = 'A' + out[i] - 10;
				NUM += temp;
			}
			else
				NUM += to_string(out[i]);
		}
		/*NUM += ".";
		for (int i = 0; i < c; ++i) {
			NUM += "0";
		}*/
	}
	else {
		int t = int(A);
		vector<int> out;
		while (t > 0) {
			out.push_back(t%b);
			t /= b;
		}
		for (int i = out.size(); i > 0; i--) {
			NUM += to_string(out[i - 1]);
		}
		double z = A - int(A);
		out.clear();
		double x = 1.0;
		for (int i = 0; i < c; ++i) {
			x /= (double)b;
			t = 0;
			while (z - x >= 0.0) {
				z -= x;
				t++;
			}
			out.push_back(t);
		}
		NUM += ".";
		for (int i = 0; i < int(out.size()); i++) {
			if (out[i] > 9) {
				char temp = out[i] - 10 + 'A';
				NUM += temp;
			}
			else
				NUM += to_string(out[i]);
		}
	}
	if((*this).a < 0)
		return "-" + NUM;
	else
		return NUM;
}
string TPNumber::strB(){
	return to_string(this->b);
}
string TPNumber::strC() {
	return to_string(this->c);
}

void TPNumber::setB(int B) {
	if (B >= 2 && B <= 16) {
		this->b = B;
	}
	else
		throw exception("out of range");
}

void TPNumber::setB(string B) {
	if (atoi(B.c_str()) >= 2 && atoi(B.c_str()) <= 16) {
		this->b = atoi(B.c_str());
	}
	else
		throw exception("out of range");
}

void TPNumber::setC(int C) {
	if (C >= 0) {
		this->c = C;
	}
	else
		throw exception("out of range");
}

void TPNumber::setC(string C) {
	if (atoi(C.c_str()) >= 0) {
		this->c = atoi(C.c_str());
	}
	else
		throw exception("out of range");
}