#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    cout<<"PERFECTION OUTPUT\n";

    int a;


    while(cin>>a)
    {
        long long int i,x=0,b,c;

        if(a==0)
        {
              cout<<"END OF FILE";
              break;
        }


        for(i=1;i<=a/2;i++)
        {
            if(a%i==0)
                x+=i;
        }

        stringstream ss;
        string pass;

        int z = a;

        ss << z;

        ss >> pass;

        for(int i=0;i<6-pass.size();i++)
                cout<<' ';
         if(a<0)
            cout<<a<<' '<<' '<<"ABUNDANT\n";
        else if(x==a)
            cout<<a<<' '<<' '<<"PERFECT\n";
        else if(x<a)
            cout<<a<<' '<<' '<<"DEFICIENT\n";
        else if(x>a)
            cout<<a<<' '<<' '<<"ABUNDANT\n";
    }


}
