#include <iostream>
using namespace std;

// ❌ BAD Strategy example:
// - Refund logic is hardcoded inside each card class
// - Changing refund rules requires editing these classes (Open/Closed violation)
// - You cannot swap refund behavior at runtime
// - Rules get duplicated across card types as variations grow

class Visa {
public:
    void swipeAndPay() { cout << "Visa: swipe\n"; }

    // Hardcoded refund rule (no easy way to switch to a different rule)
    void refundAmount(double amount) {
        cout << "Visa refund: " << amount << " (basic full refund)\n";
    }
};

class Amex {
public:
    void swipeAndPay() { cout << "Amex: swipe\n"; }

    // Different hardcoded rule here (business logic mixed into card class)
    void refundAmount(double amount) {
        cout << "Amex refund: " << (amount * 0.9) << " (10% fee)\n";
    }
};

int main() {
    cout << "=== Strategy BAD (hardcoded rules) ===\n";

    Visa visa;    // If rules change, we must edit Visa
    Amex amex;    // And we must edit Amex separately too

    visa.swipeAndPay();
    visa.refundAmount(100);

    amex.swipeAndPay();
    amex.refundAmount(100);

    // ⚠️ Problems to notice:
    // - Adding a promo or region-based rule means adding more code here or inside classes
    // - Testing refund math requires constructing these concrete cards
    // - No reuse of the refund rules between card types without copy-paste

    return 0;
}
