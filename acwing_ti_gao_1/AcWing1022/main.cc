// 所有从前i个物品中选，花费不超过V1,花费不超过V2，的最大选法
#include <iostream>
using namespace std;
const int N = 1010, M = 510;
int f[N][M];
int V1, V2, n;
int main() {
	cin >> V1 >> V2 >> n;
	for (int i = 1; i <= n; i++) {
		int v1, v2; cin >> v1 >> v2;
		// 这里与之前并无不同，所以我自己就写出来了（大概）
		for (int j = V1; j >= v1; j--)
			for (int k = V2 - 1; k >= v2; k--) // k代表的是消耗的体积，最大只能是V2-1
				f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
	}
	cout << f[V1][V2 - 1] << " ";
	int cost = V2 - 1;
	for (int k = V2 - 1; k >= 0; k--)
	{
		if (f[V1][V2 - 1] == f[V1][k]) // 找到那个体积相等，但是k不同的地方
			cost = min(cost,k); // 消耗的最小，剩余的最大
	}
	cout << V2 - cost << endl; // 减去那个得到剩余的
	return 0;
}