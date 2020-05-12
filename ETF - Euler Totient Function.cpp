#include <bits/stdc++.h>

#define SIZE 1000001

using namespace std;

int ans[SIZE];

void phi()
{
    for(int i = 1; i < SIZE; i++) ans[i] = i;
    for(int i = 2; i < SIZE; i++)
    {
        if(ans[i] == i)
        {
            for(int j = i; j < SIZE; j += i)
                ans[j] -= ans[j] / i;
        }
    }
}

int main()
{
    phi();
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}

