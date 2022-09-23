#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 10;
const int inf = 1e9;
char mz[N][N];
struct po
{
    int x, y;
    po(int x = 0, int y = 0) : x(x), y(y) {}
} tgt, que[N * N];
vector<int> row[N], col[N];
int dis[N][N];
int n, m;
int bfs()
{
    int qf, qt = 1;
    que[qf = 0] = po(1, 1);
    dis[1][1] = 0;
    po tp;
    vector<po> v;
    while (qf < qt)
    {
        tp = que[qf++];
        int x = tp.x, y = tp.y;
        v.clear();
        // right left
        auto it = upper_bound(row[x].begin(), row[x].end(), y);
        v.push_back(po(x, *it - 1));
        v.push_back(po(x, (*(--it)) + 1));

        // up down
        it = upper_bound(col[y].begin(), col[y].end(), x);
        v.push_back(po(*it - 1, y));
        v.push_back(po(1 + *(--it), y));
        //
        for (int i = 0; i < v.size(); i++)
        {
            int nx = v[i].x, ny = v[i].y;
            if (dis[nx][ny] >= inf)
            {
                dis[nx][ny] = dis[x][y] + 1;
                que[qt++] = po(nx, ny);
                if (abs(nx - tgt.x) + abs(ny - tgt.y) == 1)
                {
                    return dis[nx][ny];
                }
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", mz[i] + 1);
    }
    for (int i = 0; i <= m + 1; i++)
    {
        mz[n + 1][i] = mz[0][i] = '#';
    }
    for (int i = 0; i <= n + 1; i++)
    {
        mz[i][0] = mz[i][m + 1] = '#';
    }
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            dis[i][j] = inf;
            if (mz[i][j] == '@')
            {
                tgt.x = i;
                tgt.y = j;
            }
            if (mz[i][j] != '.')
            {
                row[i].push_back(j);
                col[j].push_back(i);
            }
        }
    }
    cout << bfs() << endl;
    return 0;
}