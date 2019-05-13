#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    cin>>n;

    string Vaporeon="vaporeon", Jolteon="jolteon", Flareon="flareon", Espeon="espeon", Umbreon="umbreon", Leafeon="leafeon", Glaceon="glaceon", Sylveon="sylveon",str;

    cin>>str;

    int stakk[11],top=0,i,a=1,b,c,x;

    for(i=0;i<str.size();i++)
    {
        if(str[i]!='.')
        {
            stakk[top]=i;
            top++;
        }
    }



    if(str.size()==Vaporeon.size())
    {
        a=0;
         for(x=0;x<top;x++)
        {
            if(str[stakk[x]]!=Vaporeon[stakk[x]])
                a=1;
        }
        if(a==0)
            cout<<Vaporeon;
    }
     if(str.size()==Jolteon.size()&&a==1)
    {
        a=0;
         for(x=0;x<top;x++)
        {
            if(str[stakk[x]]!=Jolteon[stakk[x]])
                a=1;
        }
        if(a==0)
            cout<<Jolteon;
    }
     if(str.size()==Flareon.size()&&a==1)
    {
        a=0;
         for(x=0;x<top;x++)
        {
            if(str[stakk[x]]!=Flareon[stakk[x]])
                a=1;
        }
        if(a==0)
            cout<<Flareon;
    }
      if(str.size()==Espeon.size()&&a==1)
    {
        a=0;
         for(x=0;x<top;x++)
        {
            if(str[stakk[x]]!=Espeon[stakk[x]])
                a=1;
        }
        if(a==0)
            cout<<Espeon;
    }
      if(str.size()==Umbreon.size()&&a==1)
    {
        a=0;
         for(x=0;x<top;x++)
        {
            if(str[stakk[x]]!=Umbreon[stakk[x]])
                a=1;
        }
        if(a==0)
            cout<<Umbreon;
    }
      if(str.size()==Umbreon.size()&&a==1)
    {
        a=0;
         for(x=0;x<top;x++)
        {
            if(str[stakk[x]]!=Umbreon[stakk[x]])
                a=1;
        }
        if(a==0)
            cout<<Umbreon;
    }

      if(str.size()==Leafeon.size()&&a==1)
    {

        a=0;
         for(x=0;x<top;x++)
        {
            if(str[stakk[x]]!=Leafeon[stakk[x]])
                a=1;
        }
        if(a==0)
            cout<<Leafeon;
    }

     if(str.size()== Glaceon.size()&&a==1)
    {
        a=0;
         for(x=0;x<top;x++)
        {
            if(str[stakk[x]]!= Glaceon[stakk[x]])
                a=1;
        }
        if(a==0)
            cout<< Glaceon;
    }

      if(str.size()==  Sylveon.size()&&a==1)
    {
        a=0;
         for(x=0;x<top;x++)
        {
            if(str[stakk[x]]!=  Sylveon[stakk[x]])
                a=1;
        }
        if(a==0)
            cout<<  Sylveon;
    }




}
