#include<iostream>
#include<string>


using namespace std;

int main()
{
    string str;

    cin>>str;

    long long int arr[10*10*10*10*10+2],a,b,i,j,x=0,n,m;

    cin>>m;

    n=str.size();


    for(i=0;i<m;i++)
    {
        cin>>a;
        a--;
        arr[a]++;
    }

    for(i=0;i<n/2;i++)
    {
        x+=arr[i];

        if(x%2)
            swap(str[i],str[n-i-1]);
    }

    cout<<str;

}
