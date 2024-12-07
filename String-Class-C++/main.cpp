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




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
