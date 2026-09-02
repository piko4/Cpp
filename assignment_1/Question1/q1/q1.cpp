#include <iostream>
using namespace std;
void display(string action, double degree_f, double reading, string status);

void classification_module(double reading)
{
    double degree_c = reading, degree_f = (reading * 9 / 5) + 32;

    int status_code;
    if (reading < 0)
        status_code = -1;
    else if (reading >= 0 && reading <= 29)
        status_code = 0;
    else if (reading >= 30 && reading <= 44)
        status_code = 1;
    else if (reading >= 45 && reading <= 59)
        status_code = 2;
    else if (reading >= 60)
        status_code = 3;

    switch (status_code)
    {
    case -1:
        display("Sensor fault--check wiring", degree_f, reading, "SENSOR_ERROR");
        break;
    case 0:
        display("no action required", degree_f, reading, "NORMAL");
        break;
    case 1:
        display("Alert sent to supervisor", degree_f, reading, "WARNING");

        break;
    case 2:
        display("Cooling system triggered ", degree_f, reading, "CRITICAL");

        break;
    case 3:
        display("Emergency shutdown initiated", degree_f, reading, "SHUTDOWN");

        break;

    default:
        break;
    }
}
void display(string action, double degree_f, double reading, string status)
{
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Temperature: " << reading << "\370C /" << degree_f << "\370F " << "\nStatus : " << status << endl;
    cout << "Action : " << action << "\nReading : " << (reading < 25.0 ? "Below average" : "Above average") << endl;
    cout << "--------------------------------------------------------------------------" << endl;
}
//-------------------- MAIN ------------------------------------------------------
int main(int argc, char const *argv[])
{
    double reading;
    cout << "Enter the temperature reading" << endl;
    cin >> reading;
    cout << "You have entered " << reading << "\370 C" << endl;

    classification_module(reading);
    return 0;
}
