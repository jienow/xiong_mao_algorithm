#include <iostream>
using namespace std; 
int main() {
	double num; cin >> num;
	double l = -10000.0;
	double r = 10000;
	double mid = (l + r) / 2;
	while (r - l >= 1e-8) {
		mid = (l + r) / 2;
		if (mid * mid * mid > num) r = mid;
		else l = mid;
	}
	printf("%.6f", mid);

	return 0;
}