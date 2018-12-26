#pragma once
#include <set>
#include <algorithm>

using namespace std;

template <class T>
class TSet {
private:
	set<T> container;
public:
	void clear();
	void add(T other);
	void del(T other);
	bool isClear();
	bool isContains(T other);
	TSet<T> addition(const TSet<T> &other);
	TSet<T> subtraction(const TSet<T> &other);
	TSet<T> multiply(const TSet<T> &other);
	int count();
	T elem(int number);
	TSet();
	~TSet();
};

template<class T>
void TSet<T>::clear() {
	container.clear();
}

template<class T>
void TSet<T>::add(T other) {
	container.insert(other);
}

template<class T>
void TSet<T>::del(T other) {
	if (container.count(other))
		container.erase(other);
}

template<class T>
bool TSet<T>::isClear() {
	if (container.size() == 0)
		return true;
	else
		return false;
}

template<class T>
bool TSet<T>::isContains(T other) {
	return container.count(other);
}

template<class T>
TSet<T> TSet<T>::addition(const TSet<T> &other) {
	TSet<T> result = *this;
	//for (T &i : other.container)
	//	result.add(i);
	for (auto v = other.container.begin(); v != other.container.end(); ++v) {
		result.add(*v);
	}
	return result;
}

template<class T>
TSet<T> TSet<T>::subtraction(const TSet<T> &other) {
	TSet<T> result = *this;
	//for (T &i : other.container)
	for (auto v = other.container.begin(); v != other.container.end(); ++v) {
		T i = (T)*v;
		if (result.container.count(i))
			result.del(i);
	}
	return result;
}

template<class T>
TSet<T> TSet<T>::multiply(const TSet<T> &other) {
	TSet<T> result;
	for (auto v = other.container.begin(); v != other.container.end(); ++v) {
		T i = (T)*v;
		if (container.count(i))
			result.add(i);
	}
	return result;
}

template<class T>
int TSet<T>::count() {
	return container.size();
}

template<class T>
T TSet<T>::elem(int Number) {
	if (Number < 0 || Number >= container.size()) {
		T toReturn;
		return toReturn;
	}
	auto it = container.begin();
	advance(it, Number);
	return *it;
}

template<class T>
TSet<T>::TSet() {
}

template<class T>
TSet<T>::~TSet() {
	container.clear();
}