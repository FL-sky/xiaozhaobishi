#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
int dp[N][10][10];
ll dfs(int pos, int pre2, int pre1)
{
    if (pos == -1)
    {
        return 1;
    }
    if (dp[pos][pre2][pre1] != -1)
    {
        return dp[pos][pre2][pre1];
    }
    ll cnt = 0;
    for (int i = 1; i < 10; i++)
    {
        if (pre1 == 1 && i == 1)
            continue;
        if (pre2 == 1 && i == 1)
            continue;
        cnt += dfs(pos - 1, pre1, i);
        if (cnt >= mod)
            cnt %= mod;
    }
    return dp[pos][pre2][pre1] = cnt;
}
int main()
{
    int n;
    cin >> n;
    cout << dfs(n, -1, -2) << endl;
    return 0;
}