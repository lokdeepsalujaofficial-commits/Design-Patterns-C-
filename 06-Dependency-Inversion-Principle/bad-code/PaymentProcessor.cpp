#include <iostream>
using namespace std;

// ❌ BAD: High-level class depends on concrete low-level classes
// PaymentProcessor directly creates and uses concrete implementations

class EmailService {
public:
    void sendEmail(string message) {
        cout << "Email sent: " << message << endl;
    }
};

class DatabaseLogger {
public:
    void log(string message) {
        cout << "Logged to database: " << message << endl;
    }
};

class PaymentProcessor {
public:
    void processPayment(double amount, string customer) {
        // Direct dependency on concrete classes
        EmailService email;
        DatabaseLogger logger;
        
        // Process payment
        cout << "Processing payment of $" << amount << " for " << customer << endl;
        
        // Send notification
        email.sendEmail("Payment of $" + to_string(amount) + " processed");
        
        // Log transaction
        logger.log("Payment processed for " + customer);
    }
};

int main() {
    cout << "=== BAD DIP Example ===" << endl;
    
    PaymentProcessor processor;
    processor.processPayment(100.0, "John Doe");
    
    cout << "\nProblems:" << endl;
    cout << "❌ PaymentProcessor is tightly coupled to EmailService and DatabaseLogger" << endl;
    cout << "❌ Cannot easily swap email service (Gmail vs Yahoo)" << endl;
    cout << "❌ Cannot easily swap logging (Database vs File vs Console)" << endl;
    cout << "❌ Hard to test (cannot mock dependencies)" << endl;
    
    return 0;
}
