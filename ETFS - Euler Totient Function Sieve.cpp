#include <bits/stdc++.h>

#define SIZE 10000001

using namespace std;

typedef long long int ll;

vector <ll> p;
bool marked[SIZE];

void sieve()
{
    for(ll i = 3; i * i < SIZE; i += 2)
    {
        if(!marked[i])
        {
            for(ll j = i * i; j < SIZE; j += 2 * i)
                marked[j] = true;
        }
    }
    p.push_back(2);
    for(ll i = 3; i < SIZE; i += 2)
        if(!marked[i]) p.push_back(i);
}

void phi(ll a, ll b)
{
    ll ans[100001], temp[100001];
    for(ll i = a; i <= b; i++)
        ans[i - a] = i, temp[i - a] = i;
    for(int i = 0; i < p.size(); i++)
    {
        ll start = (a / p[i]) * p[i];
        if(start < a) start += p[i];
        for(ll j = start; j <= b; j += p[i])
        {
            ans[j - a] -= (ans[j-a] / p[i]);
            while(!(temp[j - a] % p[i])) temp[j - a] /= p[i];
        }
    }
    for(ll i = a; i <= b; i++)
        if(temp[i - a] > 1) ans[i - a] -= (ans[i - a] / temp[i - a]);
    for(ll i = a; i <= b; i++) cout<<ans[i-a]<<endl;
}

int main()
{
    sieve();
    ll a, b;
    cin>>a>>b;
    phi(a, b);
    return 0;
}
