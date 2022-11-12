/*
* ǱˮԱΪ��ǱˮҪʹ�������װ����

����һ����2����������ף�һ��Ϊ������һ��Ϊ������

��ǱˮԱ��Ǳ�������Ҫ�������������͵���

ǱˮԱ��һ�����������ס�

ÿ�����׶�������������������

ǱˮԱΪ��������Ĺ�����Ҫ�ض����������͵���

����ɹ����������׵����ص�����޶ȵ��Ƕ��٣�

���磺ǱˮԱ��5�����ס�ÿ����������Ϊ���������ģ������������׵�������

    3 36 120
    
    10 25 129
    
    5 50 250
    
    1 45 130
    
    4 20 119
    

���ǱˮԱ��Ҫ5��������60���ĵ���������СΪ249��1��2����4��5�����ף���

���������Ǽ���ǱˮԱΪ��������Ĺ�����Ҫ�����׵����������ֵ��

#### �����ʽ

��һ����2������ $m��n$�����Ǳ�ʾ������������Ҫ������

�ڶ���Ϊ���� $k$ ��ʾ���׵ĸ�����

�˺�� $k$ �У�ÿ�а���$a\_i��b\_i��c\_i$��3����������Щ�����ǣ��� $i$ ������������͵�������������������

#### �����ʽ

��һ�а���һ��������ΪǱˮԱ��ɹ�����������׵������ܺ͵����ֵ��

#### ���ݷ�Χ

$1 \\le m \\le 21$,  
$1 \\le n \\le 79$,  
$1 \\le k \\le 1000$,  
$1 \\le a\_i \\le 21$,  
$1 \\le b\_i \\le 79$,  
$1 \\le c\_i \\le 800$

#### ����������

    5 60
    5
    3 36 120
    10 25 129
    5 50 250
    1 45 130
    4 20 119
    

#### ���������

    249
*/



/*
* ״̬��ʾ: ���������i����������������j������£������������Ƕ���
*     ���ԣ�����
* ״̬���̣�         f[i][j][k]
*           ��ѡ��i����Ʒ��f[i-1][j][k]
*           ѡ��i����Ʒ��f[i][j-v][k-w] + w
* �����i��ȫ����ʼ��Ϊ0
* ǡ����i��f[0][0]Ϊ0������Ϊ�����j-v >= 0
* ������i��f[0][0]Ϊ0������Ϊ�����j����Ϊ0��С��ʱ����ζ����Ϊj��
* ���Կ���Ϊv�����������v�Ǵ���j�����Կ��Կ���ֻѡv
*/

#include <iostream>
#include <cstring>
using namespace std;
const int N = 25, M = 85;
int f[N][M];
int m, n, k;
int main() {
    ios::sync_with_stdio(false);
    cin >> m >> n >> k;

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = m; j >= 0; --j)
            for (int z = n; z >= 0; --z) 
                f[j][z] = min(f[j][z], f[max(0,j - a)][max(0,z - b)] + c);
    }
    cout << f[m][n] << endl;
	return 0;
}