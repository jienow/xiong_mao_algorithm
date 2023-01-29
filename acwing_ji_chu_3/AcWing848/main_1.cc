#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int arr[N], ar, n, m, rudu[N], cnt;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
	rudu[b] ++;
}
bool getsort() {
	queue<int> que;
	for (int i = 1; i <= n; i++) 
		if (rudu[i] == 0) {
			que.push(i);
			arr[cnt++] = i;
		}
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			rudu[j]--;
			if (rudu[j] == 0) {
				que.push(j);
				arr[cnt++] = j;
			}
		}
	}
	return cnt == n;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		add(a, b);
	}
	if (getsort()) {
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << " ";
	}
	else cout << -1 << endl;
	return 0;
}