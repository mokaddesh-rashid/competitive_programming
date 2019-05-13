#include<iostream>
#include<string>

using namespace std;


int main()
{
    string str;

    cin>>str;

    int x=0,i,a=0,b=str.size()-1,c,y;

    while(a<b)
    {
        if(str[a]!=str[b])
            x++;
            a++;
            b--;

    }

     a=str.size();

     if(x==0&&a%2==0)
    {
        b=0;
        while(b<a/2)
        {
            cout<<str[b];
            b++;
        }
        b--;
        cout<<'a';
        while(b>=0)
        {
            cout<<str[b];
            b--;
        }
    }
    else if(x==0&&a%2==1)
    {
        b=0;
        while(b<a/2)
        {
            cout<<str[b];
            b++;
        }
        cout<<str[b];

        while(b>=0)
        {
            cout<<str[b];
            b--;
        }
    }

    else if(str.size()==2)
    {
        cout<<str<<str[0];
    }

    else
    {

     c=0;

     a=0;
     b=str.size()-1;
     x=0;

       while(a<b)
    {
       // cout<<str[a]<<' '<<str[b]<<endl;
        if(str[a]!=str[b])
           {
                x++;
                y=a;
                b++;
           }
            a++;
            b--;

    }

    if(x==1)
       {
            c=1;
         a=str.size();
         b=0;
        while(b<a/2)
        {
            cout<<str[b];
            b++;
        }

        if(a%2)
           b++;
        while(b>=0)
        {
            cout<<str[b];
            b--;
        }
       }

     a=0;
     b=str.size()-1;
     x=0;

       while(a<b)
    {
       // cout<<str[a]<<' '<<str[b]<<endl;
        if(str[a]!=str[b])
           {
                x++;
                y=a;
                a--;
           }
            a++;
            b--;



    }

      if(x==1)
       {
          // cout<<"here\n";
         c=1;
         a=str.size();
         b=str.size()-1;
        while(b>a/2)
        {
            cout<<str[b];
            b--;
        }
        if(a%2==0)
           b-=2;
        else
            b--;
        while(b<a)
        {
            cout<<str[b];
            b++;
        }
       }


     else if(c==0)
        cout<<"NA";

    }

}


