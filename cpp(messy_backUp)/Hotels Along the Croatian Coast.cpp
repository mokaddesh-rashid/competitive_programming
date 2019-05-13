#include<iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int N,M;

    cin>>N>>M;

    long long int value[N+1],save[N+1],x=0,y,z=0,a,b=0,i,j,maxi=0;

    for(i=0;i<N;i++)
    {
        cin >> value[i];
        x += value[i];

        save[i] = x;

        if (maxi == 0 && save[i]<=M)
          maxi = save[i];

        else if (maxi < save[i] && save[i]<=M)
          maxi = save[i];

       else
       {
            j=b;

        while(j<i)
        {
            z=save[i]-save[j];

            if(z>M)
             b++;

            if(z<=M)
               maxi=max(z,maxi);

            if(z<maxi)
                break;

            j++;
        }


       }

    }

    cout<<maxi;

}
