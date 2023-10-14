//#include <iostream>
//#include <fstream>
//#include <string>
//
//
//int main() {
//	std::ifstream in("input.txt");
//	std::ofstream out("output.txt");
//
//	std::string str;
//	in >> str;
//
//	int len = str.length();
//	int** matrix = new int* [len];
//	for (int i = 0; i < len; i++) {
//		matrix[i] = new int[i + 1];
//	}
//
//	matrix[0][0] = 1;
//	for (int i = 1; i < len; i++) {
//		matrix[i][i] = 1;
//		if (str[i - 1] == str[i]) {
//			matrix[i][i - 1] = 2;
//		}
//		else {
//			matrix[i][i - 1] = 1;
//		}
//	}
//
//	for (int i = 2; i < len; i++) {
//		for (int j = i -2 ; j >= 0; j--) {
//			if (str[i] == str[j]) {
//				matrix[i][j] = matrix[i - 1][j + 1] + 2;
//			}
//			else {
//				if (matrix[i - 1][j] > matrix[i][j + 1]) {
//					matrix[i][j] = matrix[i - 1][j];
//				}
//				else {
//					matrix[i][j] = matrix[i][j + 1];
//				}
//			}
//		}
//	}
//
//	int sizeAnswer = matrix[len - 1][0];
//	out << sizeAnswer << std::endl;
//
//
//	int line = len - 1, column = 0;
//	std::string answer = "";
//	while(column <= line){
//		if (str[line] == str[column]) {
//			answer += str[line];
//			line--;
//			column++;
//		}
//		else {
//			if (matrix[line - 1][column] > matrix[line][column + 1]) {
//				line--;
//			}
//			else {
//				column++;
//			}
//		}
//	}
//	out << answer;
//	for (int i = sizeAnswer - answer.length() - 1; i >= 0; i--) {
//		out << answer[i];
//	}
//
//	delete[] matrix;
//	in.close();
//	out.close();
//
//	return 0;
//}