#include <bits/stdc++.h>
using namespace std;
const int N = 50 * 4 + 10;
char mz[N][N];
int main()
{
    int n;
    scanf("%d", &n);
    int n4 = 4 * n;
    memset(mz, '*', sizeof(mz));
    for (int i = 0; i < n; i++)
    {
        int len = n - i;
        for (int j = 0; j < len; j++)
        {
            mz[i][j] = '.';
            mz[i][n4 - 1 - j] = '.';
            mz[n4 - 1 - i][j] = '.';
            mz[n4 - 1 - i][n4 - 1 - j] = '.';
        }
    }

    for (int i = n; i < n * 3; i++)
    {
        for (int j = n; j < n * 3; j++)
        {
            mz[i][j] = '.';
        }
    }
    for (int i = 0; i < n4; i++)
    {
        for (int j = 0; j < n4; j++)
        {
            putchar(mz[i][j]);
        }
        puts("");
    }
    return 0;
}