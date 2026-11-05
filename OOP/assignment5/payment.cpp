#include <iostream>

using namespace std;

class Payment {
    public:
        virtual void processPayment(double amount) = 0;
        virtual ~Payment() = default;
};

class CreditCardPayment: public Payment {
    public:
        void processPayment(double amount) {
            cout<<"paying amount: "<<amount<<" via Credit Card..."<<endl;
        }
};

class PayPalPayment: public Payment {
    public:
        void processPayment(double amount) {
            cout<<"paying amount: "<<amount<<" via PayPal..."<<endl;
        }
};

class BitcoinPayment: public Payment {
    public:
        void processPayment(double amount) {
            cout<<"paying amount: "<<amount<<" via Bitcoin..."<<endl;
        }
};

void executeTransaction(Payment* paymentMethod, double amount) {
    paymentMethod->processPayment(amount);
}

int main() {
    CreditCardPayment c;
    PayPalPayment p;
    BitcoinPayment b;

    executeTransaction(&c, 50);
    executeTransaction(&p, 100);
    executeTransaction(&b, 150);
    return 0;
}
