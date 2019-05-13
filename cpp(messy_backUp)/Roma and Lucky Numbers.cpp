#include<iostream>

#include<string>

using namespace std;

int main()
{
     std::ios::sync_with_stdio(false);
    int n,k;

    cin>>n>>k;

    int i,count0=0,x,a,b;

    for(i=0;i<n;i++)
    {
        a=0;
        string str;

        cin>>str;

        for(x=0;x<str.size();x++)
        {
            if(str[x]=='4'||str[x]=='7')
                a++;
        }

        if(a<=k)
            count0++;
    }

    cout<<count0;
}
