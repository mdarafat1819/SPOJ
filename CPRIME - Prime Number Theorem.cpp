#include <bits/stdc++.h>

#define SIZE 100000001

using namespace std;

bool marked[SIZE];
vector <int> primes;

void sieve()
{
    for(int i = 3; i * i < SIZE; i += 2)
    {
        if(!(marked[i]))
        {
            for(int j = i * i; j < SIZE; j += 2 * i)
            marked[j] = true;
        }
    }
    primes.push_back(2);
    for(int i = 3; i < SIZE; i += 2)
        if(!(marked[i])) primes.push_back(i);
}
int main()
{
    sieve();
    double n;
    while(1)
    {
        cin>>n;
        if(n == 0.0) break;
        int x = upper_bound(primes.begin(), primes.end(), (int)n) - primes.begin();
        printf("%.1lf\n", abs((x - (n / log(n)))) / x * 100);
    }
    return 0;
}
