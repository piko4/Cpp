#include <iostream>
#include <algorithm>
using namespace std;

//--------------------------------B.A.M------------------------------------------
void buffer_analysis_module(int n, double readings[])
{

    int skipped = 0, fc_index;
    double fc_temperature;

    double Min = readings[0], Max = readings[0], Avg = 0.0;
    double total_sum = 0.0, total_count = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (readings[i] == 0.0)
            continue;

        total_count++;
        total_sum += readings[i];
    }
    Avg = total_sum / total_count;
    for (int i = 0; i < n; i++)
    {
        if (readings[i] <= 0.0)
        {
            skipped++;
            continue;
        }
        if (readings[i] >= 45.0)
        {
            fc_temperature = readings[i];
            fc_index = i;
            break;
        }
    }

    //--------------reading cat---------
    int normal = 0, warning = 0, critical = 0, shutdown = 0;

    //-----------display--------
    cout << "readings entered : " << n << endl;
    cout << "Valid readings : ";
    for (int i = 0; i < n; i++)
    {
        if (readings[i] == 0)
            continue;
        cout << readings[i] << " ";
        if (readings[i] < Min)
            Min = readings[i];
        if (readings[i] > Max)
            Max = readings[i];

        if (readings[i] >= 0 && readings[i] <= 29)
            normal++;
        else if (readings[i] >= 30 && readings[i] <= 44)
            warning++;
        else if (readings[i] >= 45 && readings[i] <= 59)
            critical++;
        else if (readings[i] >= 60)
            shutdown++;
    }
    cout << "\nSkipped (errors) : " << skipped << endl;
    cout << "First CRITICAL  : index " << fc_index << " -> " << fc_temperature << endl;
    cout << "Min : " << Min << " Max : " << Max << " Avg : " << Avg << endl;
    cout << "Normal : " << normal << "  Warning : " << warning << "  Critical : " << critical << "  Shutdown : " << shutdown << endl;
}
//----------------------------------MAIN----------------------------------------
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter readings count" << endl;
    cin >> n;
    double readings_arr[n];
    cout << "Enter readings temperature one by one" << endl;
    for (int i = 0; i < n; i++)
        cin >> readings_arr[i];

    buffer_analysis_module(n, readings_arr);
    return 0;
}
