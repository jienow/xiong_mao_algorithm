/*
* �� $N$ ����Ʒ��һ�������� $V$ �ı�����ÿ����Ʒֻ��ʹ��һ�Ρ�

�� $i$ ����Ʒ������� $v\_i$����ֵ�� $w\_i$��

��⽫��Щ��Ʒװ�뱳������ʹ��Щ��Ʒ��������������������������ܼ�ֵ���

��� **����ѡ���ķ�����**��ע��𰸿��ܴܺ��������ģ $10^9 + 7$ �Ľ����

#### �����ʽ

��һ������������$N��V$���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���

�������� $N$ �У�ÿ���������� $v\_i, w\_i$���ÿո�������ֱ��ʾ�� $i$ ����Ʒ������ͼ�ֵ��

#### �����ʽ

���һ����������ʾ **������** ģ $10^9 + 7$ �Ľ����

#### ���ݷ�Χ

$0 \\lt N, V \\le 1000$  
$0\\lt v\_i, w\_i \\le 1000$

#### ��������

    4 5
    1 2
    2 4
    3 4
    4 6
    

#### ���������

    2
*/

#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int f[N], g[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--)
        {
            int maxv = max(f[j], f[j - v] + w);
            int s = 0;
            if (maxv == f[j]) s = g[j];
            if (maxv == f[j - v] + w) s = (s + g[j - v]) % mod;
            f[j] = maxv, g[j] = s;
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++)
        if (f[i] > f[res])
            res = i;
    int sum = 0;
    for (int i = 0; i <= m; i++)
        if (f[i] == f[res])
            sum = (sum + g[i]) % mod;
    cout << sum << endl;

	return 0;
}