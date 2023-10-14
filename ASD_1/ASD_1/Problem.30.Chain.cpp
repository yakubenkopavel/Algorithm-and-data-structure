#include <iostream>
#include <fstream>
#include <queue>
#include <stdio.h>

class Chain {
private:
	int sizeMatrix;
	int countDominos;
	
	int* result;
	int** matrix;


public:

	Chain(int size) {
		countDominos = 0;
		sizeMatrix = size;

		result = new int[sizeMatrix];
		matrix = new int* [sizeMatrix];
		for (int i = 0; i < sizeMatrix; i++) {
			matrix[i] = new int[sizeMatrix + 1];
			result[i] = 0;
		}

		for (int i = 0; i < sizeMatrix; i++) {
			for (int j = 0; j < sizeMatrix + 1; j++) {
				matrix[i][j] = 0;
			}
		}

	}

	~Chain() {
		delete[] result;
		delete[] matrix;
	}

	void input();
	bool connectedBFS();
	bool checkEuler();
	void output(int check); 
};

void Chain::input() {
	FILE* input;
	fopen_s(&input, "input.txt", "r");
	fscanf_s(input, "%d", &countDominos);

	int element1, element2;
	for (int i = 0; i < countDominos; i++) {
		fscanf_s(input, "%d", &element1);
		fscanf_s(input, "%d", &element2);
		result[element1] -= 1;
		result[element2] -= 1;
		matrix[element1][element2] += 1;
		matrix[element2][element1] += 1;

		matrix[element1][7] += 1;
		matrix[element2][7] += 1;
	}
}

void Chain::output(int check) {
	std::ofstream out("output.txt");
	if (check == 1) {
		out << "Yes";
	}
	else {
		out << "No";
	}
	out.close();
}

bool Chain::connectedBFS() {
	int count = 0;
	std::queue<int> q;

	for (int i = 0; i < sizeMatrix; i++) {
		if (result[i] < 0) {
			q.push(i);
			result[i] += 1;

			count++;

			while (!q.empty()) {
				int start = q.front();
				q.pop();

				for (int j = 0; j < sizeMatrix; j++) {
					if (matrix[start][j] > 0 && result[j] < 0) {
						q.push(j);
						result[j] += 1;
					}
				}

			}

		}
	}

	if (count == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Chain::checkEuler() {
	for (int i = 0; i < sizeMatrix; i++) {
		if (matrix[i][7] % 2 != 0) {
			return false;
		}
	}

	if (!connectedBFS()) {
		return false;
	}

	return true;
}

int main() {
	Chain start(7);
	start.input();
	if (start.checkEuler()) {
		start.output(1);
	}
	else {
		start.output(0);
	}
}