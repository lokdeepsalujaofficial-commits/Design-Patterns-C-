#include <iostream>
#include <string>

using namespace std;

// ✅ GOOD: Follows Open/Closed Principle
// Open for extension (new notification types) but closed for modification

// Abstract base class - defines the contract
class Notification {
public:
    virtual void send(string message, string recipient) = 0;  // Pure virtual function
    virtual ~Notification() {}  // Virtual destructor
};

// Concrete implementation for WhatsApp
class WhatsAppNotification : public Notification {
public:
    void send(string message, string recipient) override {
        cout << "📱 WhatsApp: Sending to " << recipient << ": " << message << endl;
    }
};

// Concrete implementation for SMS
class SMSNotification : public Notification {
public:
    void send(string message, string recipient) override {
        cout << "📧 SMS: Sending to " << recipient << ": " << message << endl;
    }
};

// Concrete implementation for Email
class EmailNotification : public Notification {
public:
    void send(string message, string recipient) override {
        cout << "✉️ Email: Sending to " << recipient << ": " << message << endl;
    }
};

// Notification service that works with any notification type
class NotificationService {
public:
    void sendNotification(Notification* notification, string message, string recipient) {
        notification->send(message, recipient);
    }
};

int main() {
    cout << "=== GOOD CODE: Follows Open/Closed Principle ===" << endl;
    
    NotificationService service;
    
    // Create different notification types
    WhatsAppNotification whatsapp;
    SMSNotification sms;
    EmailNotification email;
    
    // Send notifications using the service
    service.sendNotification(&whatsapp, "Hello from WhatsApp!", "1234567890");
    service.sendNotification(&sms, "Hello from SMS!", "9876543210");
    service.sendNotification(&email, "Hello from Email!", "user@example.com");
    
    cout << "\n✅ Benefits:" << endl;
    cout << "✅ To add 'push notification', just create new class - NO MODIFICATION!" << endl;
    cout << "✅ To add 'telegram', just create new class - NO MODIFICATION!" << endl;
    cout << "✅ NotificationService never needs to change" << endl;
    cout << "✅ Open for extension, closed for modification!" << endl;
    
    return 0;
}
