#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;
const int N = 1e5 + 5;
const ull M = N * 10;

unordered_set<ull> st, nd;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
ull hs(uint x, uint y)
{
    ull ret = (x + N) * M + (y + N);
    return ret;
}
bool is3(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        ull val = hs(nx, ny);
        if (st.find(val) != st.end())
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
            // po tp = po(nx, ny);
            ull val = hs(nx, ny);
            if (st.find(val) == st.end())
            {
                st.insert(val);
                nd.insert(val);
                dfs(nx, ny, 1);
            }
        }
    }
    if (ty == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            // po tp = po(nx, ny);
            ull val = hs(nx, ny);
            if (st.find(val) != st.end())
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
        // po tp = po(x, y);
        ull val = hs(x, y);
        nd.erase(val);
        st.insert(val);
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