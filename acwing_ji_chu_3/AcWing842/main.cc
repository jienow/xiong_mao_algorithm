#include <iostream>
using namespace std;
const int N = 10;
int n;
int f[N];
bool st[N];
void dfs(int u) {
	if (u == n + 1) {
		for (int i = 1; i <= n; i++)
			cout << f[i] << " ";
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!st[i])
		{
			f[u] = i;
			st[i] = true;
			dfs(u + 1);
			st[i] = false;
		}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	dfs(1);
	return 0;
}