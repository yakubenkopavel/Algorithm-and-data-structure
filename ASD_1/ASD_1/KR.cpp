#include <iostream>
#include<fstream>

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	int n;
	int** mas;
	int* numbers;
	in >> n;

	numbers = new int[n];
	mas = new int*[n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];
		in >> numbers[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mas[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		mas[i][i] = numbers[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (numbers[i] > numbers[i + 1]) {
			mas[i][i + 1] = numbers[i];
		}
		else {
			mas[i][i + 1] = numbers[i + 1];
		}
	}

	int a = 0;
	int b = 0;
	int start = 0;
	if (n % 2 == 0) {
		start = 3;
	}
	else {
		start = 2;
	}
	for (int j = start; j < n; j++) {
		for (int i = j - start; i >= 0; i-=2){

			if (mas[i + 2][j] > mas[i + 1][j - 1]) {
				a = numbers[i] + mas[i + 1][j - 1];
			}
			else {
				a = numbers[i] + mas[i + 2][j];
			}


			if (mas[i + 1][j - 1] > mas[i][j - 2]) {
				b = numbers[j] + mas[i][j - 2];
			}
			else {
				b = numbers[j] + mas[i + 1][j - 1];
			}

			

			if (a > b) {
				mas[i][j] = a;
			}
			else {
				mas[i][j] = b;
			}
		}
	}

	out << mas[0][n - 1];

	delete[] mas;
	delete[] numbers;
	in.close();
	out.close();
}