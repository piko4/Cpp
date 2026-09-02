#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


// ======================================================
// GLOBAL VARIABLE - Scope Resolution Bonus
// ======================================================

int level = 1;


// ======================================================
// PART A - ENTITY CLASS
// ======================================================

class Entity
{
private:
    string name;
    int health;
    int level;
    string type;

public:

    // Setters using this pointer
    Entity& setName(const string& name)
    {
        this->name = name;
        return *this;
    }

    Entity& setHealth(int health)
    {
        this->health = health;
        return *this;
    }

    Entity& setLevel(int level)
    {
        this->level = level;
        return *this;
    }

    Entity& setType(const string& type)
    {
        this->type = type;
        return *this;
    }

    // Getters
    string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    int getLevel() const
    {
        return level;
    }

    string getType() const
    {
        return type;
    }

    // Display entity information
    void displayInfo() const
    {
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "Type   : " << type << endl;
        cout << endl;
    }
};


// ======================================================
// PART B - NAMESPACES
// ======================================================

namespace Physics
{
    double clamp(double val, double min, double max)
    {
        if (val < min)
            return min;
        else if (val > max)
            return max;
        else
            return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


namespace GameMath
{
    int clamp(int val, int min, int max)
    {
        if (val < min)
            return min;
        else if (val > max)
            return max;
        else
            return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


// ======================================================
// OPTIONAL BONUS - NESTED NAMESPACE
// ======================================================

namespace Engine
{
    namespace Audio
    {
        void playSound(string name)
        {
            cout << "Playing: " << name << endl;
        }
    }
}


// ======================================================
// MAIN
// ======================================================

int main()
{
    // ==================================================
    // PART A - METHOD CHAINING
    // ==================================================

    Entity player;
    Entity enemy;
    Entity item;

    player.setName("Aragorn")
          .setHealth(100)
          .setLevel(10)
          .setType("Player");

    enemy.setName("Orc")
         .setHealth(60)
         .setLevel(5)
         .setType("Enemy");

    item.setName("HealthPotion")
        .setHealth(0)
        .setLevel(1)
        .setType("Item");

    cout << "===== ENTITY INFORMATION =====" << endl;

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();


    // ==================================================
    // PART B - NAMESPACES
    // ==================================================

    cout << "===== NAMESPACE EXAMPLES =====" << endl;

    double velocity = Physics::clamp(120.5, 0.0, 100.0);

    cout << "Physics clamp : "
         << velocity << endl;

    int health = GameMath::clamp(150, 0, 100);

    cout << "GameMath clamp: "
         << health << endl;

    double physicsLerp = Physics::lerp(0.0, 100.0, 0.25);

    cout << "Physics lerp  : "
         << physicsLerp << endl;

    double gameLerp = GameMath::lerp(0.0, 1.0, 0.5);

    cout << "GameMath lerp : "
         << gameLerp << endl;


    // --------------------------------------------------
    // Limited namespace scope
    // --------------------------------------------------

    {
        using namespace Physics;

        cout << "Limited scope Physics clamp: "
             << clamp(150.0, 0.0, 100.0)
             << endl;
    }


    // ==================================================
    // PART C - DYNAMIC 2D GAME MAP
    // ==================================================

    int R, C;

    cout << "\nEnter number of rows: ";
    cin >> R;

    cout << "Enter number of columns: ";
    cin >> C;

    // Allocate outer array
    int** gameMap = new int*[R];

    // Allocate each row
    for (int i = 0; i < R; i++)
    {
        gameMap[i] = new int[C];
    }


    // Fill map using random tile types 0-4
    srand(time(0));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            gameMap[i][j] = rand() % 5;
        }
    }


    // Display map
    cout << "\n===== GAME MAP ("
         << R << " x " << C
         << ") =====" << endl;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << "  " << gameMap[i][j];
        }

        cout << endl;
    }


    // Legend
    cout << "\nLegend: "
         << "0=Grass  "
         << "1=Water  "
         << "2=Mountain  "
         << "3=Forest  "
         << "4=Dungeon"
         << endl;


    // Count each tile type
    int count[5] = {0};

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            count[gameMap[i][j]]++;
        }
    }


    // Display tile counts
    cout << "\nTile Count:" << endl;

    cout << "  Grass    : " << count[0] << endl;
    cout << "  Water    : " << count[1] << endl;
    cout << "  Mountain : " << count[2] << endl;
    cout << "  Forest   : " << count[3] << endl;
    cout << "  Dungeon  : " << count[4] << endl;


    // ==================================================
    // DEALLOCATE 2D ARRAY
    // ==================================================

    for (int i = 0; i < R; i++)
    {
        delete[] gameMap[i];
    }

    delete[] gameMap;


    // ==================================================
    // SCOPE RESOLUTION BONUS
    // ==================================================

    int level = 10;  // local level

    cout << "\n===== SCOPE RESOLUTION =====" << endl;

    cout << "Local level  : "
         << level << endl;

    cout << "Global level : "
         << ::level << endl;


    // ==================================================
    // NESTED NAMESPACE BONUS
    // ==================================================

    Engine::Audio::playSound("sword_clash");


    return 0;
}