//#include <iostream>
//#include <fstream>
//#include <stdio.h>
//
//class DFS {
//private:
//	int n;
//	int index;
//	int* result;
//	int** matrix;
//
//
//public:
//
//	void input() {
//		index = 1;
//
//
//		FILE* input;
//		fopen_s(&input, "input.txt", "r");
//
//		fscanf_s(input, "%d", &n);
//		result = new int[n];
//		matrix = new int* [n];
//		for (int i = 0; i < n; i++) {
//			matrix[i] = new int[n];
//			result[i] = -1;
//		}
//
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0;j < n; j++) {
//				fscanf_s(input, "%d", &matrix[i][j]);
//			}
//		}
//	}
//
//	void dfs(int i) {
//		result[i] = index;
//		index++;
//
//		for (int j = 0; j < n; j++) {
//			if (matrix[i][j] == 1 && result[j] == -1) {
//				dfs(j);
//			}
//		}
//	}
//
//	void loop() {
//		for (int i = 0; i < n; i++) {
//			if (result[i] == -1) {
//				dfs(i);
//			}
//		}
//	}
//
//	void output() {
//		std::ofstream out("output.txt");
//		for (int i = 0; i < n; i++) {
//			out << result[i] << " ";
//		}
//		out.close();
//	}
//};
//
//int main() {
//	DFS start;
//	start.input();
//	start.loop();
//	start.output();
//}