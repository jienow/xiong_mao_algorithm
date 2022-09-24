// #include <iostream>
// using namespace std;
// int main() {
// 	cout << "hello world" << endl;
// 	cout << "hello wrold" << endl;
// 	return 0;
// }

// 这个问题需要高版本c++,这里设置为20
// #include <iostream>
// #include <vector>
// #include <tuple>
// using namespace std;
// auto func(){
// 	return tuple<int, int>{1, 2};
// }
// int main(){
// 	tuple<int, int, int, int> t{1, 2, 3, 4};
// 	auto [a, b, c, d] = t;
// 	cout << a << b << c << d;
// 	auto [e, f] = func();

// 	return 0;
// }

#include <iostream>
using namespace std;

// ostream &output(ostream &out,int a){
// 	out << "hello world" << endl;
// 	return out;
// }

int func(){
	return 1;
}

template <typename Func>
ostream &operator<<(ostream &out,Func Func){
	out << "hello world" << func() << endl;
}
// template <class T>
// class type
// {
// public:
// 	void operator<<(ostream& out,)
// };

int main()
{
	//cout << 1 << func() << 2;
	// cout << output << 1;
	// output(cout, 1);
	cout << func;
	return 0;
}