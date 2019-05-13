#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[111];



    int len,i,x=0,a,b,c,d=0,n;

    cin>>len>>str;



    for(i=0;i<len;i++)
    {
        n=i;

        while(str[n+1]==str[i])
        {
            n++;
            x++;
            i++;
        }

    }

    cout<<x;

}
