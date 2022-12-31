#include <iostream>
using namespace std;
const int N = 10010;
int f[N], w[N];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i];
	// f[i][j] 表示前i个数字，和为j的方案数最大
	f[0] = 1;
	for (int i = 1; i <= n; i++) { // 选择第一个物品
		for (int j = m; j >= w[i]; j--) // 
			f[j] += f[j - w[i]]; // j-w[i]那个数字就是那个位置加上当前的数字等于j
	}
	cout << f[m] << endl;
	return 0;
}