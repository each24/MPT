#include "stdafx.h"
#include "../../Lab1/Lab1/Drobi.h"
#include "TFracEdit.h"


const string TFracEdit::ZERO = "0/1";
const string TFracEdit::SIGN = string("/");

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
		number = number + SIGN;
	}
	return number;
}

void TFracEdit::setNumber(string num) {
	bool flag = true;
	int znak = 0;
	for (auto &i : num) {
		if ((i >= 48 && i <= 57) || i == 43 || i == 45 || i == 47) {
			if (i == 43 || i == 45) {
				znak++;
				if (znak > 2) {
					flag = false;
					break;
				}
			}
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag)
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
