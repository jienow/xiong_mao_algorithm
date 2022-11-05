/*
* 小明手里有n元钱全部用来买书，书的价格为10元，20元，50元，100元。

问小明有多少种买书方案？（每种书可购买多本）

#### 输入格式

一个整数 n，代表总共钱数。

#### 输出格式

一个整数，代表选择方案种数。

#### 数据范围

$0 \\le n \\le 1000$

#### 输入样例1：

	20


#### 输出样例1：

	2


#### 输入样例2：

	15


#### 输出样例2：

	0


#### 输入样例3：

	0


#### 输出样例3：

	1
*/

#include <iostream>
#include <array>
using namespace std;
const int N = 1010;
array<int, N> f;
array<int, 4> v{ 10,20,50,100 };
int n;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	f[0] = 1;
	for (int i = 0; i < 4; ++i)
		for (int j = v[i]; j <= n; ++j)
			f[j] += f[j - v[i]];
	cout << f[n] << endl;

	return 0;
}