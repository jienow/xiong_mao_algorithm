#include <iostream>
using namespace std;
const int N = 1010;
int f1[N], f2[N];
int w[N];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		f1[i] = 1;
		for (int j = 1; j < i; j++)
			if (w[i] > w[j])
				f1[i] = max(f1[i], f1[j] + 1);
	}
	for (int i = n; i >= 1; i--)
	{
		f2[i] = 1;
		for (int j = n; j > i; j--)
			if (w[i] > w[j])
				f2[i] = max(f2[i], f2[j] + 1);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res = max(res, f1[i] + f2[i]);
	cout << res - 1 << endl;

	return 0;
}