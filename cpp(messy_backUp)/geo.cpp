#include<iostream>

using namespace std;

int main()
{
    int t,a,i;

    cin>>t;

    for(i=0;i<t;i++)
    {
        cin>>a;

        if(a==60||a==90||a==108||a==120||a==135||a==156||a==135||a==140||a==144||a==150||a==160||a==162||a==168||a==171||a==174||a==176)
            cout<<"YES"<<endl;

        else
            cout<<"NO"<<endl;
    }
}
