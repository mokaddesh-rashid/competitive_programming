#include<iostream>


using namespace std;


int main()
{
    int t,o=1;

    cin>>t;

    while(t>0)
    {
        int n;

        cin>>n;

        long long int x=0,y,z,pos=-1;

        for(int i=0;i<n;i++)
        {
            cin>>y>>z;

            y=(z*z)+(y*y);

            if(i==0)
            {
                pos=i+1;
                x=y;
            }

            else if(x<y)
            {
                pos=i+1;
                x=y;
            }


        }

            cout<<"Case "<<o<<": "<<pos<<endl;
            o++;
            t--;
    }
}
