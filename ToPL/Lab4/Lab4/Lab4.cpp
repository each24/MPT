// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Rule {
	string A;
	string B;
	string C;
	string D;
	string E;
	string F;
	string G;
};

string replaceall(string A, string b, string c) {
	while (A.find(b) != -1)
		A = A.substr(0, A.find(b)) + c + A.substr(A.find(b) + b.length(), A.length() - 1);
	return A;
}

int main()
{
	string VT, VTT, *Q, q0, *QF, stackBegin, transstackBegin;
	cout << "\ninsert terminal lettesr for main grammar\n";
	cin >> VT;
	cout << "\ninsert terminal lettesr for trans grammar\n";
	cin >> VTT;
	int n, NQF;
	cout << "\n insert amount of Q's\n";
	cin >> n;
	Q = new string[n];
	for (int i = 0; i < n; ++i) {
		cout << "\ninsert q" << i << endl;
		cin >> Q[i];
	}
	cout << "\n insert q0:\n";
	cin >> q0;
	cout << "\n insert amount of final Q:\n";
	cin >> NQF;
	QF = new string[NQF];
	for (int i = 0; i < NQF; ++i) {
		cout << "\ninsert final q № " << i << endl;
		cin >> QF[i];
	}
	cout << "\ninsert, what main stack contains in the beginning\n";
	cin >> stackBegin;
	stackBegin = replaceall(stackBegin, "`", "");
	cout << "\ninsert, what trans string contains in the beginning\n";
	cin >> transstackBegin;
	transstackBegin = replaceall(transstackBegin, "`", "");
	cout << "\n insert amount of Rules\n";
	cin >> n;
	vector<vector<vector<string>>> Rules;
	vector<string*> ListOfR;
	printf("\ninsert Rule like:\nq(*,*,*) = q(*,*,*);\n");
	for (int i = 0; i < n; ++i) {
		string *temp;
		temp = new string[6];
		for (int i = 0; i < 6; ++i) {
			cin >> temp[i];
			temp[i] = replaceall(temp[i], "`", "");
		}
		cout << "\nR( " << temp[0] << " , " << temp[1] << " , " << temp[2] << " )=( " << temp[3] << " , " << temp[4] << " , " << temp[5] << " )\n";
		ListOfR.push_back(temp);
	}
	int menu = 0;
	while (menu != 4) {
		cout << "\ninsert:\n0 to start game\n1 to change starting point\n2 to change ending points\n3 to change what stack contains\n4 to end\n";
		cin >> menu;
		string pos = q0;
		switch (menu)
		{
		case 0: {
			string t = "";
			vector<char> stack, transstack;
			while (1) {
				stack.clear();
				transstack.clear();
				for (int i = stackBegin.length() - 1; i >= 0; --i)
					stack.push_back(stackBegin[i]);
				for (int i = transstackBegin.length() - 1; i >= 0; --i)
					transstack.push_back(transstack[i]);
				pos = q0;
				cout << "\nto end game insert end!, else insert string\n";
				cin >> t;
				string part = "" + t[0];
				if (t == "end!")
					break;
				t = replaceall(t, "`", "");
				string temp = t;
				bool L = 1, founded = 0, ended = 0;
				if (stack.size())
					cout << "Q( " << pos << " , " << t << " , " << stack.back() << " )" << endl;
				else
					cout << "Q( " << pos << " , " << t << " , \"\")" << endl;
				for (int i = 0; i <= temp.length(); ++i) {
					founded = 0;
					L = 1;
					for (int j = 0; j < ListOfR.size(); ++j) {
						if (pos == ListOfR[j][0]) {
							if (temp[i] == ListOfR[j][1][0] && ListOfR[j][1].size() != 0) {
								if (stack.size() != 0) {
									if (stack.back() == ListOfR[j][2][0]) {
										stack.pop_back();
										pos = ListOfR[j][3];
										for (int k = ListOfR[j][4].length() - 1; k >= 0; --k)
											stack.push_back(ListOfR[j][4][k]);
										for (int k = ListOfR[j][5].length() - 1; k >= 0; --k)
											transstack.push_back(ListOfR[j][5][k]);
										part = "";
										founded = 1;
										break;
									}
								}
								else
									if (ListOfR[j][2].length() == 0) {
										pos = ListOfR[j][3];
										for (int k = ListOfR[j][5].length() - 1; k >= 0; --k)
											transstack.push_back(ListOfR[j][5][k]);
										part = "";
										founded = 1;
										break;
									}
							}
							else
								if (ListOfR[j][1].length() == 0) {
									if (stack.size() != 0) {
										if (stack.back() == ListOfR[j][2][0]) {
											stack.pop_back();
											pos = ListOfR[j][3];
											for (int k = ListOfR[j][4].length() - 1; k >= 0; --k)
												stack.push_back(ListOfR[j][4][k]);
											for (int k = ListOfR[j][5].length() - 1; k >= 0; --k)
												transstack.push_back(ListOfR[j][5][k]);
											i--;
											L = 0;
											founded = 1;
											break;
										}
									}
									else
										if (ListOfR[j][2].size() == 0) {
											pos = ListOfR[j][3];
											for (int k = ListOfR[j][5].length() - 1; k >= 0; --k)
												transstack.push_back(ListOfR[j][5][k]);
											i--;
											L = 0;
											founded = 1;
											break;
										}
								}
						}
					}
					if (!founded)
						break;
					if (L && i != temp.length()) {
						part += temp[i];
						t = t.substr(1, t.length() - 1);
					}
					string transstring = "";
					for (int a = 0; a < transstack.size(); a++)
						transstring += transstack[a];
					if (stack.size())
						cout << "Q( " << pos << " , " << t << " , " << stack.back() << " , " << transstring << " )" << endl;
					else
						cout << "Q( " << pos << " , " << t << " , \"\" , " << transstring << " )" << endl;
				}
				if (t.length() != 0)
					cout << "\n string is not readed\nstring doesn't belong to grammar\n";
				else {
					for (int i = 0; i < NQF; ++i)
						if (pos == QF[i]) {
							ended = 1;
						}
					if (ended) {
						if (stack.size() == 0)
							cout << "\nstring was right!\n";
						else
							cout << "\n memory is not empty\nstring doesn't belong to this grammar!\n";
					}
					else
						cout << "\nstring doesn't belong to this grammar!\n";
				}
			}
			break;
		}
		case 1: {
			cout << "\n insert q0:\n";
			cin >> q0;
			break;
		}
		case 2: {
			cout << "\n insert amount of final Q:\n";
			cin >> NQF;
			delete(QF);
			QF = new string[NQF];
			for (int i = 0; i < NQF; ++i)
				cin >> QF[i];
			break;
		}
		case 3: {
			cout << "insert, what stack contains in the begining";
			cin >> stackBegin;
			break;
		}
		case 4: {
			break;
		}
		default: {
			menu = 4;
			break;
		}
		}
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
