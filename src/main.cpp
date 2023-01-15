#include <iostream>
#include <tuple>
using namespace std;
int main() {
	tuple<int, int> a[]{ {1,2}, {3,4} };

	for (auto& [i, j] : a) {
		cout << i << " " << j << endl;
	}

	return 0;
}