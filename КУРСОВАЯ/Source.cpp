#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<ctime>
using namespace std;


struct FIO {
	string surname;
	string name;
	string patronymic;
};
struct Date {
	int day;
	int month;
	int year;
};
struct Worker {
	string login;
	string role;
	string password;
	int access;
    FIO fio;
	Date birth;
	string department;
    string position;
    Date start_work;
	Date work_experience;
};


const string FILE_WORKERS="Data.txt";
const string FILE_ADMIN = "admin.txt";
void core(vector<Worker>& v);
int menu();
string choose_role(vector<Worker>& v);
int menu_for_admin();
bool core_for_admin(vector<Worker>& v,int index);
int menu_for_employee();
bool core_for_employee(vector<Worker>& v,int index);
int menu_for_chief();
bool core_for_chief(vector<Worker>& v,int index);


void show_workers_admin(const vector<Worker> v);
void show_worker_admin(const vector<Worker> v, int i);
void show_worker_him(const vector<Worker> v, int i);
void show_workers_chief(const vector<Worker> v);
void show_worker_chief(const vector<Worker> v, int i);
void read_workers_from_File(vector<Worker>& v);
void write_Workers_in_File(vector<Worker>v);

int authorization(const vector<Worker> v);
void entrance(vector<Worker>& v);
void registration(vector<Worker>& v);
void registration_admin(vector<Worker>& v);
void reg_admin(vector<Worker>& v, Worker temp);
void reg_employee(vector<Worker>& v, Worker temp);
void reg_chief(vector<Worker>& v, Worker temp);
void del(vector<Worker>& v);
void update_for_chief(vector<Worker>& v);
void update_himself(vector<Worker>& v, int index);
void confirm_or_block(vector<Worker>& v);
void work_experience(vector<Worker>& v, int i);


void date(vector<Worker>& v);
int check_Input();
string check_Login();
string check_Password();
string imagen_Password();
string check_String();
string check_line();
bool check_individuality(const vector<Worker> v, string log);
bool exit_or_not();





int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 30,number=0;
	vector<Worker> v;
	v.reserve(n);

   

	read_workers_from_File(v);
	core(v);
	write_Workers_in_File(v);
}

void core(vector<Worker>& v)
{
	int input;
	bool flag = true;

	while (flag)
	{
		input = menu();
        switch (input)
		{
		case 1:entrance(v);
			break;
		case 2:registration(v);
			exit_or_not();
			break;
		case 0:flag = false;
			break;
		}
	}
}
int menu() {
	int input;
	cout << "1 - ����� "<<endl;
	cout << "2 - ������������������"<<endl;
	cout << "0- �����"<<endl;
	input = check_Input();
	return input;
}
string choose_role(vector<Worker>& v)
{
	int rol;
	string role;
    cout << "�������� ����: 1 - �������������, 2 - c��������, 3 - ��������� " << endl;
	do {
		cout << "�������: ";
		cin >> rol;
	} while (rol != 2 && rol != 1 && rol != 3);
	if (rol == 1)role = "�������������";
	if (rol == 2)role = "���������";
	if (rol == 3)role = "���������";
	cout << endl;
	return role;
}

