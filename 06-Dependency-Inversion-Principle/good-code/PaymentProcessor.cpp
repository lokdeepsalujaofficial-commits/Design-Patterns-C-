#include <iostream>
using namespace std;

// ✅ GOOD: DIP - Depend on abstractions, not concretions
// High-level classes depend on interfaces, not concrete implementations

// Abstract interfaces (abstractions)
class NotificationService {
public:
    virtual void send(string message) = 0;
    virtual ~NotificationService() = default;
};

class Logger {
public:
    virtual void log(string message) = 0;
    virtual ~Logger() = default;
};

// Concrete implementations (low-level classes)
class EmailService : public NotificationService {
public:
    void send(string message) override {
        cout << "Email sent: " << message << endl;
    }
};

class SMSService : public NotificationService {
public:
    void send(string message) override {
        cout << "SMS sent: " << message << endl;
    }
};

class DatabaseLogger : public Logger {
public:
    void log(string message) override {
        cout << "Logged to database: " << message << endl;
    }
};

class FileLogger : public Logger {
public:
    void log(string message) override {
        cout << "Logged to file: " << message << endl;
    }
};

// High-level class depends on abstractions (interfaces)
class PaymentProcessor {
private:
    NotificationService& notificationService;
    Logger& logger;
    
public:
    // Dependency injection via constructor
    PaymentProcessor(NotificationService& notif, Logger& log) 
        : notificationService(notif), logger(log) {}
    
    void processPayment(double amount, string customer) {
        // Process payment
        cout << "Processing payment of $" << amount << " for " << customer << endl;
        
        // Send notification (uses injected service)
        notificationService.send("Payment of $" + to_string(amount) + " processed");
        
        // Log transaction (uses injected logger)
        logger.log("Payment processed for " + customer);
    }
};

int main() {
    cout << "=== GOOD DIP Example ===" << endl;
    
    // Create concrete implementations
    EmailService email;
    DatabaseLogger dbLogger;
    
    // Inject dependencies into high-level class
    PaymentProcessor processor(email, dbLogger);
    processor.processPayment(100.0, "John Doe");
    
    cout << "\nBenefits:" << endl;
    cout << "✅ PaymentProcessor depends on abstractions (interfaces)" << endl;
    cout << "✅ Easy to swap implementations (Email vs SMS)" << endl;
    cout << "✅ Easy to swap loggers (Database vs File)" << endl;
    cout << "✅ Easy to test (can inject mock objects)" << endl;
    
    // Example: swap to SMS and File logging
    SMSService sms;
    FileLogger fileLogger;
    PaymentProcessor processor2(sms, fileLogger);
    processor2.processPayment(200.0, "Jane Smith");
    
    return 0;
}
