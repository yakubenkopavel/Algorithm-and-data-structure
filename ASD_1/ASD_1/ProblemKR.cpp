//#include <iostream>
//#include <fstream>
//#include <math.h>
//
//int main() {
//	std::ifstream in("input.txt");
//	std::ofstream out("output.txt");
//
//	int size;
//	in >> size;
//
//	if (size == 0) {
//		out << 0;
//	}
//	else {
//		int* mass = nullptr;
//		int* f = nullptr;
//		mass = new int[size];
//		f = new int[size];
//
//		int number;
//		int count = 0;
//		for (int i = 0; i < size; i++) {
//			mass[i] = 0;
//			f[i] = 1;
//		}
//
//		int it = 0;
//		for (int i = 0; i < size; i++) {
//			in >> number;
//
//			if (number == 0) {
//				count++;
//			}
//			else if (number < 0) {
//				mass[it] = (-1) * number;
//				it++;
//			}
//			else {
//				mass[it] = number;
//				it++;
//			}
//		}
//
//		if (count >= 1) {
//			size = size - count;
//		}
//
//		int min = 0;
//		int index = 0;
//		int temp = 0;
//		for (int i = 0; i < size; i++) {
//			min = mass[i];
//			index = i;
//			for (int j = i + 1; j < size; j++) {
//				if (min > mass[j]) {
//					min = mass[j];
//					index = j;
//				}
//			}
//			temp = mass[i];
//			mass[i] = mass[index];
//			mass[index] = temp;
//		}
//
//		if (count >= 1) {
//			size++;
//		}
//
//		int max = 0;
//		int check = 0;
//		for (int i = 1; i < size; i++) {
//			max = f[i];
//			check = 0;
//			for (int j = 0; j < i; j++) {
//				if (mass[i] % mass[j] == 0 && max <= f[j]) {
//					max = f[j];
//					check = 1;
//				}
//			}
//			if (check == 1) {
//				f[i] = max + 1;
//			}
//
//		}
//
//		max = f[0];
//		for (int i = 1; i < size; i++) {
//			if (max < f[i]) {
//				max = f[i];
//			}
//		}
//
//		out << max;
//
//		delete[] f;
//		delete[] mass;
//	}
//
//
//	in.close();
//	out.close();
//}