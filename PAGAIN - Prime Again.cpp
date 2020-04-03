#include <bits/stdc++.h>

#define SIZE 65537

using namespace std;

bool marked[SIZE];
long long int primes[SIZE], idx;

void sieve()
{
    for(int i = 3; i * i < SIZE; i += 2)
    {
        if(!marked[i])
            for(int j = i * i; j < SIZE; j += 2 * i)
                marked[j] = 1;
    }
    primes[idx++] = 2;
    for(int i = 3; i < SIZE; i += 2)
        if(!marked[i]) primes[idx++] = i;
}
bool isPrime(long long int n)
{
    for(int i = 0; (primes[i]*primes[i]<=n) && (i<idx); i++)
        if(!(n % primes[i])) return 0;
    return 1;
}
int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        if(n == 3)
        {
            cout<<"2"<<endl;
             continue;
        }
        if(!(n % 2)) n--;
        else n -= 2;
        while(1)
        {
            if(isPrime(n))
                {
                    cout<<n<<endl;
                    break;
                }
            n -= 2;
        }
    }
    return 0;
}
