/*
* ��������Ҫ���һ������ $S$��$S$ ��Ҫ���㣺

*   $S$ �ĳ����� $N$��
*   $S$ ֻ����СдӢ����ĸ��
*   $S$ �������Ӵ� $T$��

���磺$abc$ �� $abcde$ �� $abcde$ ���Ӵ���$abd$ ���� $abcde$ ���Ӵ���

���ʹ��ж����ֲ�ͬ����������Ҫ��

���ڴ𰸻�ǳ����������ģ $10^9+7$ ��������

#### �����ʽ

��һ����������N����ʾ����ĳ��ȡ�

�ڶ��������ַ���T��T��ֻ����Сд��ĸ��

#### �����ʽ

���һ��**������**����ʾ�ܷ�����ģ $10^9+7$ ��Ľ����

#### ���ݷ�Χ

$1 \\le N \\le 50$,  
$1 \\le |T| \\le N$��$|T|$��$T$�ĳ��ȡ�

#### ��������1��

    2
    a
    

#### �������1��

    625
    

#### ��������2��

    4
    cbc
    

#### �������2��

    456924
*/



#include <iostream> 
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 55, mod = 1e9 + 7;

int n, m;
int f[N][N];
int nxt[N];
char str[N];

int main() {
    cin >> n;
    scanf("%s", str + 1);
    
    m = strlen(str + 1);
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && str[i] != str[j + 1]) j = nxt[j];
        if (str[i] == str[j + 1]) j++;
        nxt[i] = j;
    }

    f[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (char k = 'a'; k <= 'z'; k++)
            {
                int u = j;
                while (u && k != str[u + 1]) u = nxt[u];
                if (k == str[u + 1]) u++;
                if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
            }

    int res = 0;
    for (int i = 0; i < m; i++)
        res = (res + f[n][i]) % mod;
    cout << res << endl;

	return 0;
}