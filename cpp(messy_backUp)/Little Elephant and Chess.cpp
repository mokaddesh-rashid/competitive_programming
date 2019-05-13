#include<iostream>
#include<string>


using namespace std;

int main()
{
    string a_part="WBWBWBWB";
    string b_part="BWBWBWBW";

    int a=0,b=0,i;

    for(i=0;i<8;i++)
    {
        string str;

        cin>>str;

        if(str==a_part)
            a++;
        else if(str==b_part)
            b++;
    }

    if(a+b==8)
        cout<<"YES";
    else
        cout<<"NO";

}