int menu_for_admin() {
	int input;
	cout << "        ����  ��������������           " << endl;
	cout << "1 - �������� ������� �������" << endl;
	cout << "2 - ���������� ����� ������� ������" << endl;
	cout << "3 - �������������� ����� ������� ������" << endl;
	cout << "4 - �������� ������� ������" << endl;
	cout << "5 - ������������� ��� ���������� ������� ������" << endl;
	cout << "6 - ����� ��������� �� ... " << endl;//�� ������� //�� �������//�� ������ 
	cout << "0 - �����" << endl;

	input = check_Input();
	return input;
}
bool core_for_admin(vector<Worker>&v,int index) {
	bool flag = true;
	while (flag)
	{
		int item = menu_for_admin();
		switch (item)
		{
		case 1:show_workers_admin(v);
			break;
		case 2:registration_admin(v);
			break;
		case 3:update_himself(v,index);
			break;
		case 4:del(v);
			break;
		case 5:confirm_or_block(v);
			break;
		case 6:
			break;
		case 0: flag = false;
			break;
		}
	}
	return flag;
}
int menu_for_employee() {
	int input;
	cout << "           ����  ����������         " << endl;
	cout << "1 - �������� ����� ������� ������" << endl;
	cout << "2 - �������������� ������ ������ � ������� ������" << endl;
	cout << "0 - �����" << endl;

	input = check_Input();
	return input;
}
bool core_for_employee(vector<Worker>& v,int index) {
	bool flag = true;
	while (flag)
	{
		int item = menu_for_employee();
		switch (item)
		{
		case 1:see_himself(v, index);
			break;
		case 2:update_himself(v, index);
			break;
		case 0: flag = false;
			break;
		}
	}
	return flag;
}
int menu_for_chief() {
	int input;
	cout << "          ����  ����������            " << endl;
	cout << "1 - �������� ������� �������" << endl;
	cout << "2 - ������������� ���������� � ����������" << endl;
	cout << "3 - �������� ����� ������� ������" << endl;
	cout << "4 - �������������� ������ ������ � ������� ������" << endl;
	cout << "5 - ����� ���������� �� ..." << endl;//�������//���������//������
	cout << "6 - ���������� ����������� �� ..." << endl;//����//�� ������ (1-���������, 2-�������������,3-����������)//��������(����������� ��������,� ���)
	cout << "0 - �����" << endl;

	input = check_Input();
	return input;
}
bool core_for_chief(vector<Worker>& v,int index) {
	bool flag = true;
	while (flag)
	{
		int item = menu_for_employee();
		switch (item)
		{
		case 1:show_workers_chief(v);
			break;
		case 2:update_for_chief(v);
			break;
		case 3:see_himself(v, index);
			break;
		case 4:update_himself(v, index);
			break;
		case 5:
			break;
		case 6:
			break;
		case 0: flag = false;
			break;
		}
	}
	return flag;
}


void show_workers_admin(const vector<Worker> v)
{
	for (int i = 0 ; i < v.size(); i++)
	{
		cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname<<" "<< v.at(i).fio.name <<" "<< v.at(i).fio.patronymic << endl;
		cout << "�����: " << v.at(i).login<<endl;
		cout << "����: "  << v.at(i).role << endl;
		cout << "������: ";
		if (v.at(i).access == 0)
			cout << "������";
		else cout << "������";
        cout << endl;
	}
}
void show_worker_admin(const vector<Worker> v, int i)
{
		cout << "��� " << i+1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
		cout << "�����: " << v.at(i).login << endl;
		cout << "����: " << v.at(i).role << endl;
		cout << "������: ";
		if (v.at(i).access == 0)
			cout << "������";
		else cout << "������";
		cout << endl;
}
void show_worker_him(const vector<Worker> v, int i)
{
	cout << "1 - �����: " << v.at(i).login << endl;
	cout << "2 - ������: " << " ********    (���������� �������� � ������ ����� �� ��������� � ���������� ����������� ��������)" << endl;
	cout << "3 - ��� : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "4 - ���� ��������: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;

}
void see_himself(vector<Worker> v, int i) {
	cout << "�����: " << v.at(i).login << endl;
	cout << "������: " << " ********    (���������� �������� � ������ ����� �� ��������� � ���������� ����������� ��������)" << endl;
	cout << "��� : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "���� ��������: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;
	cout << "���������: " << v[i].position << " ������ " << v[i].department << endl;
	work_experience(v, i);
}
void show_workers_chief(const vector<Worker> v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
		cout << "�����: " << v.at(i).login << endl;
		cout << "���������: " << v.at(i).position << " � ������ " << v.at(i).department << endl;
		cout << "����: ";
		cout << endl;
	}
}
void show_worker_chief(const vector<Worker> v, int i) {

	cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "�����: " << v.at(i).login << endl;
	cout << "���������: " << v.at(i).position << " � ������ " << v.at(i).department << endl;
	cout << "����: ";
	cout << endl;
}
void read_workers_from_File(vector<Worker>& v)
{
	int i = 0;
	ifstream fin(FILE_WORKERS, ios::in);
	if (!fin.is_open())
	{
		Worker temp;
		temp.login = "admin_admin";
		temp.role = "�������������";
		temp.password = "1";
		temp.access = 1;
		temp.fio.surname = "--- "; temp.fio.name = " --- "; temp.fio.patronymic = " ---";
		temp.birth.day = 0; temp.birth.month = 0; temp.birth.year = 0;
		temp.position = temp.role; temp.department = " ---";
		temp.start_work.day = 0; temp.start_work.month = 0; temp.start_work.year = 0;
		v.push_back(temp);
		write_Workers_in_File(v);
	}

	else
	{
		while (!fin.eof())
		{
			Worker temp;
			fin >> temp.login;
			fin >> temp.role;
			fin >> temp.password;
			fin >> temp.access;
			fin >> temp.fio.surname >> temp.fio.name >> temp.fio.patronymic;
			fin >> temp.birth.day >> temp.birth.month >> temp.birth.year;
			fin >> temp.position >> temp.department;
			fin >> temp.start_work.day >> temp.start_work.month >> temp.start_work.year;
			v.push_back(temp);
		}
	}
	fin.close();
}
void write_Workers_in_File(vector<Worker>v)
{
	ofstream fout(FILE_WORKERS, ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		fout << v.at(i).login << " "
			<< v.at(i).role << " "
			<< v.at(i).password << " "
			<< v.at(i).access << " "
			<< v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << " "
			<< v.at(i).birth.day << " " << v.at(i).birth.month << " " << v.at(i).birth.year
			<< v.at(i).position << " " << v.at(i).department << " "
			<< v.at(i).start_work.day << " " << v.at(i).start_work.month << " " << v.at(i).start_work.year;

		if (i < v.size() - 1)
		{
			fout << endl;
		}
	}
	fout.close();
}


