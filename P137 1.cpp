#include <iostream>
#include <cmath>
using namespace std;

void prime(int a)
{
	int i;
	for (i = 2; i <= int(sqrt(a)); ++i){
		if (a % i == 0) break;
	}
	if (i == int(sqrt(a)) + 1) cout << endl << a << "������";
	else cout << endl << a << "��������"; 
}

int main()
{
	int a;
	cout << "������һ������: ";
	cin >> a;
	if (a == 1) cout << endl << a << "��������"; 
	else prime(a);
	return 0;
}
