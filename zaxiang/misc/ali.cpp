#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char str[N];
int main()
{
    vector<string> v = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO",
                        "PQRS", "TUV", "WXYZ"};
    while (scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        char ch = 0;
        int l = -1, lastop = 0;

        for (int i = 0; i < len; i++)
        {
            int op = str[i] - '0';
            if (op == 1)
            {
                if (ch)
                    putchar(ch);

                ch = 0;
                l = -1;
            }
            else
            {
                if (op != lastop)
                {
                    if (ch)
                        putchar(ch);

                    ch = v[op][0];
                    l = 0;
                }
                else
                {
                    l = (l + 1) % v[op].length();
                    ch = v[op][l];
                }
            }
            lastop = op;
        }
        puts("");
    }
    return 0;
}