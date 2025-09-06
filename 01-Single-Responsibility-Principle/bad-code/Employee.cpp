#include <iostream>
#include <string>

using namespace std;

// ❌ BAD: This class violates Single Responsibility Principle
// It has multiple responsibilities:
// 1. Employee data management
// 2. Salary calculations  
// 3. Database operations
// 4. Email sending

class Employee {
private:
    string name;
    double salary;
    string department;

public:
    // Constructor
    Employee(string n, double s, string d) {
        name = n;
        salary = s;
        department = d;
    }
    
    // Responsibility 1: Employee data management
    string getName() {
        return name;
    }
    
    double getSalary() {
        return salary;
    }
    
    string getDepartment() {
        return department;
    }
    
    // Responsibility 2: Salary calculations (SHOULD NOT BE HERE)
    double calculateTax() {
        if (salary < 50000) {
            return salary * 0.1;  // 10% tax
        } else if (salary < 100000) {
            return salary * 0.2;  // 20% tax
        } else {
            return salary * 0.3;  // 30% tax
        }
    }
    
    double calculateBonus() {
        return salary * 0.1;  // 10% bonus
    }
    
    // Responsibility 3: Database operations (SHOULD NOT BE HERE)
    void saveToDatabase() {
        cout << "Saving employee " << name << " to database..." << endl;
    }
    
    void loadFromDatabase(int id) {
        cout << "Loading employee with ID: " << id << " from database..." << endl;
    }
    
    // Responsibility 4: Email operations (SHOULD NOT BE HERE)
    void sendSalaryEmail() {
        cout << "Sending salary email to " << name << "..." << endl;
    }
};

// Example usage
int main() {
    cout << "=== BAD CODE: Violates Single Responsibility Principle ===" << endl;
    
    // Create an employee
    Employee emp("John Doe", 75000, "Engineering");
    
    // Using the employee
    cout << "Name: " << emp.getName() << endl;
    cout << "Salary: $" << emp.getSalary() << endl;
    cout << "Department: " << emp.getDepartment() << endl;
    
    // These methods should NOT be in Employee class
    cout << "Tax: $" << emp.calculateTax() << endl;
    cout << "Bonus: $" << emp.calculateBonus() << endl;
    
    emp.saveToDatabase();
    emp.sendSalaryEmail();
    
    cout << "\n❌ Problem: This class does too many things!" << endl;
    cout << "❌ If we need to change salary calculation, we modify Employee class" << endl;
    cout << "❌ If we need to change database operations, we modify Employee class" << endl;
    cout << "❌ If we need to change email sending, we modify Employee class" << endl;
    
    return 0;
}
