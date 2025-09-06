#include <iostream>
#include <string>

using namespace std;

// ✅ GOOD: Simple version following Single Responsibility Principle

// Responsibility 1: Employee data ONLY
class Employee {
private:
    string name;
    double salary;

public:
    Employee(string n, double s) : name(n), salary(s) {}
    
    string getName() { return name; }
    double getSalary() { return salary; }
};

// Responsibility 2: Salary calculations ONLY
class SalaryCalculator {
public:
    static double calculateTax(double salary) {
        return salary * 0.2;  // Simple 20% tax
    }
    
    static double calculateBonus(double salary) {
        return salary * 0.1;  // Simple 10% bonus
    }
};

// Responsibility 3: Database operations ONLY
class EmployeeRepository {
public:
    void save(Employee emp) {
        cout << "Saving " << emp.getName() << " to database" << endl;
    }
};

// Responsibility 4: Email operations ONLY
class EmailService {
public:
    void sendEmail(Employee emp) {
        cout << "Sending email to " << emp.getName() << endl;
    }
};

// Simple example
int main() {
    cout << "=== GOOD CODE: Simple SRP Example ===" << endl;
    
    // Create employee
    Employee emp("John", 50000);
    
    // Use separate classes for different jobs
    cout << "Name: " << emp.getName() << endl;
    cout << "Salary: $" << emp.getSalary() << endl;
    cout << "Tax: $" << SalaryCalculator::calculateTax(emp.getSalary()) << endl;
    cout << "Bonus: $" << SalaryCalculator::calculateBonus(emp.getSalary()) << endl;
    
    EmployeeRepository repo;
    repo.save(emp);
    
    EmailService email;
    email.sendEmail(emp);
    
    cout << "\n✅ Each class does ONE thing only!" << endl;
    
    return 0;
}
