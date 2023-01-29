#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 2e5;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int n, m;
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra() {
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,1 });
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	while (!heap.empty()) {
		PII u = heap.top(); heap.pop();
		int ver = u.second, val = u.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > val + w[i]) {
				dist[j] = min(dist[j], val + w[i]);
				heap.push({ dist[j], j });
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f)return -1;
	else return dist[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		add(x, y, z);
	}
	cout << dijkstra() << endl;
	return 0;
}