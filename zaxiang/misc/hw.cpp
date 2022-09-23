#include <bits/stdc++.h>
using namespace std;
map<string, int> bt, zw;
const int N = (5000 + 10) * 2;
char str[N];
struct po
{
    int btcnt, cnt;
    int btpos, zwpos;
    po()
    {
        btcnt = cnt = 0;
        btpos = zwpos = N;
    }
    bool operator<(const po &b) const
    {
        if (cnt == b.cnt)
        {
            if (btcnt == b.btcnt)
            {
                if (btpos == b.btpos)
                {
                    return zwpos < b.zwpos;
                }
                return btpos < b.btpos;
            }
            return btcnt > b.btcnt;
        }
        return cnt > b.cnt;
    }
};
map<string, po> mp;
map<string, int> btp, zwp;
struct ele
{
    string word;
    po val;
    bool operator<(const ele &b) const
    {
        return val < b.val;
    }
};
vector<ele> v;
int main()
{
    int n, m;
    cin >> n >> m;
    getchar();
    for (int i = 0; i < m; i++)
    {
        {
            int idx = 0;
            fgets(str, N, stdin);
            int len = strlen(str);
            string word = "";
            for (int j = 0; j < len;)
            {
                word = "";
                while (j < len && (str[j] == ' ' || str[j] == '\n' || str[j] == '\r' || str[j] == 0))
                    ++j;
                while (j < len && str[j] != ' ' && str[j] != '\n' && str[j] != '\r' && str[j] != 0)
                {
                    word += str[j++];
                }
                if (word.length())
                {
                    ++idx;
                    bt[word]++;
                    if (btp.find(word) == btp.end())
                    {
                        btp[word] = idx;
                    }
                }
            }
        }
        {
            int idx = 0;
            fgets(str, N, stdin);
            int len = strlen(str);
            string word = "";
            for (int j = 0; j < len;)
            {
                word = "";
                while (j < len && (str[j] == ' ' || str[j] == '\n' || str[j] == '\r' || str[j] == 0))
                    ++j;
                while (j < len && str[j] != ' ' && str[j] != '\n' && str[j] != '\r' && str[j] != 0)
                {
                    word += str[j++];
                }
                if (word.length())
                {
                    ++idx;
                    zw[word]++;
                    if (zwp.find(word) == zwp.end())
                    {
                        zwp[word] = idx;
                    }
                }
            }
        }
    }
    for (auto it = bt.begin(); it != bt.end(); it++)
    {
        mp[it->first].btcnt = it->second;
        mp[it->first].btpos = btp[it->first];
    }
    for (auto it = zw.begin(); it != zw.end(); it++)
    {
        // mp[it->first].zwcnt = it->second;
        mp[it->first].cnt = it->second + mp[it->first].btcnt * 3;
        mp[it->first].zwpos = zwp[it->first];
    }
    v.resize(mp.size());
    int i = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        v[i].word = it->first;
        v[i].val = it->second;
    }
    sort(v.begin(), v.end());
    puts("\n==============\n");
    cout << v[0].word;
    for (int i = 1; i < n; i++)
    {
        cout << " " << v[i].word;
    }
    cout << endl;
    return 0;
}