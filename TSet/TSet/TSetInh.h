#pragma once

#include "TSet.h"

template<class T>
class TSetInh : public std::set<T> {
public:
	TSetInh();

	bool isContains(T x);

	TSetInh<T> addition(TSetInh<T> &x);

	TSetInh<T> substraction(TSetInh<T> &x);

	TSetInh<T> multiply(TSetInh<T> &x);

	T elemAt(int i);
};

template<class T>
TSetInh<T>::TSetInh() = default;

template<class T>
bool TSetInh<T>::isContains(T x) {
	return (bool)this->count(x);
}

template<class T>
TSetInh<T> TSetInh<T>::addition(TSetInh<T> &x) {
	TSetInh res;

	std::set_union(this->begin(), this->end(), x.begin(), x.end(), std::inserter(res, res.begin()));

	return res;
}

template<class T>
TSetInh<T> TSetInh<T>::substraction(TSetInh<T> &x) {
	TSetInh res;

	std::set_difference(this->begin(), this->end(), x.begin(), x.end(), std::inserter(res, res.begin()));

	return res;
}

template<class T>
TSetInh<T> TSetInh<T>::multiply(TSetInh<T> &x) {
	TSetInh res;

	std::set_intersection(this->begin(), this->end(), x.begin(), x.end(), std::inserter(res, res.begin()));

	return res;
}

template<class T>
T TSetInh<T>::elemAt(int i) {
	return *std::next(std::set<T>::begin(), i);
}
