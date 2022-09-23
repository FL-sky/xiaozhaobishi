#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
const int M = N * 2;
int a[M], b[M], w[M];
struct po
{
    int v, w;
    po(int v = 0, int w = 0) : v(v), w(w) {}
};
vector<po> g[N];
int n, m, k;
int que[N], dist[N];
int bfs(int x)
{
    int qf, qt = 1;
    que[qf = 0] = 1;
    int u;
    memset(dist, -1, sizeof(dist[0]) * (n + 1));
    dist[1] = 0;
    while (qf < qt)
    {
        u = que[qf++];
        for (auto it : g[u])
        {
            int v = it.v, w = it.w;
            if (w > x)
                continue;
            if (dist[u] + 1 > k)
                continue;
            if (dist[v] >= 0)
                continue;
            if (v == n)
                return 1;
            dist[v] = dist[u] + 1;
            que[qt++] = v;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 0, x, y, z; i < m; i++)
    {
        x = a[i];
        y = b[i];
        z = w[i];
        g[x].push_back(po(y, z));
        g[y].push_back(po(x, z));
    }
    int l = 0, r = *max_element(w, w + m), mid, rt = -1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (bfs(mid))
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