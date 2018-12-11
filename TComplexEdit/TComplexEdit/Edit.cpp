#include "stdafx.h"
#include "../../Lab2/Lab2/TComplex.h"
#include "Edit.h"


const string TComplexEditor::ZERO = "0+i*0";
const string TComplexEditor::SIGN = "+i*";

TComplexEditor::TComplexEditor() : number("0"), isRealPartEditing(true) {
}


bool TComplexEditor::isZero() {
	return TComplex(number).str() == TComplex().str();
}


string TComplexEditor::changeSign() {
	if (number[0] == '-') {
		number.erase(number.begin());
	}
	else {
		if (number[0] != '0') {
			number = "-" + number;
		}
	}
	return number;
}


string TComplexEditor::addDigit(int digit) {
	int pos = isRealPartEditing ? 0 : number.find('*') + 1;
	if (digit >= 0 && digit < 10) {
		if (number[pos] == '0') {
			number.pop_back();
		}
		number += (char)('0' + digit);
	}
	return number;
}

string TComplexEditor::addZero() {
	return addDigit(0);
}

string TComplexEditor::backspace() {
	number.pop_back();
	if (isRealPartEditing) {
		if (number == "-" || number.empty()) {
			number = "0";
		}
	}
	else {
		if (number.find('*')) {
			number.erase(number.end() - 2, number.end());
			isRealPartEditing = true;
		}
	}
	return number;
}


std::string TComplexEditor::clear() {
	number = "0";
	isRealPartEditing = true;
	return number;
}

std::string TComplexEditor::addSplit() {
	if (number.find(SIGN) == string::npos) {
		number = number + SIGN;
		isRealPartEditing = false;
	}
	return number;
}


void TComplexEditor::setNumber(string num) {
	regex r("-?[1-9]+[[:d:]]*");
	string a, b = "0";
	int f = num.find(SIGN);
	if (num.find(SIGN) != string::npos) {
		a = num.substr(0, f);
		b = num.substr(f + 1, num.length() - f - 1);
		if (regex_match(a, r) && regex_match(b, r))
			number = TComplex(num).str();
		else
			number = TComplex("0").str();
	}
	else {
		a = num;
		if (regex_match(a, r))
			number = TComplex(num).str();
		else
			number = TComplex("0").str();
	}
	
	
}


std::string TComplexEditor::getNumber() const {
	return TComplex(number).str();
}