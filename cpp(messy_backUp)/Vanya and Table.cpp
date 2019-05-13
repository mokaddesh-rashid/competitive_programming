#include<iostream>

using namespace std;

int main()
{
    int pos[1001][111],x1,y1,x2,y2,m;

    int ni;

    cin>>ni;


    int i,n,x=0,a,b,c;

    for(i=0;i<=100;i++)
    {
         for(n=0;n<101;n++)
              pos[i][n]=0;
    }

    for(m=0;m<ni;m++)
    {
        cin>>x1>>y1>>x2>>y2;

        for(i=x1;i<=x2;i++)
        {
            for(n=y1;n<=y2;n++)
                {
                    pos[i][n]++;
                    x++;
                }
        }
    }

    cout<<x;


}
