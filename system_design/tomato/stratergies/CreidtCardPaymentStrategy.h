#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include <bits/stdc++.h>
#include "PaymentStartegy.h"
using namespace std;

class CreditCardPaymentStartegy : public PaymentStrategy{
private:
    string cardNumber;
public:
    CreditCardPaymentStartegy(const string& card){
        cardNumber = card;
    }

    void pay(double amount) override{
        cout << "Paid ₹" << amount << " using Credit Card (" << cardNumber << ")" << endl;
    }
};

#endif