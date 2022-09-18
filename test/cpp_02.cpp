// #include <iostream>
// using namespace std;
// int main() {
// 	cout << "hello world" << endl;
// 	cout << "hello wrold" << endl;
// 	return 0;
// }


// 这个问题需要高版本c++,这里设置为20
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
auto func(){
	return tuple<int, int>{1, 2};
}
int main(){
	tuple<int, int, int, int> t{1, 2, 3, 4};
	auto [a, b, c, d] = t;
	cout << a << b << c << d;
	auto [e, f] = func();

	return 0;
}

