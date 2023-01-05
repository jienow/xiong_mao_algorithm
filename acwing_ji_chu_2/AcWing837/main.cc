#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N];
int cnt[N];
int n, m;
int find(int num) {
	if (p[num] != num) p[num] = find(p[num]);
	return p[num];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		cnt[i] = 1;
	}

	while (m--) {
		int a, b;
		char op[3]; cin >> op;
		if (op[0] == 'C') {
			cin >> a >> b;
			int pa = find(a), pb = find(b);
			if (pa != pb)cnt[pb] += cnt[pa]; // 只有两个节点不在同一个集合里面才会相加数量
			p[pa] = pb;
		}
		else if (op[1] == '1') {
			cin >> a >> b;
			if (find(a) != find(b)) cout << "No" << endl;
			else cout << "Yes" << endl;
		}
		else {
			cin >> a;
			cout << cnt[find(a)] << endl;
		}
	}

	return 0;
}