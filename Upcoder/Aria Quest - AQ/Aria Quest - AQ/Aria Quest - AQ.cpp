#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, p;
int u, v, w;
vector<bool> check;
vector<bool> R(100000, false);
vector<vector<int> > map;

int solve(vector<vector<int> > map) {
	int start = 0;
	int min = 1e9;
	vector<int> path(n); // path from start to i
	vector<int> dist(n, 1e9); // distance from start to i
	dist[start] = 0;
	check[start] = true;
	for (int i = 0; i < n - 1; i++) {
		min = 1e9;
		for (int j = 1; j < n; j++) {
			if (map[start][j] + dist[start] < dist[j] && map[start][j] != 0 && check[j] == false && R[(map[start][j] + dist[start] % p)] == false) {
				dist[j] = map[start][j] + dist[start];
				path[j] = start;
			}
		}
		for (int j = 1; j < n; j++) {
			if (dist[j] < min && check[j] == false) {
				min = dist[j];
				start = j;
			}
		}
		check[start] = true;
	}
	return dist[n - 1];
}

void input(vector<vector<int> >& map) {
	string tmp;
	cin >> n >> m >> p;
	cin.ignore();
	getline(cin, tmp);
	stringstream ss(tmp);

	int x;
	while (ss >> x) {
		R[x] = true;
	}

	map.resize(n);

	for (int i = 0; i < n; i++) {
		map[i].resize(n, 0);
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		map[u][v] = w;
		map[v][u] = w;
	}
	check.resize(n, false);
}

int main() {
	int minVal;
	input(map);
	minVal = solve(map);
	cout << (minVal == 1e9 ? -1 : minVal);
	return 0;
}