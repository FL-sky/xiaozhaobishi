#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
vector<int> g[N];
int a[N], val[N];
int stk[N];
bool can[N][N];
int dfs(int u, int pa, int dep)
{
    stk[dep] = u;
    val[u] = a[u];
    if (dep)
    {
        for (int i = 0; i < dep; i++)
        {
            int v = stk[i];
            can[u][v] = can[v][u] = false;
        }
    }
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v != pa)
        {
            val[u] += dfs(v, u, dep + 1);
        }
    }
    return val[u];
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }
    memset(can, true, sizeof(can));
    dfs(1, -1, 0);
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (can[i][j])
            {
                ans = min(ans, abs(val[i] - val[j]));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}