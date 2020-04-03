#include <bits/stdc++.h>

#define SIZE 1000001

using namespace std;

int nDiv[SIZE], ans[SIZE], idx;

int primeFact(int n)
{
    int cnt = 0, p = 0;
    for(int i = 2; i * i <= n; i++)
    {
        if(!(n % i)) cnt++;
        while(!(n % i)) p++, n /= i;
    }
    if(n > 1) p++, cnt++;
    if(cnt == p && p == 2) return 1;
    return 0;
}

int main()
{
    for(int i = 1; i < SIZE; i++)
        for(int j = i; j < SIZE; j += i) nDiv[j]++;
    for(int i = 1; i < SIZE; i++)
        if(primeFact(nDiv[i])) ans[idx] = i, idx++;
    for(int i = 8; i < idx; i += 9)
        cout<<ans[i]<<endl;
    return 0;
}
