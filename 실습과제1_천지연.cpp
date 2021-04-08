#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Subject {// 과목정보
	char SubName[30]; // 과목이름
	int Hakjum; // 과목학점
	char Grade[10]; // 과목등급
	float GPA; // 과목평점
}SubJect

typedef struct Student {// 학생정보
	char StdName[30]; // 학생이름
	int Hakbun; // 학번
	Subject Sub[3]; // 과목
	float AveGPA; // 교과목평균평점
}Student

void PrintMenu(void)
{
	cout << "\n===== 메뉴=====\n"
		cout << "1. 학생 성적 입력\n"
		cout << "2. 전체 학생 성적 보기\n"
		cout << "3. 프로그램 종료\n\n"
		cout << "원하는 기능을 입력하세요: "
}

void CalcGPA(SubJect& Sub)
{
	cout << "교과목명: "
		cin >> Sub.SubName;
	cout << "과목학 점수: "
		cin >> Sub.Hakjum;
	cout << "과목등급(A+ ~ F) : "
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
	cout.precision(2); // 소수점이하2자리만출력하도록고정, on off 형식
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
				cout << "\n* " << i + 1 << " 번째학생이름과학번을입력하세요.\n"
					cout << "이름: "
					cin >> stu[i].StdName;
				cout << "학번: "
					cin >> stu[i].Hakbun;
				cout << "\n\n\n* 수강한과목3개와각교과목명, 과목학점, 과목등급을입력하세요.\n"


					for (int j = 0; j < 3; j++) {

						CalcGPA(stu[i].sub[j]);


						cout << "\n\n"
					}
				cout << "\n\n"
			}
			break

		case 2:
			cout << "\n             전체학생성적보기              "
				cout << "\n====================================================\n"

				for (int i = 0; i < 2; i++)
				{
					cout << "이름: " << stu[i].StdName << "   학번: " << stu[i].Hakbun;
					cout << "\n====================================================\n"
						cout << "          과목명  과목학점  과목등급  과목평점\n"
						cout << "====================================================\n"
						for (int j = 0; j < 3; j++) {
							cout.width(14); //출력할내용의폭지정, 다음줄에만적용
							cout << sub[i][j].SubName;
							cout.width(10); //출력할내용의폭지정, 다음줄에만적용
							cout << sub[i][j].Grade;
							cout.width(10); //출력할내용의폭지정, 다음줄에만적용
							cout << sub[i][j].Hakjum;
							cout.width(10); //출력할내용의폭지정, 다음줄에만적용
							cout << sub[i][j].GPA;
							cout << "\n====================================================\n"
						}
					cout << "                             평균평점    " << stu[i].AveGPA;
					cout << "\n\n"
				}
			break

		default:
			sw = 0;
			cout << "프로그램을종료합니다.\n"
				break
		}
	}
}