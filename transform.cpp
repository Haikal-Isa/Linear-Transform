#include <iostream>
#include <cmath>
#include <iomanip>
#define cout std::cout
#define cin std::cin

struct Vector
{
	double x, y;
	void translate(int x2, int y2)
	{
		x += x2;
		y += y2;
	}
	void reflect(char ch)
	{
		if (ch == 'x')
		{
			y *= -1;
		}
		if (ch == 'y')
		{
			x *= -1;
		}
	}
	void rotate(int deg)
	{
		double alpha = acos(x / hypotf(x, y)) * 180 / M_PI;
		double beta = asin(y / hypotf(x, y)) * 180 / M_PI;
		double r = hypotf(x, y);
		x = r * cos((alpha + deg) * M_PI / 180);
		y = r * sin((beta + deg) * M_PI / 180);
	}
};

int main()
{
	Vector v1;
	cout << "Tentukan vektor: ";
	while (!(cin >> v1.x >> v1.y))
	{
		cout << "itu bukan vektor\n";
		cin.clear();
		cin.ignore();
	}
	cout << "Tentukan Transformasi:\n";
	cout << "1. Translasi\n"
		 << "2. Refleksi\n"
		 << "3. Rotasi\n";
	int ch;
	while (!(cin >> ch) or ch < 1 or ch > 3)
	{
		cout << "Gunakan angka antara 1, 2, atau 3.\n";
		cin.clear();
		cin.ignore();
	}
	int x2, y2;
	char k;
	int deg;
	switch (ch)
	{
	case 1:
		cout << "Masukkan koordinat pangkal yang baru: ";
		while (!(cin >> x2 >> y2))
		{
			cout << "Salah ";
			cin.clear();
			cin.ignore();
		}
		v1.translate(x2, y2);
		cout << "Koordinat setelah translasi\n"
			 << v1.x << ", " << v1.y;
		break;
	case 2:
		cout << "berdasarkan sumbu x atau y?\n";
		cin >> k;
		while ((k != 'x' and k != 'y'))
		{
			cout << "berdasarkan sumbu x atau y?\n";
			cin >> k;
		}
		v1.reflect(k);
		cout << "Hasil Refleksi\n"
			 << v1.x << ", " << v1.y;
		break;
	case 3:
		cout << "Masukkan derajat\n";
		while (!(cin >> deg))
		{
			cout << "Masukkan derajat\n";
			cin.clear();
			cin.ignore();
		}
		v1.rotate(deg);
		cout << "Hasil rotasi\n";
		cout << std::fixed;
		cout << v1.x << ", " << v1.y;
		break;
	}
	return 0;
}