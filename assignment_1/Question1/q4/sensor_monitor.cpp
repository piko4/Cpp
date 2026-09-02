#include <iostream>
#include <cstdlib>
using namespace std;

void display(int warn, int crit, int readings[], int random_count)
{
    int normal = 0, warning = 0, critical = 0, shutdown = 0;
    for (int i = 0; i < random_count; i++)
    {
        // cout<<" "<<readings[i];
        if (readings[i] >= 0 && readings[i] <= 29)
            normal++;
        else if (readings[i] >= warn && readings[i] <= crit)
            warning++;
        else if (readings[i] >= crit && readings[i] <= 60)
            critical++;
        else if (readings[i] >= 60)
            shutdown++;
    }
    cout << "config : Warn=" << warn << " Critical=" << crit << " Readings= " << random_count << endl;
    cout << "Results : Normal: " << normal << " Warning: " << warning << " Critical: " << critical << " Shutdown: " << shutdown << endl;
}
//-------------------------MAIN-------------------------------------------------
int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        cout << "Usage : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl;
        cout << "Error : Missing arguments." << endl;
        return 1;
    }
    srand(time(0));
    int size = stoi(argv[3]);
    int readings[size];
    for (int i = 0; i < size; i++)
    {
        readings[i] = rand() % 70;
        // cout << " " << readings[i];
    }

    display(stoi(argv[1]), stoi(argv[2]), readings, size);
    return 0;
}
