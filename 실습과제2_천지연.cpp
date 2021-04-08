#include <iostream>
#include <iomanip>

using namespace std;

//subject(과목 구조체)
typedef struct subject
{
    char SubName[30]; // 과목이름
    int Hakjum; // 과목학점
    char Grade[10]; // 과목등급
    float GPA; // 과목 평점
}Subject;  //<- 이 이름으로 구조체 초기화

//student(학생 구조체)
typedef struct student
{
    char StdName[30]; // 학생 이름
    int Hakbun; // 학번
    Subject Sub[3]; // 과목
    float AveGPA; // 교과목 평균 평점
}Student; //<- 이 이름으로 구조체 초기화

//메뉴 함수
void PrintMenu()
{
    cout << "\n===== 메뉴=====\n";
    cout << "1. 학생 성적 입력\n";
    cout << "2. 전체 학생 성적 보기\n";
    cout << "3. 학생 이름 검색\n";
    cout << "4. 프로그램 종료\n\n";
    cout << "원하는 기능을 입력하세요: ";
}

//교과목의 평점 계산
void CalcGPA(Subject& Sub) //Sub으로 초기화
{
    cout << "교과목명 : ";
    cin >> Sub.SubName;
    cout << "과목학점수 : ";
    cin >> Sub.Hakjum;
    cout << "과목등급<A+ ~ F> : ";
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

//전체 학생 신상/성적 정보 출력
void PrintAllData(Student* stu) // stu로 초기화
{
    cout << "이름 : " << stu->StdName << "   학번 : " << stu->Hakbun; // 포인터 구조체의 변수에 접근시 -> 사용
    cout << "\n====================================================\n";
    cout << "          과목명   과목학점   과목등급   과목평점\n";
    cout << "====================================================\n";
    for (int j = 0; j < 3; j++)
    {
        cout.width(14); //출력할 내용의 폭 지정, 다음 줄에만 적용
        cout << stu->Sub[j].SubName;
        cout.width(10); //출력할 내용의 폭 지정, 다음 줄에만 적용
        cout << stu->Sub[j].Grade;
        cout.width(10); //출력할 내용의 폭 지정, 다음 줄에만 적용
        cout << stu->Sub[j].Hakjum;
        cout.width(10); //출력할 내용의 폭 지정, 다음 줄에만 적용
        cout << stu->Sub[j].GPA;
        cout << "\n====================================================\n";
    }
    //개인 학생의 평균 평점 계산
    stu->AveGPA = (stu->Sub[0].GPA + stu->Sub[1].GPA + stu->Sub[2].GPA) / 3;
    cout << "                             평균평점     " << stu->AveGPA;
    cout << "\n\n";
}

//개인 학생 신상/성적 정보 출력
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
    cout.precision(2); // 소수점 이하 2자리만 출력하도록 고정, on off 형식
    cout << fixed;

    while (sw)
    {
        PrintMenu();
        cin >> select;

        switch (select)
        {
        // 1. 학생 성적 입력 받기
        case 1:
            for (int i = 0; i < 2; i++) {
                cout << "\n* " << i + 1 << " 번째 학생 이름과 학번을 입력하세요.\n";
                cout << "이름 : ";
                cin >> stu[i].StdName;
                cout << "학번 : ";
                cin >> stu[i].Hakbun;

                cout << "\n\n\n* 수강한 과목3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

                for (int j = 0; j < 3; j++)
                    CalcGPA(stu[i].Sub[j]);

                cout << "\n\n";
            }
            break;
        // 2. 전체 학생 성적 보기
        case 2:
            cout << "\n             전체 학생 성적 보기               ";
            cout << "\n====================================================\n";

            for (int i = 0; i < 2; i++)
                PrintAllData(&stu[i]);

            break;

        // 3. 개인 학생 성적 보기
        case 3:

            cout << "\n\n\n검색 할 학생 이름 : ";
            cin >> name;
            for (int i = 0; i < 2; i++)
            {
                PrintOneData(name, &stu[i]);
            }


            break;

        default:
            sw = 0;
            cout << "프로그램을 종료합니다.\n";
            break;

        }
    }
}