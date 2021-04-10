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
		cout << "1. ���� ����\n";
		cout << "2. �Ǽ� ����\n";
		cout << "3. ����\n";
		cout << "�޴� ���� : ";
		cin >> select;

		switch (select)
		{
		case 1:
			cout << "5���� ������ �Է��ϼ��� : ";
			for (int i = 0; i < 5; i++)
				cin >> num[i];
			Sort(num, 5);
			cout << "���� ��� : ";
			for (int i = 0; i < 5; i++)
				cout << num[i] << " ";
			cout << "\n\n";
			break;

		case 2:
			cout << "5���� �Ǽ��� �Է��ϼ��� : ";
			for (int i = 0; i < 5; i++)
				cin >> num2[i];
			Sort(num2, 5);
			cout << "���� ��� : ";
			for (int i = 0; i < 5; i++)
				cout << num2[i] << " ";
			cout << "\n\n";
			break;

		case 3:
			sw = 0;
			break;

		default:
			cout << "ERROR : �߸��� �޴� �����Դϴ�.\n\n";
			break;
		}
	}

}