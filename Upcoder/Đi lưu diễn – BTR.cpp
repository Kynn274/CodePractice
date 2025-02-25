#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int n, m, x, y;
vector<vector<int>> map;

void input() {
	int a, b, c;

	cin >> n >> m >> x >> y;
	map.resize(n, vector<int>(n));
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
	}
}

void solve() {
	int start = x;
	int min = 1e9;
	vector<int> dist(n, 1e9);
	vector<bool> visited(n, false);
	vector<int> prev(n, -1);
	vector<int> length(n, 0);
	dist[start] = 0;
	visited[start] = true;
	for (int i = 0; i < n - 1; i++) {
		min = 1e9;
		for (int j = 0; j < n; j++) {
			if (map[start][j] != 0 && !visited[j]) {
				if (dist[j] > dist[start] + map[start][j]) {
					dist[j] = dist[start] + map[start][j];
					prev[j] = start;
					length[j] = length[start] + 1;
				}
				else if (dist[j] == dist[start] + map[start][j]) {
					if (length[start] + 1 > length[j]) {
						prev[j] = start;
						length[j] = length[start] + 1;
					}
				}
			}
		}
		visited[start] = true;
		for (int j = 0; j < n; j++) {
			if (dist[j] < min && !visited[j]) {
				min = dist[j];
				start = j;
			}
		}
	}
	if (dist[y] == 1e9) cout << -1;
	else {
		stack<int> st;
		int i = y;
		while (i != x) {
			st.push(i);
			i = prev[i];
		}
		st.push(x);
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << '\n' << dist[y];
	}
}
int main() {
	input();
	solve();
	return 0;
}