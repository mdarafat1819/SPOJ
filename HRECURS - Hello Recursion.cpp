#include <bits/stdc++.h>

using namespace std;

int sum(int arr[], int n)
{
    if(n == 1) return arr[n - 1];
    return arr[n - 1] + sum(arr, n - 1);
}

int main()
{
    int t, n;
    cin>>t;
    for(int cs = 1; cs <= t;  cs++)
    {
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++)  cin>>arr[i];
        cout<<"Case "<<cs<<": "<<sum(arr, n)<<endl;
    }
    return 0;
}
