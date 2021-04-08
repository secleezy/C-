#include <iostream>
#include <iomanip>

using namespace std;

//subject(���� ����ü)
typedef struct subject
{
    char SubName[30]; // �����̸�
    int Hakjum; // ��������
    char Grade[10]; // ������
    float GPA; // ���� ����
}Subject;  //<- �� �̸����� ����ü �ʱ�ȭ

//student(�л� ����ü)
typedef struct student
{
    char StdName[30]; // �л� �̸�
    int Hakbun; // �й�
    Subject Sub[3]; // ����
    float AveGPA; // ������ ��� ����
}Student; //<- �� �̸����� ����ü �ʱ�ȭ

//�޴� �Լ�
void PrintMenu()
{
    cout << "\n===== �޴�=====\n";
    cout << "1. �л� ���� �Է�\n";
    cout << "2. ��ü �л� ���� ����\n";
    cout << "3. �л� �̸� �˻�\n";
    cout << "4. ���α׷� ����\n\n";
    cout << "���ϴ� ����� �Է��ϼ���: ";
}

//�������� ���� ���
void CalcGPA(Subject& Sub) //Sub���� �ʱ�ȭ
{
    cout << "������� : ";
    cin >> Sub.SubName;
    cout << "���������� : ";
    cin >> Sub.Hakjum;
    cout << "������<A+ ~ F> : ";
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
    else if (strcmp(Sub.Grade, "F") == 0)
        Sub.GPA = Sub.Hakjum * 0;

	cout << "\n\n";
}

//��ü �л� �Ż�/���� ���� ���
void PrintAllData(Student* stu) // stu�� �ʱ�ȭ
{
    cout << "�̸� : " << stu->StdName << "   �й� : " << stu->Hakbun; // ������ ����ü�� ������ ���ٽ� -> ���
    cout << "\n====================================================\n";
    cout << "          �����   ��������   ������   ��������\n";
    cout << "====================================================\n";
    for (int j = 0; j < 3; j++)
    {
        cout.width(14); //����� ������ �� ����, ���� �ٿ��� ����
        cout << stu->Sub[j].SubName;
        cout.width(10); //����� ������ �� ����, ���� �ٿ��� ����
        cout << stu->Sub[j].Grade;
        cout.width(10); //����� ������ �� ����, ���� �ٿ��� ����
        cout << stu->Sub[j].Hakjum;
        cout.width(10); //����� ������ �� ����, ���� �ٿ��� ����
        cout << stu->Sub[j].GPA;
        cout << "\n====================================================\n";
    }
    //���� �л��� ��� ���� ���
    stu->AveGPA = (stu->Sub[0].GPA + stu->Sub[1].GPA + stu->Sub[2].GPA) / 3;
    cout << "                             �������     " << stu->AveGPA;
    cout << "\n\n";
}

//���� �л� �Ż�/���� ���� ���
void PrintOneData(char* name, student* pSt)
{
    if (strcmp(name, pSt->StdName) == 0)
        PrintAllData(pSt);
}

int main(void)
{
    int sw = 1;
    int select;
    char name[10];
    Student stu[2];

    cout.flags(ios::right);
    cout.fill('  ');
    cout.precision(2); // �Ҽ��� ���� 2�ڸ��� ����ϵ��� ����, on off ����
    cout << fixed;

    while (sw)
    {
        PrintMenu();
        cin >> select;

        switch (select)
        {
        // 1. �л� ���� �Է� �ޱ�
        case 1:
            for (int i = 0; i < 2; i++) {
                cout << "\n* " << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���.\n";
                cout << "�̸� : ";
                cin >> stu[i].StdName;
                cout << "�й� : ";
                cin >> stu[i].Hakbun;

                cout << "\n\n\n* ������ ����3���� �� �������, ��������, �������� �Է��ϼ���.\n";

                for (int j = 0; j < 3; j++)
                    CalcGPA(stu[i].Sub[j]);

                cout << "\n\n";
            }
            break;
        // 2. ��ü �л� ���� ����
        case 2:
            cout << "\n             ��ü �л� ���� ����               ";
            cout << "\n====================================================\n";

            for (int i = 0; i < 2; i++)
                PrintAllData(&stu[i]);

            break;

        // 3. ���� �л� ���� ����
        case 3:

            cout << "\n\n\n�˻� �� �л� �̸� : ";
            cin >> name;
            for (int i = 0; i < 2; i++)
            {
                PrintOneData(name, &stu[i]);
            }


            break;

        default:
            sw = 0;
            cout << "���α׷��� �����մϴ�.\n";
            break;

        }
    }
}