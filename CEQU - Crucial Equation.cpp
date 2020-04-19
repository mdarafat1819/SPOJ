#include <bits/stdc++.h>

#define print(x, y) 0

using namespace std;

int egcd(int a, int b, int* x, int* y)
{
    if(!b)
    {
        *x = 1, *y = 0;
        return a;
    }
    int x1, y1;
    int g = egcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * (y1);
    return g;
}

int main()
{
    int t, a, b, x, y;
    cin>>t;
    for(int cs = 1; cs <= t; cs++)
    {
        int a, b, c, g;
        cin>>a>>b>>c;
        g = egcd(a, b, &x, &y);
        if(!(c % g))
        {
            cout<<"Case "<<cs<<": Yes"<<endl;
            if(print(x, y)) cout<<"x: "<<(c/g)*x<<" y: "<<(c/g)*y<<endl;
        }
        else cout<<"Case "<<cs<<": No"<<endl;
    }
    return 0;
}
