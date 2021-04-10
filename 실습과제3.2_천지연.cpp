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
inline void PrintMenu()
{
    cout << "\n===== �޴�=====\n";
    cout << "1. �л� ���� �Է�\n";
    cout << "2. ��ü �л� ���� ����\n";
    cout << "3. �л� �̸� �˻�\n";
    cout << "4. ��ü �л� ��� ����\n";
    cout << "5. �л� ���� ����\n";
    cout << "6. ���α׷� ����\n\n";
    cout << "���ϴ� ����� �Է��ϼ���: ";
}

// �̸�, �����, ���� ���
inline void InputValue(char* str)
{
    cin >> str;
}

// �޴���ȣ, ��ü�л� ��, ���� 
inline void InputValue(int& i)
{
    cin >> i;
}

//1. �������� ���� ���
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

//1. ������ ��� ���� ���
float CalcAveGPA(Subject* Sub) {
    float AveGPA;
    AveGPA = (Sub[0].GPA + Sub[1].GPA + Sub[2].GPA) / 3;

    return AveGPA;
}

//2. 
void PrintOneData(const Student& rSt)
{
    cout << "�̸� : " << rSt.StdName << "   �й� : " << rSt.Hakbun; // ������ ����ü�� ������ ���ٽ� -> ���
    cout << "\n====================================================\n";
    cout << "          �����   ��������   ������   ��������\n";
    cout << "====================================================\n";
    for (int j = 0; j < 3; j++)
    {
        cout.width(14); //����� ������ �� ����, ���� �ٿ��� ����
        cout << rSt.Sub[j].SubName;
        cout.width(10); //����� ������ �� ����, ���� �ٿ��� ����
        cout << rSt.Sub[j].Grade;
        cout.width(10); //����� ������ �� ����, ���� �ٿ��� ����
        cout << rSt.Sub[j].Hakjum;
        cout.width(10); //����� ������ �� ����, ���� �ٿ��� ����
        cout << rSt.Sub[j].GPA;
        cout << "\n====================================================\n";
    }
    cout << "                             �������     " << rSt.AveGPA;
    cout << "\n\n";
}
// rSt : �л������� ��� Student ���۷��� ����
void PrintAllData(const Student* pSt, int StudentNum)
{
    for (int i = 0; i < StudentNum; i++)
        PrintOneData(pSt[i]);
}

//3. �̸� �˻�
Student* StdSearch(Student* pSt, int StudentNum)
{
    cout << "\n\n\n�˻� �� �л� �̸� : ";
    char StdName[10];
    InputValue(StdName);
    for (int i = 0; i < StudentNum; i++)
    {
        if (strcmp(StdName, pSt[i].StdName) == 0)
            return &pSt[i];
    }
}

//4. ��ü �л� ��� ���
void PrintAllStdList(const Student* pSt, int StudentNum = 2)
{

    cout << "\n             ��ü �л� ��� ����               ";
    cout << "\n=====================================\n";
    cout << "          �̸�       �й�\n";
    cout << "=====================================\n";
    for (int i = 0; i < StudentNum; i++)
    {
        cout.width(14); //����� ������ �� ����, ���� �ٿ��� ����
        cout << pSt[i].StdName;
        cout.width(10); //����� ������ �� ����, ���� �ٿ��� ����
        cout << pSt[i].Hakbun << "\n";
    }
    cout << "=====================================\n";

}

//5. �л� ���� ����
void Modify(Student* pSt)
{
    cout << "* (" << pSt->StdName << ", " << pSt->Hakbun << ")�� ������ �����ϼ���\n";
    cout << "�̸� : ";
    InputValue(pSt->StdName);
    cout << "�й� : ";
    InputValue(pSt->Hakbun);
}


int main(void)
{
    int sw = 1;
    int select;
    char name[10];
    int StdNum = 2; // �л� ��
    Student* stu = new Student[StdNum];
    Student* SearchStd;
    float AveGPA;

    cout.flags(ios::right);
    cout.fill('  ');
    cout.precision(2); // �Ҽ��� ���� 2�ڸ��� ����ϵ��� ����, on off ����
    cout << fixed;

    while (sw)
    {
        PrintMenu();
        InputValue(select);

        switch (select)
        {
            // 1. �л� ���� �Է� �ޱ�
        case 1:
            for (int i = 0; i < StdNum; i++) {
                cout << "\n* " << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���.\n";
                cout << "�̸� : ";
                InputValue(stu[i].StdName); // �л� �� �Է�
                cout << "�й� : ";
                InputValue(stu[i].Hakbun); // �й� �Է�

                cout << "\n\n\n* ������ ����3���� �� �������, ��������, �������� �Է��ϼ���.\n";

                for (int j = 0; j < 3; j++)
                    CalcGPA(stu[i].Sub[j]);

                AveGPA = CalcAveGPA(stu[i].Sub);
                stu[i].AveGPA = AveGPA;
                cout << "\n\n";
            }
            break;

            // 2. ��ü �л� ���� ����
        case 2:
            cout << "\n             ��ü �л� ���� ����               ";
            cout << "\n====================================================\n";
            PrintAllData(stu, StdNum);
            break;

            // 3. ���� �л� ���� ����
        case 3:
            SearchStd = StdSearch(stu, StdNum);

            if (SearchStd != NULL)
                PrintOneData(*SearchStd);
            break;

            //4. ��ü �л� ��� ���
        case 4:
            PrintAllStdList(stu, StdNum);
            break;

            //5. �л� ���� ����
        case 5:
            SearchStd = StdSearch(stu, StdNum);
            if (SearchStd != NULL)
                Modify(SearchStd);
            break;

        default:
            sw = 0;
            cout << "���α׷��� �����մϴ�.\n";
            break;
        }
    }
}