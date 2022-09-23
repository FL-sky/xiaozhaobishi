#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 2;
const double eps = 1e-6;
vector<int> g[N];
int ind[N];
int du[N];

void tuopu()
{
    memset(du, 0, sizeof(du));
    for (int i = 0; i < N; i++)
        du[i] = ind[i];
    int tot = 0;
    queue<int> que;
    for (int i = 1; i < 10; i++)
        if (du[i] == 0)
            que.push(i);
    while (que.size())
    {
        int x = que.front();
        que.pop();
        for (auto it : g[x])
        {
            du[it]--;
            if (du[it] <= 0)
                que.push(it);
        }
    }
}
int main()
{
    int hang;
    cin >> hang;
    vector<int> q;
    char str[1024];
    //
    cin.getline(str, 1024);
    int ls = strlen(str);
    for (int i = 0; i < ls; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int j = i;
            while (j < ls && str[j] >= '0' && str[j] <= '9')
            {
                ++j;
            }
            str[j] = 0;
            int num = atoi(str + i);
            q.push_back(num);
            i = j;
        }
    }
    //
    memset(ind, 0, sizeof(ind));
    for (int ih = 2; ih <= hang; ih++)
    {
        cin.getline(str, 1024);
        int ls = strlen(str);
        bool fg = false;
        int u;
        for (int i = 0; i < ls; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                int j = i;
                while (j < ls && str[j] >= '0' && str[j] <= '9')
                {
                    ++j;
                }
                str[j] = 0;
                int num = atoi(str + i);
                if (!fg)
                {
                    fg = true;
                    u = num;
                }
                else
                {
                    g[num].push_back(u);
                    ind[u]++;
                }
                i = j;
            }
        }
    }
    tuopu();
    cout << (du[q[0]] == 0 ? 1 : 0);
    for (int i = 1; i < q.size(); i++)
    {
        cout << " " << (du[q[i]] == 0 ? 1 : 0);
    }
    return 0;
}