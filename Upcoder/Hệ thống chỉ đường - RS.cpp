#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int v, e;
int s;
vector<vector<int>> map;

void input() {
	cin >> v >> e;
	map.resize(v, vector<int>(v));

	int a, b, c;
	for (int i = 0; i < e; i++) {

		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
	}
	cin >> s;
}

void solve() {
	int start(s), min(1e9);
	vector<int> d(v, INT_MAX);
	vector<int> p(v, -1);
	vector<bool> visited(v, false);
	d[s] = 0;
	visited[s] = true;
	for (int i = 0; i < v - 1; i++) {
		min = 1e9;
		for (int j = 0; j < v; j++) {
			if (!visited[j] && d[start] + map[start][j] < d[j] && map[start][j] != 0) {
				d[j] = d[start] + map[start][j];
				p[j] = start;
			}
		}
		visited[start] = true;
		for (int j = 0; j < v; j++) {
			if (!visited[j] && min > d[j]) {
				min = d[j];
				start = j;
			}
		}
	}
	cout << "Khoang cach tu dinh " << s << " :\n";
	for (int i = 0; i < v; i++) {
		cout << s << "-> " << i << ": " << d[i] << "\n";
	}
}

int main() {
	input();
	solve();
	return 0;
}