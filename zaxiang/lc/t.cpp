#include <iostream>
#include <vector>
using namespace std;
const int N = 200 + 10;
int a[N][N];
int dp[N][N][4];
int n, m, cha;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}, UP;
int dfs(int x, int y, int z)
{
    if (dp[x][y][z] != -1)
    {
        return dp[x][y][z];
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            int ad = abs(a[x][y] - a[nx][ny]) > cha;
            if (z + ad >= 4)
                continue;
        }
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    cin >> n >> m >> cha;
    UP = n * m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    return 0;
}