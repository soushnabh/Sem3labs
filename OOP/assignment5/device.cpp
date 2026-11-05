#include <iostream>

using namespace std;

class SmartDevice {
    protected:
        bool device_status;
    public:
        virtual void turnOn() {
            cout<<"Turning Device On..."<<endl;
            device_status = true;
        }
        virtual void turnOff() {
            cout<<"Turning Device Off..."<<endl;
            device_status = false;
        }
        virtual bool getDeviceStatus() = 0;
        virtual ~SmartDevice() = default;
};

class SmartLight: public SmartDevice {
    public:
        int dim_percent;
        void turnOn() {
            cout<<"Turning SmartLight On (dimmed to 50%)..."<<endl;
            device_status = true;
            dim_percent = 50;
        }
        void turnOn(int dim_percent) {
            cout<<"Turning SmartLight On (dimmed to "<<dim_percent<<"%)..."<<endl;
            device_status = true;
            dim_percent = dim_percent;
        }
        virtual bool getDeviceStatus() {
            return device_status;
        }
};

class SmartThermostat: public SmartDevice {
    public:
        virtual bool getDeviceStatus() {
            return device_status;
        }
};

int main() {
    SmartLight light;
    SmartThermostat thermostat;

    // Array of base class pointers managing different devices
    SmartDevice* devices[2];
    devices[0] = &light;
    devices[1] = &thermostat;

    cout << "Turning all devices ON" << endl;
    for (int i = 0; i < 2; i++) {
        devices[i]->turnOn();
        cout << "Status: " << (devices[i]->getDeviceStatus() ? "Active" : "Inactive") << endl;
        cout << endl;
    }

    light.turnOn(80);

    cout << "\nTurning all devices OFF" << endl;
    for (int i = 0; i < 2; i++) {
        devices[i]->turnOff();
    }

    return 0;
}
