#include<iostream>
#include<string>


using namespace std;


int main()
{
    int n;

    cin>>n;

    while(n>0)
    {
        string str;
        int x=1111,i,arr[111]={0};

        cin>>str;

        for(i=0;i<str.size();i++)
        {
            arr[str[i]-48]++;
        }

        for(i=0;i<10;i++)
        {
            if(arr[i]!=0)
            {
                x=min(x,arr[i]);
            }
        }

        cout<<str.size()-x<<endl;
        n--;

    }
}
