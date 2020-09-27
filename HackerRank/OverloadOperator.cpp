//https://www.hackerrank.com/challenges/box-it/problem
#include <iostream>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box
class Box
{
private:
    int l,b,h;
public:
    Box();
    Box(int,int,int);
    Box(const Box&);

    int getLength(); // Return box's length
    int getBreadth (); // Return box's breadth
    int getHeight ();  //Return box's height
    long long CalculateVolume(); // Return the volume of the box
    bool operator<(Box& b); //Overload operator < as specified
    friend ostream& operator<<(ostream& out, Box& B); //Overload operator << as specified
  
};

Box::Box(){
    this->l = 0;
    this->b = 0;
    this->h = 0;
}

Box::Box(int l, int b, int h){
    this->l = l;
    this->b = b;
    this->h = h;
}

Box::Box(const Box &B){
    this->l = B.l;
    this->b = B.b;
    this->h = B.h;
}

bool Box::operator <(Box& b){
    if((this->l < b.l)||(this->l == b.l && this->b < b.b)||
    (this->l == b.l && this->b ==b.b && this->h < b.h)) return true;
    else return false;
}

int Box::getLength(){
    return this->l;
} // Return box's length
int Box::getBreadth (){
    return this->b;
} // Return box's breadth
int Box::getHeight (){
    return this->h;
}  //Return box's height
long long Box::CalculateVolume(){
    long long v = (l*b);
    v *= h;
    return v;
} // Return the volume of the box

ostream& operator<<(ostream& out, Box& B){
    return cout << B.l << " " << B.b << " "<< B.h << " ";
}


void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}



// https://www.hackerrank.com/challenges/operator-overloading/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Matrix{
    public:
    vector<vector<int>> a;
    Matrix operator+(Matrix& A){
        if(this->a.size() != A.a.size()){
            cout<< "Non equal dimensions: Addition not defined" << endl;
            exit(0);
        }
        Matrix result;
        for(int i = 0;i<this->a.size();i++){
            vector<int> b;
            int add;
            for(int j=0;j<this->a[i].size();j++) {
                add = (this->a[i][j] + A.a[i][j]);
                b.push_back(add);
            }
            result.a.push_back(b);
        }
        return result;
    }
};
int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }
   return 0;
}




//https://www.hackerrank.com/challenges/overload-operators/problem

//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};
//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
Complex operator +(Complex& a,Complex& b){
    Complex z;
    z.a = a.a + b.a; z.b =a.b + b.b;
    return z;
};
// "<<" should print a complex number in the format "a+ib
ostream& operator<< (ostream& out, Complex& b){
    return cout << b.a <<"+i"<<b.b<< endl;
};


int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}

