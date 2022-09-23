#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
char mz[N][N];
struct po
{
    int x, y;
    void input(int t = 0)
    {
        cin >> x >> y;
        --x;
        --y;
    }
};
po nd[N];
map<int, map<int, int>> dist;
set<int> us;
int gid(int x, int y)
{
    return x * N + y;
}
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m;
void bfs(int x, int y)
{
    int st = gid(x, y);
    queue<int> que;
    int u = gid(x, y);
    que.push(u);
    dist[st][u] = 0;
    while (que.size())
    {
        u = que.front();
        que.pop();
        int x = u / N, y = u % N;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = dir[i][1] + y;
            if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
            {
                continue;
            }
            int newid = gid(nx, ny);
            if (dist[st].find(newid) != dist[st].end())
                continue;
            if (mz[nx][ny] != '#')
            {
                que.push(newid);
                dist[st][newid] = dist[st][u] + 1;
            }
        }
    }
}
int main()
{
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> mz[i];
    for (int i = 0; i < k; i++)
        nd[i].input(-1);
    int S, T;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mz[i][j] == 'S')
            {
                S = gid(i, j);
                bfs(i, j);
            }
            if (mz[i][j] == 'F')
            {
                T = gid(i, j);
                bfs(i, j);
            }
        }
    }
    vector<int> sv = {S};
    map<int, int> dp;
    dp[S] = 0;
    vector<int> tv;
    for (int i = 0; i < k; i++)
    {
        int x = nd[i].x, y = nd[i].y;
        tv.clear();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = dir[i][1] + y;
            if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
            {
                continue;
            }
            int newid = gid(nx, ny);
            if (mz[nx][ny] != '#')
            {
                // bfs(nx, ny);
                tv.push_back(newid);
            }
        }
        for (auto it : sv)
        {
            int x = it / N, y = it % N;
            bfs(x, y);
            for (auto ij : tv)
            {
                int nx = ij / N, ny = ij % y;
                if (dp.find(ij) == dp.end())
                {
                    dp[ij] = dp[it] + dist[it][ij];
                }
                else
                {
                    dp[ij] = min(dp[ij], dp[it] + dist[it][ij]);
                }
            }
        }
        if (tv.size() == 0)
        {
            puts("-1");
            return 0;
        }
        sv = tv;
    }
    if (sv.size())
    {
        for (auto it : sv)
        {
            int x = it / N, y = it % N;
            bfs(x, y);
            int ij = T;
            int nx = ij / N, ny = ij % y;
            if (dp.find(ij) == dp.end())
            {
                dp[ij] = dp[it] + dist[it][ij];
            }
            else
            {
                dp[ij] = min(dp[ij], dp[it] + dist[it][ij]);
            }
        }
    }
    printf("%d\n", dp[T]);
    return 0;
}