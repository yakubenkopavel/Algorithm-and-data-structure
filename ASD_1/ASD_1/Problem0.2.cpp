//#include <iostream>
//
//int main() {
//	int n, k;
//	const long long module = 1e9+7;
//	long long answer = 1;
//	std::cin >> n >> k;
//
//	if (n < 0 || k < 0 || n > 1000 || k > 1000 || k > n) {
//		return 1;
//	}
//
//	long long** matrix;
//	matrix = new long long* [n + 1];
//
//	matrix[0] = new long long[1];
//	matrix[0][0] = 1;
//
//	for (int i = 1; i < n + 1; i++) {
//		matrix[i] = new long long[1 + (i / 2) + (i % 2)];
//	}
//
//	if (k > n / 2) {
//		k = n - k;
//	}
//
//	for (int i = 1; i < n + 1; i++) {
//		matrix[i][0] = 1;
//		int limit = i / 2;
//
//		if (k < limit) {
//			limit = k;
//		}
//
//		for (int j = 1; j <= limit; j++) {
//			matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
//			matrix[i][j] %= module;
//		}
//		if (i % 2 == 1) {
//			matrix[i][limit + 1] = matrix[i][limit];
//		}
//	}
//
//	answer = matrix[n][k];
//
//	std::cout << answer;
//
//
//	delete[] matrix;
//	return 0;
//}