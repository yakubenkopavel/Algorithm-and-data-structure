#include <iostream>
#include <fstream>

void merge(long long* arrayNumber, int* arrayIndex, int first, int last) {
	int median = (first + last) / 2;
	int start = first;
	int final = median + 1;
	long long* mas = new long long[last+1];
	int* mas1 = new int[last+1];

	for (int i = first; i <= last; i++) {
		if (start <= median && (final > last || arrayNumber[start] < arrayNumber[final])) {
			mas[i] = arrayNumber[start];
			mas1[i] = arrayIndex[start];
			start++;
		}
		else {
			mas[i] = arrayNumber[final];
			mas1[i] = arrayIndex[final];
			final++;
		}
	}

	for (int i = first; i <= last; i++) {
		arrayNumber[i] = mas[i];
		arrayIndex[i] = mas1[i];
	}

	delete[] mas;
	delete[] mas1;
}

void mergeSort(long long* arrayNumber, int* arrayIndex, int first, int last) {
	if (first < last) {
		mergeSort(arrayNumber, arrayIndex, first, (first+last)/2);
		mergeSort(arrayNumber, arrayIndex, (first + last) / 2 + 1, last);
		merge(arrayNumber, arrayIndex, first, last);
	}
}

int getMax(int* arrayFenwick, int index) {
	int result = -1;
	for (int i = index; i >= 0; i = (i & (i + 1)) - 1) {
		if (result < arrayFenwick[i]) {
			result = arrayFenwick[i];
		}
	}
	return result;
}


void insert(int* arrayFenwick, int val, int index, int size) {
	for (int i = index; i <= size; i = i | (i + 1)) {
		if (val > arrayFenwick[i]) {
			arrayFenwick[i] = val;
		}
	}
}

int main() {
	std::ifstream in("m-gaps.in");
	std::ofstream out("m-gaps.out");

	int n, m = 0;
	long long* arrayNumbers;
	int* arrayIndex;
	in >> n;
	in >> m;

	arrayIndex = new int[n];
	arrayNumbers = new long long[n];
	for (int i = 0; i < n; i++) {
		arrayIndex[i] = i;
		in >> arrayNumbers[i];
	}

	mergeSort(arrayNumbers, arrayIndex, 0, n - 1);
	for (int i = 0; i < n; i++) {
		arrayIndex[i]+= 1;
	}

	int** arrayFenwick = new int*[2];
	for (int i = 0; i < 2; i++) {
		arrayFenwick[i] = new int[n + 1];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= n; j++) {
			arrayFenwick[i][j] = 0;
		}
	}

	int prevMax1 = 0;
	int prevMax2 = 0;
	int index1 = 0;
	int index2 = 0;
	for (int k = 0; k <= m; k++) {
		index2 = k % 2;
		index1 = (k + 1) % 2;
		for (int i = 0; i < n; i++) {
			prevMax2 = getMax(arrayFenwick[index2], arrayIndex[i] - 1);
			prevMax1 = getMax(arrayFenwick[index1], arrayIndex[i] - 1);
			if (prevMax1 > prevMax2) {
				insert(arrayFenwick[index1], prevMax1 + 1, arrayIndex[i], n);
			}
			else {
				insert(arrayFenwick[index1], prevMax2 + 1, arrayIndex[i], n);
			}
		}
	}

	out << getMax(arrayFenwick[index1], n);

	in.close();
	out.close();
	return 0;
}