#include <iostream>
#include <iomanip>

using namespace std;

template<typename T, size_t n>
void Sort(T(&arr)[n], int count)
{
	T temp;

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main(){

	int select;
	int sw = 1;
	int num[5];
	double num2[5];

	while (sw)
	{
		cout << "1. 정수 정렬\n";
		cout << "2. 실수 정렬\n";
		cout << "3. 종료\n";
		cout << "메뉴 선택 : ";
		cin >> select;

		switch (select)
		{
		case 1:
			cout << "5개의 정수를 입력하세요 : ";
			for (int i = 0; i < 5; i++)
				cin >> num[i];
			Sort(num, 5);
			cout << "정렬 결과 : ";
			for (int i = 0; i < 5; i++)
				cout << num[i] << " ";
			cout << "\n\n";
			break;

		case 2:
			cout << "5개의 실수를 입력하세요 : ";
			for (int i = 0; i < 5; i++)
				cin >> num2[i];
			Sort(num2, 5);
			cout << "정렬 결과 : ";
			for (int i = 0; i < 5; i++)
				cout << num2[i] << " ";
			cout << "\n\n";
			break;

		case 3:
			sw = 0;
			break;

		default:
			cout << "ERROR : 잘못된 메뉴 선택입니다.\n\n";
			break;
		}
	}

}