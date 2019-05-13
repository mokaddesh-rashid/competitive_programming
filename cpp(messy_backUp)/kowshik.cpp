#include<iostream>


using namespace std;

int main()
{
    double a, b;

    char ch;

    cin >> ch;

    cin >> a >> b;

    if( ch == 'a' )
        cout << a+b;
    else if( ch == 's' )
        cout << a-b;
    else if( ch == 'd' )
        cout << a/b;
    else
        cout << a*b;
}
