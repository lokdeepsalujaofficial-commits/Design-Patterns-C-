#include <iostream>
#include <string>

using namespace std;

// ❌ BAD: Violates Open/Closed Principle
// Every time we add a new notification type, we must MODIFY this class

class NotificationService {
public:
    void sendNotification(string type, string message, string recipient) {
        if (type == "whatsapp") {
            sendWhatsApp(message, recipient);
        }
        else if (type == "sms") {
            sendSMS(message, recipient);
        }
        else if (type == "email") {
            sendEmail(message, recipient);
        }
        else {
            cout << "Unknown notification type!" << endl;
        }
    }

private:
    void sendWhatsApp(string message, string recipient) {
        cout << "📱 WhatsApp: Sending to " << recipient << ": " << message << endl;
    }
    
    void sendSMS(string message, string recipient) {
        cout << "📧 SMS: Sending to " << recipient << ": " << message << endl;
    }
    
    void sendEmail(string message, string recipient) {
        cout << "✉️ Email: Sending to " << recipient << ": " << message << endl;
    }
};

int main() {
    cout << "=== BAD CODE: Violates Open/Closed Principle ===" << endl;
    
    NotificationService service;
    
    service.sendNotification("whatsapp", "Hello from WhatsApp!", "1234567890");
    service.sendNotification("sms", "Hello from SMS!", "9876543210");
    service.sendNotification("email", "Hello from Email!", "user@example.com");
    
    cout << "\n❌ Problems:" << endl;
    cout << "❌ To add 'push notification', we must MODIFY NotificationService" << endl;
    cout << "❌ To add 'telegram', we must MODIFY NotificationService" << endl;
    cout << "❌ Every new notification type requires changing existing code" << endl;
    cout << "❌ This violates Open/Closed Principle!" << endl;
    
    return 0;
}
