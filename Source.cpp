//�������������� ���������� ��������;
//���� ������:08.02.2022;
//���� ���������: ����������;
//������: 1.1.01;
//������������:�������� ��� ������ ����� � ������ �� ����������;
#include<fstream>
#include<iostream>
using namespace std;
const unsigned N = 25;
struct str {
	char stroka[N + 1];
	char mark;
	void inp1(fstream& f) {
		char ogr;
		f >> ogr;
		f >> mark;
		char c;
		unsigned i = 0;
		while (f.eof() == 0) {
			f >> c;
			if (c == ogr) {
				f >> c;
				while (c != ogr && c != '\n' && f.eof() == 0) {
					stroka[i] = c;
					f.unsetf(ios::skipws);
					f >> c;
					i++;
					f.setf(ios::skipws);
				}
				break;
			}
			else
				continue;
		}
		stroka[i] = mark;
	}
	void out(fstream& f) {
		unsigned i = 0;
		if (stroka[0] == mark)
			f << "������ ������";
		else {
			f << stroka[0];
			do {
				i++;
				f << stroka[i];
			} while (stroka[i] != mark);
		}
	}
	void obrabotka() {
		unsigned i = 0, a, b, k;
		while (stroka[i] != mark) {
			if (stroka[i] == '.') {
				a = i;
				while (stroka[i] == '.') {
					i++;
				}
				b = i-1;
				k = b - (a + 2);
				stroka[a + 3] = stroka[a + 3 + k];
				stroka[a + 4] = stroka[a + 4 + k];
				int j = a + 5;
				while (stroka[j] != mark) {
					stroka[j] = stroka[j + k];
					j++;
				}
				i = a + 3;
			}
			i++;
		}
	}
};


int main() {
	fstream f;
	f.open("in1.txt", ios::in);
	str s;
	s.inp1(f);
	f.close();
	f.open("out.txt", ios::out);
	f << "�������������� ���������� ��������;" << '\n' <<
		"���� ������ : 08.02.2022;" << '\n' <<
		"���� ��������� : ����������;" << '\n' <<
		"������: 1.1.01;" << '\n' <<
		"������������:�������� ��� ������ ����� � ������ �� ����������;" << '\n';
	f << "�������� ������:" << '\n';
	s.out(f);
	f << '\n';
	s.obrabotka();
	f << "��������� ��������� ������:" << '\n';
	s.out(f);
	f.close();
	return 0;
}