#include <iostream>
using namespace std;
const int N = 1010;
int f[N], n, m;
int money[]{ 10,20,50,100 };
int main() {
	cin >> n;
	f[0] = 1;
	for (int i = 0; i < 4; i++) {
		int v = money[i];
		for (int j = v; j <= n; j++)
			f[j] += f[j - v];
	}
	cout << f[n] << endl;

	return 0;
}