int authorization(const vector<Worker> v)
{
	string login,pass;
	int index=0,k=0;
	char input;
	do {
		cout << "������� ��� �����: ";
		login = check_Login();
		cout << "������� ������: ";
		pass = check_Password();
		for (int i = 0; i < v.size(); i++) {
			if (login == v.at(i).login && pass == v.at(i).password)
			{
				index = i;
				k++;
				input = 0;
			}

		}
		if (k == 0) 
		{
		cout << "�� ����� �������� ����� ��� ������.������� 0 - ����� � ������� ����.����� ������ ������ - ����������� �����." << endl;
		cin >> input;
		system("cls");
	    }
	} while (input != 0); 
	return index;
}

void entrance(vector<Worker>& v) {
	int index = authorization(v);
	bool flag = true;
	system("cls");
	while (flag)
	{
		if (v.at(index).access == 0) {
			cout << "� ��� ��� �������. ���������, ����������, ���� ������������� ������ ���"<<endl;
			flag = false;
		}
		else 
		{
			if (v.at(index).role == "�������������")
			{
				flag = core_for_admin(v,index);
			}
			else if (v.at(index).role == "���������")
			{
				flag = core_for_chief(v,index);
			}
			else if (v.at(index).role == "���������")
			{
				flag = core_for_employee(v,index);
			}
		}
	}
}
void registration(vector<Worker>& v)
{
	Worker temp;
	bool flag = true;
	temp.role = choose_role(v);
	cout << "���������� �����(�� ����� 8-�� ��������): ";
	while(flag){
		temp.login = check_Login();
		flag = check_individuality(v, temp.login);
	} 
	cout << "���������� ������: ";
	temp.password = imagen_Password();
	cout << "�������: ";
	temp.fio.surname = check_String();
    cout << "���: ";
	temp.fio.name = check_String();
    cout << "��������: ";
	temp.fio.patronymic = check_String();
	cout << "���� �������� " << endl;
	date(v);
    if (temp.role == "�������������")
	{
		reg_admin(v, temp);
	}
	else if (temp.role == "���������") 
	{
		reg_employee(v,temp);

    }
	else if(temp.role == "���������")
	{
		reg_chief(v,temp);

	}
	temp.access = 0;
	v.push_back(temp);
	cout << "���� ������ ��������, ��������� ���� ������������� ������ ��� ������ " << endl;
}
void registration_admin(vector<Worker>& v) {
	Worker temp;
	bool flag = true;
	temp.role = choose_role(v);
	cout << "���������� �����(�� ����� 8-�� ��������): ";
	while (flag) {
		temp.login = check_Login();
		flag = check_individuality(v, temp.login);
	}
	cout << "���������� ������: ";
	temp.password = imagen_Password();
	cout << "�������: ";
	temp.fio.surname = check_line();
	cout << "���: ";
	temp.fio.name = check_line();
	cout << "��������: ";
	temp.fio.patronymic = check_line();
	cout << "���� �������� " << endl;
	date(v);
	cout << "������ (1-������,0-������): ";
	int input;
	do {
		cin >> input;
		if (input != 1 && input != 0) cout << "�� ������ �� �������. 1 - �������, 0 - ������� " << endl;
	} while (input != 1 && input != 0);
	temp.position = "---";
	temp.department = "---";
	temp.start_work.day = 0;
	temp.start_work.month = 0;
	temp.start_work.year = 0;
	temp.work_experience.day = 0;
	temp.work_experience.month = 0;
	temp.work_experience.year = 0;

}
void reg_admin( vector<Worker>&v,Worker temp) {
	
	temp.position = temp.role;
	temp.department = "---";
	temp.start_work.day = 0;
	temp.start_work.month = 0;
	temp.start_work.year = 0;
	temp.work_experience.day = 0;
	temp.work_experience.month = 0;
	temp.work_experience.year = 0;

}
void reg_employee(vector<Worker>& v,Worker temp) {

	temp.position = "---";
	temp.department = "---";
	temp.start_work.day = 0;
	temp.start_work.month = 0;
	temp.start_work.year = 0;
	temp.work_experience.day = 0;
	temp.work_experience.month = 0;
	temp.work_experience.year = 0;

}
void reg_chief(vector<Worker>& v,Worker temp) {

	temp.position = temp.role;
	cout << "������� �������� ������: ";
	temp.department = check_line();
	cout << "���� ������ ������ "<<endl;
	date(v);

}
void del(vector<Worker>& v)
{
	show_workers_admin(v);
	cout << "������� ����� ����, ���� ������ �������: ";
	int index_delete = check_Input();
	index_delete--;
	v.erase(v.begin() + index_delete);
	cout << "�������� ������ �������" << endl;

}

