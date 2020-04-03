#include <bits/stdc++.h>

#define SIZE 100001

using namespace std;

int d[SIZE], ans[SIZE][1325];

void divisorCount()
{
    for(int i = 1; i < SIZE; i++)
    {
        int n = i, cnt = 0, ans = 1;
        for(int j = 2;  j * j <= n; j++, cnt = 0)
        {
            while(!(n % j)) n /= j, cnt++;
            ans *= (2 * cnt + 1);
        }
        if(n > 1) ans *= 3;
        d[i] = ans;
    }
}
void calc()
{
    for(int i = 1; i < SIZE; i++)
    {
        for(int j = 1; j < 1324; j++)
            ans[i][j] += ans[i-1][j];
        ans[i][d[i]]++;
    }
}
int main()
{
    divisorCount();
    calc();
    int t;
    cin>>t;
    while(t--)
    {
        long long int k, a, b, r;
        cin>>k>>a>>b;
        r = sqrt(a);
        if(r * r < a) r++;
        a = r;
        b = sqrt(b);
        cout<<ans[b][k]-ans[a-1][k]<<endl;
    }
    return 0;
}
