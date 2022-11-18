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
		cout << "��������" << endl;
	}
	int size() {
		return N;
	}
public:
	int& operator[](int n) { // ���������
		return p[n];
	}
};
int main() {
	CArray arr{ 10 };
	for (int i = 0; i < arr.size(); i++)
		arr.p[i] = i;
	// ����ָ��λ�õ�Ԫ��
	arr.show(3);
	// �޸�ָ��λ�õ�Ԫ��
	arr.setNum(3, 10);
	arr.show(3);
	// ��չ�洢��С
	arr.extend(20);
	cout << arr.size() << endl;
	// �������
	arr.reverse_show();

	return 0;
}