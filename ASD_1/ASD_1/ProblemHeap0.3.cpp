//#include <iostream>
//#include <fstream>
//
//int main() {
//	std::ifstream  in("input.txt");
//	std::ofstream out("output.txt");
//
//	int n = 0;
//	int* arrays;
//
//	in >> n;
//	arrays = new int[n];
//	for (int i = 0; i < n; i++) {
//		in >> arrays[i];
//	}
//
//	int check = 0;
//	for (int i = 1; i < n; i++) {
//		if (arrays[i] >= arrays[(i - 1) / 2]) {
//
//		}
//		else {
//			check = 1;
//			break;
//		}
//	}
//
//	if (check == 0) {
//		out << "Yes";
//	}
//	else {
//		out << "No";
//	}
//
//
//	delete[] arrays;
//	in.close();
//	out.close();
//	return 0;
//}