#include <iostream>
using namespace std;
const int N = 100000 + 10;
int arr[N];
int ge_shu(int num) {
	int res = 0;
	while (num) {
		res += num & 1;
		num >>= 1;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	while (n--) {
		int num; cin >> num;
		cout << ge_shu(num) << " ";
	}
	return 0;
}