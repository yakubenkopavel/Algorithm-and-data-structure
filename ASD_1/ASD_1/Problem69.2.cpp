#include <iostream>

int main() {
	int n = 0;
	long long max = 0;
	long long* matrix = nullptr;
	int* matrixIndex = nullptr;

	std::cin >> n;
	matrix = new long long[n];
	matrixIndex = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> matrix[i];
	}

	if (n < 1 || n > 100000) {

	}
	else if (n == 2) {
		std::cout << "-1";
	}
	else if (n == 1) {
		std::cout << matrix[0] << std::endl;
		std::cout << "1";
	}
	else {
		matrix[1] = -1;
		matrix[2] += matrix[0];

		matrixIndex[2] = 0;

		for (int i = 3; i < n; i++) {

			if (matrix[i - 2] > matrix[i - 3]) {
				max = matrix[i - 2];
				matrixIndex[i] = i - 2;
			}
			else {
				max = matrix[i - 3];
				matrixIndex[i] = i - 3;
			}

			matrix[i] += max;
		}

		int index = matrixIndex[n - 1];
		int indexOutput = 2;
		matrix[0] = n;
		matrix[0] -= 1;
		matrix[1] = index;

		while (index) {
			index = matrixIndex[index];
			matrix[indexOutput] = index;
			indexOutput++;
		}

		std::cout << matrix[n - 1] << std::endl;

		for (int i = indexOutput - 1; i >= 0; i--) {
			if (i) {
				std::cout << (matrix[i] + 1) << " ";
			}
			else {
				std::cout << (matrix[i] + 1);
			}
		}

	}

	
	delete[] matrixIndex;
	delete[] matrix;
	
	return 0;
}
