//#include <iostream>
//#include <fstream>
//#include <string>
//
//int main() {
//	std::ifstream in("input.txt");
//	std::ofstream out("output.txt");
//
//	std::string line;
//	int s = 0;
//	int* n = nullptr;
//	int* m = nullptr;
//
//	std::getline(in, line);
//	s = std::stoi(line);
//	if (s < 2 || s > 100) {
//		return 1;
//	}
//
//
//	n = new int[s];
//	m = new int[s];
//
//	for (int i = 0; i < s; i++) {
//		in >> n[i];
//		in >> m[i];
//
//		if (n[i] < 1 || m[i] < 1 || n[i] > 100 || m[i] > 100) {
//			return 1;
//		}
//	}
//
//	int** matrix;
//
//	matrix = new int* [s];
//	for (int i = 0; i < s; i++) {
//		matrix[i] = new int[i + 1];
//	}
//
//	int min = 0;
//	int temp = 0;
//	for (int i = 0; i < s; i++) {
//		for (int j = i; j >= 0; j--) {
//			if(i == j){
//				matrix[i][j] = 0;
//			}
//			else if (j == (i - 1)) {
//				matrix[i][j] = n[j] * m[j] * m[i];
//			}
//			else {
//				for (int k = j; k < i; k++) {
//					temp = matrix[k][j] + matrix[i][k + 1] + n[j] * m[k] * m[i];
//					if (min == 0 || temp < min) {
//						min = temp;
//					}
//				}
//
//				matrix[i][j] = min;
//				min = 0;
//			}
//		}
//	}
//
//	out << matrix[s - 1][0];
//
//
//	delete[] matrix;
//
//	in.close();
//	out.close();
//
//	return 0;
//}