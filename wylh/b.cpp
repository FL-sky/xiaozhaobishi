#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 4;
vector<int> g[N];
int qq[N];
int vis[N], ind[N];
set<int> jz;
void dfs(int u, int iter) // jiazai
{
    vis[u] = iter;
    jz.insert(u);
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (vis[v] != iter)
        {
            ind[v]++;
            dfs(v, iter);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int tp;
    for (int i = 0; i < n; i++)
    {
        cin >> tp;
        for (int j = 0, x; j < tp; j++)
        {
            cin >> x;
            g[i].push_back(x);
        }
    }
    int ans = 0;
    int iter = 0;
    while (m-- > 0)
    {

        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            qq[x] = 1;
            if (jz.find(x) == jz.end())
            {
                dfs(x, ++iter);
            }
        }
        else
        {
            if (qq[x])
            {
                if (ind[x] == 0)
                {
                    qq[x] = 0;
                    queue<int> que;
                    que.push(x);
                    while (que.size())
                    {
                        x = que.front();
                        que.pop();
                        jz.erase(x);
                        for (auto it : g[x])
                        {
                            if (--ind[it] == 0 && qq[it] == 0)
                            {
                                que.push(it);
                            }
                        }
                    }
                }
            }
        }
        ans = max(ans, (int)jz.size());
    }
    cout << ans << endl;
    return 0;
}