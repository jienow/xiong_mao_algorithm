/*
*	多重背包问题2是将那些物品进行二进制分隔
*	这个问题是将一组物品看成01背包的一个物品，然后比较选取就可以
*/

#include <iostream>
using namespace std;
const int N = 110;
int f[N], v[N], w[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int s; cin >> s;
		for (int j = 0; j < s; j++) cin >> v[j] >> w[j];
		for (int j = m; j >= 0; j--)
			for (int k = 0; k < s; k++)
				if (j >= v[k])
					f[j] = max(f[j], f[j - v[k]] + w[k]);
	}
	cout << f[m] << endl;
	return 0;
}