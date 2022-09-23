#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char str[N];
int main()
{
    int n, r, b;
    while (scanf("%d%d%d", &n, &r, &b) != EOF)
    {
        int rawr = r, rawb = b;
        scanf("%s", str);
        int len = strlen(str);
        int needr = 0, needb = 0;
        if (n != len)
            while (1)
                ;
        for (int i = 1; i < len; i++)
        {
            if (str[i] == str[i - 1])
            {
                if (str[i] == 'r')
                {
                    if (b > 0)
                    {
                        --b;
                    }
                    else
                    {
                        needb++;
                    }
                }
                else if (str[i] == 'b')
                {
                    if (r > 0)
                    {
                        --r;
                    }
                    else
                    {
                        needr++;
                    }
                }
            }
        }
        if (needr == 0 && needb == 0)
        {
            printf("%d", int(len + rawr - r + rawb - b));
            puts("");
        }
        else
        {
            printf("%d %d", needr, needb);
            puts("");
        }
    }
    return 0;
}