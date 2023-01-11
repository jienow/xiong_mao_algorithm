#include <iostream>
using namespace std;
const int N = 110;
int f[N];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int v, w, s; scanf("%d%d%d", &v, &w, &s);
		for (int j = m; j >= v; j--)
			for (int k = 0; k <= s && k * v <= j; k++)
				f[j] = max(f[j], f[j - k * v] + k * w);
	}
	cout << f[m] << endl;
	return 0;
}