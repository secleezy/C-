#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Subject {// ��������
	char SubName[30]; // �����̸�
	int Hakjum; // ��������
	char Grade[10]; // ������
	float GPA; // ��������
}SubJect

typedef struct Student {// �л�����
	char StdName[30]; // �л��̸�
	int Hakbun; // �й�
	Subject Sub[3]; // ����
	float AveGPA; // �������������
}Student

void PrintMenu(void)
{
	cout << "\n===== �޴�=====\n"
		cout << "1. �л� ���� �Է�\n"
		cout << "2. ��ü �л� ���� ����\n"
		cout << "3. ���α׷� ����\n\n"
		cout << "���ϴ� ����� �Է��ϼ���: "
}

void CalcGPA(SubJect& Sub)
{
	cout << "�������: "
		cin >> Sub.SubName;
	cout << "������ ����: "
		cin >> Sub.Hakjum;
	cout << "������(A+ ~ F) : "
		cin >> Sub.Grade;

	if (strcmp(Sub.Grade, "A+") == 0)
		Sub.GPA = Sub.Hakjum * 4.5;
	else if (strstr(Sub.Grade, "A") != NULL)
		Sub.GPA = Sub.Hakjum * 4;
	else if (strcmp(Sub.Grade, "B+") == 0)
		Sub.GPA = Sub.Hakjum * 3.5;
	else if (strstr(Sub.Grade, "B") != NULL)
		Sub.GPA = Sub.Hakjum * 3;
	else if (strcmp(Sub.Grade, "C+") == 0)
		Sub.GPA = Sub.Hakjum * 2.5;
	else if (strstr(Sub.Grade, "C") != NULL)
		Sub.GPA = Sub.Hakjum * 2;
	else if (strcmp(Sub.Grade, "D+") == 0)
		Sub.GPA = Sub.Hakjum * 1.5;
	else if (strstr(Sub.Grade, "D") != NULL)
		Sub.GPA = Sub.Hakjum * 1;
	else if (strstr(Sub.Grade, "F") != NULL)
		Sub.GPA = Sub.Hakjum * 0;

}

int main(void) {

	int select;
	int num;
	int sw;




	cout.flags(ios::right);
	cout.fill('  ');
	cout.precision(2); // �Ҽ�������2�ڸ�������ϵ��ϰ���, on off ����
	cout << fixed;

	Student stu[2];
	Subject sub[2][3];
	sw = 1;


	while (sw)
	{
		PrintMenu();
		cin >> select;

		switch (select)
		{

		case 1:
			for (int i = 0; i < 2; i++) {
				cout << "\n* " << i + 1 << " ��°�л��̸����й����Է��ϼ���.\n"
					cout << "�̸�: "
					cin >> stu[i].StdName;
				cout << "�й�: "
					cin >> stu[i].Hakbun;
				cout << "\n\n\n* �����Ѱ���3���Ͱ��������, ��������, ���������Է��ϼ���.\n"


					for (int j = 0; j < 3; j++) {

						CalcGPA(stu[i].sub[j]);


						cout << "\n\n"
					}
				cout << "\n\n"
			}
			break

		case 2:
			cout << "\n             ��ü�л���������              "
				cout << "\n====================================================\n"

				for (int i = 0; i < 2; i++)
				{
					cout << "�̸�: " << stu[i].StdName << "   �й�: " << stu[i].Hakbun;
					cout << "\n====================================================\n"
						cout << "          �����  ��������  ������  ��������\n"
						cout << "====================================================\n"
						for (int j = 0; j < 3; j++) {
							cout.width(14); //����ҳ�����������, �����ٿ�������
							cout << sub[i][j].SubName;
							cout.width(10); //����ҳ�����������, �����ٿ�������
							cout << sub[i][j].Grade;
							cout.width(10); //����ҳ�����������, �����ٿ�������
							cout << sub[i][j].Hakjum;
							cout.width(10); //����ҳ�����������, �����ٿ�������
							cout << sub[i][j].GPA;
							cout << "\n====================================================\n"
						}
					cout << "                             �������    " << stu[i].AveGPA;
					cout << "\n\n"
				}
			break

		default:
			sw = 0;
			cout << "���α׷��������մϴ�.\n"
				break
		}
	}
}