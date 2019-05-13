#include<iostream>
#include<string>
#include<cstdio>


using namespace std;

int main()
{
    long long int t;

    cin>>t;

    while(t>0)
    {
        long long int n,i,x,a,b,c,m,val=0;

        string str;

        char ch;

        cin>>n;

        long long int arr[n+1],value[1000]={0};

        for(i=0;i<n;i++)
        {
            cin>>ch;
            cin>>a;
            x=ch;

            value[x]=a;
            //cout<<x<<' '<<a<<endl;
        }

        cin>>m;

        while(m>=0)
        {
            getline(cin,str);
            //cout<<str<<endl;

            for(x=0;x<str.size();x++)
            {
               a=str[x];
               val+=value[a];
            }

           // cout<<m<<endl;

            m--;

        }

        //cout<<val<<endl;



        printf("%lld.%02lld$\n", val/100, val%100);

        t--;


    }
}
