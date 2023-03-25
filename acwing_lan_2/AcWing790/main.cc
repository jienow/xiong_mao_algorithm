#include <iostream>
using namespace std;
int main() {
	double x; cin >> x;
	double l = -10000.0, r = 10000.0;
	while (r - l >= 1e-8) {
		double mid = (l + r) / 2;
		if (mid * mid * mid >= x) r = mid;
		else l = mid;
	}
	printf("%.6f", l);
	return 0;
}