#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    //------------------addition---------------------
    int a = 10;
    int b = 15;

    cout << "addition of " << a << " and " << b << " is " << a + b;
    //--------------area calculation---------------------
    int length, width;
    cout << "\nEnter length\t";
    cin >> length;
    cout << "Enter width\t";
    cin >> width;
    cout << "area is " << length * width;

    //--------------------swap two nums-----------------------------
    cout << "\nswapping values of a : " << a << " and b: " << b;
    int temp = a;
    a = b, b = temp;
    cout << "\nafter swapping values of a: " << a << " value of b:" << b;
    //-------------------------------calculate power of a number -------------------------------------------
    cout << "\nEnter a number\t";
    int n, power;
    cin >> n;
    cout << "\nEnter it's power\t";
    cin >> power;
    cout << power << "th power of " << n << " is " << n * power;
    //-------------------------------calculate simple interest-------------------------------------------
    int principal, rate, time;
    cout << "calculate simple interest\n";
    cout << "Enter principal amount" << endl;
    cin >> principal;
    cout << "Enter rate of interest" << endl;
    cin >> rate;
    cout << "Enter time" << endl;
    cin >> time;

    int si=(principal*rate*time)/100;
    cout<<"simple interest is "<<si;

    //-------------------------------calculate compound interest-------------------------------------------
    // compund interest is CI=A-P where A=P(1+r/100)^n
    double A,P,CI,r,t;
    cout << "calculate Compund interest\n";
    cout << "Enter principal amount" << endl;
    cin >> P;
    cout << "Enter rate of interest" << endl;
    cin >> r;
    cout << "Enter time" << endl;
    cin >> t;
    A= pow((P*(1+(r/100))),t);
    CI=A-P;
    cout<<"\n compund interest is : "<<CI<<endl;

    return 0;
}