void update_for_chief(vector<Worker>& v)
{
	int num, numeric = 0;
	bool flag = true;
	show_workers_chief(v);
	while (flag)
	{
		cout << "������� ����� ����������, �������� ������ �������������: " << endl;
		num = check_Input() - 1;
		show_worker_chief(v,num);
		cout << "������� ����� ����, ��� ������ ������������� " << endl;
		numeric = check_Input();
		cout << endl;
		switch (numeric)
		{
		case 1:cout << "���������: ";
			check_line()=v.at(num).position;
			break;
		case 2:cout << "�����: ";
			check_line()= v.at(num).department;
			break;
		case 3:cout << "���� ������ ������: ";
			date(v);
			break;
		}
		cout << endl;
		cout << endl;
		write_Workers_in_File(v);
		cout << "���������� ������������� ��� ����� � ������� ����" << endl;
		cout << endl;
		flag = exit_or_not();
	}

}
void update_himself(vector<Worker>& v, int index) {
	int input;
	bool flag = true;
	while (flag)
	{
        show_worker_him(v, index);
		cout << "�������� ����� ���������� �� ������ ������������� " << endl;
		input = check_Input();
		switch (input) {
		case 1:cout << "�����: ";
			while (flag) {
				v[index].login = check_Login();
				flag = check_individuality(v, v[index].login);
			}
            break;
		case 2:cout << "������: ";
			v[index].password = check_Password();
			break;
		case 3:cout << "���: ";
			cout << "�������: ";
			v[index].fio.surname = check_String();
			cout << "���: ";
			v[index].fio.name = check_String();
			cout << "��������: ";
			v[index].fio.patronymic = check_String();
			break;
		case 4:cout << "���� ��������: ";
			date(v);
			break;
		}
		write_Workers_in_File(v);
		cout << "���������� ������������� ��� ����� � ������� ����" << endl;
		flag = exit_or_not();
		system("cls");
	}
}


