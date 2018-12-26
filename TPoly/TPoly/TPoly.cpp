#include "stdafx.h"
#include <cmath>
#include "TPoly.h"


TPoly::TPoly(int k, int n) {
	polynom.emplace_back(k, n);
}

int TPoly::getN()
{
	return polynom.begin()->getN();
}

int TPoly::getK(int N)
{
	for (auto mem : polynom)
	{
		if (mem.getN() == N)
		{
			return mem.getK();
		}
	}
	return 0;
}

void TPoly::clear()
{
	polynom.clear();
	polynom.emplace_back(0, 0);
}


TPoly TPoly::differentiate()
{
	TPoly res;

	for (auto mem : polynom)
	{
		if (mem.getN())
		{
			TMember b = mem.differentiate();
			res = res + b;
		}
	}

	return res;
}

double TPoly::calculate(double a)
{
	double res = 0.0;

	for (auto i : polynom)
	{
		res += i.calculate(a);
	}

	return res;
}
