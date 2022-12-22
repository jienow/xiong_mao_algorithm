#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int ans = n / m; //
	int num = n % m; // 
	for (int i = num; i < m; i++)
		cout << ans << " ";
	for (int i = 0; i < num; i++)
		cout << ans + 1 << " ";
	return 0;
}