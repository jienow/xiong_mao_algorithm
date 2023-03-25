#include <iostream>
using namespace std;
const int N = 18;
int arr[N];
bool st[N];
int n;
void dfs(int u) {
	if (u > n) {
		for (int i = 1; i <= u; i++)
			if (arr[i] == 1)
				cout << i << " ";
		cout << endl;
		return;
	}
	arr[u] = 0;
	dfs(u + 1);
	arr[u] = 1;
	dfs(u + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	dfs(1);
	return 0;
}