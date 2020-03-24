#include <bits/stdc++.h>

using namespace std;

int divisorCount(int n)
{
    int cnt = 0;
    for(int i = 1; i * i <= n; i++)
    {
        if(i * i == n) cnt++;
        else if(!(n % i)) cnt += 2;
    }
    return cnt;
}
int gcd(int a, int b)
{
    while(1)
    {
        if(!a) return b;
        int temp = a;
        a = b % a;
        b = temp;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", divisorCount(gcd(a, b)));
    }
    return 0;
}
