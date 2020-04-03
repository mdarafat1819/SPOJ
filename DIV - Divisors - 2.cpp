#include <bits/stdc++.h>

#define SIZE 1000001

using namespace std;

bool np[80];
int nDiv[SIZE];

int primeFact(int n)
{
    int cnt = 0, p = 0;
    for(int i = 2; i * i <= n; i++)
    {
        if(!(n % i))
        {
            p++;
            while(!(n % i)) n /= i, cnt++;
        }
    }
    if(n > 1) p++, cnt++;
    if(p == cnt && cnt == 2) return 1;
    return 0;
}
void sieve()
{
    for(int i = 1; i < SIZE; i++)
        for(int j = i; j < SIZE; j += i)
            nDiv[j]++;
    for(int i = 1; i < 80; i++)
        np[i] = primeFact(i);
}
int main()
{
    sieve();
    int cnt = 0;
    for(int i = 1; i < SIZE; i++)
    {
        if(np[nDiv[i]])
        {
            cnt++;
            if(!(cnt % 9))
                cout<<i<<endl;
        }
    }
    return 0;
}
