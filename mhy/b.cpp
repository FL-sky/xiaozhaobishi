#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char s[N];

int main()
{
    scanf("%s", s);
    list<char> lt;
    for (int i = 0; s[i]; i++)
    {
        lt.push_back(s[i]);
    }
    lt.push_front('x');
    lt.push_back('x');
    lt.push_back('x');
    int ans = 0;
    list<char>::iterator it = lt.begin(), ij = ++lt.begin(), ip, iq;
    int fd = 0;
    while (1)
    {
        fd = 0;
        int cnt = 0;
        while (cnt < lt.size())
        {
            if (min(*it, *ij) == 'f' && max(*it, *ij) == 'w')
            {
                fd = 1;
                break;
            }
            ++it;
            ++ij;
            if (*ij == 'x')
            {
                it = lt.begin();
                ij = ++lt.begin();
            }
            ++cnt;
        }
        if (!fd)
            break;
        do
        {
            ip = it, iq = ij;
            --ip;
            ++iq;
            lt.erase(it);
            lt.erase(ij);
            ans += 2;
            it = ip;
            ij = iq;
        } while (min(*it, *ij) == 'f' && max(*it, *ij) == 'w');
    }
    cout << ans << endl;
    return 0;
}