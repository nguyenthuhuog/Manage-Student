#include <iostream>
#include <conio.h>
#include <string>  //cho cac bien kieu string va cac ham lien quan nhu length, compare,getline
#include <iomanip> //thu vien dinh dang output va input,setw, lam tron
#include <vector>  //cho cac ham lien quan den vector
#include <fstream> //vi can cac ham lien quan den file
using namespace std;
ifstream FileInput("studentlist01.txt");
     ////////////////////////////////////////////////////////////////////////////////
     //*******   THAY DUONG DAN FILE STUDENT LIST CUA BAN VAO TRONG NGOAC  ********//
     ////////////////////////////////////////////////////////////////////////////////
ofstream FileOutput("GraduateManager.dat",ios::out | ios::binary);
class student {
protected:
	string fullname;
	string gender;
	string major;
	unsigned int studentid;
	bool program = 0;//credit(0);score(1)
	double subject[2][5] = { {0,0,0,0,0 }, {1,2,3,4,5,} };
	float sumscore = 0, avr;
	int n = 0, sumcredit = 0;
};

//xay dung menu ke thua tu lop student
class menu : public student {
public:
	void addfile();
	void add();
	void printstudent();
	void outputstudent();
	string getname();
	string getgender();
	string getmajor();
	unsigned int getstudentid();
	bool getprogram();
	double getsubject(double a, double b);
	void editinfo(int& info);
	int getsumcredit();
	int getavr();
};

vector <menu> list;
menu someone;

unsigned int j;
void re_name(string& str){ //sua loi viet hoa
    for(j=0;j<str.size();j++){
        if(j==0||str[j-1]==' '){
            if(str[j]<='z' && str[j]>='a'){
                str[j]+='A'-'a';}
        }else {
        if(str[j]<='Z' && str[j]>='A'){
                str[j]-='A'-'a';}
    }
}
}
void menu::addfile() {
	FileInput.ignore(100,'\n');
//	fflush(stdin);
	getline(FileInput, fullname, '\t');
	re_name(fullname);
//	fflush(stdin);
	getline(FileInput, gender, '\t');
	re_name(gender);
//	fflush(stdin);
	getline(FileInput, major, '\t');
	re_name(major);
//	fflush(stdin);
	FileInput >> studentid;
//	fflush(stdin);
	FileInput >> program;
	//reset lai vi khi add deu dung bien someone
	sumscore = 0; avr = 0;
	n = 0; sumcredit = 0;
	for (int i = 0; i < 5; i++) {
		fflush(stdin);
		FileInput >> subject[0][i];
		if (subject[0][i] != -1) { sumscore += subject[0][i];n++; }
		if (program == 1) {
			if (subject[0][i] > 4.0) sumcredit += subject[1][i];
		}
	}
	avr = sumscore / n;
}
void menu::add() {
	cout << "\n\tAdd your full name: ";
	fflush(stdin);
	getline(cin, fullname);
	re_name(fullname);
	fflush(stdin);
	cout << "\n\tYou are male or female:";
	getline(cin, gender);
	re_name(gender);
	fflush(stdin);	
	cout << "\n\tAdd your major:";
	getline(cin, major);
	re_name(major);
	fflush(stdin);
	cout << "\n\tAdd your student ID:";
	cin >> studentid;
	fflush(stdin);
	cout << "\n\tEnter your program (0 is score type, 1 is credit type): ";
	fflush(stdin);
	cin >> program;
	//reset lai vi khi add deu dung bien someone
	sumscore = 0; avr = 0;
	n = 0; sumcredit = 0;
	cout << boolalpha;
	for (int i = 0; i < 5; i++) {
		cout << "\n\tAdd your score of subject #" << i + 1 << " (if you dont study this please enter - 1) : ";
		fflush(stdin);
		cin >> subject[0][i];
		if (subject[0][i] != -1) { sumscore += subject[0][i];n++; }
		if (program == 1) {
			if (subject[0][i] > 4.0) sumcredit += subject[1][i];
		}
	}
	avr = sumscore / n;
}

//xay dung ham in
//ham setw(5) de tao khoang cach

