#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n % 2)) return false;
    for(int i = 3; i * i <= n; i += 2)
        if(!(n % i)) return false;
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m, n;
        cin>>m>>n;
        for(int i = m; i <= n; i++)
            if(isPrime(i)) cout<<i<<endl;
        cout<<endl;
    }

    return 0;
}
