#include<iostream>
#include<string>
#include<stdio.h>



int searchX(long long x, long long* arrayNumbers, int sizeNumbers) {
	int start = 0;
	int end = sizeNumbers;
	int median = 0;

	while (start != end) {
		median = start + (end - start) / 2;

		if (x == arrayNumbers[median]) {
			return 1;
		}
		else if (x < arrayNumbers[median]) {
			end = median;
		}
		else {
			start = median + 1;
		}

	}

	return 0;
}

int searchLeft(long long x, long long* arrayNumbers, int sizeNumbers) {
	int start = 0;
	int end = sizeNumbers;
	int median = 0;

	while (start != end) {
		median = start + (end - start) / 2;

		if (arrayNumbers[median] >= x) {
			end = median;
		}
		else {
			start = median + 1;
		}

	}

	return start;
}

int searchRight(long long x, long long* arrayNumbers, int sizeNumbers) {
	int start = 0;
	int end = sizeNumbers;
	int median = 0;

	while (start != end) {
		median = start + (end - start) / 2;

		if (arrayNumbers[median] > x) {
			end = median;
		}
		else {
			start = median + 1;
		}
	}

	return start;
}


int main() {
	int sizeNumbers = 0;
	long long* arrayNumbers;
	int sizeRequest = 0;
	long long* arrayRequest;


	std::string str;
	std::string number = "";
	int count = 0;
	int len = 0;
	getline(std::cin, str, '\n');
	sizeNumbers = std::stoi(str);
	if (sizeNumbers < 1 || sizeNumbers > 300000) {
		return -1;
	}
	arrayNumbers = new long long[sizeNumbers];

	getline(std::cin, str, '\n');
	len = str.length();
	for (int i = 0; i < sizeNumbers; i++) {
		while (str[count] != ' ' && count < len) {
			number += str[count];
			count++;
		}
		count++;

		arrayNumbers[i] = std::stoll(number);
		if (arrayNumbers[i] < -4294967296 || arrayNumbers[i] > 4294967295) {
			return -1;
		}
		number = "";
	}
	count = 0;

	getline(std::cin, str, '\n');
	sizeRequest = std::stoi(str);
	if (sizeRequest < 1 || sizeRequest > 300000) {
		return -1;
	}
	arrayRequest = new long long[sizeRequest];

	getline(std::cin, str, '\n');
	len = str.length();
	for (int i = 0; i < sizeRequest; i++) {
		while (str[count] != ' ' && count < len) {
			number += str[count];
			count++;
		}
		count++;

		arrayRequest[i] = std::stoll(number);
		if (arrayRequest[i]  < -4294967296 || arrayRequest[i] > 4294967295) {
			return -1;
		}
		number = "";
	}
	

	for (int i = 0; i < sizeRequest; i++) {
		printf("%d", searchX(arrayRequest[i], arrayNumbers, sizeNumbers));
		printf("%c", ' ');
		printf("%d", searchLeft(arrayRequest[i], arrayNumbers, sizeNumbers));
		printf("%c", ' ');
		printf("%d", searchRight(arrayRequest[i], arrayNumbers, sizeNumbers));
		printf("%c", '\n');
	}

	delete[] arrayNumbers;
	delete[] arrayRequest;

	return 0;
}
