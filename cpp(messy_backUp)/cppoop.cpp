#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i = j; i <= k; i++)

class jog
{
    int dude, duh;
    public:
    virtual void show() {cout << "it the first one" << endl;}
};

class jug : public jog
{
    public:
    void show() {cout << "it the second one" << endl;}
};

class dug : public jog
{
    public:
    void show() {cout << "it the 9 one" << endl;}
};

int main()
{
    ios::sync_with_stdio(false);

    jog *ob1 = new jog();
    jug j;

    ob1 = &j;
    ob1->show();
    return 0;
}
