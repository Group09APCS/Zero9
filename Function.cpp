#include "Function.h"
/*
void save(const char pathToSaveFile[], Student *head) {
ofstream fout(pathToSaveFile);
if (!fout.is_open()) {
return;
}
Student *cur = head;
while (cur->next != NULL) {
fout << cur->no << "  " << cur->ID << "  " << cur->name << "  ";
cur = cur->next;
}
if (cur->next == NULL) {
fout << cur->no << "  " << cur->ID << "  " << cur->name << "  ";
}

fout.close();
}
*/

//IMPORT USER
void Import(User *&head)
{
	// Import the users from csv file
	ifstream fin;
	fin.open("user.csv");
	if (!fin.is_open()) {
		return;
	}
	User * cur = NULL;
	head = new User;
	getline(fin, head->userName, ',');
	getline(fin, head->fullName, ',');
	getline(fin, head->ID, ',');
	getline(fin, head->email, ',');
	getline(fin, head->mobilePhone, ',');
	getline(fin, head->type, ',');
	getline(fin, head->password, ',');
	getline(fin, head->className, ' ');
	head->next = NULL;
	cur = head;
	while (fin.good())
	{
		cur->next = new User;
		cur = cur->next;
		getline(fin, cur->userName, ',');
		getline(fin, cur->fullName, ',');
		getline(fin, cur->ID, ',');
		getline(fin, cur->email, ',');
		getline(fin, cur->mobilePhone, ',');
		getline(fin, cur->type, ',');
		getline(fin, cur->password, ',');
		getline(fin, cur->className);
	}
	cur->next = NULL;
	fin.close();
}
//LOGIN
void Login(User *&head)
{
	system("cls");
	int choice;
	string name, Username, password;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	cout << "	********************************************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "						FINAL PROJECT" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "	********************************************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout << "	          @@HH00                      00                            MM@@HH      @@HH00" << endl;
	cout << "	            @@                        HH                          WW      HH  WW" << endl;
	cout << "	            MM      WWOOMM            @@    WWOOMM                00      @@  00" << endl;
	cout << "	            OO            MM    00WWOOMM  HH      MM              HH      MM  HH        " << endl;
	cout << "	            WW      HH00WWOO  @@      OO  @@HH00WWOO    HH00WW    @@      OO  @@    WWOO" << endl;
	cout << "	    OO      00    MM      WW  MM      WW  MM                      MM      WW  MM      WW" << endl;
	cout << "	      OOMM@@        MM@@HH00    MM@@HH00    MM@@HH                  MM@@HH      MM@@HH" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "	********************************************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "					STUDENT MANAGEMENT SYSTEM" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "	********************************************************************************************" << endl;
	cout << "						<<LOGIN>>" << endl;
	cout << "					Enter UserName: ";
	bool check = false;
	int t = 0;
	User * cur = head->next;
	for (int i = 0; i < 3; i++)
	{
		cur = head->next;
		getline(cin, Username);
		while (cur)
		{
			if (Username == cur->userName)
			{
				check = true;
				break;
			}
			cur = cur->next;
		}
		if (check == true)
			break;
		else
			cout << "					Mismatched! " << 3 - i << " time(s) remain:";

	}
	if (check == false)
	{
		system("cls");
		cur = head;
		cout << "					Do u want to create a new account? \n";
		cout << "					1.YES \n";
		cout << "					2.NO \n";
		cout << "					What do you want to do: ";
		cin >> t;
		switch (t)
		{
		case 1:
		{

			cout << "					Please input your fullname: ";
			cin.ignore();
			getline(cin, name);
			while (cur->next)
				cur = cur->next;
			cur->next = new User;
			cur = cur->next;
			cur->fullName = name;

			generateid(name, Username);
			cur->userName = Username;
			cout << "					Choose your password: ";
			password.clear();
			getline(cin, password);
			cur->password = password;
			cout << "					Your username: " << cur->userName << endl;
			cout << "					Your password: " << cur->password << endl;
			/*cout << "					Please set a new password: ";
			getline(cin, password);

			cout << "					Your username: " << cur->userName << endl;
			cout << "					Your password: " << cur->password << endl;*/
			break;
		}
		case 2:
		{
			cout << "					See you next time \n";
			exit(0);
		}
		}
	}
	cout << "					Enter Password: ";
	check = false;
	t = 0;
	for (int i = 0; i < 3; i++)
	{
		getline(cin, password);
		if (password == cur->password)
		{
			check = true;
			break;
		}
		else cout << "					" << 3 - i << "time(s) to try";
	}
	if (check == false)
		exit(0);
	showMenu(head, cur);
}
//SHOW MENU
void showMenu(User *&head, User *&cur)
{
	bool check = false;
	int choice;
	string password;
	system("cls");
	cout << "______________________________________________________WELCOME___________________________________________________________" << endl;

	cout << endl
		<< " 1 - Show the menu.\n"
		<< " 2 - View info.\n"
		<< " 3 - Change password.\n"
		<< " 4 - Exit.\n"
		<< " What do you want to do: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{	if (cur->type == "1")
		acastaffMenu(head, cur);
	if (cur->type == "0")
		studentMenu(head,cur);
	if (cur->type == "2")
		lecturerMenu();
	break;
	}
	case 2:
	{
		system("cls");
		cout << " User Name: " << cur->userName << endl;
		cout << " Full Name: " << cur->fullName << endl;
		cout << " ID: " << cur->ID << endl;
		cout << " Email: " << cur->email << endl;
		cout << " Phone: " << cur->mobilePhone << endl;
		cout << " Type: " << cur->type << endl;
		cout << " Password: " << cur->password << endl;
		cout << " Class: " << cur->className << endl;
		cout << " 1 - Return to the menu.\n";
		cout << " 2 - Exit. \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{showMenu(head, cur);
		break;
		}
		case 2:
		{
			cout << " SEEYA!.\n";
			exit(0);
			break;
		}
		default:
		{
			cout << " Not a Valid Choice. \n"
				<< " Choose again.\n";
			break;
		}
		}
	}
	case 3:
	{
		system("cls");
		cout << " Pls enter your old password: \n";
		cin.ignore();
		getline(cin, password);
		check = false;
		for (int i = 0; i < 3; i++)
		{
			if (password == cur->password)
			{
				check = true;
				break;
			}
			if (password != cur->password)
			{
				cout << " Mismatched! " << 3 - i << " time(s) remain: \n";
				check = false;
				getline(cin, password);
			}

		}
		if (check == true)
		{
			cout << " Pls enter your new password: \n";
			getline(cin, password);
			cur->password = password;
			cout << " Pls enter your new password again: \n";
			getline(cin, password);
			while (password != cur->password)
				getline(cin, password);
			cur->password = password;
			cout << " Complete! Your password has been changed! \n";
			cout << " 1 - Return to the menu.\n";
			cout << " 2 - Exit. \n";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{showMenu(head, cur);
			break;
			}
			case 2:
			{
				cout << "SEEYA!.\n";
				exit(0);
				break;
			}
			default:
			{
				cout << "Not a Valid Choice. \n"
					<< "Choose again.\n";
				break;
			}
			}

		}

		else {
			Login(head);
		}
		break;
	}
	case 4:
	{
		system("cls");
		cout << "SEEYA!.\n";
		return;
	}
	default:
	{
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
	}
	}
}
//STUDENT MENU
void studentMenu(User *&head, User *&cur)
{
	system("cls");
	int choice;
	cout << "\n\n  _________________________STUDENT DATABASE_________________________";
	cout << "\n\n 1: Check - in ";
	cout << "\n\n 2: View score for a course ";
	cout << "\n\n 3: Schedule ";
	cout << "\n\n 4: View your info ";
	cout << "\n\n 5: Change password ";
	cout << "\n\n 6: Log out ";
	cout << "\n\n 7: Exit ";
	cout << "\n\n What do you want to do: ";
	cin.ignore();
	cin >> choice;
	int newchoice;
	switch (choice)
	{
	case 4:
	{
		system("cls");
		cout << " User Name: " << cur->userName << endl;
		cout << " Full Name: " << cur->fullName << endl;
		cout << " ID: " << cur->ID << endl;
		cout << " Email: " << cur->email << endl;
		cout << " Phone: " << cur->mobilePhone << endl;
		cout << " Type: " << cur->type << endl;
		cout << " Password: " << cur->password << endl;
		cout << " Class: " << cur->className << endl;
		cout << " 1 - Return to the menu.\n";
		cout << " 2 - Exit. \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{showMenu(head, cur);
		break;
		}
		case 2:
		{
			cout << " SEEYA!.\n";
			exit(0);
			break;
		}
		default:
		{
			cout << " Not a Valid Choice. \n"
				<< " Choose again.\n";
			break;
		}
		}
	}
	case 5:
	{
		system("cls");
		cout << " Pls enter your old password: \n";
		cin.ignore();
		string password;
		getline(cin, password);
		bool check = false;
		for (int i = 0; i < 3; i++)
		{
			if (password == cur->password)
			{
				check = true;
				break;
			}
			if (password != cur->password)
			{
				cout << " Mismatched! " << 3 - i << " time(s) remain: \n";
				check = false;
				getline(cin, password);
			}

		}
		if (check == true)
		{
			cout << " Pls enter your new password: \n";
			getline(cin, password);
			cur->password = password;
			cout << " Pls enter your new password again: \n";
			getline(cin, password);
			while (password != cur->password)
				getline(cin, password);
			cur->password = password;
			cout << " Complete! Your password has been changed! \n";
			cout << " 1 - Return to the menu.\n";
			cout << " 2 - Exit. \n";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{showMenu(head, cur);
			break;
			}
			case 2:
			{
				cout << "SEEYA!.\n";
				exit(0);
				break;
			}
			default:
			{
				cout << "Not a Valid Choice. \n"
					<< "Choose again.\n";
				break;
			}
			}

		}

		else {
			Login(head);
		}
		break;
	}
	case 6:
	{
		cin.ignore();
		Login(head);
		break;
	}
	case 7:
	{
		return;
	}
	default:
	{
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
	}

	}
	studentMenu(head, cur);
}
//LECTURER MENU
void lecturerMenu()
{
	cout << "\n\n  _________________________LECTURER DATABASE_________________________";
	cout << "\n\n 1: Scoreboard ";
	cout << "\n\n 2: Edit Grade ";
	cout << "\n\n 3: Your info ";
	cout << "\n\n 4: Change password ";
	cout << "\n\n 5: Log out ";
	cout << "\n\n 6: Exit ";
}
//GENERATEID (NOT YET COMPLETED)
void generateid(string&name, string&Username)
{
	int i = name.length() - 1;
	int p = 0, k = 1;
	string add;
	Username.clear();
	int n = i;
	for (int j = 0; j < n; j++)
		name[j] = tolower(name[j]);
	Username = name[0];
	while (name[i] != ' ')
	{
		i--;
	}
	i++;
	for (int j = i; j <= n; j++)
	{
		add += name[j];
	}
	for (int t = 0; t < i - 1; t++)
	{
		if (name[t] == ' ')
		{
			Username += name[t + 1];
		}
	}
	Username += add;
}
//PASS (NOT YET COMPLETED)
int pass()
{
	srand(time(NULL));
	int a = rand();
	return a;
}
//THIS AREA IS USED FOR ACADEMIC STAFF, AUTHORIZED PERSONNEL ONLY!!!
//ACADEMIC STAFF MENU
void acastaffMenu(User *&head, User*&cur)
{
	system("cls");
	int choice;
	cout << "\n\n  _________________________ACADEMIC STAFF DATABASE_________________________";
	cout << "\n\n 1: Student Management ";
	cout << "\n\n 2: Courses ";
	cout << "\n\n 3: Courses Schedule ";
	cout << "\n\n 4: Search for attendance list ";
	cout << "\n\n 5: Scoreboard ";
	cout << "\n\n 6: Return ";
	cout << "\n\n 7: Log out ";
	cout << "\n\n 8: Exit ";
	cout << "\n\n What do you want to do: ";
	cin >> choice;
	int newchoice;
	switch (choice)
	{
	case 1:
	{
		system("cls");
		cout << "\n\n 1: Import Students Of A Class From A CSV File ";
		cout << "\n\n 2: Add New Student ";
		cout << "\n\n 3: Edit An Existing Student ";
		cout << "\n\n 4: Remove A Student ";
		cout << "\n\n 5: Change Students From Class A to Class B ";
		cout << "\n\n 6: Add A New Empty Class ";
		cout << "\n\n 7: View list of classes ";
		cout << "\n\n 8: View list of student in a class ";
		cout << "\n\n What do you want to do: ";
		Student * head1 = NULL;
		Student *head2 = NULL;
		importstudentfromfile(head1, "17CTT1.csv");
		importstudentfromfile(head2, "17CTT2.csv");
		cin >> newchoice;
		switch (newchoice) {
//6. Import students of a class from a csv file
		case 1:
		{
			system("cls");
			string cl;
			cout << "\n\n Which class you want to import? \n";
			cout << "\n\n 1: 17CTT1 ";
			cout << "\n\n 2: 17CTT2 ";
			getline(cin, cl);
			while (cl != "1" && cl != "2")
				getline(cin, cl);
			cout << "Successful! Return to menu... \n";
			showMenu(head, cur);
		}
//7. Add a new student to a class
		case 2:
		{
			system("cls");
			cout << "\n\n In which class do you want to add new student? ";
			cout << "\n\n 1: 17CTT1 ";
			cout << "\n\n 2: 17CTT2 ";
			int cls;
			cin >> cls;
			string css;
			if (cls == 1)
			{
				css = "17CTT1";
				addnewstudent(head1, css);
				printout(head1, "17CTT1.csv");
			}
			if (cls == 2)
			{
				css = "17CTT2";
				addnewstudent(head2, css);
				printout(head2, "17CTT1.csv");
			}
			acastaffMenu(head, cur);
			break;
		}
//8. Edit an existing student
		case 3:
		{
			system("cls");
			int Choice2;
			Student* cur1 = NULL;
			cout << "\n\n In which class do you want to edit a student?" << endl;
			cout << "\n\n 1: 17CTT1\n";
			cout << "\n\n 2: 17CTT2\n";
			cin >> Choice2;
			if (Choice2 == 1)
			{
				string scs = "17CTT1.csv";
				string unscs = "17CTT2.csv";
				editastudent(head1, head2, scs, unscs);
			}
			if (Choice2 == 2)
			{
				string scs = "17CTT2.csv";
				string unscs = "17CTT1.csv";
				editastudent(head2, head1, scs, unscs);
			}
			acastaffMenu(head, cur);
		}
//9. Remove a student
		case 4:
		{
			system("cls");
			int Choicex;
			cout << "\n\n In which class do you want to remove a student?" << endl;
			cout << "\n\n 1: 17CTT1\n";
			cout << "\n\n 2: 17CTT2\n";
			cin >> Choicex;
			string name;
			cout << "\n\n Which student you want to remove? ";
			cin.ignore();
			getline(cin, name, '\n');
			switch (Choicex) {
			case 1:
			{
				removestudent(head1, name);
				printout(head1, "17CTT1.csv");
				cout << "Done!" << endl;
				break;
			}
			case 2:
			{
				removestudent(head2, name);
				printout(head2, "17CTT2.csv");
				cout << "Done!" << endl;
				break;
			}
			default:
			{
				cout << "Error!\n";
				break;
			}
			}
			acastaffMenu(head, cur);
		}
//10. Change Class (Binh sua lai nha)
		case 5:
		{
			changeclass(head1, head2);
			break;
		}
//11. Add a new empty class
		case 6:
		{
			system("cls");
			newclass();
			acastaffMenu(head, cur);
			break;
		}
//12. View list of classes (Phuong sua lai nha)
		case 7:
		{
			listOfClass(head);
			acastaffMenu(head, cur);
			break;
		}
//13. View list of students in a class
		case 8:
		{
			system("cls");
			cout << " Pls enter the name of the class: ";
			string nme;
			cin.ignore();
			getline(cin, nme);
			listOfStudent(head, nme);
		}
		break;
		}
	}
//***************************   COURSE   ***************************
	case 2:
	{
		system("cls");
		cout << "\n\n 1: Import A Course ";
		cout << "\n\n 2: Add New Course ";
		cout << "\n\n 3: View List Courses ";
		cout << "\n\n 4: Edit Courses ";
		cout << "\n\n 5: Remove Courses ";
		cout << "\n\n What do you want to do: ";
		Course * chead = NULL;
		importcoursefromfile(chead, "course.csv");
		cin >> choice;
		switch (choice)
		{
			//14. Import courses from a csv file
		case 1:
		{
			system("cls");
			Course * chead = NULL;
			importcoursefromfile(chead, "course.csv");
			acastaffMenu(head, cur);
			break;
		}
		//15. Add a new course
		case 2:
		{
			system("cls");
			addanewcourse(chead, "course.csv");
			acastaffMenu(head, cur);
			break;
		}
		//16. Edit an existing course
		case 4:
		{
			system("cls");
			editcourse(chead, "course.csv");
			acastaffMenu(head, cur);
			break;
		}
		//17. Remove a course
		case 5:
		{
			system("cls");
			cout << "Pls enter the course of code you want to remove: ";
			string c;
			cin.ignore();
			getline(cin, c);
			removeCourse(chead, c);
			printcout(chead, "course.csv");
			acastaffMenu(head, cur);
			break;
		}
		//18. View list of courses
		case 3:
		{
			system("cls");
			viewcourse(chead, "course.csv");
			acastaffMenu(head, cur);
			break;
		}
		}
	}
	case 3:
	{	system("cls");
	cout << "\n\n 1: Import Courses' Schedules ";
	cout << "\n\n 2: Add New Courses' Schedule ";
	cout << "\n\n 3: View List Courses' Schedules ";
	cout << "\n\n 4: Edit Courses' Schedules ";
	cout << "\n\n 5: Remove Courses' Schedules ";
	cout << "\n\n What do you want to do: ";
	Course * chead = NULL;
	importcoursefromfile(chead, "course.csv");
	int richchoi;
	cin >> richchoi;
	switch (richchoi)
	{
	case 1:
	{
		cout << "Done!";
		acastaffMenu(head, cur);
	}
	case 2:
	{

	}
	}
	}
	case 4:
	{	system("cls");
	cout << "\n\n 1: Search & View Attendance List ";
	cout << "\n\n 2: Export Attendance List";
	break;

	}
	case 5:
	{	system("cls");
	cout << "\n\n 1: Search & View Scoreboard ";
	cout << "\n\n 2: Export Scoreboard";
	break;
	}
	case 6:
	{
		showMenu(head, cur);
		break;
	}
	case 7:
	{
		cin.ignore();
		Login(head);
		break;
	}
	case 8:
	{
		exit(0);
		break;
	}
	default:
	{
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
	}
	}
}
//PRINT OUT STUDENT
void printout(Student *&head, const string file)
{
	ofstream fout;
	fout.open(file);
	Student * cur = head;
	while (cur)
	{
		fout << cur->ID << "," << cur->fullName << "," << cur->email << "," << cur->sclass << endl;
		cur = cur->next;
	}
	fout.close();
}
//FIND STUDENT
void findstudent(Student * &cur, Student * head, string name)
{
	cur = head;
	if (head->fullName == name)
		return;
	else
	{
		while (cur != NULL && cur->fullName != name)
			cur = cur->next;
	}
}
//6
void importstudentfromfile(Student *&head, string cl) {
	ifstream fin(cl);
	if (!fin.is_open()) {
		return;
	}
	Student *cur = NULL;
	while (fin.good()) {
		if (head == NULL) {
			head = new Student;
			getline(fin, head->ID, ',');
			getline(fin, head->fullName, ',');
			getline(fin, head->email, ',');
			getline(fin, head->sclass);
			head->next = NULL;
			cur = head;
		}
		else {
			cur->next = new Student;
			cur = cur->next;
			getline(fin, cur->ID, ',');
			getline(fin, cur->fullName, ',');
			getline(fin, cur->email, ',');
			getline(fin, cur->sclass);
			cur->next = NULL;
		}
	}
	fin.close();
}
//7
void addnewstudent(Student *&head, string scs)
{
		Student * cu = head;
		while (cu ->next != NULL)
			cu = cu->next;
		cu ->next = new Student;
		cu = cu->next;
		cout << "Pls enter student ID: ";
		string id;
		cin.ignore();
		getline(cin, id);
		cu->ID = id;
		cout << "Pls enter student Full name";
		string fullname;
		getline(cin, fullname);
		cu->fullName = fullname;
		cout << "Pls enter student email";
		string smail;
		getline(cin, smail);
		cu->email = smail;
		cu->sclass = scs;
		cu->next = NULL;
}
//8
void editastudent(Student *&head1, Student *&head2, string scs, string unscs)
{

	Student* cur1 = NULL;
	string name;
	system("cls");
	cout << "Which student you want edit?\n";
	cin.ignore();
	getline(cin, name);
	cout << "\n What do you want to edit?\n";
	cout << "1: Student ID\ n";
	cout << "2: Student Name \n";
	cout << "3: Email \n";
	cout << "4: Class \n";
	int Choice1;
		cin >> Choice1;
		string str;
		findstudent(cur1, head1, name);
		switch (Choice1)
		{
		case 1:
		{
			cout << "Please enter new student ID: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->ID = str;
			cout << "Done!" << endl;
			printout(head1, scs);
			break;
		}
		case 2:
		{
			cout << "Please enter the new student name: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->fullName = str;
			printout(head1, scs);
			cout << "Done!" << endl;
			break;
		}
		case 3:
		{
			cout << "Please enter the new student email: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->email = str;
			printout(head1, scs);
			cout << "Done!" << endl;
			break;
		}
		case 4:
		{
			cin.ignore();
			getline(cin, str, '\n');
			changeclass(head1, head2);
			printout(head1, scs);
			printout(head2, unscs);
			cout << "Done!" << endl;
			break;
		}
		default:
		{
			cout << "Error!\n";
			break;
		}
		}
}
//9
void removestudent(Student *&head, string name)
{
	Student* cur = head;
	if (cur->fullName == name)
	{
		head = head->next;
		delete cur;
		cur = NULL;
	}
	else
	{
		while (cur != NULL && cur->next != NULL && cur->next->fullName != name)
		{
			cur = cur->next;
		}
		if (cur == NULL)
			return;
		else
		{
			Student* cur2 = cur;
			cur = cur->next;
			if (cur == NULL)
				cur2->next = NULL;
			else cur2->next = cur->next;
			delete cur;
			cur = NULL;
		}
	}
}
//10
void changeclass(Student  *&head1, Student *&head2)
{
	string studentID;
	cout << "Please input ID of the student that you want to change class:";
	cin.ignore();
	getline(cin, studentID);
	Student*cur = head1;
	while (studentID.compare(cur->ID) != 0 && cur != NULL)
	{
		cur = cur->next;
	}
	if (cur == NULL)
	{
		cout << "That student is not in this class";
		system("pause");
		return;
	}
	else
	{
		{
			Student *temp = new Student;
			temp = cur;
			cur = cur->next;

			Student*cur2 = head2;
			while (studentID.compare(cur2->ID) < 0 && cur2->next != NULL)
				cur2 = cur2->next;
			if (cur2->next == NULL)
			{
				cur2->next = new Student;
				cur2 = cur2->next;
				cur2->ID = temp->ID;
				cur2->fullName = temp->fullName;
				cur2->email = temp->email;
				cur2->sclass = temp->sclass;
				cur2->next = NULL;
				cout << "Added student in the end of the class";
			}
			else
			{
				Student *temp2 = new Student;
				temp2->ID = temp->ID;
				temp2->fullName = temp->fullName;
				temp2->email = temp->email;
				temp2->sclass = temp->sclass;
				temp2->next = cur->next;
				cur2->next = temp2;
				cur2 = cur2->next;
				cout << "Done!";
			}
			delete temp;
		}

	}
	printout(head1, "17CTT1.csv");
	printout(head2, "17CTT2.csv");
}
//11
void newclass()
{
	string classname;
	ofstream fout;
	cout << "Please input the name of the new class:";
	cin.ignore();
	getline(cin, classname);
	classname.append(".csv");
	fout.open(classname);
	fout.close();
	cout << "Done!";
}
//12. View list of classes
void listOfClass(User *head) {
	User *cur = head->next;
	string classes[50];
	int numberOfClass = 0;
	cout << "List of Classes:\n";
	while (cur->next != NULL) {
		if (!duplicateCheck(numberOfClass, classes, cur->className)) {
			classes[numberOfClass++] = cur->className;
		}
		cur = cur->next;
	}
	/*if (cur->next == NULL && (!duplicateCheck(numberOfClass, classes, cur->className))) {
	classes[numberOfClass++] = cur->className;
	}*/
	for (int i = 0; i < numberOfClass - 1; ++i) {
		cout << classes[i] << endl;
	}
}

