#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:
    Employee()
    {
        empId = 1001 + employeeCount;
        employeeCount++;

        name = "";
        department = "";
        grade = 'D';
        basicSalary = 0;
        isActive = true;
    }

    // ---------------- SETTERS ----------------

    void setName(const string &n)
    {
        if (n.empty())
        {
            cout << "ERROR: Name cannot be empty. Value rejected." << endl;
            return;
        }

        name = n;
    }

    void setDepartment(const string &dept)
    {
        if (dept == "Engineering" ||
            dept == "HR" ||
            dept == "Finance" ||
            dept == "Operations")
        {
            department = dept;
        }
        else
        {
            cout << "ERROR: '" << dept
                 << "' is not a registered department." << endl;
        }
    }

    void setGrade(char g)
    {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D')
        {
            grade = g;
        }
        else
        {
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D." << endl;
        }
    }

    void setBasicSalary(double salary)
    {
        if (salary > 10000 && salary < 500000)
        {
            basicSalary = salary;
        }
        else
        {
            cout << "ERROR: Salary must be between Rs.10,000 and "
                 << "Rs.5,00,000. Value rejected." << endl;
        }
    }

    void deactivate()
    {
        isActive = false;
    }

    // ---------------- GETTERS ----------------

    int getEmpId() const
    {
        return empId;
    }

    string getName() const
    {
        return name;
    }

    string getDepartment() const
    {
        return department;
    }

    char getGrade() const
    {
        return grade;
    }

    double getBasicSalary() const
    {
        return basicSalary;
    }

    bool getIsActive() const
    {
        return isActive;
    }

    // ---------------- BUSINESS LOGIC ----------------

    double computeAllowances() const
    {
        switch (grade)
        {
        case 'A':
            return basicSalary * 0.40;

        case 'B':
            return basicSalary * 0.30;

        case 'C':
            return basicSalary * 0.20;

        case 'D':
            return basicSalary * 0.10;

        default:
            return 0;
        }
    }

    double computeGrossSalary() const
    {
        return basicSalary + computeAllowances();
    }

    double computeTax() const
    {
        double gross = computeGrossSalary();

        if (gross <= 50000)
        {
            return 0;
        }
        else if (gross <= 100000)
        {
            return (gross - 50000) * 0.10;
        }
        else
        {
            return 5000 + (gross - 100000) * 0.20;
        }
    }

    double computeNetSalary() const
    {
        return computeGrossSalary() - computeTax();
    }

    void printPayslip() const
    {
        cout << fixed << setprecision(2);

        cout << "\n============================================" << endl;
        cout << "         EMPLOYEE PAYSLIP - AUG 2026" << endl;
        cout << "============================================" << endl;

        cout << "Emp ID      : " << empId << endl;
        cout << "Name        : " << name << endl;
        cout << "Department  : " << department << endl;
        cout << "Grade       : " << grade << endl;
        cout << "Status      : " << (isActive ? "Active" : "Inactive") << endl;

        cout << "--------------------------------------------" << endl;

        cout << left << setw(20) << "Basic Salary"
             << ":  Rs. " << right << setw(10)
             << basicSalary << endl;

        double allowance = computeAllowances();

        int percentage = 0;

        switch (grade)
        {
        case 'A':
            percentage = 40;
            break;
        case 'B':
            percentage = 30;
            break;
        case 'C':
            percentage = 20;
            break;
        case 'D':
            percentage = 10;
            break;
        }

        cout << left << setw(20)
             << ("Allowances (" + to_string(percentage) + "%)")
             << ":  Rs. " << right << setw(10)
             << allowance << endl;

        cout << left << setw(20) << "Gross Salary"
             << ":  Rs. " << right << setw(10)
             << computeGrossSalary() << endl;

        cout << "--------------------------------------------" << endl;

        cout << left << setw(20) << "Tax Deduction"
             << ":  Rs. " << right << setw(10)
             << computeTax() << endl;

        cout << left << setw(20) << "Net Salary"
             << ":  Rs. " << right << setw(10)
             << computeNetSalary() << endl;

        cout << "============================================" << endl;
    }

    // ---------------- STATIC MEMBER ----------------

    static int getEmployeeCount()
    {
        return employeeCount;
    }

    // ---------------- INPUT ----------------

    void acceptDetails()
    {
        string inputName;
        string inputDepartment;
        char inputGrade;
        double inputSalary;

        cout << "\nEnter name: ";
        getline(cin >> ws, inputName);
        setName(inputName);

        cout << "Enter department: ";
        getline(cin >> ws, inputDepartment);
        setDepartment(inputDepartment);

        cout << "Enter grade: ";
        cin >> inputGrade;
        setGrade(inputGrade);

        cout << "Enter basic salary: ";
        cin >> inputSalary;
        setBasicSalary(inputSalary);
    }
};

int Employee::employeeCount = 0;

// ================= MAIN =================

int main()
{
    Employee e1;
    Employee *e2 = new Employee();
    Employee *e3 = new Employee();

    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    // e1.empId = 999;
    // e1.basicSalary = -1000;
    // ERROR: empId and basicSalary are private members.

    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    e3->deactivate();

    if (!e3->getIsActive())
    {
        cout << e3->getName()
             << " is no longer active. Payroll skipped."
             << endl;
    }

    cout << "Total Employees : " << Employee::getEmployeeCount() << endl;

    delete e2;
    delete e3;

    return 0;
}