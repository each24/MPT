#include <string>
#include <regex>
using namespace std;

class TPNumberEditor {
public:
	static const string ZERO;
	static const char SIGN;
	TPNumberEditor();
	bool isZero();
	string clear();
	string addSplit();
	void setNumber(string num);
	string getNumber() const;
	string changeSign();
	string addDigit(int digit);
	string addZero();
	string backspace();
private:
	string number;
	int base;
};


