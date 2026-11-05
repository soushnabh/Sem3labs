#include <iostream>

using namespace std;

// --- Report Hierarchy ---
class Report {
    public:
        virtual void display() {
            cout << "Generic Employee Report" << endl;
        }
        virtual ~Report() = default;
};

class FullTimeReport : public Report {
    public:
        void display() {
            cout << "Full-Time Employee Report: Salary + Benefits included." << endl;
        }
};

class ContractReport : public Report {
    public:
        void display() {
            cout << "Contract Employee Report: Hourly Rate + Invoice included." << endl;
        }
};


class Employee {
    public:
        virtual Report* generateReport() = 0;
        virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee {
    public:
        FullTimeReport* generateReport() {
            return new FullTimeReport();
        }
};

class ContractEmployee : public Employee {
    public:
        ContractReport* generateReport() {
            return new ContractReport();
        }
};


int main() {
    FullTimeEmployee fte;
    ContractEmployee ce;
    FullTimeReport* ftReport = fte.generateReport();
    ContractReport* ctReport = ce.generateReport();

    cout << "Direct calls" << endl;
    ftReport->display();
    ctReport->display();

    cout << "\nPolymorphic call via base pointer" << endl;
    Employee* emp = &fte;
    Report* genericReport = emp->generateReport();
    genericReport->display();

    delete ftReport;
    delete ctReport;
    delete genericReport;

    return 0;
}
