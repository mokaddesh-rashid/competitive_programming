#include<iostream>
#include<string>


using namespace std;


int main()
{
    string a0="O-|-OOOO";
    string a1="O-|O-OOO";
    string a2="O-|OO-OO";
    string a3="O-|OOO-O";
    string a4="O-|OOOO-";
    string a5="-O|-OOOO";
    string a6="-O|O-OOO";
    string a7="-O|OO-OO";
    string a8="-O|OOO-O";
    string a9="-O|OOOO-";



    string str;

    cin>>str;

    long long int i;


    for(i=str.size()-1;i>=0;i--)
    {
        if(str[i]=='0')
            cout<<a0<<endl;
        else if(str[i]=='1')
            cout<<a1<<endl;
        else if(str[i]=='2')
            cout<<a2<<endl;
        else if(str[i]=='3')
            cout<<a3<<endl;
        else if(str[i]=='4')
            cout<<a4<<endl;
        else if(str[i]=='5')
            cout<<a5<<endl;
        else if(str[i]=='6')
            cout<<a6<<endl;
        else if(str[i]=='7')
            cout<<a7<<endl;
        else if(str[i]=='8')
            cout<<a8<<endl;
        else if(str[i]=='9')
            cout<<a9<<endl;
    }
}
