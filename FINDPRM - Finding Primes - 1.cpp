#include <bits/stdc++.h>

#define SIZE 10000001

using namespace std;

bool marked[SIZE];
int cp[SIZE], ans[SIZE];

vector <int> prime;
void sieve()
{
    for(int i = 3; i * i < SIZE; i += 2)
        if(!marked[i])
            for(int j = i * i; j < SIZE; j += 2 * i)
                marked[j] = true;
    cp[2] = 1;
    for(int i = 3; i < SIZE; i += 2)
    {
        if(!marked[i]) cp[i] = cp[i-1] + 1;
        else cp[i] = cp[i-1];
        cp[i+1] = cp[i];
    }
    prime.push_back(2);
    for(int i = 3; i < SIZE; i += 2)
        if(!marked[i]) prime.push_back(i);
}
int main()
{
    sieve();
    int p = 0;
    for(int i = 0; i < prime.size()-1; i++)
    {
        int v = 2 * prime[i];
        p++;
        for(int j = v; (j < 2 * prime[i+1]) && (j < SIZE); j ++)
            cp[j] -= p;
    }
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", cp[n]);
    }
    return 0;
}
