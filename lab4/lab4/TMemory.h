#pragma once
#include <string>
template <class T>
class TMemory
{
private:
	T fNumber;
	bool fState;
public:
	TMemory() : fNumber(T()), fState(false) {};
	~TMemory() {};

	void write(const T e) {
		fNumber = e;
		fState = true;
	};
	T get() {
		fState = true;
		T A = fNumber;
		return A;
	};
	bool getState() {
		return fState;
	};
	void add(const T e) {
		fNumber = fNumber + e;
		fState = true;
	};
	void clear() {
		fNumber = T();
		fState = false;
	};
	std::string readMemoryState() {
		if (fState)
			return std::string("_On");
		else
			return std::string("_Off");
	};
	T getFNumber() {
		return fNumber;
	};
};

