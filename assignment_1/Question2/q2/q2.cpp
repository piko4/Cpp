#include <iostream>
#include <cmath>
using namespace std;

double computeRMS(double *signal, int n);
// Returns sqrt( sum of (each element squared) / n )
void normalise(double *signal, int n);
// Divides every element by the max absolute value in the array (in-place)
int countZeroCrossings(double *signal, int n);
// Returns count of positions where adjacent elements have opposite signs
void applyGain(double *signal, int n, double gainFactor);
// Multiplies every element by gainFactor (in-place)
//========================================================================================
//------------------RMS------------
double computeRMS(double *signal, int n)
{
    double sum = 0;
    double *ptr = signal;
    for (int i = 0; i < n; i++)
    {
        sum += (*ptr) * (*ptr);
        ptr++;
    }
    double rms = sqrt(sum / n);
    return rms;
}
//------------NORM-----------------
void normalise(double *signal, int n)
{
    double max_abs, *ptr = signal;
    for (int i = 0; i < n; i++)
    {
        if (abs(*ptr) > abs(max_abs))
            max_abs = abs(*ptr);
        ptr++;
    }
    for (int i = 0; i < n; i++)
    {
        *signal = *signal / max_abs;
        signal++;
    }
}
//------------countAdzero-----------------
int countZeroCrossings(double *signal, int n)
{
    int count = 0;
    double *ptr = signal;
    for (int i = 0; i < n; i++)
    {
        if ((*ptr > 0 && *(ptr + 1) < 0) || (*ptr < 0 && *(ptr + 1) > 0))
            count++;
        ptr++;
    }
    return count;
}
//------------gainfact-----------------
void applyGain(double *signal, int n, double gainFactor)
{
    for(int i=0;i<n;i++){
        *signal*=(*signal)*gainFactor;
        signal++;
    }
}
//-------------------------Main-------------------------------------------------
int main(int argc, char const *argv[])
{
    double arry[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
    int size = sizeof(arry) / sizeof(double);
    double rms = computeRMS(arry, size);
    cout << "Rms is " << rms << endl;
    cout << "Befor normalise : ";

    for (int i = 0; i < size; i++)
        cout << " " << arry[i];

    normalise(arry, size);
    cout << "\nAfter normalise : ";

    for (int i = 0; i < size; i++)
        cout << " " << arry[i];
    cout << "\ncountZeroCrossings : " << countZeroCrossings(arry, size) << endl;

    cout << "Befor applyGain : ";
    for (int i = 0; i < size; i++)
        cout << " " << arry[i];
    applyGain(arry,size, 2.2);
    cout << "\nAfter applyGain : ";
    for (int i = 0; i < size; i++)
        cout << " " << arry[i];
    return 0;
}
