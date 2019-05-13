#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str,st;

    cin>>str;

    st.assign(str,2,4);

    cout<<st;
}

