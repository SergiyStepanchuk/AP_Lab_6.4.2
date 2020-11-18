// Lab_6_4_2
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
double myrand(const T& min, const T& max) {
	return (T)(rand()) / RAND_MAX * (max - min) + min;
}

void draw_line(const int& size, const char& c = '-') {
	cout << c;
	if (size > 1) {
		draw_line(size - 1, c);
		return;
	}
	cout << endl;
}

template <typename T>
void full_mass(T* mass, int size, const T* dia) {
	mass[size - 1] = myrand(dia[0], dia[1]);
	if (size > 1)
		full_mass<T>(mass, size - 1, dia);
}

template <typename T>
void draw_mass_recurs(const T* mass, const int& size, const int& c_space) {
	if (size > 1)
		draw_mass_recurs<T>(mass, size - 1, c_space);

	cout << "|" << setw(c_space - 1) << mass[size - 1];
}

template <typename T>
void draw_mass(const T* mass, const int& size, const int& c_space) {
	draw_line(size * c_space + 2);
	draw_mass_recurs(mass, size, c_space);
	cout << " |" << endl;
	draw_line(size * c_space + 2);
}

double sum_dod(double* mass, const int& size) {
	return size > 1 ?
		(mass[size - 1] > 0 ? mass[size - 1] : 0) + sum_dod(mass, size - 1) :
		mass[size - 1] > 0 ? mass[size - 1] : 0;
}

int min_(double* mass, int size) {
	if (--size > 0) {
		int b = min_(mass, size);
		return mass[size] < mass[b] ? size : b;
	}
	else return 0;
}

double sum(double* mass, const int& size) {
	return size > 1 ? mass[size - 1] + sum_dod(mass, size - 1) : mass[size - 1];
}

void sort_half_(double* mass, const int& max, const int& j = 0) {
	if (j < max - 1 && mass[j] > mass[j + 2])
		swap(mass[j], mass[j + 2]);

	if (j > 0 && mass[j - 1] > mass[j + 1])
		swap(mass[j - 1], mass[j + 1]);

	if (j + 2 < max)
		sort_half_(mass, max, j + 2);
}

void sort_half(double* mass, const int& size, const int& i = 0) {
	if (i < size - 1) {
		sort_half_(mass, size - i - 1);
		sort_half(mass, size, i + 2);
	}
}

void main() {
	srand(time(NULL));
	const int c_space = 6; // ������� ���� ��� ���������� �� ���� ������ �������, ��� ����� � �������
	double dia[2]; // �������, n
	int n;

	cout << "n = "; cin >> n;
	cout << "dia start = "; cin >> dia[0];
	cout << "dia end = "; cin >> dia[1];
	cout.precision(2);

	double* mass = new double[n];
	full_mass<double>(mass, n, dia);
	draw_mass(mass, n, c_space);

	cout.precision(10);

	cout << "1.1 sum dod: " << sum_dod(mass, n) << endl;
	cout << "1.2 min index: " << min_(mass, n) << endl;
	cout << "1.2 sum to min: " << sum(mass, min_(mass, n)) << endl;
	cout << "2. sort_half" << endl;
	cout.precision(2);
	sort_half(mass, n);
	draw_mass(mass, n, c_space);

	delete[] mass;

}
