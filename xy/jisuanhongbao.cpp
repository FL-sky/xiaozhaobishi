#include <bits/stdc++.h>
using namespace std;

int getrand()
{
    return rand() % 100;
}

int getgift()
{ //另外的约束：一等奖最多获得一次，奖项有数量限制，没有就是 5感谢参与
    int rd = getrand();
    if (rd < 5)
        return 1; //一等奖
    if (rd < 5 + 10)
        return 2; //二等奖
    if (rd < 5 + 10 + 15)
        return 3; //三等奖
    if (rd < 5 + 10 + 15 + 30)
        return 4; //纪念奖
    return 5;     //感谢参与
}
int main()
{

    return 0;
}