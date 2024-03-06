#include<iostream>
#include<string>
#include<fstream>


bool check(long long* key, int* parent, short* label, int* root, char* side, int n) {
	int parentIndex = 0;
	int index = 0;
	int parent1 = 0;

	for (int i = 1; i < n; i++) {
		parentIndex = parent[i] - 1;

		if (side[i] == 'L') {
			if (key[i] >= key[parentIndex]) {
				return false;
			}
			else if(side[parentIndex] == 'R') {5
				if (key[i] < key[parent[parentIndex] - 1]) {
					return false;
				}
				root[i] = parent[parentIndex] - 1;
				label[i] = 2;
			}
			else if (label[parentIndex] == 2) {
				root[i] = root[parentIndex];

				if (key[i] < key[root[i]]) {
					return false;
				}
				label[i] = 2;
			}
		}
		else if (side[i] == 'R') {
			if (key[i] < key[parentIndex]) {
				return false;
			}
			else if (side[parentIndex] == 'L'){9
				if (key[i] >= key[parent[parentIndex] - 1] ) {
					return false;
				}
				root[i] = parent[parentIndex] - 1;
				label[i] = 1;
			}
			else if (label[parentIndex] == 1) {
				root[i] = root[parentIndex];

				if (key[i] >= key[root[i]]) {
					return false;
				}
				label[i] = 1;
			}
		}
	}

	return true;
}

int main() {
	std::ifstream in("bst.in");
	std::ofstream out("bst.out");

	std::string line;

	long long* key;
	int* parent;
	int* root;
	short* label;
	char* side;


	int n = 0;
	int n1 = 0;
	int p = 0;
	long long m = 0;

    std::getline(in, line);
	n = std::stoi(line);
	if (n < 1 || n > 800000) {
		return -1;
	}
	n1 = n - 1;

	key = new long long[n];
	parent = new int[n];
	root = new int[n];
	label = new short[n];
	side = new char[n];

	std::getline(in, line);
	m = std::stoll(line);
	if (m < -4294967296 || m > 4294967295) {
		return -1;
	}

	key[0] = m;
	parent[0] = 0;
	root[0] = 0;
	label[0] = 0;
	side[0] = ' ';


	for (int pos = 1; pos < n; pos++) {
		std::getline(in, line, ' ');
		m = std::stoll(line);

		std::getline(in, line, ' ');
		p = std::stoi(line);

		std::getline(in, line);

		if ( (-4294967296 <= m && m <= 4294967295) && (1 <= p && p <= n1) ) {
			key[pos] = m;
			parent[pos] = p;
			root[pos] = 0;
			label[pos] = 0;
			side[pos] = line[0];
		}
	}

	if (check(key, parent, label, root, side, n) == true) {
		out << "YES";
	}
	else {
		out << "NO";
	}


	delete[] key;
	delete[] parent;
	delete[] root;
	delete[] label;
	delete[] side;

	in.close();
	out.close();
	return 0;
}