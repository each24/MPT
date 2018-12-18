#include "stdafx.h"
#include <math.h>
class TMember
{
private:
	int k;
	int n;
public:
	explicit TMember(int k, int n) : k(k), n(n){}
	int getN();
	int getK();
	void setN(int n);
	void setK(int k);
	bool operator==(TMember &other);
	TMember differentiate();
	double calculate(double a);
};