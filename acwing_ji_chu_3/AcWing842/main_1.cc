#include <iostream>
using namespace std;
const int N = 10;
int arr[N];
bool st[N];
int n;
void dfs(int u) {
	if (u > n) {
		for (int i = 1; i <= n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
		if (!st[i])
		{
			arr[u] = i;
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