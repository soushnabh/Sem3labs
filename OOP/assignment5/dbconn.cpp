#include <iostream>

using namespace std;

class DatabaseConnection {
    public:
        virtual void logConnectionStatus() {
            cout<<"log connection established"<<endl;
        }
        DatabaseConnection() {
            logConnectionStatus();
        }
};

class SecureConnection: public DatabaseConnection {
    public:
        void logConnectionStatus() {
            cout<<"Secure logged"<<endl;
        }
        SecureConnection(): DatabaseConnection() {}
};

int main() {
    SecureConnection sc;

    return 0;
}
