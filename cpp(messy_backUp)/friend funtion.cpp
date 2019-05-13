
#include<iostream>

using namespace std;
int area(int,int);

class hmm
{
    int i,n,a,b,c;
public:
    int square(int x)
    {
        return x*x;
    }
    friend int area(int,int);
};

int main()
{
    int a,b,c;
    cin>>a>>b;
    c=area(a,b);
    cout<<c;
    return 0;

}

int area(int a,int b)
{
    int c;
    hmm o;
     c=o.square(a*b);
     return c;
}
