#include<iostream>

using namespace std;
void chng();

namespace var
{
    int i=0,n,a[11],b;
}

int main()
{
    using namespace var;
    cout<<i<<endl;
    i=9;
    for(i=0;i<3;i++)
        cin>>a[i];
    chng();
    return 0;

}

void chng()
{
     using namespace var;
     for(i=0;i<3;i++)
        cout<<a[i];
}

