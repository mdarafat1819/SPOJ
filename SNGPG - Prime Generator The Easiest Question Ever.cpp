#include <iostream>

using namespace std;

int main()
{
    int t, a, b;
    cin>>t;
    while(t--)
    {
        int cnt = 0;
        cin>>a>>b;
        if(a < 4)
        {
            if(b > 4) b = 3;
            cnt = b - a + 1;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
