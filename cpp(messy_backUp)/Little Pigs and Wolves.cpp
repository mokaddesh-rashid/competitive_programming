#include<iostream>
#include<cstring>

using namespace std;


int main()
{
    int n,m;

    cin>>n>>m;

    char str[n+1][m+1];
    int i,j,a,x=0;

    for(i=0;i<n;i++)
        {
            cin>>str[i];

        }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(str[i][j]=='P')
            {
                if(str[i+1][j]=='W')
                {
                    //cout<<"here";
                    x++;
                    str[i+1][j]='.';

                }
                else if(str[i-1][j]=='W')
                {
                     //cout<<"here2";
                    x++;
                    str[i-1][j]='.';
                }
                else if(str[i][j+1]=='W')
                {
                     //cout<<"here3";
                    x++;
                    str[i][j+1]='.';
                }
                else if(str[i][j-1]=='W')
                {
                     //cout<<"here4";
                    x++;
                    str[i][j-1]='.';
                }

            }
        }
    }

    cout<<x;
}
