//#include <iostream>
//#include <fstream>
//
//int searchRight(long long x, long long* arrayNumbers, int sizeNumbers) {
//	int start = 0;
//	int end = sizeNumbers;
//	int median = 0;
//
//	while (start != end) {
//		median = start + (end - start) / 2;
//
//		if (arrayNumbers[median] >= x) {
//			end = median;
//		}
//		else {
//			start = median + 1;
//		}
//	}
//
//	return start;
//}
//
//int main() {
//	std::ifstream in("input.txt");
//	std::ofstream out("output.txt");
//
//	int n = 0;
//	int sizeLine = 0;
//	in >> n;
//	if (n < 1 || n > 700000) {
//		return 1;
//	}
//
//	long long* arrays = new long long[n];
//	long long* maxLine = new long long[n];
//
//	for (int i = 0; i < n; i++) {
//		in >> arrays[i];
//	}
//
//	int count = 1;
//	int index = 0;
//	int end = 1;
//	maxLine[0] = arrays[0];
//
//	for (int i = 1; i < n; i++) {
//		index = searchRight(arrays[i], maxLine, end);
//
//		if (index == count) {
//			maxLine[index] = arrays[i];
//			count++;
//			end++;
//		}
//
//		if (arrays[i] <= maxLine[index]) {
//			maxLine[index] = arrays[i];
//		}
//	}
//
//	out << count;
//
//	delete[] maxLine;
//	delete[] arrays;
//
//	in.close();
//	out.close();
//
//	return 0;
//}