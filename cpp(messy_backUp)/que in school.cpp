#include<iostream>

using namespace std;

int main()
{
    char str[11111];

    int len,t,i,n,a,b;

    cin>>len>>t;

    cin>>str;

    for(i=0;i<t;i++)
    {
        for(n=0;n<len;n++)
        {
            if(str[n]=='B'&&str[n+1]=='G')
            {
                swap(str[n],str[n+1]);
                n++;
            }
        }
    }

    cout<<str;
}
