#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n;
    while (n-- > 0)
    {
        cin >> m;
        string str;
        map<string, int> mp;
        for (int i = 0; i < m; i++)
        {
            cin >> str;
            for (int j = 0; j < str.length(); j++)
            {
                if (str[j] >= 'A' && str[j] <= 'Z')
                {
                    str[j] += 'a' - 'A';
                } //转小写
            }
            mp[str]++;
        }
        cin >> k;
        vector<string> pb(k);
        for (int i = 0; i < k; i++)
        {
            cin >> pb[i];
            for (int j = 0; j < pb[i].length(); j++)
                if (pb[i][j] >= 'A' && pb[i][j] <= 'Z')
                {
                    pb[i][j] += 'a' - 'A';
                } //转小写
        }
        int ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            bool flg = true;
            for (int i = 0; i < k; i++) // k个停用词
            {
                const string &wd = it->first;
                int len = wd.length();
                if (len != pb[i].length())
                    continue;
                bool pipei = true;
                for (int j = 0; j < len; j++)
                {
                    if (pb[i][j] == '?')
                        continue;
                    if (pb[i][j] != wd[j])
                    {
                        pipei = false;
                        break;
                    }
                }
                if (pipei)
                {
                    flg = false;
                    break;
                }
            }
            if (flg)
            {
                ans = max(ans, it->second);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
