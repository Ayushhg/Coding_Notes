#include<iostream>
using namespace std;

//basic syntax to define a class
class student{
    //you should make a class public if you want to add/access elements out of the class definition, otherwise it will be
    //default.
    //if you write any data member before public, it will be private by default.
    //now for example you have a private attribute in your class
    //and you want to make it private then you will define a seperate
    //function.
    //string name;
    public:
    string name;
    int age;
    bool gender;
    static int ClassToComplete;//static keyword use

    student(){
        cout<<"Default Constructor"<<endl;
    }//default constructor

    student(string s, int a, bool g){
        cout<<"Parameterised Constructor"<<endl;
        name=s;
        age=a;
        gender=g;
    }//constructor (Parameterised Constructor)

    student(student &a){
        //there is also a default copy constructor
        //but the problem it is shallow copy constructor
        //i.e. it does not copy memory locations as well
        //that's why we define our own copy constructor
        //DEEP COPY CONSTRUCTOR
        cout<<"Copy Constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }//copy constructor

    ~student(){//Destructor
        cout<<"Destructor Called!"<<endl;
    }

    //here is the function to use a private class:
    //this is a set function to set something in the class.
    void setName(string s){
        name=s;
    }

    //now to get someting from a private class object
    //we will define a get function!
    void getName(){
        cout<<name<<endl;
    }
    void printInfo(){
        cout<<"Name = ";
        cout<<name<<endl;
        cout<<"Age = ";
        cout<<age<<endl;
        cout<<"Gender = ";
        cout<<gender<<endl;
    }

    bool operator == (student &a){
        if(name==a.name && age==a.age && gender==a.gender){
            return true;
        }
        return false;
    }
};
//do add a terminator after class defining.

int student::ClassToComplete = 5;//Intitializing Static Object
//:: is scope resolution operator
//IT DOES NOT REQUIRED TO CREATE AN OBJECT TO USE A STATIC DATA MEMBER

int main(){
//defining an array of class datatype including objects
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     //for example name is a private class attribute
    //     string s; //to take s as input
    //     //cin>>s; //taking s input
    //     //arr[i].setName(s); we access private name using this function. 
    //     cout<<"Name: ";
    //     cin>>arr[i].name;
    //     cout<<"Age: ";
    //     cin>>arr[i].age;
    //     cout<<"Gender: ";
    //     cin>>arr[i].gender;
    // }

    // for(int i=0;i<3;i++){
    //     arr[i].printInfo();
    // }

    /* student a;
    a.name = 'Ayush';
    a.age = 18;
    a.gender = 0; */
    //alternative method to define a object in a class

    //WHAT IF WE WANT TO ADD A OBJECT NAME AS A STUDENT NAME?
    //WE WILL USE A CONSTRUCTOR
    student a("Ayush",18,0);
    //a.getName();
    //a.printInfo();
    student b;//as b does not exist it will return default constructor
    student c = a;//copy constructor

    cout<<student::ClassToComplete<<endl;//static member call - best method
    //A static function can only access static member simple!

    if(c==a){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"notSame"<<endl;
    }
    return 0;
}