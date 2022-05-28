//#include <iostream>
//#include <fstream>
//
//int main() {
//	std::ifstream in("input.txt");
//	std::ofstream out("output.txt");
//	int c, m, n;
//	in >> m >> c >> n;
//	long long* table = new long long[m];
//	long long* numbers = new long long[n];
//
//	long long min = -1;
//	for (int i = 0; i < n; i++) {
//		in >> numbers[i];
//	}
//
//	for (int i = 0; i < m; i++) {
//		table[i] = min;
//	}
//
//	int it = 0;
//	int index = 0;
//	for (int i = 0; i < n; i++) {
//		it = 0;
//		do {
//			index = ((numbers[i] % m) + c*it) % m;
//			it++;
//		} while (table[index] != min && table[index] != numbers[i]);
//		table[index] = numbers[i];
//	}
//
//	for (int i = 0; i < m; i++) {
//		out << table[i] << " ";
//	}
//
//	delete[] numbers;
//	delete[] table;
//	in.close();
//	out.close();
//	return 0;
//}