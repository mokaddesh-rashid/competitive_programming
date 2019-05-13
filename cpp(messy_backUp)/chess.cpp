#include<iostream>
#include<cstring>


using namespace std;


int main()
{
    char str[11][11],ch;

    int i,j,a_t=11,b_t=11,c,a,b,l;


    for(i=0;i<8;i++)
        cin>>str[i];

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(str[i][j]=='W')
            {
                b=-1;
                a=0;
                l=i-1;
                while(l>=0)
                {
                    if(str[l][j]=='B')
                        b=1;
                    l--;
                    a++;
                }
              //cout<<b<<' '<<a<<endl<<'w'<<endl;
              if(b==-1)
                a_t=min(a_t,a);
            }

            else if(str[i][j]=='B')
            {
                b=-1;
                a=0;
                l=i+1;
                while(l<8)
                {
                    if(str[l][j]=='W')
                        b=1;
                    l++;
                    a++;
                }
                //cout<<b<<' '<<a<<endl<<'b'<<endl;
              if(b==-1)
                b_t=min(b_t,a);
            }
        }
    }

    if(a_t<=b_t)
        cout<<"A";
    else
        cout<<"B";
}
