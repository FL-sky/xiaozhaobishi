#include <bits/stdc++.h>
using namespace std;

int mz[10][10];
int dp[10][10][10][10];

int n;
int mx;
int dfs(int v, int w, int x, int y, int val, int lv)
{
    if (dp[v][w][x][y] != -1)
    {
        mx = max(mx, val + dp[v][w][x][y]);
        // int rv = val + dp[v][w][x][y] - lv;
        int rv = dp[v][w][x][y];
        // return rv;
        if (rv + val <= mx)
        {
            return rv;
        }
    }
    int rt = 0;
    if (v == n && w == n && x == n && y == n)
    {
        mx = max(mx, val);
        return 0;
    }
    if (v == x)
    {
        if (v + 1 <= n)
        {
            int tv = mz[v + 1][w];
            mz[v + 1][w] = 0;
            rt = max(rt, tv + dfs(v + 1, w, x, y, val + tv, tv));
            mz[v + 1][w] = tv;
        }
        if (w + 1 <= n)
        {
            int tv = mz[v][w + 1];
            mz[v][w + 1] = 0;
            rt = max(rt, tv + dfs(v, w + 1, x, y, val + tv, tv));
            mz[v][w + 1] = tv;
        }
        //
        if (y + 1 <= n)
        {
            int tv = mz[x][y + 1];
            mz[x][y + 1] = 0;
            rt = max(rt, tv + dfs(v, w, x, y + 1, val + tv, tv));
            mz[x][y + 1] = tv;
        }
    }
    else
    {
        if (x + 1 <= n)
        {
            int tv = mz[x + 1][y];
            mz[x + 1][y] = 0;
            rt = max(rt, tv + dfs(v, w, x + 1, y, val + tv, tv));
            mz[x + 1][y] = tv;
        }
        if (y + 1 <= n)
        {
            int tv = mz[x][y + 1];
            mz[x][y + 1] = 0;
            rt = max(rt, tv + dfs(v, w, x, y + 1, val + tv, tv));
            mz[x][y + 1] = tv;
        }
    }
    return dp[v][w][x][y] = max(rt, dp[v][w][x][y]);
}
int main()
{
    int x, y, z;
    cin >> n;
    while (cin >> x >> y >> z)
    {
        if (x == 0 && y == 0 && z == 0)
        {
            break;
        }
        mz[x][y] = z;
    }
    memset(dp, -1, sizeof(dp));
    dfs(1, 1, 1, 1, 0, 0);
    cout << mx + mz[1][1] << endl;
    cout << dp[1][1][1][1] << endl;
    return 0;
}