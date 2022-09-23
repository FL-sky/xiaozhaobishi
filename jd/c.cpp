#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3;
int s[N];
int cnt, len;
ll dp[N];
ll dfs(int u)
{
    if (u == len)
        return 1;
    if (dp[u] != -1)
        return dp[u];
    ll rt = dfs(u + 1);
    if (u + 2 < len)
    {
        int x = s[u] * 10 + s[u + 1];
        if (x > 0 && x <= 26)
            rt += dfs(u + 1);
    }
    return dp[u] = rt;
}
int main()
{
    memset(dp, -1, sizeof(dp));

    return 0;
}