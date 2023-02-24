#include <iostream>
using namespace std;
const int N = 10000 + 10;
int n;
int main() {
	double l = -10000.0, r = 10000.0;
	double num; cin >> num;
	while (r - l > 10e-8) {
		double mid = (l + r) / 2;
		if (mid * mid * mid > num)  r = mid;
		else l = mid;
	}
	printf("%.6f", l);
	return 0;
}