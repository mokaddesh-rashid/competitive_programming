#include<iostream>
#include<cstring>

using namespace std;

class account
{
    int balance,acnt_id;

    char name[123],account_type[111];

public:

//    friend cheque(current &);
    void setdata()
    {
        cout<<"type name!!\n";
        cin>>name;
        cout<<"id for account \n";
        cin>>acnt_id;
        cout<<"account type\n";
        cin>>account_type;
        balance=0;
    }
    void add()
    {
       int x;

       cout<<"\namount to add for "<<name<<" "<<account_type<<" accout\n";
       cin>>x;
       this->balance+=x;
       if(strcmp("saving",account_type)==0)
           balance=balance+balance*.1;
       display();
    }
    void widraw()
    {
        if(this->balance<500&&this->account_type=="current")
           {
                this->balance*=.1;
                cout<<"balance is below 500"<<endl;
           }
       int x;
       cout<<"\namount to widraw for "<<name<<" "<<account_type<<" accout\n";
       cin>>x;
       if(x>balance)
        cout<<"not enough balance\n";
       else
        this->balance-=x;

         display();
    }
    void display()
    {
        cout<<"Total balance of "<<this->name<<" id "<<this->acnt_id<<" "<<this->balance<<endl;
    }
};

class saving : public account
{
public:
    void setdata()
    {
        account::setdata();
    }
    void add()
    {
        account::add();
    }
    void widraw()
    {
        account::widraw();
    }
};

class current : public account
{
public:
    void cheque()
{
    char ch;

    cout<<"use cheque for !!!!! : ";
    cin>>ch;
    cout<<endl;
    if(ch=='a')
    {
      account::add();
    }
    else if(ch=='w')
    {

          account::widraw();

    }
}
};





int main()
{
    saving ob;
    current o;

    o.setdata();
    ob.setdata();
    ob.add();
    ob.widraw();
    ob.widraw();

    o.cheque();
    o.cheque();
    o.cheque();

}




