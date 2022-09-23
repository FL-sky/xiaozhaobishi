#include <bits/stdc++.h>
using namespace std;
// nowcoder for 1e9 430ms
const int N = 4e4 + 10, M = 2e5 + 10;
vector<int> g[N];
int col[N];
int vis[N];
int cnt = 0;
void dfs(int u, int cl)
{
    for (int i = 0; i < g[u].size(); i++)
    {
        int t = g[u][i];
        if (!vis[t] && col[t] == cl)
        {
            vis[t] = 1;
            ++cnt;
            dfs(t, cl);
        }
    }
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0, u, v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0, x, c; i < q; i++)
    {
        cin >> x >> c;
        col[x] = c;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt = 1;
            vis[i] = 1;
            dfs(i, col[i]);
            mx = max(mx, cnt);
        }
    }
    cout << mx << endl;
    return 0;
}