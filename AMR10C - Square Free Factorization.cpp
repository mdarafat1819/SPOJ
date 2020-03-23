#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, res = 0, ans = 1;
        cin>>n;
        for(int i = 2; i * i <= n; i++)
        {
            res = 0;
            while(!(n % i))
            {
                n /= i;
                res++;
            }
            ans = max(ans, res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
