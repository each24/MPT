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
		TMember &elemAt(int idx);
		TPoly &operator=(TPoly &other) = default;
		TPoly operator+(TMember &elem);
		TPoly operator+(TPoly &sec);
		TPoly operator-(TMember &elem);
		TPoly operator-(TPoly &sec);
		TPoly operator*(TMember &elem);
		TPoly operator*(TPoly &sec);
		TPoly operator-();
		bool operator==(TPoly &sec);
	private:
		list<TMember> polynom;
};
