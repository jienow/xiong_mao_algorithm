/*
* ��������ܿ��ģ����ﹺ�õ��·���Ҫ��Կ���ˣ��·�����һ������Լ�ר�õĺܿ��ķ��䡣

���������˵��ǣ������������˵������ķ�����Ҫ������Щ��Ʒ����ô���ã���˵���㣬ֻҪ������NԪǮ���С���

����һ�磬�����Ϳ�ʼ��Ԥ���ˣ������������Ʒ��Ϊ���ࣺ�����븽���������Ǵ�����ĳ�������ģ��±����һЩ�����븽�������ӣ�

![QQ��ͼ20190313024710.png](/media/article/image/2019/03/13/19_45c6dcea44-QQ��ͼ20190313024710.png)

���Ҫ�����Ϊ��������Ʒ����������ø���������������

ÿ������������0����1����2��������

���������д������Լ��ĸ�����

��������Ķ����ܶ࣬�϶��ᳬ�������޶���NԪ��

���ǣ�����ÿ����Ʒ�涨��һ����Ҫ�ȣ���Ϊ5�ȣ�������1~5��ʾ����5������Ҫ��

�������������ϲ鵽��ÿ����Ʒ�ļ۸񣨶���10Ԫ������������

��ϣ���ڲ�����NԪ�����Ե���NԪ����ǰ���£�ʹÿ����Ʒ�ļ۸�����Ҫ�ȵĳ˻����ܺ����

���j����Ʒ�ļ۸�Ϊv\[j\]����Ҫ��Ϊw\[j\]����ѡ����k����Ʒ���������Ϊ$j\_1��j\_2������j\_k$����������ܺ�Ϊ��

 $v\[j\_1\] \* w\[j\_1\]+v\[j\_2\] \* w\[j\_2\]+��+v\[j\_k\] \* w\[j\_k\]$ ������\*Ϊ�˺ţ�

��������������һ������Ҫ��Ĺ��ﵥ��

#### �����ʽ

�����ļ��ĵ�1�У�Ϊ��������������һ���ո������N m������N��ʾ��Ǯ����mΪϣ��������Ʒ�ĸ�����

�ӵ�2�е���m+1�У���j�и����˱��Ϊj-1����Ʒ�Ļ������ݣ�ÿ����3���Ǹ�����v p q������v��ʾ����Ʒ�ļ۸�p��ʾ����Ʒ����Ҫ�ȣ�1~5����q��ʾ����Ʒ���������Ǹ�����

���q=0����ʾ����ƷΪ���������q>0����ʾ����ƷΪ������q�����������ı�š�

#### �����ʽ

����ļ�ֻ��һ����������Ϊ��������Ǯ������Ʒ�ļ۸�����Ҫ�ȳ˻����ܺ͵����ֵ��<200000����

#### ���ݷ�Χ

 $N < 32000, m < 60, v < 10000$

#### ����������

	1000 5
	800 2 0
	400 5 1
	300 5 1
	400 3 0
	500 2 0


#### ���������

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
				*   servant[i].size() ��ʾ��i����Ʒ�ж��ٸ�����
				*   1 << ����.size() ��ʾһ���ж����ַ�ʽ��
				*            2�����ˣ�  ѡ��һ����ѡ�ڶ�����һ������ѡ����ѡ
				*/
			{
				/*
				*   v,w��ʾ����Ʒ������ͼ�ֵ
				*/
				int v = master[i].v, w = master[i].w;
				for (int k = 0; k < servant[i].size(); k++)
					/*
					*   ���j�ĵ�kλΪ1��ʾ�������������
					*/
					if (j >> k & 1)
					{
						/*
						*   �������˵ļ�ֵ�����
						*/
						v += servant[i][k].v;
						w += servant[i][k].w;
					}
				/*
				*	һ�㶯̬�滮
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