void menu::printstudent() {
	cout << "\t" << fullname << setw(38 - fullname.length()) << gender;
	cout << "\t" << studentid << "\t" << major;
	cout << "\t" << setprecision(2) << avr; //lam tron
	cout << "\t\t" << sumcredit;
}
void menu::outputstudent() {
	FileOutput << "\n" << fullname << "\t" << gender;
	FileOutput << "\t" << studentid << "\t" << major <<"\t" <<program;
	FileOutput << "\t" << setprecision(2) << avr; //lam tron
	FileOutput << "\t" << sumcredit;
}
void menu::editinfo(int& info) {
	switch (info) {
	case 0:
		cout << "\n------------------------Press Enter to continue!------------------------";
		fflush(stdin);
		getchar();
		break;
	case 1:
		cout << "\n\tEnter new full name: ";
		fflush(stdin);
		getline(cin, fullname, '\n');
		cout << "\n------------------------Press Enter to continue!------------------------";
		fflush(stdin);
		getchar();
		break;
	case 2:
		cout << "\n\tEnter new gender: ";
		fflush(stdin);
		getline(cin, gender, '\n');
		cout << "\n------------------------Press Enter to continue!------------------------";
		fflush(stdin);
		getchar();
		break;
	case 3:
		cout << "\n\tEnter new major: ";
		fflush(stdin);
		getline(cin, major, '\n');
		cout << "\n------------------------Press Enter to continue!------------------------";
		fflush(stdin);
		getchar();
		break;
	case 4:
		cout << "\n\tEnter new student ID: ";
		fflush(stdin);
		cin >> studentid;
		cout << "\n------------------------Press Enter to continue!------------------------";
		fflush(stdin);
		getchar();
		break;
	case 5:
		sumscore = 0;
		n = 0;
		for (int i = 0; i < 5; i++) {
			cout << "\n\tAdd your score of subject #" << i + 1 << " (if you dont study this please enter - 1) : ";
			fflush(stdin);
			cin >> subject[0][i];
			if (subject[0][i] != -1) { sumscore += subject[0][i];n++; }
			if (program == 1) {
				if (subject[0][i] > 4.0) sumcredit += subject[1][i];
			}
		}
		avr = sumscore / n;
		cout << "\n------------------------Press Enter to continue!------------------------";
		fflush(stdin);
		getchar();
		break;
	default:
		cout << "\n------------------------Invalid function!------------------------";
		cout << "\n------------------------Press Enter to continue!------------------------";
		fflush(stdin);
		getchar();
		break;
	}
}
void printline120();
void printheader();
int main() {
	system("Color 70");
	if (!FileInput)cout << "\n------------------------Error in open input file------------------------";
	int function, statistic, info;unsigned int i = 0, testnum;
	string test;
	while (1) {
		system("cls");
		cout << "\n\n";
		printline120();
		cout << "\n 					Group 09 - Students Management System ";
		cout << "\n\n 		  /****************************/ MENU FUNCTIONS /*****************************/";
		cout << "\n 		  /   0.Exit                                                                  /";
		cout << "\n 		  /   1.Add all students from input file                                      /";
		cout << "\n 		  /   2.Add a student                                                         /";
		cout << "\n 		  /   3.Print all students                                                    /";
		cout << "\n 		  /   4.Find then edit or delete students' information                        /";
		cout << "\n 		  /   5.Statistic the list of student according to the studying program       /";
		cout << "\n 		  /   6.Statistic the list of student allowed to graduate this year and print /";
		cout << "\n 		  /***************************************************************************/";
		printline120();
		cout << "\n\t----------Enter the number corresponding with the function you want to use: ";
		fflush(stdin);
		cin >> function;
		cout << "\n";
		switch (function) {
		case 0:
			printline120();
			cout << "\n 					Group 09 - Students Management System ";
			cout << "\n\n 		  /****************************/ GROUP MEMBERS /*****************************/";
			cout << "\n 		  /                    1.Bui Hanh Trang   -   20210851                       /";
			cout << "\n 		  /                    2.Vu Minh Trung    -   20213591                       /";
			cout << "\n 		  /                    3.Nguyen Danh Huy  -   20213571                       /";
			cout << "\n 		  /                    4.Nguyen Thu Huong -   20210423                       /";
			cout << "\n 		  /**************************************************************************/";
			cout << "\n 		  /  -----------------------------* THANK YOU *----------------------------  /";
			printline120();
			cout << "\n\t\t\t   ------------------------Exiting------------------------" << endl;
			FileInput.close();
			FileOutput.close();
			return 0;
		case 1:
			info = 0;
			while (!FileInput.eof()) {
				someone.addfile();
				list.push_back(someone);
				info++;
			}
			cout << "\n\t-----------Had enter information of " << info << " students";
			cout << "\n------------------------Press Enter to continue!------------------------";
			fflush(stdin);
			getchar();
			break;
		case 2:
			someone.add();
			list.push_back(someone);
			cout << "\n------------------------Press Enter to continue!------------------------";
			fflush(stdin);
			getchar();
			break;
		case 3:
			printline120();
			printheader();
			for (i = 0; i < list.size(); i++) {
				cout << endl << "\t" << i + 1;
				list[i].printstudent();
			}
			printline120();
			cout << "\n 		Total students in the list is: " << list.size();
			cout << "\n------------------------Press Enter to continue!------------------------";
			fflush(stdin);
			getchar();
			break;
		case 4:
			printline120();
			cout << "\n\t1.Fullname";
			cout << "\n\t2.Gender";
			cout << "\n\t3.Major";
			cout << "\n\t4.Student ID";
			cout << "\n\t5.Subject";
			printline120();
			cout << "\n--------Enter the number corresponding with the information you find: ";
			fflush(stdin);
			cin >> info;
			switch (info) {
			case 1:
				cout << "\n\tEnter their fullname: "; fflush(stdin);getline(cin, test, '\n');
				printline120();
				printheader();
				info = 0;
				for (i = 0; i < list.size(); i++) {
					if (list[i].getname().find(test) >= list[i].getname().length())continue;else {
						cout << endl << "\t" << i + 1;
						list[i].printstudent();
						info++;
					}
				}
				if (info == 0)cout << "\n\t\t**************************No student found!**************************";
				printline120();
				break;
			case 2:
				cout << "\n\tEnter their gender (male,female,etc): "; fflush(stdin);getline(cin, test, '\n');
				printline120();
				printheader();
				info = 0;
				for (i = 0; i < list.size(); i++) {
					if (test.compare(list[i].getgender()) == 0) {
						cout << endl << "\t" << i + 1;
						list[i].printstudent();
						info++;
					}
				}
				if (info == 0)cout << "\n\t\t**************************No student found!**************************";
				printline120();
				break;
			case 3:
				cout << "\n\tEnter their major: "; fflush(stdin);getline(cin, test, '\n');
				printline120();
				printheader();
				info = 0;
				for (i = 0; i < list.size(); i++) {
					if (test.compare(list[i].getmajor()) == 0) {
						cout << endl << "\t" << i + 1;
						list[i].printstudent();
						info++;
					}
				}
				if (info == 0)cout << "\n\t\t**************************No student found!**************************";
				printline120();
				break;
			case 4:
				cout << "\n\tEnter the student ID: "; fflush(stdin);cin >> testnum;
				printline120();
				printheader();
				info = 0;
				for (i = 0; i < list.size(); i++) {
					if (testnum == list[i].getstudentid()) {
						cout << endl << "\t" << i + 1;
						list[i].printstudent();
						info++;
					}
				}
				if (info == 0)cout << "\n\t\t**************************No student found!**************************";
				printline120();
				break;
			case 5:
				cout << "\n\tEnter their number of subject: #"; fflush(stdin);cin >> testnum;
				printline120();
				printheader();
				info = 0;
				for (i = 0; i < list.size(); i++) {
					if (list[i].getsubject(0, testnum - 1) != -1) {
						cout << endl << "\t" << i + 1;
						list[i].printstudent();
						info++;
					}
				}
				if (info == 0)cout << "\n\t\t**************************No student found!**************************";
				printline120();
				break;
			default:
				cout << "\n------------------------Invalid function------------------------";
				break;
			}
			cout << "\n\t Do you want to: ";
			cout << "\n\t\t 1.Delete a student's information ";
			cout << "\n\t\t 2.Edit a student's information ";
			cout << "\n\t\t 3.Return to main menu";
			cout << "\n\t Enter your choice: ";
			fflush(stdin);
			cin >> info;
			switch (info) {
			case 1:
				cout << "\n-------Enter the order number of student you want to delete: ";
				fflush(stdin);
				cin >> testnum;
				if (testnum > list.size()) {
					cout << "\n------The student list is only have " << list.size() << " students now!------";
					cout << "\n------------------------Press Enter to continue!------------------------";
					fflush(stdin);
					getchar();
					break;
				}
				printheader();
				cout << endl << "\t" << testnum;
				list[testnum - 1].printstudent();
				cout << "\n\n\tDo you want to delete this student? \n\tPress 1 to continue, 0 to cancel : ";
				fflush(stdin);
				cin >> info;
				if (info) {
					list.erase(list.begin() + testnum - 1);
					cout << "\n------------------------Deleted student #" << testnum << " !!!------------------------";
				}
				else if(info==0) cout << "\n------------------------Cancelled deleting!------------------------";
				else cout<<"\n------------------------Invalid function, please try again!------------------------";
				cout << "\n------------------------Press Enter to continue!------------------------";
				fflush(stdin);
				getchar();
				break;
			case 2:
				cout << "\n-----Enter the order number of student you want to edit information: ";
				fflush(stdin);
				cin >> testnum;
				if (testnum > list.size()) {
					cout << "\n-------The student is only have " << list.size() << " students now!-------";
					cout << "\n------------------------Press Enter to continue!------------------------";
					fflush(stdin);
					getchar();
					break;
				}
				printline120();
				printheader();
				cout << endl << "\t" << testnum;
				list[testnum - 1].printstudent();
				printline120();
				info = 1;
				while (info) {
					cout << "\n\t0.Exit editting";
					cout << "\n\t1.Fullname";
					cout << "\n\t2.Gender";
					cout << "\n\t3.Major";
					cout << "\n\t4.Student ID";
					cout << "\n\t5.Score of subjects";
					cout << "\n------------Enter the number of information you want to edit: ";
					fflush(stdin);
					cin >> info;
					list[testnum - 1].editinfo(info);
				}
				printline120();
				cout << "\n------------------------Finished editting!------------------------";
				printheader();
				cout << endl << "\t" << testnum;
				list[testnum - 1].printstudent();
				printline120();
				cout << "\n------------------------Press Enter to continue!------------------------";
				fflush(stdin);
				getchar();
				break;
			case 3:
				cout << "\n------------------------Press Enter to continue!------------------------";
				fflush(stdin);
				getchar();
				break;
			default:
				cout << "\n------------------------Invalid function!------------------------";
				cout << "\n------------------------Press Enter to continue!------------------------";
				fflush(stdin);
				getchar();
				break;
			}
			break;
		case 5:
			statistic = 0;
			cout << "\n\t0:Model program. ";
			cout << "\n\t1:Credit program. ";
			cout << "\n\tEnter the program that you want to statistic: ";
			fflush(stdin);
			cin >> testnum;
			if (testnum != 0 && testnum != 1) {
				cout << "\n------------------------Invalid function! Please try again.------------------------";
				break;
			}
			printline120();
			printheader();
				for (i = 0;i < list.size();i++) {
				if (testnum == list[i].getprogram()) {
					cout << endl << "\t" << i + 1;
					list[i].printstudent();
					statistic++;
				}
			}
			printline120();
			cout << "\n-----------Total student in this program is: " << statistic<<" ------------";
			cout << "\n------------------------Press Enter to continue!------------------------";
			fflush(stdin);
			getchar();
			break;
		case 6:
			statistic = 0;
			printline120();
			printheader();
			for (i = 0;i < list.size();i++) {
				if ((list[i].getprogram() == 0 && list[i].getavr() > 5.0) || (list[i].getprogram() == 1 && list[i].getsumcredit() >= 10)) {
					cout << endl << "\t" << i + 1;
					list[i].printstudent();
					statistic++;
				}
			}

			printline120();
			cout << "\n------------Total student is graduate this year is: " << statistic<<" ------------------------";
			cout << "\n\t---Do you want to print the list of students graduate this year? (Press 1 for Yes, 0 for No) : ";
			cin >>testnum;
			if(testnum){
					FileOutput << "Full name \t Gender \t Student ID \t Major \t Program \t Average Score \t Total Credits";
					for (i = 0; i < list.size(); i++) {
						if ((list[i].getprogram() == 0 && list[i].getavr() > 5.0) || (list[i].getprogram() == 1 && list[i].getsumcredit() >= 10)){
					list[i].outputstudent();}
				}	cout<<"\n\t----File have been saved in the same folder of the program as 'GraduateManager.txt'----";
			}
			cout << "\n------------------------Press Enter to continue!------------------------";
			fflush(stdin);
			getchar();
			break;
		default:
			cout << "\n------------------------Ivalid function, please try again!------------------------";
			cout << "\n------------------------Press Enter to continue!------------------------";
			fflush(stdin);
			getchar();
			break;
		}
	}
}

string menu::getname() {
	return fullname;
}
string menu::getgender() {
	return gender;
}
string menu::getmajor() {
	return major;
}
unsigned int menu::getstudentid() {
	return studentid;
}
bool menu::getprogram() {
	return program;
}
double menu::getsubject(double a, double b) {
	return subject[(int)a][(int)b];
}
int menu::getavr() {
	return avr;
}
int menu::getsumcredit() {
	return sumcredit;
}
void printheader() {
	cout << "\n\t#\tFullname\t\t\tGender\tStudentID\tMajor\tAverage Score\tTotal Credits";
}
void printline120() {
	cout << endl << "\n________________________________________________________________________________________________________________________\n";
}
