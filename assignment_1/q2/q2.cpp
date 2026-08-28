#include <iostream>
using namespace std;

void displayReport()
{
    cout << "readings entered : " << endl;
    cout << "Valid readings : " << endl;
    cout << "Skipped (errors) : " << endl;
    cout << "First CRITICAL  : " << endl;
    cout << "Min : " << "Max : " << "Avg : " << endl;
    cout << "Normal : " << "Warning : " << "Critical : " << "Shutdown : " << endl;
}
void buffer_analysis_module(int n,double readings[])
{
    
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter readings count" << endl;
    cin >> n;
    double readings_arr[n];
    cout << "Enter readings temperature one by one" << endl;
    for (int i = 0; i < n; i++)
        cin >> readings_arr[i];
    buffer_analysis_module(n,readings_arr);
    return 0;
}
