#include <iostream>
#include <fstream>
#include <queue>

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	int size;
	int** matrix;
	int* result;
	std::queue<int> q;

	in >> size;
	result = new int[size];
	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		result[i] = -1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0;j < size; j++) {
			in >> matrix[i][j];
		}
	}

	int lable = 1;

	for (int i = 0; i < size; i++) {
		if (result[i] == -1) {
			q.push(i);
			result[i] = lable;
			lable++;
		}

		while (!q.empty()) {
			int start = q.front();
			q.pop();

			for (int j = 0; j < size; j++) {
				if (matrix[start][j] == 1 && result[j] == -1) {
					q.push(j);
					result[j] = lable;
					lable++;
				}
			}

		}
	}

	for (int i = 0; i < size; i++) {
		out << result[i] << " ";
	}

	in.close();
	out.close();
}