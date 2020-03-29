#include <bits/stdc++.h>

#define SIZE 10000001

using namespace std;

bool marked[SIZE];
int cp[SIZE];

void sieve()
{
    for(int i = 3; i * i < SIZE; i += 2)
        if(!marked[i])
            for(int j = i * i; j < SIZE; j += 2 * i)
                marked[j] = true;
    cp[2] = 1;//count prime(1 to n)
    for(int i = 3; i < SIZE; i += 2)
    {
        if(!marked[i]) cp[i] = cp[i-1] + 1;
        else cp[i] = cp[i-1];
        cp[i+1] = cp[i];
    }
}
int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<cp[n] - cp[n/2]<<endl;
    }
    return 0;
}
