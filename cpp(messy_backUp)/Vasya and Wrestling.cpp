#include<iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n;

    cin>>n;

    long long int i,y=0,a=0,b=0,x=0,z,m,f[n+1],s[n+1],k=-1,l=-1,g=0,h;

    for(i=0;i<n;i++)
    {
        cin>>m;

        if(m>0)
        {
            k++;
            f[k]=m;
            a++;
            x+=m;
            z=1;
        }
        else
        {
            l++;
            b++;
            m*=-1;
            s[l]=m;
            y+=m;
            z=-1;
        }

        if(k>-1&&l>-1&&g==0)
        {
            h=min(k,l);

            if(f[h]>s[h])
                g=1;
            else if(f[h]<s[h])
                g=-1;

        }
    }

    //cout<<x<<' '<<y<<' '<<g<<endl;

    if(x>y)
      cout<<"first";
    else if(x<y)
      cout<<"second";
    else if(g==1)
      cout<<"first";
    else if(g==-1)
      cout<<"second";
    else if(z==1)
        cout<<"first";
    else
        cout<<"second";



}
