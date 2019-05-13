#include<iostream>

using namespace std;

class account
{
public:
    char name[11];
    int id,amount;

    void setdata()
    {
        cout<<"enter name and id\n";
        cin>>name>>id;

    }

    virtual void display()
    {

    }

};

class type : public account
{
public:
    void display()
    {
        cout<<"name "<<name<<endl;
        cout<<"id "<<id;

    }
};

int main()
{
    account *ob;

    type ob2,ob3;

    ob=&ob2;

    ob->setdata();

    ob->display();

}

