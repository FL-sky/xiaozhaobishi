#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 3;
struct po
{
    int v, a, b;
};
vector<po> g[N];
int vis[N];
bool dfs(int u, int sc)
{
    vis[u]++;
    if (vis[u] > 1)
    {
        return true;
    }
    for (int i = 0; i < g[u].size(); i++)
    {
        po tp = g[u][i];
        if (sc >= tp.a)
        {
            if (dfs(tp.v, sc + tp.b))
                return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, a, b;
    int mx = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> a >> b;
        g[u].push_back({v, a, b});
        mx = max(mx, a);
    }
    int l = 0, r = mx, rt = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        bool flg = false;
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (dfs(i, mid))
            {
                flg = true;
                break;
            }
        }
        if (flg)
        {
            rt = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << rt << endl;
    return 0;
}