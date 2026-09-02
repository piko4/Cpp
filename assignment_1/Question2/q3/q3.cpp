#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int statusReg = 0b10110001;  // Read-only from firmware side
    int controlReg = 0b00000000; // Firmware writes here
    int dataReg = 0b11001010;    // For reassignment demo

    const int *regptr1 = &statusReg;
    cout << " regptr1 : " << *regptr1 << endl;
    int *const regptr2 = &controlReg;
    cout << " regptr2 : " << *regptr2 << endl;
    const int *const regptr3 = &dataReg;
    cout << " regptr1 : " << *regptr3 << endl;

    return 0;
}
