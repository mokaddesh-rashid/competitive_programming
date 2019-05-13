#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    while(true)
    {
        long long int n;

        cin>>n;



        if(n==0)
            break;

         long long int arr[n+1],i,a=0,b=0,c;

         for(i=0;i<n;i++)
           {
              cin>>arr[i];

            if(arr[i]!=i+1)
                a++;

            if(i>1&&arr[i]>arr[i-1])
                b=1;

           }

          // cout<<a<<' '<<b<<endl;


           if(a==0)
                cout<<"Carlos";
           else if(b==0&&n%2)
                cout<<"Carlos";
           else if(b==0&&n%2==0)
                cout<<"Marcelo";
           else
           {
               if(a%2==0)
                cout<<"Marcelo";
               else
                 cout<<"Carlos";
           }

           cout<<endl;




    }
}
