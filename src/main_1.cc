#include <iostream>
using namespace std;
class student {
public:
	student(int age,int name);
	void display() {
		cout << this->age << " " << this->name << endl;
	}
private:
	int age;
	int name;
};
student::student(int age,int name) {
	this->age = age;
	this->name = name;
}
int main() {
	student st(10, 20);
	st.display();
}