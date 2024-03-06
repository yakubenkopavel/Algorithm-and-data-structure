#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>

int main() {
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");

	int x = 0, y = 0, z = 0;
	std::string strA = "", strB = "";

	in >> x >> y >> z >> strA >> strB;

	int sizeA = strA.length(), sizeB = strB.length();

	int** matrix = new int* [2];

	for (int i = 0; i < 2; i++) {
		matrix[i] = new int[sizeA + 1];
	}

	for (int i = 0; i <= sizeA; i++) {
		matrix[0][i] = i * x;
	}


	int min = 0;
	int index = 0, index1 = 0;
	int par = 1;
	for (int i = 1; i <= sizeB; i++) {
		index = i % 2;
		index1 = (i + 1) % 2;

		matrix[index][0] = i * y;

		for (int j = 1; j <= sizeA; j++) {
			if (strA[j - 1] == strB[i - 1]) {
				par = 0;
			}
			else {
				par = 1;
			}

			min = matrix[index1][j] + y;

			if (min > (matrix[index][j-1] + x)) {
				min = matrix[index][j-1] + x;
			}

			if (min > (matrix[index1][j - 1] + z*par)) {
				min = matrix[index1][j - 1] + z*par;
			}

			matrix[index][j] = min;
		}
	}

	out << matrix[sizeB % 2][sizeA];

	in.close();
	out.close();

	delete[] matrix;

	return 0;
}