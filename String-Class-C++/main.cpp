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
        //str[strlen(val)] = '\0';
        
        cout << "The string passed is: " << str << endl;
    
    }
}

//Implementing the copy constructor
MyString::MyString(const MyString& source)
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    //str[strlen(source.str)] = '\0';
}

//Implementing move constructor : transfers ownership from an rvalue object (source)
MyString::MyString(MyString&& source)
{
    str = source.str; //Transfer ownership of the resource from source
    source.str = nullptr; //Nullify source pointer to prevent double deletion
}

int main(int argc, const char * argv[]) {
    
    MyString a; //Create a MyString object using the default constructor
    
    char temp[] = "Hello"; //Create a character array initialized with the string "Hello"
    
    MyString b{ temp }; // // Initialize MyString object b using the constructor with a C-style string
    
    return 0;
}
