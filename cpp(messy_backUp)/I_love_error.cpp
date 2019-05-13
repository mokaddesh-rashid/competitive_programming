#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int lowest,highest,x=0,i,a;

    cin>>highest;

    lowest=highest;

    for(i=1;i<n;i++)
    {
        cin>>a;

        if(a>highest)
        {
            x++;
            highest=a;
        }

        else if(a<lowest)
        {
            x++;
            lowest=a;
        }
    }

    cout<<x;
}
