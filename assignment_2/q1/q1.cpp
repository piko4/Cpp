#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ================= PRODUCT CLASS =================

class Product
{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:

    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const
    {
        cout << left << setw(6) << productId
             << setw(13) << name
             << setw(10) << fixed << setprecision(2) << price
             << setw(7) << quantity
             << setw(12) << totalValue();

        if (quantity < 10)
            cout << "  <-- LOW STOCK";

        cout << endl;
    }

    double totalValue() const
    {
        return price * quantity;
    }

    bool isLowStock(int threshold) const
    {
        return quantity < threshold;
    }

    string getName() const
    {
        return name;
    }
};


// ================= FUNCTION OVERLOADING =================

double reorderCost(int qty, double unitPrice)
{
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice)
{
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate)
{
    double cost = qty * unitPrice;
    return cost + (cost * taxRate / 100);
}


// ================= DEFAULT ARGUMENT =================

double applyDiscount(double price, double discountPercent = 10.0)
{
    return price - (price * discountPercent / 100);
}


// ================= MAIN =================

int main()
{
    Product products[5];

    cout << "===== ENTER PRODUCT DETAILS =====" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        products[i].acceptDetails();
    }


    cout << "\n\n===== INVENTORY REPORT =====" << endl;

    cout << left << setw(6) << "ID"
         << setw(13) << "Name"
         << setw(10) << "Price"
         << setw(7) << "Qty"
         << setw(12) << "Total Value" << endl;

    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        products[i].displayDetails();
    }


    int highestIndex = 0;

    for (int i = 1; i < 5; i++)
    {
        if (products[i].totalValue() > products[highestIndex].totalValue())
        {
            highestIndex = i;
        }
    }

    cout << "\nHighest Value Product : "
         << products[highestIndex].getName()
         << "  (Rs. " << fixed << setprecision(2)
         << products[highestIndex].totalValue() << ")" << endl;


    int threshold;

    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    cout << "\nLow Stock (threshold: "
         << threshold << ") : ";

    bool found = false;

    for (int i = 0; i < 5; i++)
    {
        if (products[i].isLowStock(threshold))
        {
            if (found)
                cout << ", ";

            cout << products[i].getName();
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;


    // ================= PART B =================

    cout << "\n\n===== FUNCTION OVERLOADING =====" << endl;

    cout << "Integer reorder cost : Rs. "
         << reorderCost(10, 50.0) << endl;

    cout << "Fractional reorder cost : Rs. "
         << reorderCost(2.5, 100.0) << endl;

    cout << "Reorder cost with tax : Rs. "
         << reorderCost(10, 50.0, 18.0) << endl;


    cout << "\n===== DISCOUNT =====" << endl;

    cout << "Price after default 10% discount : Rs. "
         << applyDiscount(1000) << endl;

    cout << "Price after 20% discount : Rs. "
         << applyDiscount(1000, 20.0) << endl;


    return 0;
}