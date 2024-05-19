#include <QCoreApplication>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothLocalDevice>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Check if Bluetooth is available on the device
    if (!QBluetoothLocalDevice::allDevices().isEmpty()) {
        QBluetoothLocalDevice device;
        device.powerOn(); // Make sure Bluetooth is powered on

        // Create a device discovery agent and start discovery
        auto discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
        QObject::connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
                         [](const QBluetoothDeviceInfo& info) {
                             cout << "Found device: " << info.name().toStdString()
                                  << " Address: " << info.address().toString().toStdString() << endl;
                         });

        discoveryAgent->start();

        cout << "Scanning for Bluetooth devices..." << endl;
    } else {
        cout << "Bluetooth is not available on this device." << endl;
        return -1;
    }

    return app.exec();
}
