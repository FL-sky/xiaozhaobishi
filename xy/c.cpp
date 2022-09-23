

#include <bits/stdc++.h>
using namespace std;
// nowcoder for 1e9 430ms
const int N = 4e4 + 10;
vector<int> g[N];
int col[N];
int pa[N];
int jishu[N];
int getp(int x)
{
    if (pa[x] == x)
        return x;
    return pa[x] = getp(pa[x]);
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < N; i++)
    {
        pa[i] = i;
        col[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        jishu[i] = 1;
    }
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int mx = 1;
    for (int i = 0, x, c; i < q; i++)
    {
        cin >> x >> c;
        col[x] = c;
        for (int j = 0; j < g[x].size(); j++)
        {
            int y = g[x][j];
            int fx = getp(x);
            int fy = getp(y);
            if (col[fy] < 1)
                continue;
            if (col[fx] != col[fy])
                continue;
            if (fx == fy)
            {
            }
            else
            {
                jishu[fx] += jishu[y];
                pa[fy] = fx;
                mx = max(mx, jishu[fx]);
            }
        }
        cout << mx << endl;
    }

    return 0;
}