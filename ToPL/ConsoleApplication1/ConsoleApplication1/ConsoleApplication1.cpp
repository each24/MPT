// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string replaceall(string A, string b, string c) {
	while (A.find(b) != -1)
		A = A.substr(0, A.find(b)) + c + A.substr(A.find(b) + b.length(), A.length() - 1);
	return A;
}

bool checking(string A, string B) {
	for (int i = 0; i < A.length(); ++i)
		if (B.find(A[i]) == -1)
			return false;
	return true;
}

int main()
{
	string VT;
	cout << "insert VT" << endl;
	int n, nQ, *FQ, iQ;
	cin >> VT;
	cout << "\n insert size of table" << endl;
	cin >> n;
	string temp = "", **A;
	A = new string*[n];
	for (int i = 0; i < n; ++i) {
		A[i] = new string[n];
		for (int j = 0; j < n; ++j) {
			cout << "from q" << i << "  to q" << j << endl;
			cin >> A[i][j];
			replaceall(A[i][j], " ", "");
			replaceall(A[i][j], ",", "");
			replaceall(A[i][j], "`", "");
		}
	}
	cout << "\ninsert initial q\n";
	cin >> iQ;
	cout << "\ninsert amount of final q:" << endl;
	cin >> nQ;
	FQ = new int[nQ];
	for (int i = 0; i < nQ; ++i) {
		cout << endl << "insert " << i << "q final" << endl;
		cin >> FQ[i];
	}
	while (temp != "end!") {
		cout << "\n insert string :" << endl;
		cin >> temp;
		if (checking(temp, VT) == 0) {
			cout << "\nERROR string contains unexepted characters" << endl;
			continue;
		}
		int it = 0, pos = iQ;
		while (it != temp.length() - 1) {
			bool founded = false;
			for (int i = 0; i < n; ++i)
				if (A[pos][i].find(temp[it]) != -1) {
					pos = i;
					founded = true;
					break;
				}
			if (founded)
				it++;
			else {
				cout << "ERROR can't go further  " << endl << "stoped at : " << it << endl;
				break;
			}
		}
		bool finished = 1;
		for (int i = 0; i < nQ; ++i)
			if (pos == FQ[i])
				finished = 0;
		if (finished)
			cout << endl << "ERROR Ended on not finishing q(" << endl;
		else
			cout << "\n string is right\n";
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
