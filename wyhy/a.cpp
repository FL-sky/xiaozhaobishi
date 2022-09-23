#include <bits/stdc++.h>
using namespace std;
const int M = 200 * 3 + 10;
char a[M][M];
int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n, m;
        cin >> n >> m;
        int bs;
        for (int i = 100;; i++)
        {
            if (i % n == 0)
            {
                bs = i;
                break;
            }
        }
        int o = (bs + bs + n - 1) / 2;
        for (int i = o - m / 2; i <= o + m / 2; i++)
        {
            for (int j = o - m / 2; j <= o + m / 2; j++)
            {
                a[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
            cin >> (a[i + bs] + bs);
        for (int i = o - m / 2; i <= o + m / 2; i++)
        {
            for (int j = o - m / 2; j <= o + m / 2; j++)
            {
                if (a[i][j])
                    putchar(a[i][j]);
                else
                {
                    putchar(a[i % n + bs][j % n + bs]);
                }
            }
            puts("");
        }
        puts("");
    }
    return 0;
}