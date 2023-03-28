#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
const int N = 110;
int arr[N];
int main() {
	ios::sync_with_stdio(false);
	int cnt; cin >> cnt;
	string str;
	int n = 0;
	getline(cin, str);
	while (cnt--) {
		getline(cin, str);
		stringstream ss(str);
		while (ss >> arr[n]) n++;
	}
	sort(arr, arr + n);
	int p1, p2;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1])p1 = arr[i];
		else if (arr[i] == arr[i - 1] + 2) p2 = arr[i] - 1;
	}
	cout << p2 << " " << p1;
	return 0;
}