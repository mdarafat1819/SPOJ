#include <bits/stdc++.h>

#define SIZE 32000

using namespace std;

bool marked[SIZE];
bool primes[100001];
void sieve()
{
    for(int i = 3; i * i < SIZE; i += 2)
        if(!marked[i])
        for(int j = i * i; j < SIZE; j += 2 * i)
            marked[j] = true;
}
void segmentSieve(int m, int n)
{
    for(int i = 3; i * i <= n; i += 2)
    {
        if(!marked[i])
        {
            int temp = (m / i) * i;
            if(temp < m) temp += i;
            for(int j = temp; j <= n; j += i)
                primes[j-m] = true;
            if(temp == i) primes[i-m] = false;
        }
    }
    int temp = (m / 2) * 2;
    if(temp < m) temp += 2;
    for(int i = temp; i <= n; i += 2)
        primes[i-m] = true;
    if(m <= 2) primes[2-m] = false;
}
int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, cnt = 0;
        cin>>a>>b;
        if(a == 1) a++;
        segmentSieve(a, b);
        for(int i = a; i <= b; i++)
            if(!primes[i-a]) cout<<i<<endl;
        memset(primes, false, sizeof(primes));
    }
    return 0;
}
