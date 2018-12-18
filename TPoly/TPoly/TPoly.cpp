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

TPoly TPoly::operator+(TMember &elem)
{
	TPoly res = *this;

	res.polynom.remove(TMember(0, 0));

	for (auto it = res.polynom.begin(); it != res.polynom.end(); ++it)
	{
		int memExp = it->getN();
		int elemExp = elem.getN();
		if (memExp == elemExp)
		{
			int buf = it->getK() + elem.getK();
			if (buf != 0)
			{
				it->setK(buf);
			}
			else
			{
				res.polynom.remove(*it);
			}
			if (res.polynom.empty())
			{
				res.polynom.emplace_back(0, 0);
			}
			return res;
		}
		else
		{
			if (elemExp > memExp)
			{
				TMember buf = elem;
				res.polynom.insert(it, buf);
				return res;
			}
		}
	}

	res.polynom.push_back(elem);

	return res;
}

TPoly TPoly::operator+(TPoly &sec)
{
	TPoly res = *this;
	auto itFst = res.polynom.begin();
	auto itSnd = sec.polynom.begin();
	for (; itFst != res.polynom.end(); ++itFst)
	{
		while (itSnd->getN() > itFst->getN() && itSnd != sec.polynom.end())
		{
			res.polynom.insert(itFst, *itSnd);
			++itSnd;
		}
		if (itSnd->getN() == itFst->getN())
		{
			int buf = itFst->getK() + itSnd->getK();
			if (buf != 0)
			{
				itFst->setK(buf);
			}
			else
			{
				res.polynom.remove(*itFst);
			}
			++itSnd;
		}
	}
	if (itSnd != sec.polynom.end())
	{
		res.polynom.insert(itFst, itSnd, sec.polynom.end());
	}
	if (res.polynom.empty())
	{
		polynom.emplace_back(0, 0);
	}
	return res;
}

TPoly TPoly::operator-(TMember &elem)
{
	return *this + TMember(-elem.getK(), elem.getN());
}

TPoly TPoly::operator-(TPoly &sec)
{
	TPoly res = *this;

	for (auto mem : sec.polynom)
	{
		res = res - mem;
	}

	return res;
}

TPoly TPoly::operator*(TMember &elem)
{
	TPoly res;

	for (auto mem : polynom)
	{
		res = res + TMember(mem.getK() * elem.getK(), mem.getN() + elem.getN());
	}

	return res;
}

TPoly TPoly::operator*(TPoly &sec)
{
	TPoly res;

	for (auto mem : polynom)
	{
		for (auto secMem : sec.polynom)
		{
			res = res + TMember(mem.getK() * secMem.getK(), mem.getN() + secMem.getN());
		}
	}

	return res;
}

TPoly TPoly::operator-()
{
	TPoly zero(0, 0);
	return zero - *this;
}

bool TPoly::operator==(TPoly &sec)
{
	auto size = polynom.size();
	if (size != sec.polynom.size())
	{
		return false;
	}

	auto secMem = sec.polynom.begin();
	for (auto mem : polynom)
	{
		if (!(mem == *secMem))
		{
			return false;
		}
	}

	return true;
}

TPoly TPoly::differentiate()
{
	TPoly res;

	for (auto mem : polynom)
	{
		if (mem.getN())
		{
			res = res + mem.differentiate();
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
