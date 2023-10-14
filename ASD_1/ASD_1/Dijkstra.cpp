//#include <iostream>
//#include <fstream>
//#include <list>
//#include <queue>
//
//int main() {
//	FILE* input;
//	std::ofstream out("output.txt");
//	fopen_s(&input, "input.txt", "r");
//
//	std::list<int>* edge;
//	std::list<int>* weight;
//	int n, m;
//	fscanf_s(input, "%d", &n);
//	fscanf_s(input, "%d", &m);
//	edge = new std::list<int>[n + 1];
//	weight = new std::list<int>[n + 1];
//
//	int index;
//	int index1;
//	int temp;
//	for (int i = 0; i < m; i++) {
//		fscanf_s(input, "%d", &index);
//		fscanf_s(input, "%d", &index1);
//		fscanf_s(input, "%d", &temp);
//
//		edge[index].push_back(index1);
//		edge[index1].push_back(index);
//		weight[index].push_back(temp);
//		weight[index1].push_back(temp);
//	}
//
//	bool* process = new bool[n + 1];
//	long long* distance = new long long[n + 1];
//	for (int i = 0; i < n+1;i++) {
//		process[i] = false;
//		distance[i] = -1;
//	}
//	std::priority_queue<std::pair<long long, int>> q;
//	q.push(std::make_pair(0, 1));
//	
//
//	long long tempL = 0;
//	while (!q.empty()) {
//		index = q.top().second;
//		tempL = (-1) * q.top().first;
//		q.pop();
//
//		if (!process[index]) {
//			distance[index] = tempL;
//			process[index] = true;
//
//			int count = edge[index].size();
//			for (int i = 0; i < count; i++) {
//				int u = edge[index].back();
//				long long len = distance[index] + weight[index].back();
//				edge[index].pop_back();
//				weight[index].pop_back();
//
//				if (!process[u]) {
//					q.push(std::make_pair((-1) * len, u));
//				}
//			}
//		}
//	}
//
//	out << distance[n];
//
//	delete[] edge;
//	delete[] weight;
//	delete[] process;
//	out.close();
//}