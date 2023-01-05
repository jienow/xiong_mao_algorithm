#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int f[N];
int n, m;
int find(int a) {
	if (a != f[a]) f[a] = find(f[a]);
	return f[a];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) f[i] = i;
	while (m--) {
		int a, b;
		char op[2]; cin >> op >> a >> b;
		if (op[0] == 'M') {
			int pa = find(a), pb = find(b);
			if (pa != pb) f[pa] = pb;
		}
		else {
			int pa = find(a), pb = find(b);
			if (pa == pb) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}