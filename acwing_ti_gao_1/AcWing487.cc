/*
* 金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间金明自己专用的很宽敞的房间。

更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过N元钱就行”。

今天一早，金明就开始做预算了，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：

![QQ截图20190313024710.png](/media/article/image/2019/03/13/19_45c6dcea44-QQ截图20190313024710.png)

如果要买归类为附件的物品，必须先买该附件所属的主件。

每个主件可以有0个、1个或2个附件。

附件不再有从属于自己的附件。

金明想买的东西很多，肯定会超过妈妈限定的N元。

于是，他把每件物品规定了一个重要度，分为5等：用整数1~5表示，第5等最重要。

他还从因特网上查到了每件物品的价格（都是10元的整数倍）。

他希望在不超过N元（可以等于N元）的前提下，使每件物品的价格与重要度的乘积的总和最大。

设第j件物品的价格为v\[j\]，重要度为w\[j\]，共选中了k件物品，编号依次为$j\_1，j\_2，…，j\_k$，则所求的总和为：

 $v\[j\_1\] \* w\[j\_1\]+v\[j\_2\] \* w\[j\_2\]+…+v\[j\_k\] \* w\[j\_k\]$ （其中\*为乘号）

请你帮助金明设计一个满足要求的购物单。

#### 输入格式

输入文件的第1行，为两个正整数，用一个空格隔开：N m，其中N表示总钱数，m为希望购买物品的个数。

从第2行到第m+1行，第j行给出了编号为j-1的物品的基本数据，每行有3个非负整数v p q，其中v表示该物品的价格，p表示该物品的重要度（1~5），q表示该物品是主件还是附件。

如果q=0，表示该物品为主件，如果q>0，表示该物品为附件，q是所属主件的编号。

#### 输出格式

输出文件只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<200000）。

#### 数据范围

 $N < 32000, m < 60, v < 10000$

#### 输入样例：

	1000 5
	800 2 0
	400 5 1
	300 5 1
	400 3 0
	500 2 0


#### 输出样例：

	2200
*/


#include <iostream>
#include <vector>
using namespace std;
const int N = 70, M = 32010;
#define v first
#define w second

typedef pair<int, int> PII;
vector<PII> servant[N];
PII master[N];
int f[M];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		int v, p, q;
		cin >> v >> p >> q;
		p *= v;
		if (!q) master[i] = { v,p };
		else servant[q].push_back({ v,p });
	}

	for (int i = 1; i <= n; i++)
		for (int u = m; u >= 0; u -= 10)
			for (int j = 0; j < 1 << servant[i].size(); j++)
				/*
				*   servant[i].size() 表示第i个物品有多少个仆人
				*   1 << 仆人.size() 表示一共有多少种方式，
				*            2个仆人：  选第一个，选第二个，一个都不选，都选
				*/
			{
				/*
				*   v,w表示主物品的体积和价值
				*/
				int v = master[i].v, w = master[i].w;
				for (int k = 0; k < servant[i].size(); k++)
					/*
					*   如果j的第k位为1表示，包含这个仆人
					*/
					if (j >> k & 1)
					{
						/*
						*   加上仆人的价值和体积
						*/
						v += servant[i][k].v;
						w += servant[i][k].w;
					}
				/*
				*	一般动态规划
				*/
				if (u >= v) f[u] = max(f[u], f[u - v] + w);
			}

	cout << f[m] << endl;
	return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//const int N = 70, M = 32010;
//typedef pair<int, int> PII;
//#define v first
//#define w second
//
//int f[M];
//int n, m;
//PII master[N];
//vector<PII> servant[N];
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin >> m >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		int v, p, q;
//		cin >> v >> p >> q;
//		p *= v;
//		if (!q) master[i] = { v,p };
//		else servant[q].push_back({ v,p });
//	}
//	for (int i = 1; i <= n; i++)
//		for (int u = m; u >= 0; u -= 10)
//			for (int j = 0; j < 1 << servant[i].size(); j++)
//			{
//				int v = master[i].first, w = master[i].second;
//				for (int k = 0; k < servant[i].size(); k++)
//					if (j >> k & 1)
//					{
//						v += servant[i][k].v;
//						w += servant[i][k].w;
//					}
//				if (u >= v)
//					f[u] = max(f[u], f[u - v] + w);
//			}
//	cout << f[m] << endl;
//
//	return 0;
//}