#include <iostream>
#include <deque>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int d[N], n, m, arr[N], ar;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
	d[b] ++;
}
bool getsort() {
	deque<int> que;
	for (int i = 1; i <= n; i++)
		if (d[i] == 0) {
			que.push_back(i);
			arr[ar++] = i;
		}
	while (!que.empty()) {
		int u = que.front();
		que.pop_front();
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			d[j] --;
			if (!d[j]){
				que.push_back(j);
				arr[ar++] = j;	
			}
		}
	}
	return ar == n;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b; cin >> a >> b;
		add(a, b);
	}
	if (getsort()) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
	else cout << "-1" << endl;
	return 0;
}