#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
char mz[N][N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", mz[i]);
    int dir[4][2] = {0, 1, 1, 1, 1, 0, 1, -1};
    int win = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            char st = mz[x][y];
            if (st == '.')
                continue;
            for (int i = 0; i < 4; i++)
            {
                int len = 1;
                for (int j = 1; j < 4; j++)
                {
                    int nx = x + dir[i][0] * j;
                    int ny = y + dir[i][1] * j;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mz[nx][ny] == st)
                    {
                        ++len;
                    }
                    else
                    {
                        break;
                    }
                }
                //
                for (int j = 1; j < 4; j++)
                {
                    int nx = x - dir[i][0] * j;
                    int ny = y - dir[i][1] * j;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mz[nx][ny] == st)
                    {
                        ++len;
                    }
                    else
                    {
                        break;
                    }
                }
                if (len >= 4)
                {
                    win = 1;
                    puts(st == 'r' ? "kou" : "yukari");
                    return 0;
                }
            }
        }
    }
    puts("to be continued");
    return 0;
}