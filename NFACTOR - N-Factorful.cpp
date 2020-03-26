#include <bits/stdc++.h>

#define SIZE 1000001

using namespace std;

int marked[SIZE];
int ans[SIZE][11];

void sieve()
{
    for(int i = 2; i < SIZE; i++)
        if(!marked[i])
            for(int j = i; j < SIZE; j += i)
                marked[j]++;
    for(int i = 1; i < SIZE; i++)
    {
        for(int j = 0; j <= 10; j++)
            ans[i][j] = ans[i-1][j];
        ans[i][marked[i]]++;
    }
}
int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, n;
        cin>>a>>b>>n;
        cout<<ans[b][n] - ans[a-1][n]<<endl;
    }
    return 0;
}
