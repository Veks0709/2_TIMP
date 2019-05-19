#include "Skital.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Swap::Swap(const int key, const int ende1, std::string stroka1)
{
    kolver = ThatsNotChislo(key);
    ende = ende1;
    stroka = getValidKey(stroka1);
}


std::string Swap::endecrypt()
{

    int kolgor,c;
    double sum,sum1;
    sum=stroka.length();
    sum1 = sum/kolver;
    kolgor = ceil(sum1);
    int m = kolgor;
    int n = kolver;
    cout<<"строки m "<<m<<endl;
    cout<<"столбцы n "<<n<<endl;
    char matr[n][m];
    string resalt;
    for (unsigned int j = 0; j < m; j++) {
        for(unsigned int i = 0; i < n; i++) {
            matr[i][j] = '!';
        }
    }
    if (ende == 1) {
        for (unsigned int j = 0; j < m; j++) {
            for(unsigned int i = 0; i < n; i++) {
                if (j*n +i < sum) {
                    matr[i][j] = stroka [j*n +i];
                    cout << matr[i][j];
                    if (i==n-1) {
                        cout<<endl;
                    }
                }
            }
        }
        cout<< "Код для дешивровки"<< endl;
        for (int i = n-1; i >= 0 ; i--) {
            for(int j = 0; j < m; j++) {
                cout << matr[i][j];
                resalt [c] = matr[i][j];
                c++;
            }
        }
        cout<<endl;
        cout<< "Читаемый код"<< endl;
        for (int i = n-1; i >= 0 ; i--) {
            for(int j = 0; j < m; j++) {
                if (matr[i][j] != '1')
                    cout << matr[i][j];

            }
        }
        cout<<endl;
    } else if (ende == 0) {
        for (int i = n-1; i >= 0 ; i--) {
            for(int j = 0; j < m; j++) {
                if (c < sum) {
                    matr[i][j] = stroka [c];
                    cout << matr[i][j];
                    c++;
                }
            }
        }
        cout<< "Код для дешивровки"<< endl;
        c=0;
        for (unsigned int j = 0; j < m; j++) {
            for(unsigned int i = 0; i < n; i++) {
                cout << matr[i][j];
                resalt [c] = matr[i][j];
                c++;
            }
        }
        cout<<endl;
        cout<< "Читаемый код"<< endl;
        for (unsigned int j = 0; j < m; j++) {
            for(unsigned int i = 0; i < n; i++) {
                if (matr[i][j] != '!')
                    cout << matr[i][j];

            }
        }
        cout<<endl;
    } else
        cout<<"Error"<<endl;
    return resalt;
}

inline std::string Swap::getValidKey(const std::string & stroka11)
{
    for (int i=0; i<stroka.size(); i++) {
        if (stroka11.at(i)== '!')
            throw cipher_error("Nedopustimie simvoli");
    }
    if (stroka11.size()==1)
        throw cipher_error("Not encrypted");
    return stroka11;
}
inline int Swap::ThatsNotChislo(const int key1)
{
    if ((key1 <= 0)||(key1 > 9))
        throw cipher_error("Code not chislo or null");
    if (key1==1)
        throw cipher_error("Encryption does not make sense");
    return key1;
};
