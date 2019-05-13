#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n;

    cin>>n;

    char str[n+1][n+1];

    int x=0,i,j,a=0;

    for(i=0;i<n;i++)
    {
        cin>>str[i];

    }

    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
           if(str[i][j]=='#'&&str[i-1][j]=='#'&&str[i+1][j]=='#'&&str[i][j-1]=='#'&&str[i][j+1]=='#')
           {
               //cout<<"HERE";
               str[i][j]='.';
               str[i-1][j]='.';
               str[i+1][j]='.';
               str[i][j-1]='.';
               str[i][j+1]='.';
           }
        }
    }
    for(i=0;i<n;i++)
    {
        //cout<<str[i]<<endl;
        for(j=0;j<n;j++)
        {
           if(str[i][j]=='#')
            a=1;
        }
    }
    if(a==0)
        cout<<"YES";
    else
        cout<<"NO";


}
