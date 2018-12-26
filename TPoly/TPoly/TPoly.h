#include "stdafx.h"
#include <string>
#include <list>
#include "../TMember/TMember.h"

using namespace std;

class TPoly
{
	public:
		explicit TPoly(int k = 0, int n = 0);
		int getN();
		int getK(int N);
		void clear();
		TPoly differentiate();
		double calculate(double a);
		//TMember &elemAt(int idx);
		//TPoly &operator=(TPoly &other) = default;
		TPoly operator+(TMember &elem)
		{
			TPoly a = *this;
			//a = a + a;
			//a.polynom.remove(TMember(0, 0));
			
			for (auto i = a.polynom.begin(); i != a.polynom.end(); ++i)
			{
				if (i->getN() == elem.getN())
				{
					if (i->getK() + elem.getK())
					{
						i->setK(i->getK() + elem.getK());
					}
					else
					{
						//a.polynom.remove(*i);
					}
					if (a.polynom.empty())
					{
						a.polynom.emplace_back(0, 0);
					}
					return a;
				}
				else
				{
					if (i->getN() < elem.getN())
					{
						a.polynom.insert(i,elem);
						return a;
					}
				}
			}
			a.polynom.push_back(elem);
			return a;
		}
		TPoly operator+(TPoly &sec)
		{
			TPoly a = *this;
			auto itFst = a.polynom.begin();
			auto itSnd = sec.polynom.begin();
			for (; itFst != a.polynom.end(); ++itFst)
			{
				while (itSnd->getN() > itFst->getN() && itSnd != sec.polynom.end())
				{
					a.polynom.insert(itFst, *itSnd);
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
						//a.polynom.remove(*itFst);
					}
					++itSnd;
				}
			}
			if (itSnd != sec.polynom.end())
			{
				a.polynom.insert(itFst, itSnd, sec.polynom.end());
			}
			if (a.polynom.empty())
			{
				polynom.emplace_back(0, 0);
			}
			return a;
		}
		TPoly operator-(TMember &elem)
		{
			TMember b(-elem.getK(), elem.getN());
			return *this + b;
		}
		TPoly  operator-(TPoly &sec)
		{
			TPoly a = *this;

			for (auto mem : sec.polynom)
			{
				a = a - mem;
			}

			return a;
		}

		TPoly  operator*(TMember &elem)
		{
			TPoly a;
			
			for (auto &mem : polynom)
			{
				TMember b(mem.getK() * elem.getK(), mem.getN() + elem.getN());
				a = a + b;
			}

			return a;
		}

		TPoly operator*(TPoly &sec)
		{
			TPoly a;

			for (auto mem : polynom)
			{
				for (auto secMem : sec.polynom)
				{
					TMember b(mem.getK() * secMem.getK(), mem.getN() + secMem.getN());
					a = a + b;
				}
			}

			return a;
		}

		TPoly operator-()
		{
			TPoly zero(0, 0);
			return zero - *this;
		}

		bool operator==(TPoly &sec)
		{
			auto size = polynom.size();
			if (size != sec.polynom.size())
			{
				return false;
			}

			auto secMem = sec.polynom.begin();
			for (auto &mem : polynom)
			{
				TMember m2 = (TMember)(*secMem);
				TMember m1 = ((TMember)mem);
				if (!((m1.getK() == m2.getK() && m1.getN() == m2.getN())))
				{
					return false;
				}
			}

			return true;
		}
		/*
		void Method1() {
			TPoly p1;
			TPoly p2;
			TPoly p3 = p1 + p2;
		}*/
	private:
		list<TMember> polynom;
};
