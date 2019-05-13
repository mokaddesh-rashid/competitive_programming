
#include<iostream>

using namespace std;

void view(char *nm,char ar[]={"fuck"},int a=0)
{
    cout<<nm<<ar<<a<<endl;
}

int main()
{
    int a,b,c;
    char nm[111],ar[111];
    cin>>nm>>ar>>a;
    view(nm);
    view(nm,ar,a);


}

