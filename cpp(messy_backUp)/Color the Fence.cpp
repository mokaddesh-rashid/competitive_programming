#include<iostream>

using namespace std;


int main()
{
    long long int v;

    cin>>v;

    long long int arr[11],i,j,a,b,c,minn=0,x;

    for(i=0;i<9;i++)
    {
        cin>>arr[i];

        if(i==0)
        {

            minn=arr[i];
            j=i+1;

        }

        else if(minn>=arr[i])
        {
           minn=arr[i];
            j=i+1;
        }
    }

    cout<<j<<' '<<minn<<endl;


   if(v>=minn)
    {
        x=(v/minn)*minn;
        x=v-x;



        while(v>=minn)
        {
             //cout<<x<<endl;
            for(i=0;i<9;i++)
            {
               if(arr[i]<=minn+x)
                  j=i+1;
            }

            cout<<j;
            v-=minn;
            if(arr[j-1]>minn)
            {
                x=x-(arr[j-1]-minn);
                // cout<<x<<endl<<endl;
            }
        }
    }

    else
        cout<<-1;
}
