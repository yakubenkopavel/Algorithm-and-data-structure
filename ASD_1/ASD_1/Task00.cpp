#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include <numeric>

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	std::set<long long> set;
	std::string line;


	while (std::getline(in, line)) {
		long long number = std::stoll(line);
		if (-4294967296 <= number && number <= 4294967295) {
			set.insert(number);
		}
	}

	out << accumulate(set.begin(), set.end(), 0LL);

	out.close();
	in.close();
	return 0;
}