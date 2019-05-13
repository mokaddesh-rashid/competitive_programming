#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    char str[n+1][m+1];

    int i,x,d=0;

    for(i=0;i<n;i++)
       {
          cin>>str[i];

          for(x=1;x<m;x++)
          {
              if(str[i][0]!=str[i][x])
                d=1;
          }
       }

    if(d==0)
    for(i=0;i<n;i++)
         for(x=i;x<i+1;x++)
    {
        if(x==i)
            continue;
        else if(strcmp(str[i],str[x])==0)
        {
            d=1;
            break;
        }
        if(d==1)
            break;
    }

    if(d==0)
        cout<<"YES";

    else
        cout<<"NO";




}
