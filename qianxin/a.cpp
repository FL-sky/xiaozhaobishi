#include <bits/stdc++.h>
using namespace std;

int stk[10], ls;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算dag 路径上起始到目的节点的路径数目
     * @param nodes int整型vector<vector<>> 第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ），若为空，就是没有下一个节点了。
     * @return int整型
     */
    vector<int> g[5];
    int cnt;
    void dfs(int u, int dep = 1)
    {
        if (u == 4)
        {
            ++cnt;
            for (int i = 0; i < dep; i++)
            {
                printf("%d->", stk[i]);
            }
            puts("");
            return;
        }
        for (int j = 0; j < g[u].size(); j++)
        {
            int t = g[u][j];
            stk[dep] = t;
            dfs(t, dep + 1);
        }
    }
    int DagPathNum(vector<vector<int>> &nodes)
    {
        int n = nodes.size();

        if (n > 5)
        {
            while (1)
                ;
        }
        for (int i = 0; i < 5; i++)
            g[i].clear();
        for (int i = 0; i < nodes.size(); i++)
        {
            for (int j = 0; j < nodes[i].size(); j++)
            {
                int t = nodes[i][j];
                if (t > 5)
                {
                    while (1)
                        ;
                }
                g[i].push_back(t);
            }
        }
        cnt = 0;
        dfs(0);
        return cnt;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4}, {2, 3, 4}, {3, 4}, {4}};
    Solution sl;
    auto it = sl.DagPathNum(v);
    cout << it << endl;
    return 0;
}