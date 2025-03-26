#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, p, x, y;
int u, v, w;
vector<bool> check;
vector<vector<int> > map;

int solve(vector<vector<int> > map) {
	int start = x;
	int min = 1e9;
	vector<int> path(n); // path from start to i
	vector<int> dist(n, 1e9); // distance from start to i
	dist[start] = 0;
	check[start] = true;

	for (int i = 0; i < n - 1; i++) {
		min = 1e9;
		for (int j = 1; j < n; j++) {
			if (map[start][j] + dist[start] < dist[j] && map[start][j] != 0 && check[j] == false && (map[start][j] + dist[start]) % p != 0) {
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
	return dist[y];
}

void input(vector<vector<int> >& map) {
	string tmp;
	cin >> n >> m >> p >> x >> y;
	
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