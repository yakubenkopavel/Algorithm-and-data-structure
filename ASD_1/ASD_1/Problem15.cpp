#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

void inputMatrix(int** matrix, int index, std::string str) {
	std::stringstream ss(str);
	std::string number;
	while (ss >> number) {
		int j = stoi(number) - 1;
		if (j >= 0) {
			matrix[index][j] = 1;
		}
	}
}

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	bool check = true;
	int countTown;
	int* result = nullptr;
	int** matrix = nullptr;
	std::queue<int> q;

	in >> countTown;
	matrix = new int* [countTown];
	result = new int[countTown];
	for (int i = 0; i < countTown; i++) {
		matrix[i] = new int[countTown];
		result[i] = -1;
	}

	for (int i = 0; i < countTown; i++) {
		for (int j = 0; j < countTown; j++) {
			matrix[i][j] = 0;
		}
	}

	std::string str;
	getline(in, str);
	for (int i = 0; i < countTown; i++) {
		getline(in, str);
		inputMatrix(matrix, i, str);
	}

	bool checkOdd;
	int countOne;
	int countZero;
	int power = 0;

	for (int i = 0; i < countTown; i++) {
		if (result[i] == -1) {
			q.push(i);
			result[i] = 0;
			if (i != 0) {
				check = false;
			}


			countOne = 0;
			countZero = 1;
			checkOdd = false;
			while (!q.empty()) {
				int start = q.front();
				q.pop();

				for (int j = 0; j < countTown; j++) {
					if (matrix[start][j] == 1) {
						if (result[j] == -1) {
							q.push(j);
							result[j] = (result[start] + 1) % 2;
							if (result[j] == 0) {
								countZero++;
							}
							else {
								countOne++;
							}
						}
						else {
							if (result[j] == result[start]) {
								checkOdd = true;
							}
						}
					}
				}
			}

			if (checkOdd) {
				power++;
			}
			else {
				if (countZero > countOne) {
					power += countZero;
				}
				else {
					power += countOne;
				}
			}

			if (i == 0 && !checkOdd) {
				check = false;
			}
		}
	}

	if (check) {
		out << "YES";
	}
	else {
		out << "NO" << std::endl;
		out << power;
	}


	delete[] result;
	delete[] matrix;

	in.close();
	out.close();
}