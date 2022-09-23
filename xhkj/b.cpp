#include <bits/stdc++.h>
using namespace std;
const int N = 20;
struct po
{
    int x, y;
    void input()
    {
        cin >> x >> y;
        --x, --y;
    }
} a[N];
int n;
int dp[1 << 17][17];
int getdis(po A, po B)
{
    return abs(A.y - B.x) + abs(B.x - B.y);
}
int dfs(int st, int u)
{
    if (dp[st][u] != -1)
    {
        return dp[st][u];
    }
    int newst = st ^ (1 << u);
    // vector<int> v;
    int rt = 2e9;
    for (int i = 0; i < 16; i++)
    {
        if (newst & (1 << i))
        {
            rt = min(rt, dfs(newst, i) + getdis(a[i], a[u]));
        }
    }
    return dp[st][u] = rt;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i].input();
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        if (a[i].x <= a[i].y)
        {
            dp[1 << i][i] = a[i].y;
        }
        else
        {
            dp[1 << i][i] = a[i].x + a[i].x - a[i].y;
        }
    }
    a[n].x = a[n].y = 0;
    int rt = dfs((1 << (n + 1)) - 1, n);
    cout << rt << endl;
    return 0;
}