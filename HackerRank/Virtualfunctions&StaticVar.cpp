//https://www.hackerrank.com/challenges/virtual-functions/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person{
protected:
    string name;
    int age;
public:
    virtual void getdata(){};
    virtual void putdata(){};
};

class Professor : public Person {
public :
    int publications, cur_id;
    static int static_cur_id;
    Professor(){
        cur_id=static_cur_id++;
        };
    void getdata(){
        cin >> name >> age >> publications;
        }
    void putdata(){
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

class Student : public Person {
public:
    int marks[6] , totalmarks, cur_id;
    static int static_cur_id;
    Student(){
        cur_id=static_cur_id++;
        };
    void getdata(){
        cin >> name;
        cin >> age;
        for (int i : marks){
            int input; cin >>input;
            marks[i] = input; totalmarks += input;
        }
    }
    void putdata(){
        cout << name << " " << age << " " << totalmarks << " " << cur_id << endl;
    }
};

int Professor::static_cur_id = 1;
int Student::static_cur_id = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

