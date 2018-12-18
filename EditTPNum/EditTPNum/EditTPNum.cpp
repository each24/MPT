#include "stdafx.h"
#include "EditTPNumber.h"
#include "../../Lab3/Lab3/TPNumber.h"


const string TPNumberEditor::ZERO = "0";
const char TPNumberEditor::SIGN = '.';

TPNumberEditor::TPNumberEditor() : number(TPNumberEditor::ZERO), base(10) {
}


bool TPNumberEditor::isZero() {
	if (TPNumber(number, to_string(base)).getA() == 0.0)
		return true;
	else
		return false;
}


string TPNumberEditor::changeSign() {
	if (number[0] == '-') {
		number.erase(number.begin());
	}
	else {
		if (number != TPNumberEditor::ZERO) {
			number = "-" + number;
		}
	}
	return number;
}


string TPNumberEditor::addDigit(int digit) {
	if (digit < base) {
		if (number == TPNumberEditor::ZERO) {
			number = "";
		}
		if (digit < 10)
			number += (char)digit + '0';
		else
			if(digit <= 15)
				number += (char)('A' + digit - 10);
	}
	return number;
}


string TPNumberEditor::addZero() {
	number += '0';
	return number;
}


string TPNumberEditor::backspace() {
	if(number.length() > 0)
		number.pop_back();
	if (number == "-" || number.length() == 0) {
		number = TPNumberEditor::ZERO;
	}
	return number;
}


string TPNumberEditor::clear() {
	number = TPNumberEditor::ZERO;
	return number;
}

std::string TPNumberEditor::addSplit() {
	if (number.find(SIGN) == string::npos) {
		number = number + SIGN;
	}
	return number;
}


void TPNumberEditor::setNumber(string num) {
	bool flag = true;
	string a, b = "1", B, reg;
	if (base > 10) {
		B = to_string(base - 11 + 'A');
		reg = "-?[1-9,A-" + B + "]+[0-9,A-" + B + "]*";
	}
	else {
		B = to_string(base - 1);
		reg = "-?[1-" + B + "]+[0-" + B + "]*";
	}
	regex r(reg.c_str());
	int f = num.find(SIGN);
	if (num.find(SIGN) != string::npos) {
		a = num.substr(0, f);
		b = num.substr(f + 1, num.length() - f - 1);
	}
	else {
		a = num;
	}
	if (regex_match(a,r) && regex_match(b,r))
		number = TPNumber(num, to_string(base)).strN();
	else
		number = ZERO;
}


std::string TPNumberEditor::getNumber() const {
	if (number != ZERO)
		return TPNumber(number, to_string(base)).strN();
	else
		return ZERO;
}
