/*
* ��һ�� $8 \\times 8$ �����̽������·ָ��ԭ���̸���һ��������̲�ʹʣ�²���Ҳ�Ǿ��Σ��ٽ�ʣ�µĲ��ּ�����˷ָ�������� $(n-1)$ �κ���ͬ���ʣ�µľ������̹��� $n$ ��������̡�(ÿ���иֻ���������̸��ӵı߽���)

![1191_1.jpg](/media/article/image/2019/02/05/19_32dad08629-1191_1.jpg)

ԭ������ÿһ����һ����ֵ��һ��������̵��ܷ�Ϊ�����������ֵ֮�͡�

������Ҫ�����̰���������ָ�� $n$ ��������̣���ʹ�����������ֵܷľ�������С��

������![formula.png](/media/article/image/2019/02/05/19_566d096029-formula.png) ������ƽ��ֵ![lala.png](/media/article/image/2019/02/05/19_047fe57229-lala.png) ��$x\_i$ Ϊ�� $i$ ��������̵��ܷ֡�

���̶Ը��������̼� $n$��������������Сֵ��

#### �����ʽ

�� $1$ ��Ϊһ������ $n$��

�� $2$ ������ $9$ ��ÿ��Ϊ $8$ ��С�� $100$ �ķǸ���������ʾ��������Ӧ���ӵķ�ֵ��ÿ����������֮����һ���ո�ָ���

#### �����ʽ

�����С������ֵ���������뾫ȷ��С�������λ����

#### ���ݷ�Χ

$1 < n < 15$

#### ����������

    3
    1 1 1 1 1 1 1 3
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 0
    1 1 1 1 1 1 0 3
    

#### ���������

    1.633
*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 18, M = 9, INF = 0x3f3f3f3f;
int s[M][M];
double f[N][N][N][N][M];
int n, m = 8;
double X;
double get_sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}
double get(int x1, int y1, int x2, int y2) {
    int sum = get_sum(x1, y1, x2, y2) - X;
    return (double) sum * sum / n;
}
double dp(int x1, int y1, int x2, int y2, int k) {
    double& v = f[x1][y1][x2][y2][k];
    if (v >= 0) return v;
    if (k == 1) return v = get(x1, y1, x2, y2);

    v = INF;
    for (int i = x1; i < x2; i++)
    {
        v = min(v, get(i + 1,y1,x2,y2) + dp(x1, y1, i, y2, k - 1));
        v = min(v, get(x1, y1, i, y2) + dp(i + 1, y1, x2, y2, k - 1));
    }
    for (int i = y1; i < y2; i++)
    {
        v = min(v, get(x1, y1, x2, i) + dp(x1, i + 1, x2, y2, k - 1));
        v = min(v, get(x1, i + 1, x2, y2) + dp(x1, y1, x2, i,k-1));
    }
    return v;
}
int main() {
    cin >> n;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    X = (double)s[m][m] / n;
    memset(f, -1, sizeof f);
    printf("%.3lf", sqrt(dp(1, 1, 8, 8, n)));
	return 0;
}