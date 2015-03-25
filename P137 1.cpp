#include <iostream>
#include <cmath>
using namespace std;

void prime(int a)
{
	int i;
	for (i = 2; i <= int(sqrt(a)); ++i){
		if (a % i == 0) break;
	}
	if (i == int(sqrt(a)) + 1) cout << endl << a << "是素数";
	else cout << endl << a << "不是素数"; 
}

int main()
{
	int a;
	cout << "请输入一个整数: ";
	cin >> a;
	if (a == 1) cout << endl << a << "不是素数"; 
	else prime(a);
	return 0;
}
