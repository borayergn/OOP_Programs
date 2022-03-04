#include <iostream>
#include <fstream>
#include <exception>

using namespace std;
/*
 ***************************************************
 NORMAL CONSTRUCTOR QUESTION
 ***************************************************
class Square{

private:
    int side;

public:
    Square(){

    }
    Square(int side){
        this->side = side;
    }

    ~Square(){
        cout<<endl<<"Destructor";
    }
    int getSide(){return side;}
    void setSide(int side){this->side = side;}

    int calculatePerimeter(){
        return side * 4;
    }
    int calculateArea(){
        return side*side;
    }

};



int main() {
    Square sqr(5);

    cout<<"Perimeter: "<<sqr.calculatePerimeter()<<endl;
    cout<<"Area: "<<sqr.calculateArea();

    return 0;
}

 ***************************************************
 FRIEND CLASS QUESTION
 ***************************************************

class Increment;



class Square{

    friend class Increment;

private:
    int side;

public:
    Square(){

    }
    Square(int side){
        this->side = side;
    }

    ~Square(){

    }
    int getSide(){return side;}
    void setSide(int side){this->side = side;}

    int calculatePerimeter(){
        return side * 4;
    }
    int calculateArea(){
        return side*side;
    }

};

class Increment{
private:
    int incrementSize;

public:
    Increment(){
        cout<<"Enter increment value: ";
        cin>>incrementSize;
    }
    void change(Square sqr){
        sqr.side += incrementSize;
        cout<<"Incremented size: "<<sqr.side;

    }

};

int main(void){

int size;
cout<<"Enter size of Square: ";
cin>>size;

Square square(size);
Increment incObj;
incObj.change(square);



    return 0;
}

********************************
 QUEUE QUESTION
********************************
const string NOT_A_STRING = "";
class Queue{
private:
    string array[100];

public:
    Queue(){
        array[0] = NOT_A_STRING;
    }

    void enqueue(string str);
    string dequeue();
    void peek();
    void display();


};
void Queue::enqueue(string str) {
    for(int i = 0; i<100 ; i++){
        if(array[i] == NOT_A_STRING){
            array[i] = str;
            array[i+1] = NOT_A_STRING;
            break;
        }
    }
}
string Queue::dequeue(){
    string toBeReturned = array[0];
    for(int i = 0 ; i<100 ; i++){
        if(array[i+1] == NOT_A_STRING){
            array[i]=array[i+1];
            break;
        }
        array[i]=array[i+1];
    }
    return toBeReturned;
}

void Queue::peek(){
    cout<<"First element of queue: "<<array[0]<<endl;
}
void Queue::display() {
    cout<<"All elements in queue:"<<endl;
    for(int i = 0 ; array[i] != NOT_A_STRING ; i++){
        cout<<array[i]<<endl;
    }
}

int main(){

    Queue myQueue;

    myQueue.enqueue("Boray");
    myQueue.enqueue("Nazo");
    myQueue.enqueue("Baaa");
    myQueue.display();
    myQueue.peek();
    cout<<"Dequeued element: "<<myQueue.dequeue()<<endl;
    myQueue.display();


    return 0;
}
************************************
COPY CONSTRUCTOR
************************************

class Person{
private:
    string name;
public:
    Person(string name_):name(name_){}

    Person(const Person &p){
        cout<<"Copy Constructor ."<<endl;
        name = p.name + "copy";
    }

    string getName(){return name;}



};

void display(Person p){
    cout<<p.getName()<<endl;
}

int main(){

Person person1("Boray");

Person person2 = person1;

display(person2);









    return 0;
}
*******************************
COMPOSITION
*******************************

class Birthday{
private:
    int month , day , year;
public:
    Birthday(int month_ , int day_ , int year_):month(month_),day(day_),year(year_){}

    void printDate(){
        cout<<month<<"."<<day<<"."<<year<<endl;
    }

    ~Birthday(){
        cout<<"Destroyed: Birth"<<endl;
    }


};

class Person{
private:
    string name;
    Birthday birth;
public:
    Person(string name_ , Birthday birth_):name(name_),birth(birth_){}

    ~Person(){
        cout<<"Destroyed: Person"<<endl;
    }

    void printInfo(){
        cout<<"Name: "<<name<<endl<<"Birthday: ";
        birth.printDate();
    }

};
int main(){

    Birthday birthday1(1,6,2001);
    Person boray("Boray",birthday1);

    boray.printInfo();





    return 0;
}
*************************************************
RETURNING THIS (CHAIN METHOD)
*************************************************


class Operation{
private:
    int value;
public:
    Operation(int value_):value(value_){}

    int getValue(){return value;}

    Operation &add(int num){
        value+=num;
        return *this;
    }
};

int main(){

    Operation opr(5);

    opr.add(2).add(5).getValue();
    cout<<opr.getValue();


}
*************************************************
NORMAL QUESTION
*************************************************


class Employee{
private:
    string name;
    string position;
    double salary;

public:
    Employee()= default;

    Employee(string name_ , string position_ , double salary_):name(name_),position(position_),salary(salary_){}

    string getName(){return name;}
    string getPosition(){return position;}
    double getSalary(){return salary;}

    void setName(string name){ this->name = name;}
    void setPosition(string position){ this->position = position;}
    void setSalary( double salary){this->salary = salary;}

    void updateSalary(double percentage , Employee e , string pos){
       if(e.position == pos){
           salary = salary + (salary*percentage);
       }

    }
};

int main(){

    Employee arr[100];

    Employee boray("Boray" , "Manager" , 5000);
    Employee naz("Naz" , "Manager" , 6000);
    Employee ahmet("Ahmet" , "Amele " , 2500);
    Employee mehmet("Mehmet" , "Çalışan " , 3000);

    arr[0]=boray;
    arr[1]=naz;
    arr[2]=ahmet;
    arr[3]=mehmet;

    for(int i = 0 ; i < 4 ; i++){
        cout<<arr[i].getName()<<": "<<arr[i].getSalary()<<endl;
    }

    for(int i = 0 ; i < 4 ; i++){
        arr[i].updateSalary(0.50 , arr[i] , "Manager");
    }

    for(int i = 0 ; i < 4 ; i++){
        cout<<arr[i].getName()<<": "<<arr[i].getSalary()<<endl;
    }

}
***********************************
AGGREGATION
***********************************


class Address{

private:
    string addressLine , city , state;

public:
    Address()= default;

    Address(string addressLine_ , string city_ , string state_):addressLine(addressLine_), city(city_) , state(state_){}

    void showAddress(){
        cout<<addressLine<<endl<<city<<endl<<state;
    }

};


class Employee{
private:
    Address address;
    int id;
    string name;

public:

    Employee() = default;

    Employee( Address &address , int id , string name){
        this->address = address;
        this->name = name;
        this->id = id;
    }

    void display(){
        cout<<"Name: "<<name<<endl<<"ID: "<<id<<endl<<"Address: ";
        address.showAddress();
        cout<<endl;
    }


};


int main(){

    Address myAddress("Portakal cicegi sokak" , "Ankara" , "Aziziye Mahallesi");
    Employee boray(myAddress , 2024 , "Boray");
    boray.display();


}
***********************************************
STATIC VARIABLE AND FUNCTION
***********************************************


class Cube{

private:
    double length;
    double breadth;
    double height;
    static int objectCounter;

public:

    Cube(){
        objectCounter++;
    }

    Cube(double length_ , double breadth_ , double height_):length(length_) , breadth(breadth_) , height(height_){
        objectCounter++;
    }


    static int getObjectCounter(){
        return objectCounter;
    }
    int volume(){

        return length * breadth * height;

    }

};

int Cube::objectCounter = 0;



int main(){

    Cube cube1(3.3, 2.2, 1.1);
    Cube cube2(5.5, 6.0, 7.0);

    cout<<"Cube 1: "<<cube1.volume()<<endl<<"Cube 2: "<< cube2.volume()<<endl;
    cout<<Cube::getObjectCounter()<<endl;

}

****************************************************************************
 STRING CLASS MANIPULATION (MEMBER OPERATOR OVERLOAD OF -)
****************************************************************************



class MyString{

private:
    string sentence;
    int a;

public:

     MyString(string sentence_):sentence(sentence_){}
     MyString()=default;

     void print(){
         cout<<sentence<<endl;
     }
     MyString operator-(int s){
     return MyString(this->sentence.substr(0,this->sentence.length()-s));
     }


};

int main (){

MyString string1("My new string");
string1.print();
MyString string2 = string1 - 6;
string2.print();
}

**************************************************************
 OPERATOR OVERLOAD (INPUT OUTPUT AS FRIEND.)
**************************************************************


class Math{
private:
    int num1 , num2 , result;
public:

    Math()=default;

    void sum(){
        result = num1 + num2;
    }
    void subs(){
        result = num1 - num2;
    }
    void multiply(){
        result = num1 * num2;
    }

    friend istream& operator>>(istream &input,Math &obj);
    friend ostream& operator<<(ostream &output , Math &obj);

};

istream& operator>>(istream &input,Math &obj){
    input>>obj.num1>>obj.num2;

    return input;

}
ostream& operator<<(ostream &output , Math &obj){
    output<<obj.result<<endl;

    return output;

}

int main(){

    Math board1;

    cin>>board1;

    Math board2;

    cin>>board2;

    Math board3;

    cin>>board3;

    board1.sum();
    board2.subs();
    board3.multiply();

    cout<<board1<<board2<<board3;
}
**************************************************************
POLYMORPHISM AND INHERITANCE
**************************************************************




#include <iostream>

using namespace std;

class Shape
{
protected:
    int locX,locY;
public:
    Shape(int x=0,int y=0){locX=x;locY=y;}
    virtual void print()
    {
        cout<<"Shape Coordinates ("<<locX<<"-"<<locY<<")"<<endl;
    }
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(int x=0, int y=0, int r=0):Shape(x,y){radius=r;}
    void print()
    {
        cout<<"Circle Coordinates ("<<locX<<"-"<<locY<<") and it's radius is "<<radius <<endl;
    }
    int getRaidus(){return  radius;}
};

class Rectangle : public Shape
{
private:
    int height, width;
public:
    Rectangle(int x=0, int y=0, int h=0, int w=0):Shape(x,y){height=h;width=w;}

    void print()
    {
        cout<<"Rectangle Coordinates :("<<locX<<"-"<<locY<<") ("<< width <<"-"<< height << ")" <<endl;
    }

};

// will print any object, as long as it is derived from Shape class
void reportShapes(Shape *p)
{
    p->print();
}


int main ()
{
    Circle bCirc(1,2,3);

    Shape *circle = new Circle(1,2,3);
    Shape *rectangle = new Rectangle(2,1,6,4);


    Shape *arr[2] = {circle , rectangle};

    // Main usage of polymorphism in terms of practical situations.
    //SAME ARRAY and same for loop but different functions.
    for(int i = 0 ; i<2 ; i++){
        reportShapes(arr[i]);
    }

   

    //   vShape = vRect;
    // reportShapes(&vShape);
    return 0;
}

****************************************
 MULTIPLE INHERITANCE
****************************************


class Student{
private:
    int studentId;

public:
  Student(int ID):studentId(ID){}
  int getID(){return studentId;}

};

class Teacher{

private:
    int registirationId;

public:
    Teacher(int ID):registirationId(ID){}
    int getRID(){return registirationId;}

};

class Assistant:public Student,public Teacher{

public:
    Assistant(int ID ,int RID): Student(ID), Teacher(RID){}
};

int main(){

    Assistant ast(9753,987);

    cout<<"Student ID: "<<ast.getID()<<endl<<"Registiration ID: "<<ast.getRID()<<endl;


    return 0;
}

********************************************************
 CUSTOM STACK STRUCTURE WITH TEMPLATE
********************************************************


template <typename T>

    class Stack{

    private:
        int size , top;
        T *stack;


    public:
        Stack(int arrSize){
            size = arrSize;
            stack = new T [size];
            top = -1;
        }
        ~Stack(){
            delete [] stack;
        }
        void push(T obj){
            stack[top + 1] = obj;
            top++;
        }
        void pop(){
            stack[top] = NULL;
            top--;
        }
        void isEmpty(){
            top == -1 ? cout<<"Stack is empty"<<endl : cout<<"Stack is not empty"<<endl;
        }
        void isFull(){
            top == size-1 ? cout<<"Stack is full"<<endl : cout<<"Stack is not full"<<endl;
        }
        void showStack(){
            if(top == -1){
                cout<<"Cant show the stack. Stack is empty.";
            }
            else{
                cout<<"Showing the stack..."<<endl<<endl;

                for(int i = 0 ; i<top+1 ; i++){
                    cout<<stack[i]<<endl;
                }

                cout<<endl<<"End of stack."<<endl<<endl;
            }
            }



    };


int main(){

    Stack <int> intStack(4);
    Stack <char> charStack(5);


    intStack.push(5);
    intStack.push(2);
    intStack.push(30);
    intStack.push(-9);

    charStack.push('i');
    charStack.push('d');
    charStack.push('i');
    charStack.push('l');


    intStack.isFull();
    intStack.showStack();

    charStack.isFull();
    charStack.showStack();

    for(int i = 0 ; i < 4 ; i++){
        intStack.pop();
    }

    intStack.showStack();
    intStack.isEmpty();




    return 0;
}

*************************************************
 POLYMORPHISM AND ABSTRACTION
*************************************************


class CompanyEmployees{

protected:
   string fullName;
   int age;

public:
   CompanyEmployees(string name , int age){
       fullName = name;
       this->age = age;
   }
   virtual ~CompanyEmployees(){
       cout<<fullName<<" Has left the job at age of "<<age<<endl;
   }
   string getName(){return  fullName;}

   int getAge(){return age;}

   virtual float calcSalary() = 0;

};

class Managers : public CompanyEmployees{

private:
   int rank;

public:
   Managers(string name , int age_ , int rank_): CompanyEmployees(name,age_),rank(rank_){}

   ~Managers(){
       cout<<fullName<<" has left the Management Department at the age of"<<age<<endl;
   }

   float calcSalary() override{
       float salary = 5000;
       salary += (salary * (float(rank) / 100));

       return salary;
   }

};

class Employees : public CompanyEmployees{


private:
   int year;

public:

   Employees(string name , int age_ , int year_): CompanyEmployees(name,age_),year(year_){}

   ~Employees(){
       cout<<fullName<<" has left being employee at the age of "<<age<<endl;
   }

   float calcSalary() override{
       float salary = 2000;

       int reminder = static_cast<int>(year / 5);

       salary += reminder * 1000;

       return salary;

   }

};

void display(CompanyEmployees &obj){
   cout<<"Name:"<<obj.getName()<<", Age:"<<obj.getAge()<<", Salary"<<obj.calcSalary()<<endl;
}

int main(){


   CompanyEmployees *employeeArray[2];

   CompanyEmployees *kobe = new Managers("Kobe Bryant" , 42 , 3);
   CompanyEmployees *steph = new Employees("Stephen Curry" , 32 , 12);

   employeeArray[0] = kobe;
   employeeArray[1] = steph;

   for(int i = 0 ; i < 2 ; i++){

       display(*employeeArray[i]);

   }
   for (int i = 0 ; i<2 ; i++){
       delete employeeArray[i];
   }

   return 0;
}

**********************************
 FILE HANDLING
*********************************

int main(){

    ofstream myFileO("idil.txt");
    if(myFileO.is_open()){
        myFileO<<"Borayin yasi: "<<21<<endl;
        myFileO<<"Idilin yasi: "<<20<<endl;
        myFileO.close();
    }
    else
        cout<<"File can not be opened!"<<endl;

    ifstream myFileIn("idil.txt");
    int num , sum = 0 ;
    string temp;
    while(true){

        myFileIn>>num;
        myFileIn.get();
        if(myFileIn.eof())
            break;
        sum += num;
    }


    cout<<"Sum: "<<sum<<endl;







    return 0;
}


***************************************
EXCEPTION HANDLING
***************************************

class NegativeError : public exception{

private:
    string msg;

public:
    NegativeError(string msg_):msg(msg_){}

    string what(){
        return msg;
    }
};

class OverFlow : public exception{
private:
    string msg;

public:
    OverFlow(string msg_):msg(msg_){}

    string what(){
        return msg;
    }
};

int main(){

    int num1 , num2;


    try{

        double result;

        cin>>num1>>num2;


        if (num2 < 0){
            throw NegativeError("second number can not be negative.");
        }
        if(num2 == 0){
            throw runtime_error("Please enter a number other than zero");
        }
        if (num1 > 100){
            throw OverFlow("Number is too large");
        }

        result = num1 / num2;
        cout<<result;

    }catch(runtime_error a){
        cout<<"Error occured!!! Error Code: "<<a.what()<<endl;
        while(num2 == 0){
            cout<<"Please enter a valid value"<<endl;
            cin>>num2;
        }
        int newResult;
        newResult = num1 / num2;
        cout<<newResult<<endl;
    }
    catch(NegativeError obj){
        cout<<"Error: "<<obj.what()<<endl;
    }


    return 0;
}



 */


