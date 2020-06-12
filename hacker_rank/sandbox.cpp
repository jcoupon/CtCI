#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

class Person{

    public: 
        int age; 
        //Person(int);
        virtual void sayHi(){
            std::cout << "Hi I am a person" << endl;
        };
        virtual ~Person(){

            std::cout << "Deleting person..." << endl;

        }
};

//Person::Person(int a){
//    age = a;
//}

class Student: public Person{

    public:
        int age; 
        //Student(int);
        void sayHi(){
            std::cout << "Hi" << endl;
        }
        ~Student(){

            std::cout << "Deleting..." << endl;

        }

};

//Student Student::operator+(Student &other){
//    return age + other.age;
//}

//Student::Student(int a){
//    age = a;
//}



vector<int> parseInts(string str) {
	// Complete this function

    std::stringstream ss(str);
    std::vector<int> result;
    int n;
    char c;
    //string n;

    while(ss >> n){
        std::cout << n << endl;
        result.push_back(n);
        ss >> c;
    }

    return result;
}

void default_par(int a, int b = 10, int c = 20){


    std::cout << a << ' ' << b << ' ' << c << endl;

    return;

}

void test(){


    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

}

int main() {

    Person * p1 = new Student();
    Person * p2 = new Student();

    Person * p3 = new Student();

    p1->age = 21;
    p2->age = 22;

    // *p3 = *p1 + *p2;

    std::cout << p3->age << endl;

    delete p1;
    delete p2;

    
    return 0;
}