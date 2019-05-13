#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;

int main()  {
	int ara[5] = { 1, 3, 4, 5, 7 };
	int *it = lower_bound(ara, ara + 5, 3);
	int index = it - ara;
	cout << index << "\n";
	return 0;
}
