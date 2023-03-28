#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int a[100][100];
bool dis[1000000];
int has[1000000];
int main()
{
    int i = 0;
    int j = 0;

    memset(a, 1, sizeof a);
    int cot = 1;
    for (i = 1; i < 25; i++)
    {
        for (j = 1; j < i; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    for (i = 0; i < 25; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (!dis[a[i][j]])
            {
                dis[a[i][j]] = true;
                has[a[i][j]] = cot;
            }
            if (a[i][j])
                cot++;
        }
    }
    int N;
    cin >> N;
    cout << has[N];
    return 0;
}
