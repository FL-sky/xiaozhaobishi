#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-6;
const int N = 500 + 10;
const ll mod = 998244353;
ll dp[N][4][11];
int m;
ll dfs(int u, int s, int w)
{
    if (u <= 0 || s <= 0 || u < s || s > w)
        return 0;
    if (dp[u][s][w] != -1)
        return dp[u][s][w];
    ll rt = 0;
    for (int i = 1; i < w; i++)
        rt += dfs(u - 1, s - 1, i);
    for (int i = w; i <= m; i++)
        rt += dfs(u - 1, s, i);
    return dp[u][s][w] = rt % mod;
}
int main()
{
    int n;
    memset(dp, -1, sizeof(dp));

    for (int j = 1; j <= 10; j++)
    {
        dp[1][1][j] = 1;
    }
    while (cin >> n >> m)
    {
        ll ans = 0;
        for (int i = 3; i <= m; i++)
            ans += dfs(n, 3, i);
        cout << ans % mod << endl;
    }
    return 0;
}