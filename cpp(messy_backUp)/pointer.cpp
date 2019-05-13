#include<iostream>

using namespace std;

class B
{
	int b;
public:
	B(int b=0):b(b){}
	virtual void show()
	{
		cout <<"b = " <<b<<endl;
	}
};

class D : public B
{
	int d;
public:
	D(int d=0):d(d){}
	void show()
	{
		//B::show();
		cout << "d = "<<d<<endl;
	}
};

int main()
{
  B *pb;
  B bb(5);

  pb = & bb;
  pb->show();

  D dd(10);
  pb = &dd;
  pb->show();

  D *pd;
  pd = &dd;
  pd->show();

  ((D *)pb)->show();

  return 0;
}
