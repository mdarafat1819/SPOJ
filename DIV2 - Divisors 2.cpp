#include <bits/stdc++.h>

#define SIZE 1000001

using namespace std;

int nDiv[SIZE], cnt = 0;
bool mark[SIZE];

void dn()
{
    for(int i = 1; i < SIZE; i++)
        for(int j = i; j < SIZE; j += i) nDiv[j]++;
}
int main()
{
    dn();
    for(int i = 1; i < SIZE; i++)
        for(int j = i; j < SIZE; j += i)
        {
            if((nDiv[j] % nDiv[i]) || (nDiv[j] <= 3) && !mark[j])
                mark[j] = 1;
        }
    for(int i = 1; i < SIZE; i++)
    {
        if(!mark[i])
        {
            cnt++;
            if(!(cnt % 108)) cout<<i<<endl;
        }
    }
    return 0;
}
