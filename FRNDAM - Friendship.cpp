#include <iostream>

using namespace std;

long int sumOfDiv(long int n)
{
    long int sum = 0;
    for(int i = 1; i * i <= n; i++)
    {
        if(i * i == n)
            sum += i;
        else if(!(n % i))
        {
            sum += i;
            sum += (n / i);
        }
    }
    return sum - n;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        if(a == sumOfDiv(b))
            cout<<"Friendship is ideal"<<endl;
        else
            cout<<"Friendship is not ideal"<<endl;
    }

    return 0;
}
