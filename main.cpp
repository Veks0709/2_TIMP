#include <iostream>
#include "Skital.h"
#include <string>
using namespace std;

void checkskit(const string Text, const int key, const int chto)
{
    try {
    string SkitalText;
    Swap Skital(key, chto, Text);
    SkitalText = Skital.endecrypt();
    cout << endl << endl;
    cout << "key=" << key << endl;
    cout << Text << endl;
    cout << SkitalText << endl;
    } catch (const cipher_error & e) {
 cerr<<"Error: "<<e.what()<<endl;
 }
}
int main()
{
    string text1;
    int chto;
    int kluch;
    cout << "������� ����� ��� ���������� - ";
    cin >> text1;
    cout << endl;
    cout << "������� ���� - ";
    cin >> kluch;
    cout << "������ �� �� ����������� ��� ����������� ����� ? [1/0]" << endl;
    cin >> chto;
    cout << endl;
    checkskit(text1,kluch,chto);
    return 0;
}