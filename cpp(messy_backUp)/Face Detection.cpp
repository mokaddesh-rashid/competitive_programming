#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    char str[n+5][m+5],f,a,c,e;

    int i,x,y,z,aa=0,ff=0,cc=0,ee=0,res=0;

    for(i=0;i<n;i++)
        cin>>str[i];

    for(i=0;i<n;i++)
    {
        for(m=0;m<n;m++)
        {
            if(str[i][m]!='*')
            {
                aa=0;
                ff=0;
                cc=0;
                ee=0;
                if(str[i][m]=='a')
                    aa++;
                else if(str[i][m]=='f')
                    ff++;
                else if(str[i][m]=='c')
                    cc++;
                else if(str[i][m]=='e')
                    ee++;
                if(str[i][m+1]=='a')
                    aa++;
                else if(str[i][m+1]=='f')
                    ff++;
                else if(str[i][m+1]=='c')
                    cc++;
                else if(str[i][m+1]=='e')
                    ee++;

                if(str[i+1][m+1]=='a')
                    aa++;
                else if(str[i+1][m+1]=='f')
                    ff++;
                else if(str[i+1][m+1]=='c')
                    cc++;
                else if(str[i+1][m+1]=='e')
                    ee++;

                if(str[i+1][m]=='a')
                    aa++;
                else if(str[i+1][m]=='f')
                    ff++;
                else if(str[i+1][m]=='c')
                    cc++;
                else if(str[i+1][m]=='e')
                    ee++;

               if(aa==1&&ff==1&&cc==1&&ee==1)
                  res++;
            }
        }
    }
    cout<<res;
}
