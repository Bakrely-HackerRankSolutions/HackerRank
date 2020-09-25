//https://www.hackerrank.com/challenges/box-it/problem?h_r=next-challenge&h_v=zen
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

