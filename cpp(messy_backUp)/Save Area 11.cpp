#include<iostream>


using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    int t,o=1;

    cin>>t;

    while(t>0)
    {
        long long int n,x;

        cin>>x>>n;

        long long int arr[10*10*10*10+4]={0},i,j,a=0,b,d,maxx=0,c=0;

        for(i=0;i<n;i++)
        {
            cin>>b>>d;
            arr[b]++;
            arr[d+1]--;
            maxx=max(b,maxx);
        }

       // cout<<maxx<<endl;

        if(n<=x)
            cout<<"Plan "<<o<<": Yes\n";

        else
        {
            for(i=0;i<=maxx;i++)
            {

                a+=arr[i];
                //cout<<a<<' '<<endl;
                c=max(c,a);

            }
            //cout<<c<<' '<<endl;

            if(c<=x)
                 cout<<"Plan "<<o<<": Yes\n";
            else
                cout<<"Plan "<<o<<": No\n";
        }

            t--;
            o++;
    }
}
