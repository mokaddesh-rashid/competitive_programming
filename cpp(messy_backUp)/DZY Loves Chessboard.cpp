#include<iostream>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    char str[n+1][m+1],i,x,a,b,c;

    for(i=0;i<n;i++)
        cin>>str[i];

    for(i=0;i<n;i++)
    {
        for(x=0;x<m;x++)
        {
            if(i%2==0)
            {
                if(x%2==0&&str[i][x]=='.')
                    cout<<'B';
                else if(x%2==1&&str[i][x]=='.')
                    cout<<'W';
                else
                    cout<<'-';
            }
            if(i%2==1)
            {
                if(x%2==1&&str[i][x]=='.')
                    cout<<'B';
                else if(x%2==0&&str[i][x]=='.')
                    cout<<'W';
                else
                    cout<<'-';
            }
        }

        cout<<endl;
    }

}
