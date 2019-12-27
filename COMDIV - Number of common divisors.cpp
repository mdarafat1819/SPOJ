#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}
int cDivisorCount(int a, int b)
{
    int g = gcd(a, b), cnt = 0;
    for(int i = 1; i * i <= g; i++)
       {
           if(i * i == g) cnt++;
           else if(!(g % i)) cnt += 2;
       }
    return cnt;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, g, cnt = 0;
        scanf("%d%d", &a, &b);
        printf("%d\n", cDivisorCount(a, b));
    }

    return 0;
}
