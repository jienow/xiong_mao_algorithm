#include <iostream>
using namespace std;
const int N = 1010;
int f[N];
int n, m;
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		int w, v;
		cin >> v >> w;
		for (int j = m; j >= v; j--)
			f[j] = max(f[j], f[j - v] + w);
	}
	cout << f[m] << endl;
	return 0;
}