#include <iostream>
#include <fstream>

int main() {
	FILE* input;
	FILE* output;
	fopen_s(&input, "input.txt", "r");
	fopen_s(&output, "output.txt", "w");

	int n, q, count;
	fscanf_s(input, "%d", &n);
	fscanf_s(input, "%d", &q);
	count = n;

	int* town = new int[n];
	int* size = new int[n];

	for (int i = 0; i < n; i++) {
		town[i] = i;
		size[i] = 1;
	}

	int u, v;
	for (int i = 0; i < q;i++) {
		fscanf_s(input, "%d", &u);
		fscanf_s(input, "%d", &v);
		u--;
		v--;

		if (count != 1) {
			while (u != town[u]) {
				u = town[u];
			}
			while (v != town[v]) {
				v = town[v];
			}

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

		fprintf_s(output, "%d", count);
		fprintf_s(output, "%s", "\n");
		std::cout << count << std::endl;
	}


	delete[] town;
	delete[] size;
	return 0;
}