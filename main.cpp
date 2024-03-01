#include <iostream>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

// Компаратор для сравнения ключей в убывающем порядке
struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a > b; // Сравниваем ключи в порядке убывания
    }
};

std::string derivative(std::string polynomial) {
    // преоброзуем формулу к виду x^2+x -> 1*x^2+1*x^1
    polynomial+=" ";
    string polynomialMod="";
    string last=" ";
    for(int i=0;i<polynomial.length()-1;i++)
    {
        if(polynomial[i]=='-') polynomialMod+="+-";
        else if (polynomial[i]!='x') 
        {
            polynomialMod+=polynomial[i];
            last = polynomial[i];
        }else
        {
          if (last[0]!='*') polynomialMod+="1*x";
            else polynomialMod+="x";
          if (polynomial[i+1]!='^') polynomialMod+="^1";              
        }  
    }
//cout << polynomialMod << endl;
    map<int, int, Compare> polynomialMap;
    istringstream iss(polynomialMod);
    string termStr;
    while (getline(iss, termStr, '+')) {
    if (termStr.find('x') != string::npos) 
    {

        int coefficient, exponent;
        char x;
        stringstream ss(termStr);
        ss >> coefficient >> x >> x >> x >> exponent; // Пропускаем '*'
        polynomialMap[exponent] += coefficient;
    }
// cout << exponent <<  coefficient << endl;        
    }   
    
 // Функция для вычисления производной многочлена
    
    map<int, int, Compare> derivativePr;
    for (const auto& term : polynomialMap) {
        if (term.first > 0) { // Исключаем свободный член
            derivativePr[term.first - 1] = term.second * term.first;
        }
    }
   
    // Функция для вывода многочлена
    ostringstream oss;
    bool firstTerm = true;
    for (const auto& term : derivativePr) {
        if (!firstTerm && term.second >= 0) {
            oss << "+";
        }
         if (term.first==0)    
        oss <<term.second;
        else
        if (term.second==1) oss << "x";
        else
        if (term.second==-1) oss << "-x";
        else
        oss << term.second << "*x";
        if (term.first>1)    
        oss << "^" << term.first;
        firstTerm = false;
    }
    oss << endl;
    
    
    return oss.str();
}
