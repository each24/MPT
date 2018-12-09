#pragma once
#include <string>
#include <regex>

using namespace std;

class TFracEdit
{
public:
	TFracEdit();
	bool isZero();

	string changeSign();
	string addDigit(int digit);
	string addZero();
	string backspace();
	string clear();
	string addSplit();	
	void setNumber(string num);
	string getNumber() const;
	static const string ZERO;
	static const string SIGN;
private:
	string number;
};