void confirm_or_block(vector<Worker>&v){
	show_workers_admin(v);
	int index;
	int input;
	cout << "������� ����� ����, ��� ������ �� ������ ��������: ";
	index = check_Input();
	index--;
	if (index > v.size() || index < 0) cout << "�� ������ �� �������"<<endl;
	else {
		show_worker_admin(v, index);
		cout << "������ ������� ������������ ";
		if (v.at(index).access == 0) {
			cout << "������" << endl;
			cout << endl;
			cout << "������ ������� ������? ���� ��,�� ������� 1 " << endl;
			cin >> input;
			if (input == 1 ) {
				v.at(index).access = 1;
				cout << "������ ������" << endl;
			}
			else cout << "������ ������� �������" << endl;
		}
		else {
			cout << "������" << endl;
			cout << endl;
			cout << "������ ������� ������? ���� ��,�� ������� 0" << endl;
			cin >> input;
			if (input == 0 ) {
				v.at(index).access = 0;
				cout << "������ ������" << endl;
			}
			else cout << "������ ������� �������" << endl;
		}
    }

    system("pause");
	system("cls");
}
void work_experience( vector<Worker>& v,int i) {
	SYSTEMTIME t;
	GetLocalTime(&t);
	int day =  t.wDay - v.at(i).start_work.day;
	int mon = t.wMonth - v.at(i).start_work.month;
	int year = t.wYear - v.at(i).start_work.year;
	cout << "����: ";
	if (year % 10 >= 5 || year % 10 == 0 || (year <= 19 && year >= 11)) cout << year << " ��� ";
	else if (year % 10 == 1)cout << year << " ��� ";
	else if (year % 10 <= 4 && year % 10 >= 2)cout << year << " ���� ";

	if (mon == 1)cout << mon << " ����� ";
	if (mon <= 4 && mon >= 2) cout << mon << " ������ ";
	if (mon <= 12 && mon >= 5)cout << mon << " ������� ";

	if (day % 10 >= 5 || day % 10 == 0 || (day <= 19 && day >= 11)) cout << day << " ���� " << endl;
	else if (day % 10 == 1)cout << day << " ����" << endl;
	else if (day % 10 <= 4 && day % 10 >= 2)cout << day << " ��� " << endl;

	v.at(i).work_experience.day = day;
	v.at(i).work_experience.month = mon;
	v.at(i).work_experience.year = year;
}

