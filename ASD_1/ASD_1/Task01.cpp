#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int n;
int count;
vector<vector<int>> list;
vector<int> met;
bool two;
bool connect;
int ma;

int bfs(int v) {
	int dols[] = { 1,0 };
	int count = 1;
	two = true;
	met[v] = 0;
	queue<int> fifo;
	fifo.push(v);
	while (!fifo.empty()) {
		int tmp = fifo.front();
		fifo.pop();
		for (int i = 0; i < list[tmp].size(); i++) {
			if (met[list[tmp][i]] == -1) {
				count++;
				met[list[tmp][i]] = (met[tmp] + 1) % 2;
				dols[(met[tmp] + 1) % 2]++;
				fifo.push(list[tmp][i]);
			}
			else if (met[list[tmp][i]] == met[tmp]) {
				two = false;
			}
		}
	}
	if (two) {
		if (dols[0] > dols[1]) {
			ma += dols[0];
		}
		else {
			ma += dols[1];
		}
	}
	else {
		ma++;
	}
	return count;
}

int main() {
	ifstream fin("input.txt");
	ma = 0;
	int j = 0;
	fin >> n;
	list.resize(n);
	met.assign(n, -1);
	string s;
	getline(fin, s);
	while (getline(fin, s)) {
		stringstream ss;
		ss = stringstream(s);
		while (ss)
		{
			int v;
			ss >> v;
			if (ss && v != 0) {
				list[j].push_back(v - 1);
			}
		}
		j++;
	}
	int count = bfs(0);


	ofstream fout("output.txt");
	if (count == n && !two) {
		std::cout << "YES";
	}
	else if (count == n && two) {
		std::cout << "NO" << "\n";
		std::cout << ma;
	}
	else if (count != n) {
		for (int i = 0; i < n; i++) {
			if (met[i] == -1) {
				count += bfs(i);
			}
		}
		std::cout << "NO" << "\n";
		std::cout << ma;
	}
}