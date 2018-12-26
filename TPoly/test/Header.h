#pragma once
#include <list>

class TPoly {

	public:
		class TMember {
		protected:
			int k, n;

		public:
			explicit TMember(int k, int n) : k(k), n(n) {}

			int getN() {
				return n;
			}
			int getK() {
				return k;
			}
			void setN(int N) {
				n = N;
			}
			void setK(int K) {
				k = K;
			}
			bool operator==(TMember &other) {
				return k == other.k && n == other.n;
			}
			TMember differentiate() {
				return TMember(k * n, n - 1);
			}
			double calculate(double a) {
				return pow(a, n) * k;
			}

		};

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
						a.polynom.remove(*i);
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
						a.polynom.insert(i, elem);
						return a;
					}
				}
			}
			a.polynom.push_back(elem);
			return a;
		}
		//TPoly operator-(TMember &elem);
		void Meth1(TMember &A) {
			TPoly p;
			p = p + A;
		}


		TPoly operator-(TMember &elem)
		{
			TMember b(-elem.getK(), elem.getN());
			TPoly a = *this + b;
			return a;
		}

protected:
	std::list<TMember> polynom;
};

