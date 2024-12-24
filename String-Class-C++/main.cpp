//
//  main.cpp
//  String-Class-C++
//
//  Created by MEDLAO on 04/12/2024.
//
#include <cstring>
#include <iostream>
using namespace std;


//Custom string class
class MyString {
    //Initialize the char array
    char* str;
    
public:
    //No arguments constructor
    MyString();
    
    //Constructor with one argument
    MyString(char* val);
    
    //Copy constructor
    MyString(const MyString& source);
    
    //Move constructor
    MyString(MyString&& source);
    
    //Destructor
    ~MyString() {delete str;}
    
    //Stream insertion operator declaration
    friend ostream& operator<<(ostream& os, const MyString& obj);
    
    //Prototype for stream extraction
    friend istream& operator>>(istream& is, MyString& obj);
    
    //Declare operator+ to concatenate MyString objects
    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    
    //Declare the assignment operator
    MyString& operator=(const MyString& rhs);
    
    //pop_back() function
    void pop_back();
    
    //push_back() function
    void push_back(char a);
};

//Default constructor: Initializes the MyString object with an empty string
MyString::MyString()
    : str{nullptr}
{
    str = new char[1]; //Allocate memory for 1 character
    str[0] = '\0'; //Set the first character to the null terminator (empty string)
    
}

//Implementing the constructor with one argument
MyString::MyString(char* val)
{
    if (val == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
    
    else {
        //Dynamically allocate memory for the string, including the null terminator
        str = new char[strlen(val) + 1];
        
        strcpy(str, val); //Copy the string from val to str
        str[strlen(val)] = '\0';
        
        //cout << "The string passed is: " << str << endl;
    
    }
}

//Implementing the copy constructor
MyString::MyString(const MyString& source)
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    str[strlen(source.str)] = '\0';
}

//Implementing move constructor : transfers ownership from an rvalue object (source)
MyString::MyString(MyString&& source)
{
    str = source.str; //Transfer ownership of the resource from source
    source.str = nullptr; //Nullify source pointer to prevent double deletion
}

//Overloading the assignment operator
MyString& MyString::operator=(const MyString& rhs)
{
    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

//Overloading the stream insertion operator
ostream& operator<<(ostream& os, const MyString& obj)
{
    os << obj.str;
    return os;
}

// Overloading the stream extraction operator
istream& operator>>(istream& is, MyString& obj)
{
    //Dynamically allocate memory for a temporary buffer to store input
    char* buff = new char[1000];
    //Safely read input into the buffer
    is.getline(buff, 1000);
    //Assign the buffer content to the MyString object
    obj = MyString{ buff };
    //Free the dynamically allocated buffer
    delete[] buff;
    //Return the input stream for chaining
    return is;
}

//Implementation of pop_back()
void MyString::pop_back()
{
    int length = strlen(str);
    char* buff = new char[length];
    
    //Copy character from str to buff[]
    for (int i = 0; i < length - 1; i++) {
        buff[i] = str[i];
        buff[length - 1] = '\0';
    }
    
    //Update the current object with the new string stored in buff
    *this = MyString{ buff };
    
    delete[] buff;
}

//Implementation of push_back()
void MyString::push_back(char a)
{
    int length = strlen(str);
    
    char* buff = new char[length + 2];
    
    for (int i = 0; i < length; i++) {
        buff[i] = str[i];
    }
    
    buff[length] = a;
    buff[length + 1] = '\0';
    
    *this = MyString{ buff };
    
    delete[] buff;
    
}

int main(int argc, const char * argv[]) {
    
    MyString a; //Create a MyString object using the default constructor
    
    char temp[] = "Hello"; //Create a character array initialized with the string "Hello"
    
    MyString b{ temp }; //Initialize MyString object b using the constructor with a C-style string
    
    //Copy constructor
    MyString c{ a };
    
    char temp1[] = "World";
    
    //Create MyString object d by moving a temporary object (calls the move constructor)
    MyString d{ MyString( temp ) };
    
    cout << "MyString b: " << b << endl;
    
    //Remove last character from MyString b
    b.pop_back();
    
    cout << "MyString b: " << b << endl;
    
    //Append last character
    b.push_back('o');
    
    cout << "MyString b: " << b << endl;
    
    return 0;
}
