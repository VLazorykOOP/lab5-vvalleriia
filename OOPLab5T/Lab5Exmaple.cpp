#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void ShowTaskMenu() {
	cout << "Exersices" << endl;
	cout << "1. Task 1" << endl;
	cout << "2. Task 2" << endl;
	cout << "3. Task 3" << endl;
}
	/*Створити клас людина, що має поля: ПІБ(прізвище, ім'я, по-батькові), вік,
	вага. Визначити конструктори, деструктор і функцію друку. Створити похідний клас
	- школяр, що має поле клас (рік навчання). Визначити конструктори за
	замовчуванням і з різним числом параметрів, деструктори, функцію друку.
	Визначити функції перепризначення віку й класу. Написати програму тестування всіх
	можливостей цього класу.*/
	struct PIB
	{
		string fname;
		string name;
		string lname;
		PIB() {
			fname = "NoFirstName";
			name = "NoName";
			lname = "NoLastName";
			cout << "Default constructor PIB \n";
		}
		PIB(string fn) {
			fname = "NoFirstName";
			name = fn;
			lname = "NoLastName";
			cout << "Constructor PIB(string fn) \n";
		}
		PIB(string fn[3]) {
			fname = fn[0];
			name = fn[1];
			lname = fn[2];
			cout << "Constructor PIB(string fn[]) \n";
		}
		PIB(const PIB& s) {
			fname = s.fname;
			name = s.name;
			lname = s.lname;
			cout << "Constructor Copy PIB(const PIB &) \n";
		}
		PIB(PIB&& s) {
			fname = s.fname;
			name = s.name;
			lname = s.lname;
			cout << " Constructor Move PIB(PIB &&) \n";
			s.fname = "NoFirstName";
			s.name = "NoName";
			s.lname = "NoLastName";
		}
		PIB(const char* fn, const char* n, const char* ln) {
			fname = fn;
			name = n;
			lname = ln;
			cout << " Constructor  PIB(const char * ... ) \n";
		}
		~PIB() {
			cout << "Destructor ~PIB() \n";
		}
		PIB& operator=(const PIB& s)
		{
			fname = s.fname;
			name = s.name;
			lname = s.lname;
			cout << " PIB operator=(PIB &) \n";
			return *this;
		}

		string toString() {
			string ts = "PIB: " + fname + "  " + name + "  " + lname + " ";
			return ts;
		}
		bool operator==(PIB& b) {
			return 	name == b.name &&
				fname == b.fname && lname == b.lname ? true : false;

		}
		void Input() {
			cout << "Input fname "; cin >> fname;
			cout << "Input name ";  cin >> name;
			cout << "Input lname "; cin >> lname;
		}
		friend ostream& operator<<(ostream& os, PIB& a);
		friend istream& operator>>(istream& os, PIB& a);
	};

	ostream& operator<<(ostream& os, PIB& a) {
		os << a.fname << endl;
		os << a.name << endl;
		os << a.lname << endl;
		return os;
	}
	istream& operator>>(istream& is, PIB& a) {
		is >> a.name;
		is >> a.fname;
		is >> a.lname;
		return is;
	}



	class Person
	{
	protected:
		int age, weight;
		PIB name;
	public:
		Person() {
			age = 0;
			weight = 0;
			cout << " Default constructor   Person() \n";
		}
		Person(int a, int w, string n) {
			age = a;
			weight = w;
			name = n;
			cout << " Constructor  Person(int a, int w, string n) \n";
		}
		Person(int a, int w, PIB& n) {
			age = a;
			weight = w;
			name = n;
			cout << " Constructor  Person(int a, int w, PIB n) \n";
		}
		~Person()
		{
			cout << "\tDestructor Person\n";
		}
		void setAge(int a) {
			if (a >= 0 && a <= 200)
				age = a;
			else
				cout << "Age " << a << " not allow,  age is " << age << endl;;
		}
		void setWeight(int w) {
			if (w <= 0 || w > 300)
				weight = w;
			else
				cout << "Weight " << w << " not exist,  weight is " << weight << endl;;
		}
		string toString() {
			string r, a, w;
			a = to_string(age);
			w = to_string(weight);
			r = name.toString() + " age: " + a + " weight: " + w;
			return r;
		}
		void Input() {
			name.Input();
			cout << "Input age ";  while (!(cin >> age) || (age < 0 || age > 200)) {
				cin.clear();
				cin.ignore(MAXSHORT, '\n');
				fflush(stdin);
				cout << "bad  input age is 1 to 200 \n";
			};
			cout << "Input weight ";  while (!(cin >> weight) || (weight < 0 || weight > 300)) {
				cin.clear();
				cin.ignore(MAXSHORT, '\n');
				fflush(stdin);
				cout << "bad  input weight is 1 to 300 \n";
			};
		}

		friend ostream& operator<<(ostream& os, Person& a);
		friend istream& operator>>(istream& os, Person& a);
	};

	ostream& operator<<(ostream& os, Person& a) {
		os << a.name;
		os << a.age << endl;
		os << a.weight << endl;
		return os;
	}
	istream& operator>>(istream& is, Person& a) {
		is >> a.name;
		is >> a.age;
		is >> a.weight;
		return is;
	}

	class Schoolchild : public Person {
	protected:
		int form;
	public:
		Schoolchild() {
			form = 0;
			cout << " Default constructor  Schoolchld() \n";
		}
		Schoolchild(int a, int w, string n, int i) :
			Person(a, w, n) {
			form = i;
			cout << " Constructor Schoolchild (int a, int w, string n, int i) \n";
		}
		Schoolchild(int a, int w, PIB& pib, int i) :
			Person(a, w, pib) {
			form = i;
			cout << " Constructor  Schiilchild (int a, int w, PIB& pib, int i) \n";
		}
		~Schoolchild() {
			cout << "\tDestructor Schoolchild\n";
		}

		void setForm(int i) {
			if (i > 0) 	form = i;
			else form = 0;
		}
		string toString() {
			string form;
			string s = Person::toString() + " FORM: " + s + ".\n ";
			return s;
		}
		void Input() {
			Person::Input();
			cout << "Input Form ";
			while (!(cin >> form) || form < 0) {
				cin.clear();
				cin.ignore(MAXSHORT, '\n');
				fflush(stdin);
				cout << "bad  input ID  \n";
			};
		}
		void Output() {
			cout << toString() << endl;
		}

		friend ostream& operator<<(ostream& os, Schoolchild& a);
		friend istream& operator>>(istream& os, Schoolchild& a);
	};

	ostream& operator<<(ostream& os, Schoolchild& a) {
		os << a.name;
		os << a.age << endl;
		os << a.weight << endl;
		os << a.form << endl;
		return os;
	}
	istream& operator>>(istream& is, Schoolchild& a) {
		is >> a.name;
		is >> a.age;
		is >> a.weight;
		is >> a.form;
		return is;
	}

	void exercise1() {
		int choice = 0;
		do {
			cout << "Choose an option:" << endl;
			cout << "1. Create a person and a student, and test their functionality" << endl;
			cout << "2. Create windows and test their functionality" << endl;
			cout << "3. Create students and test their functionality" << endl;
			cout << "4. Exit" << endl;
			cin >> choice;

			switch (choice) {
			case 1: {
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				cout << "Exiting program" << endl;
				break;
			}
			default: {
				cout << "Invalid option. Try again." << endl;
				break;
			}
			}
		} while (choice != 4);
	}

	/*Використовуючи ієрархію та спадкування, створити класи вікна, вікна із
	заголовком і вікна із кнопкою.*/


	class Window {
	public:
		int width;
		int height;
		bool isMaximized;
		Window(int w, int h) : width(w), height(h), isMaximized(false) {}
		void maximize() {
			isMaximized = true;
		}
		void minimize() {
			isMaximized = false;
		}
		virtual void print() {
			cout << "Window - width: " << width << ", height: " << height << ", maximized: " << isMaximized << endl;
		}
	};

	class TitledWindow : public Window {
	public:
		string title;
		TitledWindow(int w, int h, string t) : Window(w, h), title(t) {}
		void setTitle(string newTitle) {
			title = newTitle;
		}
		void print() override {
			cout << "Titled window - width: " << width << ", height: " << height << ", maximized: " << isMaximized << ", title: " << title << endl;
		}
	};

	class ButtonWindow : public TitledWindow {
	public:
		string buttonText;
		ButtonWindow(int w, int h, string t, string bt) : TitledWindow(w, h, t), buttonText(bt) {}
		void setButtonText(string newButtonText) {
			buttonText = newButtonText;
		}
		void onClick() {}
		void print() override {
			cout << "Button window - width: " << width << ", height: " << height << ", maximized: " << isMaximized << ", title: " << title << ", button text: " << buttonText << endl;
		}
	};

	void exersice2() {
		cout << "Creating a window:" << endl;
		Window window(800, 600);
		window.print();
		cout << endl;

		cout << "Creating a titled window:" << endl;
		TitledWindow titledWindow(800, 600, "My Title");
		titledWindow.print();
		cout << endl;

		cout << "Creating a button window:" << endl;
		ButtonWindow buttonWindow(800, 600, "My Title", "OK");
		buttonWindow.print();
		cout << endl;
	}
	/*Створити ієрархію класів студент і студент дипломник. Перевизначити
	вивід у потік і введення з потоку, конструктор копіювання, оператор присвоювання
	через відповідні функції базового класу.*/

	class Student {
	protected:
		string name;
		int age;
		float averageScore;
	public:
		Student() : name(""), age(0), averageScore(0) {}
		Student(string n, int a, float s) : name(n), age(a), averageScore(s) {}
		virtual ~Student() {}
		virtual void print() {
			cout << "Student: " << name << ", Age: " << age << ", Average Score: " << averageScore << endl;
		}
		friend istream& operator>>(istream& in, Student& s) {
			cout << "Enter student name: ";
			in >> s.name;
			cout << "Enter student age: ";
			in >> s.age;
			cout << "Enter student average score: ";
			in >> s.averageScore;
			return in;
		}
		Student(const Student& other) {
			name = other.name;
			age = other.age;
			averageScore = other.averageScore;
		}
		Student& operator=(const Student& other) {
			if (this != &other) {
				name = other.name;
				age = other.age;
				averageScore = other.averageScore;
			}
			return *this;
		}
	};

	class GraduateStudent : public Student {
	private:
		string thesisTitle;
	public:
		GraduateStudent() : Student(), thesisTitle("") {}
		GraduateStudent(string n, int a, float s, string t) : Student(n, a, s), thesisTitle(t) {}
		~GraduateStudent() {}
		void print() override {
			cout << "Graduate Student: " << name << ", Age: " << age << ", Average Score: " << averageScore << ", Thesis Title: " << thesisTitle << endl;
		}
		friend istream& operator>>(istream& in, GraduateStudent& s) {
			cout << "Enter graduate student name: ";
			in >> s.name;
			cout << "Enter graduate student age: ";
			in >> s.age;
			cout << "Enter graduate student average score: ";
			in >> s.averageScore;
			cout << "Enter graduate student thesis title: ";
			in >> s.thesisTitle;
			return in;
		}
		GraduateStudent(const GraduateStudent& other) : Student(other) {
			thesisTitle = other.thesisTitle;
		}
		GraduateStudent& operator=(const GraduateStudent& other) {
			if (this != &other) {
				Student::operator=(other);
				thesisTitle = other.thesisTitle;
			}
			return *this;
		}
	};

	void exercise3() {
		Student s1("Anna Semeniuk", 20, 85.6);
		s1.print();
		cout << endl;

		GraduateStudent g1("Laura Kuziak", 25, 92.3, "Exploring the Applications of AI in Healthcare");
		g1.print();
		cout << endl;

		GraduateStudent g2;
		cin >> g2;
		g2.print();
		cout << endl;

		GraduateStudent g3 = g1;
		g3.print();
		cout << endl;

		g3 = g2;
		g3.print();
		cout << endl;
	}


	int main()
	{
		bool isSelected = false;
		while (!isSelected) {
			system("cls");
			ShowTaskMenu();
			int ch;
			cin >> ch;
			switch (ch) {
			case 1:
				//exersice1();
				isSelected = true;
				break;
			case 2:
				//exersice2();
				isSelected = true;
				break;
			case 3:
				//exersice3();
				isSelected = true;
			default:
				break;
			}
		}
		return 0;

	}
	int main() {
		int a;
		cout << "Exercise: ";
		cin >> a;
		switch (a) {
		case 2: exersice2(); break;
		case 3: exercise3(); break;
		}

		return 0;
	}

