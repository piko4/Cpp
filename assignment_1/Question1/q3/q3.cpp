#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
    double array[][3] = {{24.0, 31.5, 28.0},
                         {45.0, 22.0, 30.0},
                         {19.0, 27.5, 50.2}};
    int rows = sizeof(array) / sizeof(array[0]);
    int cols = sizeof(array[0]) / sizeof(array[0][0]);
    double hot_room_temp, avg_floor_temp[3], sum;
    int hot_room_floor_no, hot_room_no, warning;
    for (int i = 0; i < rows; i++)
    {
        sum = array[i][0] + array[i][1] + array[i][2];
        avg_floor_temp[i] = sum / 3;

        for (int j = 0; j < cols; j++)
        {

            if (array[i][j] > hot_room_temp)
            {
                hot_room_temp = array[i][j];
                hot_room_floor_no = i + 1;
                hot_room_no = j + 1;
            }
            if (array[i][j] >= 30.0)
                warning++;
        }
    }
    double highest_avg_room_temp;
    int highest_avg_room_no;
    for (int i = 0; i < 3; i++)
    {
        if (avg_floor_temp[i] > highest_avg_room_temp)
        {
            highest_avg_room_temp = avg_floor_temp[i];
            highest_avg_room_no = i + 1;
        }
    }

    //-----------display----------
    cout << "\t\troom1   room2   room3\n";
    for (int i = 0; i < rows; i++)
    {
        cout << "Floor " << i + 1 << " : ";
        for (int j = 0; j < cols; j++)
        {
            cout << "\t" << fixed << setprecision(1) << array[i][j];
        }
        cout << endl;
    }
    cout << "Hottest Room  : Floor " << hot_room_floor_no << ", Room " << hot_room_no << " -> " << hot_room_temp << "\370C" << endl;
    cout << "Hottest Floor : Floor " << highest_avg_room_no << " (avg " << highest_avg_room_temp << "\370C)" << endl;
    cout << "Rooms at WARNING or above : " << warning;
    return 0;
}
