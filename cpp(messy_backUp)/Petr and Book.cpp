#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int daily_page[8],day=0;

    for(int i=0;i<7;i++)
        cin>>daily_page[i];

    while(n>0)
    {
        n=n-daily_page[day%7];
        if(n>0)
           day++;

    }

    cout<<day%7+1;
}
