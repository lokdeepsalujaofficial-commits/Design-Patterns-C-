#include <iostream>
using namespace std;

// ❌ BAD: Fat interface forces all implementers to support everything
class CreditCard {
public:
    virtual void swipeAndPay() = 0;
    virtual void onlinePayment() = 0;
    virtual void tapAndPay() = 0;
    virtual void refundAmount() = 0;
    virtual ~CreditCard() = default;
};

class Visa : public CreditCard {
public:
    void swipeAndPay() override   { cout << "Visa: swipeAndPay\n"; }
    void onlinePayment() override { cout << "Visa: onlinePayment\n"; }
    void tapAndPay() override     { cout << "Visa: tapAndPay\n"; }
    void refundAmount() override  { cout << "Visa: refund processed\n"; }
};

// Amex does NOT support tap-and-pay in our scenario, but is forced to implement it
class Amex : public CreditCard {
public:
    void swipeAndPay() override   { cout << "Amex: swipeAndPay\n"; }
    void onlinePayment() override { cout << "Amex: onlinePayment\n"; }
    void tapAndPay() override     { cout << "Amex: tapAndPay (not supported)\n"; }
    void refundAmount() override  { cout << "Amex: refund processed\n"; }
};

int main() {
    cout << "=== BAD ISP Example (Fat Interface) ===\n";

    Visa visa;
    Amex amex;

    visa.swipeAndPay();
    visa.onlinePayment();
    visa.tapAndPay();
    visa.refundAmount();

    amex.swipeAndPay();
    amex.onlinePayment();
    amex.tapAndPay();      // ❌ misleading: forced method not truly supported
    amex.refundAmount();

    return 0;
}
