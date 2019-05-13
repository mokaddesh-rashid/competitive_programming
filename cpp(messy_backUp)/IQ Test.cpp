#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[11][11];

    int i,x=0,a,b,c,d;

    for(i=0;i<4;i++)
        cin>>str[i];

    for(i=0;i<3;i++)
    {

        for(int n=0;n<3;n++)
        {
            a=0;
            b=0;

            if(str[i][n]=='#')
                a++;
            else
                b++;
            if(str[i+1][n]=='#')
                a++;
            else
                b++;
            if(str[i][n+1]=='#')
                a++;
            else
                b++;
            if(str[i+1][n+1]=='#')
                a++;
            else
                b++;

            if(a==4||b==4||a==3||b==3)
            {
                x=1;
                break;
            }
        }
    }

    if(x==1)
        cout<<"YES";

    else
        cout<<"NO";
}
