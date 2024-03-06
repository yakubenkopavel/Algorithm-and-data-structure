#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

int parent(int child, int* town) {
	if (child == town[child]) {
		return child;
	}
	else {
		return town[child] = parent(town[child], town);
	}
}

int main() {
	FILE* input;
	FILE* output;
	fopen_s(&input, "input.txt", "r");
	fopen_s(&output, "output.txt", "w");

	int n, m, q, count;
	fscanf_s(input, "%d", &n);
	fscanf_s(input, "%d", &m);
	fscanf_s(input, "%d", &q);
	count = n;

	int* town = new int[n];
	int* size = new int[n];
	int** road = new int* [3];
	int* destr = new int[q];
	int* answer = new int[q];
	for (int i = 0; i < 3; i++) {
		road[i] = new int[m];
	}

	for (int i = 0; i < m;i++) {
		fscanf_s(input, "%d", &road[0][i]);
		fscanf_s(input, "%d", &road[1][i]);
		road[0][i]--;
		road[1][i]--;
		road[2][i] = 0;
	}

	for (int i = 0; i < q; i++) {
		fscanf_s(input, "%d", &destr[i]);
		destr[i]--;
		road[2][destr[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		town[i] = i;
		size[i] = 1;
	}

	int u, v;
	int j = 0;
	while (j < m && m!=q){
		if (road[2][j] != 1) {
			u = road[0][j];
			v = road[1][j];
			u = parent(u, town);
			v = parent(v, town);

			if (u != v) {
				if (size[v] > size[u]) {
					size[v] += size[u];
					town[u] = v;
				}
				else {
					size[u] += size[v];
					town[v] = u;
				}

				count--;
			}
		}
		
		j++;
	}

	for (int i = q-1; i >= 0;i--) {
		if (count == 1) {
			answer[i] = 1;
		}
		else {
			answer[i] = 0;

			u = road[0][destr[i]];
			v = road[1][destr[i]];

			u = parent(u, town);
			v = parent(v, town);

			if (u != v) {
				if (size[v] > size[u]) {
					size[v] += size[u];
					town[u] = v;
				}
				else {
					size[u] += size[v];
					town[v] = u;
				}

				count--;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		fprintf_s(output, "%d", answer[i]);
	}


	delete[] town;
	delete[] size;
	return 0;
}