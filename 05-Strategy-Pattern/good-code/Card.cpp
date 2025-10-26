#include <iostream>
using namespace std;

class RefundStrategy {
public:
    virtual double refund(double amount) = 0;
    virtual ~RefundStrategy() {}
};

class FullRefund : public RefundStrategy {
public:
    double refund(double amount) { return amount; }
};

class TenPercentFeeRefund : public RefundStrategy {
public:
    double refund(double amount) { return amount * 0.9; }
};

class Visa {
    RefundStrategy& strategy;
public:
    Visa(RefundStrategy& s) : strategy(s) {}
    void swipeAndPay() { cout << "Visa: swipe\n"; }
    void refundAmount(double amt) { cout << "Visa refund: " << strategy.refund(amt) << "\n"; }
};

int main() {
    FullRefund full;
    TenPercentFeeRefund fee;

    Visa visaFull(full);
    Visa visaFee(fee);

    visaFull.swipeAndPay();
    visaFull.refundAmount(100);

    visaFee.swipeAndPay();
    visaFee.refundAmount(100);
}
