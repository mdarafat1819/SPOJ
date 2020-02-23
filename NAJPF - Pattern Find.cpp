#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A, B;
        cin>>A>>B;
        vector <int> pos;
        int lena = A.length() - 1, lenb = B.length() - 1, flag = 0, cnt = 0;
        if(lena > lenb)
        {
            for(int i = 0; i < (A.length() - lenb); i++)
            {
                cnt = 0;
                if((A[i] == B[0]) && (A[i + lenb] == B[lenb]))
                {
                    for(int j = i, k = 0; j <=(i + lenb); j++, k++)
                        if(A[j] == B[k]) cnt++;
                    if(cnt == (lenb + 1))
                    {
                        pos.push_back(i);
                        flag = 1;
                        i = i + cnt - 1;
                    }
                }
            }
        }
        else flag = 0;
        if(flag)
        {
            cout<<pos.size()<<endl;
            for(int i = 0; i < pos.size(); i++)
            {
                if(i == (pos.size() - 1)) cout<<pos[i] + 1<<endl;
                else cout<<pos[i] + 1<<" ";
            }
        }
        else cout<<"Not Found"<<endl;
        if(!t) continue;
        cout<<endl;
    }
}
