#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    char str[1111111];

    cin>>str;

    if(str[0]>=97)
        str[0]-=32;

    cout<<str;
}
