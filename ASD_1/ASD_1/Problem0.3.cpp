//#include <iostream>
//#include <string>
//
//
//long long powerNumber(long long number, int power) {
//	const long long module = 1e9 + 7;
//	long long answer = number;
//
//	if (power == 0) {
//		return number;
//	}
//
//	for (int i = 0; i < power; i++) {
//		answer = (answer * answer) % module;
//	}
//	return answer;
//}
//
//long long* moduleInSum2(long long* pow, int& size) {
//	int count = 0;
//	std::string s = "";
//
//
//	long long module = 1e9 + 5;
//	long long module1 = 1e9 + 5;
//	
//	while (module) {
//		long long bit = module & 1;
//		module >>= 1;
//
//		if (bit == 1) {
//			count++;
//		}
//	}
//
//	pow = new long long[count];
//	count = 0;
//	int index = 0;
//	module = module1;
//	while (module) {
//		long long bit = module & 1;
//		module >>= 1;
//
//		if (bit == 1) {
//			pow[index] = count;
//			index++;
//		}
//		count++;
//	}
//	
//	size = index;
//	return pow;
//}
//
//int main() {
//	int n, k;
//	std::cin >> n >> k;
//
//	if (n < 0 || k < 0 || n > 1000000 || k > 1000000 || k > n) {
//		return 1;
//	}
//
//	int size = 0;
//	long long answer = 1;
//	long long* pow = nullptr;
//	const long long module = 1e9 + 7;
//	long long productLeft = 1, product1 = 1, productRight = 1;
//
//	for (int i = n - k + 1; i <= n; i++) {
//		productLeft = (productLeft * i ) % module;
//	}
//
//	for (int i = 2; i <= k; i++) {
//		product1 = (product1 * i) % module;
//	}
//
//	pow = moduleInSum2(pow, size);
//
//	for (int i = 0; i < size; i++) {
//		productRight = (productRight * powerNumber(product1, pow[i])) % module;
//	}
//
//	answer = (productLeft * productRight) % module;
//	std::cout << answer;
//
//	delete[] pow;
//
//	return 0;
//}