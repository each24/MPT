#include "stdafx.h"
#include "../../Lab1/Lab1/Drobi.h"
#include "TFracEdit.h"

const string TFracEdit::ZERO = "0/1";
const string TFracEdit::SIGN = string("/");
using namespace std;

string TFracEdit::changeSign() {
	if (number[0] == '-') {
		number.erase(number.begin());
	}
	else {
		if (!isZero()) {
			number = "-" + number;
		}
	}
	return number;
}

string TFracEdit::addDigit(int digit) {
	if (digit >= 0 && digit < 10) {
		if (number == "0") {
			number = "";
		}
		number += to_string(digit);
	}
	return number;
}

string TFracEdit::addZero() {
	return number != SIGN ? addDigit(0) : number;
}

string TFracEdit::backspace() {
	number.pop_back();
	if (number == "-" || number.empty()) {
		number = string("0");
	}
	return number;
}

string TFracEdit::clear() {
	number = "0";
	return number;
}

string TFracEdit::addSplit() {
	if (number.find(SIGN) == string::npos) {
		number = number + SIGN + "1";
	}
	return number;
}

void TFracEdit::setNumber(string num) {
	bool flag = true;
	int znak = 0;
	string a, b = "1";
	regex r("-?[1-9]+[[:d:]]*");
	int f = num.find(SIGN);
	if (num.find(SIGN) != string::npos) {
		a = num.substr(0, f);
		b = num.substr(f + 1, num.length() - f - 1);
	}else{
		a = num;
	}
	if (regex_match(a, r) && regex_match(b, r))
		number = Drobi(num).str();
	else
		number = Drobi("0").str();
}

string TFracEdit::getNumber() const {
	return Drobi(number).str();
}

TFracEdit::TFracEdit() : number("0") {
}

bool TFracEdit::isZero() {
	return Drobi(number).str() == TFracEdit::ZERO;
}
