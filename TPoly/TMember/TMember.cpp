#include "stdafx.h"
#include "TMember.h"

int TMember::getN() {
	return n;
}
int TMember::getK() {
	return k;
}
void TMember::setN(int N){
	n = N;
}
void TMember::setK(int K){
	k = K;
}
bool TMember::operator==(TMember &other){
	return k == other.k && n == other.n;
}
TMember TMember::differentiate(){
	return TMember(k * n, n - 1);
}
double TMember::calculate(double a){
	return pow(a, n) * k;
}
