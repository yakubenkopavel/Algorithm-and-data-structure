#include <iostream>
#include <fstream>
#include <list>

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int n;
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
		out << result[i] << " ";
	}

	in.close();
	out.close();
}