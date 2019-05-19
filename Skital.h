#pragma once 
#include <vector> 
#include <string> 
#include <map> 

class Swap
{ 
private: 
int kolver; 
int ende;
std::string stroka;
std::string getValidKey(const std::string & s);
int ThatsNotChislo(const int kolver);
public: 
Swap(const int key1, const int ende1, std::string stroka1);
std::string endecrypt(); //шифрование 
};

class cipher_error: public std::invalid_argument {
public:
 explicit cipher_error (const std::string& what_arg):
 std::invalid_argument(what_arg) {}
 };
