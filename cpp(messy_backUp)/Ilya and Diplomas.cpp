#include<iostream>

using namespace std;

int main()
{
    long long int target,min_1,min_2,min_3,max_1,max_2,max_3;

    cin>>target;

    cin>>min_1>>max_1>>min_2>>max_2>>min_3>>max_3;

    long long int a,b,c,i,x;

    a=min_1;
    b=min_2;
    c=min_3;


    while(x!=target)
    {
         x=a+b+c;
        if(a<max_1&&x!=target)
            a++;
        else if(b<max_2&&x!=target)
            b++;
        else if(c<max_3&&x!=target)
            c++;


    }

    cout<<a<<' '<<b<<' '<<c;




}
