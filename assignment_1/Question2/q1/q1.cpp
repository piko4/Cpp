#include <iostream>
using namespace std;

void resetSensorPariV1(int reading1, int reading2)
{
    int temp = reading2;
    reading2 = reading1;
    reading1 = temp;
}
void resetSensorPariV2(int &reading1, int &reading2)
{
    int temp = reading2;
    reading2 = reading1;
    reading1 = temp;
}
void resetSensorPariV3(int *reading1, int *reading2)
{
    int temp = *reading2;
    *reading2 = *reading1;
    *reading1 = temp;
}
int main(int argc, char const *argv[])
{
    int A = 55, B = 12;


    // v1 failed because it is passing a copy of value to the function outside main block  
    cout << "--- V1: Call by value ---" << endl;
    cout << "Before : A=" << A << " B=" << B << endl;
    resetSensorPariV1(A, B);
    cout << "After : A=" << A << " B=" << B << endl;

    cout << "\n--- V2: Call by reference ---" << endl;
    cout << "Before : A=" << A << " B=" << B << endl;
    resetSensorPariV2(A, B);
    cout << "After : A=" << A << " B=" << B << endl;

    cout << "\n--- V3: Call by pointer ---" << endl;
    cout << "Before : A=" << A << " B=" << B << endl;
    resetSensorPariV3(&A, &B);
    cout << "After : A=" << A << " B=" << B << endl;

    return 0;
}
