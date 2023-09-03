#include <iostream>
#include <string>
using namespace std;
//1
class student {
private:						//Object
	int Age;
protected:
	string Name;
	int skill = 0;
public:
	//student(string name, int age) {	//Constructor
	//	Name = name;
	//	Age = age;
	//}
	string getname(student) {
		return Name;
	}
	virtual void exam() {	//virtual function
		cout << "testing" << endl;
	}
	friend	void getinfo(student);
	friend void operator<<(ostream& COUT, student& st);
	friend void operator>>(istream& CIN, student& st);
};
//===================================================
void getinfo(student st) {
	cout << "name is " << st.Name << endl;
	cout << "age is " << st.Age << endl;
}
//===================================================
void operator<<(ostream& COUT, student& st) {
	COUT << "The name is " << st.Name << endl;
	COUT << "The Age is " << st.Age << endl;
}
//===================================================//operator overloading practice
void operator>>(istream& CIN, student& st) {
	cout << "Name is : ";
	CIN >> st.Name;
	cout << "Age is : ";
	CIN >> st.Age;
}
//===================================================
class artstudent : public student {
private:
	string masterpiece;
public:
	//artstudent(string name, int age, string m) : student(name, age) {
	//	masterpiece = m;
	//}
	void learning() {
		cout << Name << " is painting" << endl;
		skill++;
	}
	void exam() {
		if (skill >= 2)
			cout << "pass" << endl;
		else
			cout << "failed" << endl;
	}
};
//===================================================
int main() {
	//artstudent st2 = artstudent("cindy", 15, "ocean");
//===================================================
	int size;					//input student data during run time using operator overloading 2023/09/03
	cout << "size is : ";
	cin >> size;
	student* st3 = new student[size];	//st3 array created
	for (int i = 0; i < size; i++) {
		cin >> *(st3 + i);
	}
	for (int i = 0; i < size; i++) {
		cout << *(st3 + i);
	}
	//===================================================
	//cout << sizeof(student);
	//getinfo(st2);
	//student* st3 = new artstudent("jack", 14, "cloud");	//pointer
	//st3->exam();

	//cout << st2;		//can be used even in derived func(operator overloading)
	
}
