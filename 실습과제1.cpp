#include <iostream>
#include <string>
using namespace std;

int main()
{
	string myName;
	cout << "(cout)이름을 입력세요." << endl << "(cin)";
	cin >> myName;
	cout << "당신의 이름은 " << myName << " 입니다." << endl;

	return 0;
}