bool duplicateCheck(int numberOfClass, string classes[], string curClass) {
	if (numberOfClass == 0) {
		return false;
	}
	for (int i = 0; i < numberOfClass; ++i) {
		if (!strcmp(classes[i].c_str(), curClass.c_str())) {
			return true;
		}
	}
	return false;
}

//13. View list of students in a class
void listOfStudent(User *head, string curClass) {
	cout << "List of students in the class " << curClass << " :" << endl;
	User *cur = head->next;
	while (cur->next != NULL) {
		if (!strcmp(cur->className.c_str(), curClass.c_str())) {
			cout << cur->fullName << endl;
			cur = cur->next;
		}
		if (cur->next == NULL) {
			cout << cur->fullName << endl;
		}
	}
}
//PRINT OUT COURSE
void printcout(Course *&chead, const string file)
{
	ofstream fout;
	fout.open(file);
	Course * cur = chead;
	while (cur)
	{
		fout << cur->courseCode << "," << cur->academicYear << "," 
			<< cur->semester << "," << cur->courseName << "," << cur->lecturerName << ","
			<< cur->startDate << "," << cur->endDate <<  "," << cur->dayOfWeek << ","
			<< cur->startHour << "," << cur->endHour << endl;
		cur = cur->next;
	}
	fout.close();
}
//FIND COURSE
void findcourse(Course *&cur, Course *&chead, string name)
{
	cur = chead;
	if (chead->courseName == name)
		return;
	else
	{
		while (cur != NULL && cur->courseName != name)
			cur = cur->next;
	}
}
//14. Import courses from a csv file
void importcoursefromfile(Course * &chead, string filename)
{
	ifstream fin(filename);
	if (!fin.is_open()) {
		return;
	}
	Course *cur = NULL;
	while (fin.good()) {
		if (chead == NULL) {
			chead = new Course;
			getline(fin, chead->courseCode, ',');
			getline(fin, chead->academicYear, ',');
			getline(fin, chead->semester, ',');
			getline(fin, chead->courseName, ',');
			getline(fin, chead->lecturerName, ',');
			getline(fin, chead->startDate, ',');
			getline(fin, chead->endDate, ',');
			getline(fin, chead->dayOfWeek, ',');
			getline(fin, chead->startHour, ',');
			getline(fin, chead->endHour);
			chead->next = NULL;
			cur = chead;
		}
		else {
			cur->next = new Course;
			cur = cur->next;
			getline(fin, cur->courseCode, ',');
			getline(fin, cur->academicYear, ',');
			getline(fin, cur->semester, ',');
			getline(fin, cur->courseName, ',');
			getline(fin, cur->lecturerName, ',');
			getline(fin, cur->startDate, ',');
			getline(fin, cur->endDate, ',');
			getline(fin, cur->dayOfWeek, ',');
			getline(fin, cur->startHour, ',');
			getline(fin, cur->endHour);
			cur->next = NULL;
		}
	}
	fin.close();
}
//15. Add a new course
void addanewcourse(Course *&chead, string filename)
{
	Course* cur1 = chead;
	string str;
	while (cur1->next != NULL)
	{
		cur1 = cur1->next;
	}
	cur1->next = new Course;
	cur1 = cur1->next;
	cout << "Pls input courseCode: ";
	cin.ignore();
	getline(cin, str, '\n');
	cur1->courseCode = str;
	cout << "Pls input academicYear: ";
	getline(cin, str, '\n');
	cur1->academicYear = str;
	cout << "Pls input courseSemester: ";
	getline(cin, str, '\n');
	cur1->semester = str;
	cout << "Pls input courseName: ";
	getline(cin, str, '\n');
	cur1->courseName = str;
	cout << "Pls input lecturerName: ";
	getline(cin, str, '\n');
	cur1->lecturerName = str;
	cout << "Pls input startDate: ";
	getline(cin, str, '\n');
	cur1->startDate = str;
	cout << "Pls input endDate: ";
	getline(cin, str, '\n');
	cur1->endDate = str;
	cout << "Pls input dayOfWeek: ";
	getline(cin, str, '\n');
	cur1->dayOfWeek = str;
	cout << "Pls input startHour: ";
	getline(cin, str, '\n');
	cur1->startHour = str;
	cout << "Pls input endHour: ";
	getline(cin, str, '\n');
	cur1->endHour = str;
	cur1->next = NULL;
	printcout(chead, "course.csv");
}
//16. Edit an existing course
void editcourse(Course *&chead, string filename)
{
	Course* cur = NULL;
	string name;
	system("cls");
	cout << "Which course do you want edit?\n";
	cin.ignore();
	getline(cin, name);
	cout << "\n What do you want to edit?\n";
	cout << "1: Course Code \n";
	cout << "2: Academic Year \n";
	cout << "3: Semester \n";
	cout << "4: Course Name \n";
	cout << "5: Lecturer Name \n";
	cout << "6: Start Date \n";
	cout << "7: End Date \n";
	cout << "8: Date Of Week \n";
	cout << "9: Start Hour \n";
	cout << "10: End Hour \n";
	int Choice1;
	cin >> Choice1;
	string str;
	findcourse(cur, chead, name);
	switch (Choice1)
	{
	case 1:
	{
		cout << "Please enter new Course Code: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->courseCode = str;
		cout << "Done!" << endl;
		printcout(chead, "course.csv");
		break;
	}
	case 2:
	{
		cout << "Please enter the new Academic Year: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->academicYear = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 3:
	{
		cout << "Please enter the new Semester: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->semester = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 4:
	{
		cout << "Please enter the new Course Name: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->courseName = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 5:
	{
		cout << "Please enter the new :ecturer Name: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->lecturerName = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 6:
	{
		cout << "Please enter the new Start Date: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->startDate = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 7:
	{
		cout << "Please enter the new End Date: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->endDate = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 8:
	{
		cout << "Please enter the new Day of Week: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->dayOfWeek = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 9:
	{
		cout << "Please enter the new Start Hour: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->startHour = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 10:
	{
		cout << "Please enter the new End Hour: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->endHour = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	default:
	{
		cout << "Error!\n";
		break;
	}
	}
}
//17. Remove a course
void removeCourse(Course *head, string courseToRemove) {  //use courseCode for courseToRemove
	Course *cur = head;
	while (cur->next->next != NULL) {
		if (cur->next->courseCode == courseToRemove) {
			cout << cur->next->courseCode;
			cur->next = cur->next->next;
		}
	}
	if (cur->next->next == NULL
		&& cur->next->courseCode == courseToRemove) {
		cur->next = NULL;
	}
}
//18. View list of courses
void viewcourse(Course*&chead, string f)
{
	int i = 0;
	Course * cur = chead;
	while (cur)
	{
		cout << "Course[" << i << "]: " << endl;
		cout << "Course Code: ";
		cout << cur->courseCode << endl;
		cout << "Course Name: ";
		cout << cur->courseName << endl;
		cout << "Lecturer Name: ";
		cout << cur->lecturerName << endl;
		i++;
	}
}
//******************************ATTENDANCE LIST*******************************
//IMPORT

