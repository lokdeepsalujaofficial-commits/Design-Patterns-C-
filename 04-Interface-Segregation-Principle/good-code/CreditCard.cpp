#include <iostream>
using namespace std;

// Base card: common capabilities for all cards
class CreditCard {
public:
    virtual void swipeAndPay() = 0;
    virtual void onlinePayment() = 0;
    virtual ~CreditCard() = default;
};

// Separate, optional capabilities
class TapPayable {
public:
    virtual void tapAndPay() = 0;
    virtual ~TapPayable() = default;
};

class RefundCompatibleCC {
public:
    virtual void refundAmount() = 0;
    virtual ~RefundCompatibleCC() = default;
};

// Visa supports tap + refund
class Visa : public CreditCard, public TapPayable, public RefundCompatibleCC {
public:
    void swipeAndPay() override   { cout << "Visa: swipeAndPay\n"; }
    void onlinePayment() override { cout << "Visa: onlinePayment\n"; }
    void tapAndPay() override     { cout << "Visa: tapAndPay\n"; }
    void refundAmount() override  { cout << "Visa: refund processed\n"; }
};

// Amex does not support tap in this scenario, but supports refund
class Amex : public CreditCard, public RefundCompatibleCC {
public:
    void swipeAndPay() override   { cout << "Amex: swipeAndPay\n"; }
    void onlinePayment() override { cout << "Amex: onlinePayment\n"; }
    void refundAmount() override  { cout << "Amex: refund processed\n"; }
};

// Clients depend only on what they need
void doSwipe(CreditCard& card)              { card.swipeAndPay(); }
void doOnline(CreditCard& card)             { card.onlinePayment(); }
void doTap(TapPayable& card)                { card.tapAndPay(); }
void doRefund(RefundCompatibleCC& card)     { card.refundAmount(); }

int main() {
    cout << "=== ISP (C++ with CreditCard base + capabilities) ===\n";

    Visa visa;
    Amex amex;

    doSwipe(visa);  doOnline(visa);  doTap(visa);  doRefund(visa);
    doSwipe(amex);  doOnline(amex);                doRefund(amex);
    // doTap(amex); // compile-time: Amex is not TapPayable

    return 0;
}
