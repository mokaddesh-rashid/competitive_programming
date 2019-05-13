
#include<iostream>

using namespace std;

class hmm
{
    int x;

public:
    int a,b,c,i,n;
    hmm()
    {

        cin>>a;
        x=a/2;
    }
    friend void ooh(hmm *ob);


};

int main()
{
    hmm ob;
    hmm *pt;
    pt=&ob;
    ooh(&ob);
    //cout<<pt->a;
}

void ooh(hmm *ob)
{
    hmm o;
    cout<<ob->a;
    cout<<o.x;
}
