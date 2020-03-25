#include <bits/stdc++.h>
#define SIZE 1000001

using namespace std;

int nDiv[SIZE];
int primeFact(int n)
{
    int cnt1 = 0, cnt2 = 0;
    for(int i = 2; i * i <= n; i++)
    {
        if(!(n % i)) cnt1++;
        while(!(n % i))
        {
            cnt2++;
            n /= i;
        }
    }
    if(n > 1) cnt2++, cnt1++;
    if((cnt1 == 2) && (cnt2 == 2)) return 1;
    return 0;
}
int main()
{
    int cnt = 0;
    for(int i = 1; i < SIZE; i++)
        for(int j = i; j < SIZE; j += i) nDiv[j]++;
    for(int i = 1; i < SIZE; i++)
    {
        if(primeFact(nDiv[i]))
        {
            cnt++;
            if(!(cnt % 9)) cout<<i<<endl;
        }
    }
    return 0;
}
