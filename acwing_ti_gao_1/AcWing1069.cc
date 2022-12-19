/*����һ������ $N$ �������͹����Σ�������� $1$ �� $N$ ��ţ�ÿ�������Ȩֵ����һ����������

�����͹����λ��ֳ� $N-2$ �������ཻ�������Σ�����ÿ�������Σ������������Ȩֵ��˶��ɵõ�һ��Ȩֵ�˻����������������εĶ���Ȩֵ�˻�֮������Ϊ���١�

#### �����ʽ

��һ�а������� $N$����ʾ����������

�ڶ��а��� $N$ ������������Ϊ���� $1$ ������ $N$ ��Ȩֵ��

#### �����ʽ

�����һ�У�Ϊ���������εĶ���Ȩֵ�˻�֮�͵���Сֵ��

#### ���ݷ�Χ

$N \\le 50$,  
���ݱ�֤���ж����Ȩֵ��С��$10^9$

#### ����������

    5
    121 122 123 245 231
    

#### ���������

    12214884
*/


#include <iostream>
#include <cstring> 
using namespace std;
const int N = 55, M = 35, INF = 1e9;
typedef long long LL;

int n;
int w[N];
LL f[N][N][M];

void add(LL a[], LL b[]) {
    static LL c[M];
    for (int i = 0, t = 0; i < M; i++)
    {
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}
void mult(LL a[], int b) {
    static LL c[M];
    LL t = 0;
    for (int i = 0; i < M; i++) {
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}
int cmp(LL a[], LL b[]) {
    for (int i = M - 1; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    return 0;
}
void print(LL a[]) {
    int k = M - 1;
    while (k && !a[k]) k--;
    while (k >= 0) cout << a[k--];
    cout << endl;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    LL tmp[M];
    for (int len = 3; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
			f[l][r][M - 1] = 1;
            for (int k = l + 1; k < r; k++)
            {
                memset(tmp, 0, sizeof tmp);
                tmp[0] = w[l];
                mult(tmp, w[k]);
                mult(tmp, w[r]);
                add(tmp, f[l][k]);
                add(tmp, f[k][r]);
                if (cmp(f[l][r], tmp) > 0)
                    memcpy(f[l][r], tmp, sizeof tmp);
            }
        }
    print(f[1][n]);
    return 0;
}
