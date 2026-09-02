#include <iostream>
using namespace std;

struct Layout1
{
    char c1;
    int i;
    char c2;
};

struct Layout2
{
    int i;
    char c1;
    char c2;
};

int main()
{
    cout << "Size of Layout1 : " << sizeof(Layout1) << " bytes" << endl;
    cout << "Size of Layout2 : " << sizeof(Layout2) << " bytes" << endl;

  /*
1. Why sizes differ:
   The members are in different orders, so the compiler may need
   different amounts of padding for proper alignment.

2. Padding:
   Padding is extra unused memory added by the compiler so members
   are stored at properly aligned addresses.

3. Why member order matters:
   Different ordering can change member offsets and total size.
   This is important for network packets and hardware registers,
   where the exact memory layout must match the required format.
*/
    return 0;
}