/*
* ¿íËÑµÄ¿ò¼Ü
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
typedef pair<int, int> PII;
int h[N], w[N], e[N], ne[N], idx;
bool st[N];
int n, m, dist[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra() {
	priority_queue<PII, vector<PII>, greater<PII>>heap;
	heap.push({ 0,1 });
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	while (!heap.empty()) {
		PII minn = heap.top(); heap.pop();
		int ver = minn.second, val = minn.first;
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = h[ver]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[ver] + w[i]) {
				dist[j] = min(dist[j], dist[ver] + w[i]);
				heap.push({ dist[j],j });
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--) {
		int x, y, z; cin >> x >> y >> z;
		add(x, y, z);
	}
	cout << dijkstra() << endl;
	return 0;
}