void date(vector<Worker>&v){
	
	Worker temp;
	int a;
	cout << " �����: ";
    while (true) {
	    a = check_Input();
	    if (!(a < 32 && a>0)) cout << "�� �������� � ������,���������� ��� ��� (��� ����� ���� � 1 �� 31)" << endl;
	    else
	    {
		    temp.birth.day = a;
		    break;
	    }
    }
    cout << " �����: ";
    while (true) {
	     a = check_Input();
	     if (!(a < 13 && a>0)) cout << "�� �������� � ������� ,���������� ��� ��� (�� ����� ���� �� 1 �� 12)" << endl;
	     else
	     {
		     temp.birth.month = a;
		     break;
	     }
    }
    cout << " ���: ";
    while (true) {
	     a = check_Input();
	     if (!(a < 2022 && a>1922)) cout << "�� �������� � ����� ,���������� ��� ��� (�� ����� ���� � 1922 �� 2022)" << endl;
	     else
	     {
		      temp.birth.year = a;
		      break;
	     }
    }
}
int check_Input()
{
	int num;
	while (true)
	{
		cin >> num;
		if (cin.good()) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "�������� ������ ������ �������� ������ �� ����, ���������: " << endl;
		}
	}
	return num;
}
string check_Login() {
	string log;
    int i = 0;
	char*login = new char[20];
	while (true)
	{
		if (i > 18) {
			do {
			login[i] = _getch();
			} while (login[i] != 8 && login[i] != 13);
		}
		else login[i] = _getch();

		if (login[i] == 13 && i > 7) break;
		if (login[i] == 8 && i > 0) {
			cout << "\b \b";
			i--;
			continue;
		}
		if (!((login[i] <= 'Z' && login[i] >= 'A') || (login[i] <= 'z' && login[i] >= 'a') || (login[i] <= '9' && login[i] >= '0') || login[i] == '.'
			|| login[i] == '_' || login[i] == '@' || login[i] == '-')) {
			continue;
		}

		cout << login[i];
		i++;
	}
	login[i] = '\0';
	log = login;
	delete[] login;
	cout << endl;
	return log;
}
string check_Password() {
	char pas[20];
	int i = 0;
	while (true)
	{
		if (i > 18) {
			do {
				pas[i] = _getch();
			} while (pas[i] != 8 && pas[i] != 13);
		}
		else pas[i] = _getch();

		if (pas[i] == 13 && i > 0) break;
		if (pas[i] == 8 && i > 0) {
			cout << "\b \b";
			i--;
			continue;
		}
		if (!((pas[i] <= 'Z' && pas[i] >= 'A') || (pas[i] <= 'z' && pas[i] >= 'a') || (pas[i] <= '9' && pas[i] >= '0') || pas[i] == '.'
			|| pas[i] == '_' || pas[i] == '(' || pas[i] == ')' || pas[i] == '-')) continue;

		cout << pas[i];
		i++;
	}
	pas[i] = '\0';
	cout << endl;
	string pass = pas;
	return pass;
}
string imagen_Password() {
	
	char *pass= new char(20);
	int i = 0,number=0, letter=0,caplet=0;
	string password;
	while (true) {
		number = 0, letter = 0, caplet = 0;
		if (i > 15) {
			do {
				pass[i] = _getch();
			} while (pass[i] != 8 && pass[i] != 13);
		}
		else pass[i] = _getch();

		system("cls");
		cout << "���������� ������,���������� �� ����� 8-�� ��������" << endl;

		for (int j = 0; j < i; j++) { cout << "*"; }
		for (int j = 0; j < i; j++) {
			if (pass[j] <= '9' && pass[j] >= '0') number++;
			if (pass[j] <= 'z' && pass[j] >= 'a')letter++;
			if (pass[j] <= 'Z' && pass[j] >= 'A') caplet++;
			
		}

		if (pass[i] == 13 && number != 0 && letter != 0 && caplet != 0 && i >= 8) break;
		if (pass[i] == 8 && i > 0) {
			cout << "\b \b";
			i--;
			continue;
		}
		if (!((pass[i] <= 'Z' && pass[i] >= 'A') || (pass[i] <= 'z' && pass[i] >= 'a') || (pass[i] <= '9' && pass[i] >= '0')
			|| pass[i] == '.' || pass[i] == '_' || pass[i] == '-' || pass[i] == '(' || pass[i] == ')')) continue;
		if (pass[i] == ' ') continue;

		cout << "*" << endl;

		if (i < 7) cout << "��� ������ ������������,�� ������ ��������� ������ �������� ";
		else {
			if (number != 0 && (caplet == 0 && letter == 0)) cout << "��� ������ ������������, ����������� ����� �������� � ������� ��������";
			else
				if (letter != 0 && (number == 0 && caplet == 0)) cout << "��� ������ ������������, ����������� ����� � ��������� �����";
				else
					if (caplet != 0 && (number == 0 && letter == 0)) cout << "��� ������ ������������, ����������� ����� � �������� �����";
					else
						if ((number != 0 && letter != 0) && caplet == 0) cout << "��� ������ ������������, ����������� ��������� ����� ";
						else
							if ((number != 0 && caplet != 0) && letter == 0) cout << "��� ������ ������������, ����������� �������� ����� ";
							else
								if ((letter != 0 && caplet != 0) && number == 0) cout << "��� ������ ������������, ����������� �����";
								else
									cout << "�� ��������� �������� ������!";
			
		}
		i++;
	}	
	pass[i] = '\0';
	cout << endl;
	password = pass;
	return password;
}
string check_String() {
	
	int i = 0;
	char name[22];
	while (true) {
		if (i > 20) {
			do {
				name[i] = _getch();
			} while (name[i] != 8 && name[i] != 13);
		}
		else name[i] = _getch();
		if (name[i] == 13 && i>1) break;
		if (name[i] == 8 && i > 0) {
			cout << "\b \b";
			i--;
			continue;
		}
		if (!(name[0] <= '�' && name[0] >= '�')) continue;
		if (!( name[i] <= '�' && name[i] >= '�')&& i>0) continue;

		cout << name[i];
		i++;
	}
	name[i] = '\0';
	cout << endl;
    string nam = name;
	return nam;
}
string check_line() {
	string nam;
	int i = 0;
	char name[22];
	while (true) {
		if (i > 20) {
			do {
				name[i] = _getch();
			} while (name[i] != 8 && name[i] != 13);
		}
		else name[i] = _getch();
		if (name[i] == 13 && i > 1) break;
		if (name[i] == 8 && i > 0) {
			cout << "\b \b";
			i--;
			continue;
		}
		if (name[i] == ' ' && name[i-1] == ' ' ) continue;
		if (!((name[i] <= '�' && name[i] >= '�') || (name[i] <= '�' && name[i] >= '�'))) continue;

		cout << name[i];
		i++;
	}
	name[i] = '\0';
	cout << endl;
	nam = name;
	return nam;
}
bool check_individuality(const vector<Worker> v,string log) {
	bool flag = false;
	for (int j = 0; j < v.size(); j++) {
		if (log == v.at(j).login) {
			cout << "������������ � ����� ������� ��� ����������. ���������� ������ �����: ";
			flag = true;
		}
    }
	return flag;
}


bool exit_or_not()
{
	int num ;
	cout << "1 - ����������              0 - �����" << endl;
	cout << "������� 0 ��� 1: ";
	cin >> num;
	cout << endl;
	switch (num)
	{
	case 1:system("cls"); return true;
		break;
	case 2: system("cls"); return false;
		break;
	}


}
