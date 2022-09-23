#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10, M = 1000 + 10;
int f[N][M], p[N][M];
int n;
int a[110];
bool check(int m)
{
    memset(f, 0, sizeof(f));
    memset(p, 0, sizeof(p));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (f[i][j])
            {
                p[i][j] = (i - 1) * M + j;
            }
            if (j >= a[i])
            {
                f[i][j] |= f[i - 1][j - a[i]];
                if (f[i][j])
                {
                    p[i][j] = (i - 1) * M + j - a[i];
                }
            }
        }
    }
    int tm = m;
    for (; tm >= 0; tm--)
    {
        if (f[n][tm])
        {
            break;
        }
    }
    int ti = n;
    while (f[ti][tm])
    {
        int v = p[ti][tm];
        int md = v % M;
        int u = v / M;
        if (md != tm)
        {
        }
    }
    return false;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = 1000, rt = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
    }
    return 0;
}