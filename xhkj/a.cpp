#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 4;
struct po
{
    int x, y;
    po(int x = 0, int y = 0) : x(x), y(y) {}
    void input()
    {
        cin >> x >> y;
    }
    bool operator<(const po &b) const
    {
        if (x == b.x)
        {
            return y < b.y;
        }
        return x < b.x;
    }
    bool operator==(const po &b) const
    {
        return x == b.x && y == b.y;
    }
};
int flg[N];
int main()
{
    int n;
    cin >> n;
    po tp;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        tp.input();
        mp[tp.x] = max(mp[tp.x], tp.y);
    }
    vector<po> v;
    for (auto it : mp)
    {
        v.push_back(po(it.first, it.second));
    }
    int sal = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].y > sal)
        {
            flg[i] = 1;
        }
        sal = max(sal, v[i].y);
    }
    //
    mp.clear();
    for (int i = 0; i < v.size(); i++)
    {
        if (flg[i])
        {
            tp = v[i];
            if (mp.find(tp.y) == mp.end())
            {
                mp[tp.y] = tp.x;
            }
            else
            {
                mp[tp.y] = min(tp.x, mp[tp.y]);
            }
        }
    }
    // memset(flg, 0, sizeof(flg));
    // v.clear();
    // for (auto it = mp.rbegin(); it != mp.rend(); it++)
    // {
    //     v.push_back(po(it->first, it->second));
    // }
    int minfh = 2e9;
    int ans = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        if (minfh > it->second)
        {
            ++ans;
        }
        minfh = min(minfh, it->second);
    }
    cout << ans << endl;
    return 0;
}