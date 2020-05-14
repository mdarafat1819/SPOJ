#include <bits/stdc++.h>

#define SIZE 1000001

using namespace std;

int p[SIZE], dep[SIZE], ans[SIZE][21];
bool marked[SIZE];

void phi()
{
    for(int i = 1; i < SIZE; i++) p[i] = i;
    for(int i = 2; i < SIZE; i++)
    {
        if(!marked[i])
        {
            for(int j = i; j < SIZE; j += i)
            {
                p[j] -= (p[j] / i);
                marked[j] = true;
            }
        }
    }
}
void depth()
{
    dep[1] = 0;
    for(int i = 2; i < SIZE; i++)
    {
        int cnt = 1, ep = p[i];
        while(1)
        {
            if(ep == 1) break;
            ep = p[ep];
            cnt++;
        }
        dep[i] = cnt;
    }
}

void solve()
{
    for(int i = 1; i < SIZE; i++)
        ans[i][dep[i]]++;
    for(int i = 1; i < SIZE; i++)
    {
        for(int j = 0; j < 21; j++)
            ans[i][j] += ans[i-1][j];
    }
}

int main()
{
    phi();
    depth();
    solve();
    int t, m, n, k;
    cin>>t;
    while(t--)
    {
        cin>>m>>n>>k;
        cout<<ans[n][k] - ans[m-1][k]<<endl;
    }
    return 0;
}
