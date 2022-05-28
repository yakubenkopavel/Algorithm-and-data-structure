//#include <iostream>
//#include <fstream>
//
//int main() {
//	std::ifstream in("huffman.in");
//	std::ofstream out("huffman.out");
//
//	int n = 0;
//	long long len = 0;
//	long long* arrays = nullptr;
//	long long* sumArrays = nullptr;
//
//	in >> n;
//	arrays = new long long[n];
//	sumArrays = new long long[n];
//	for (int i = 0; i < n; i++) {
//		in >> arrays[i];
//		sumArrays[i] = -1;
//	}
//	
//
//	long long min = 0;
//	int first = 0;
//	int second = 0;
//	int check = 0;
//	for (int i = 0; i < n - 1; i++) {
//		if (first >= n) {
//			check = 2;
//		}
//		else if (first + 1 >= n) {
//			if (sumArrays[second + 1] < arrays[first] && second + 1 < i) {
//				check = 2;
//			}
//			else {
//				check = 3;
//			}
//		}
//		else {
//			min = arrays[first] + sumArrays[second];
//			check = 3;
//			if (sumArrays[second + 1] < arrays[first] && second + 1 < i) {
//				min = sumArrays[second + 1] + sumArrays[second];
//				check = 2;
//			}
//
//			if (min < arrays[first + 1] + arrays[first] && second < i) {
//				
//			}
//			else {
//				check = 1;
//			}
//		}
//
//
//		if (check == 1) {
//			sumArrays[i] = arrays[first] + arrays[first + 1];
//			first += 2;
//		}
//		else if (check == 2) {
//			sumArrays[i] = sumArrays[second] + sumArrays[second + 1];
//			second += 2;
//		}
//		else {
//			sumArrays[i] = sumArrays[second] + arrays[first];
//			second++;
//			first++;
//		}
//		len += sumArrays[i];
//	}
//
//
//
//	out << len;
//
//
//	delete[] sumArrays;
//	delete[] arrays;
//	in.close();
//	out.close();
//	return 0;
//}