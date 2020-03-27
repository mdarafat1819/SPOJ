#include <bits/stdc++.h>

#define SIZE 100000001

using namespace std;

bool marked[SIZE];
vector <int> primes;

void sieve()
{
    for(int i = 3; i * i < SIZE; i += 2)
        if(!marked[i])
            for(int j = i * i; j < SIZE; j += 2 * i)
                marked[j] = true;
    primes.push_back(2);
    for(int i = 3; i < SIZE; i += 2)
        if(!marked[i]) primes.push_back(i);
}
int main()
{
    sieve();
    for(int i = 0; i < primes.size(); i += 100)
        cout<<primes[i]<<endl;
    return 0;
}
