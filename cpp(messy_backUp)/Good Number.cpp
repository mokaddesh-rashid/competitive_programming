#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;

    int i,n,k,x=0;

    cin>>n>>k;

    for(i=0;i<n;i++)
    {
        int arr[10]={0},m=1,j,z;
        char ch;

        cin>>str;

        for(j=0;j<str.size();j++)
        {
            z=str[j]-48;
            arr[z]++;

            //cout<<z;
        }

       // cout<<endl;

        for(j=0;j<=k;j++)
        {
            if(arr[j]==0)
                m=0;
        }

        x+=m;




    }

    cout<<x;
}
