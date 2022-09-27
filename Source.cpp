#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Fecha {
private:
	string a;
	string m;
	string d;
	string dateinstring;
public:
	Fecha(string, string, string);
	void validar();
	void incremento();
	int validar_mes(int m1, int a1);
};

Fecha::Fecha(string _a1, string _m1, string _d1) {
	a = _a1;
	m = _m1;
	d = _d1;
}

bool bisiesto = false;
int a1, m1, d1;

void Fecha::validar() {

	cout << "Ano: "; cin >> a; cout << "\n";
	a1 = stoi(a);
	cout << "Mes: "; cin >> m; cout << "\n";
	m1 = stoi(m);
	cout << "Dia: "; cin >> d; cout << "\n";
	d1 = stoi(d);
	cout << a1 << "/" << m1 << "/" << d1 << "\n";

	if (a1 % 4 == 0 && a1 % 100 != 100 || a1 % 400 == 0)
		bisiesto = true;

	if (d1 > 0 && d1 < 32 && m1 >0 && m1 < 13 && a1>0) {
		if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
		{
			cout << "Fecha valida \n";
		}
		else
		{
			if (m1 == 2 && d1 < 30 && bisiesto)
				cout << "Fecha valida \n";
			else if (m1 == 2 && d1 < 29 && !bisiesto)
				cout << "Fecha valida \n";
			else if (m1 != 2 && d1 < 31)
				cout << "Fecha valida \n";
			else
				cout << "Fecha no valida \n";
		}
	}
	else
		cout << "Fecha no valida \n"; 
}

int Fecha::validar_mes(int m1, int a1) {
	int c_dias;
	if ((m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 = 10 || m1 == 12)) {
		c_dias == 31;
	}
	else if ((a1 % 4 == 0) && (a1 % 100 != 100) || (a1 % 400 == 0)) {
		c_dias == 29;
	}
	else {
		c_dias == 30;
	}
}
void Fecha::incremento() {
		d1++;
		if ((d1 > validar_mes(m1, a1))){
			d1 = 1;
			m1++;
			if (m1 > 12) {
				m1 = 1;
				a1++;
			}
			cout << endl << d1 << "/" << m1 << "/" << a1;
		}
		else {
			cout << "Fecha no es valida \n";
		}

	}


int main()
{
	Fecha fh("", "","");
	fh.validar();
	fh.validar_mes();
	fh.incremento();
	return 0;
}