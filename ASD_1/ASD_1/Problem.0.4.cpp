#include <iostream>
#include <list>
#include <fstream>

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	/*int n;
	int* result;

	in >> n;
	result = new int[n];
	for (int i = 0; i < n; i++) {
		result[i] = 0;
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> temp;
			if (temp == 1) {
				result[j] = i + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << result[i] << " ";
	}*/

	/*int n, m;
	std::list<int>* arr;
	in >> n >> m;
	arr = new std::list<int>[n];

	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < m; i++) {
		in >> temp1 >> temp2;
		arr[temp1 - 1].push_front(temp2);
		arr[temp2 - 1].push_front(temp1);
	}

	for (int i = 0; i < n; i++) {
		std::cout << arr[i].size() << " ";
		for (int k : arr[i]) {
			std::cout << k << " ";
		}
		std::cout << std::endl;
	}*/

	/*int n;
	in >> n;
	int* result = new int[n];
	for (int i = 0; i < n; i++) {
		result[i] = 0;
	}

	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < n; i++) {
		in >> temp1 >> temp2;
		result[temp2 - 1] = temp1;
	}
	for (int i = 0; i < n; i++) {
		std::cout << result[i] << " ";
	}*/

	int n, m;
	in >> n >> m;
	int** result = new int* [n];
	for (int i = 0; i < n; i++) {
		result[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = 0;
		}
	}

	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		in >> temp1 >> temp2;
		result[temp1 - 1][temp2 - 1] = 1;
		result[temp2 - 1][temp1 - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << result[i][j] <<" ";
		}
		std::cout << std::endl;
	}
}