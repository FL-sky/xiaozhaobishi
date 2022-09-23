#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1e5 + 5;
struct po
{
    int x, y;
    po(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator<(const po &b) const
    {
        if (x == b.x)
            return y < b.y;
        return x < b.x;
    }
    bool operator==(const po &b) const
    {
        return x == b.x && y == b.y;
    }
};
set<po> st, nd;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool is3(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (st.find(po(nx, ny)) != st.end())
            ++cnt;
    }
    return cnt == 3;
}
int add;
void dfs(int x, int y, int ty)
{
    if (is3(x, y))
    {
        ++add;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            po tp = po(nx, ny);
            if (st.find(tp) == st.end())
            {
                st.insert(tp);
                nd.insert(tp);
                dfs(nx, ny, 1);
            }
        }
    }
    if (ty == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            po tp = po(nx, ny);
            if (st.find(tp) != st.end())
            {
                dfs(nx, ny, 0);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int it = 0, x, y; it < n; it++)
    {
        cin >> x >> y;
        po tp = po(x, y);
        nd.erase(tp);
        st.insert(tp);
        add = 0;
        dfs(x, y, 1);
        // for (int i = 0; i < 4; i++)
        // {
        //     int nx = x + dir[i][0], ny = y + dir[i][1];
        //     if (st.find(po(nx, ny)) != st.end())
        //     {
        //         dfs(nx, ny);
        //     }
        // }
        cout << nd.size() << endl;
    }
    return 0;
}