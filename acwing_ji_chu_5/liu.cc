#include <iostream>
#include <cstring>
using namespace std;

class CArray {
private:
	int N;
	int* p;
public:
	CArray(int n){
		N = n; 
		p = new int[N];
	}
	void setNum(int index,int number) {
		p[index] = number;
	}
	void show(int index) {
		cout << p[index] << endl;
	}
	void extend(int L) {
		int* newp = new int[L];
		memcpy(newp, p, N * sizeof(int));
		N = L;
	}
	void reverse_show() {
		for (int i = N - 1; i >= 0; i--)
			cout << p[i] << " ";
		cout << endl;
	}
	~CArray() {
		N = 0;
		delete p;
		cout << "对象析构" << endl;
	}
	int size() {
		return N;
	}
public:
	int& operator[](int n) { // 运算符重载
		return p[n];
	}
};
int main() {
	CArray arr{ 10 };
	for (int i = 0; i < arr.size(); i++)
		arr.p[i] = i;
	// 设置指定位置的元素
	arr.show(3);
	// 修改指定位置的元素
	arr.setNum(3, 10);
	arr.show(3);
	// 扩展存储大小
	arr.extend(20);
	cout << arr.size() << endl;
	// 逆序输出
	arr.reverse_show();

	return 0;
}