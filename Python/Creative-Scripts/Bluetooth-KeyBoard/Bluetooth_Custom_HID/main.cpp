#include <QCoreApplication>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothLocalDevice>
#include <iostream>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Check if Bluetooth is available on the device
    if (!QBluetoothLocalDevice::allDevices().isEmpty()) {
        QBluetoothLocalDevice device;
        device.powerOn(); // Make sure Bluetooth is powered on

        // Create a device discovery agent and start discovery
        QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
        QObject::connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
                         [](const QBluetoothDeviceInfo &info) {
                             std::cout << "Found device: " << info.name().toStdString()
                                       << " Address: " << info.address().toString().toStdString() << std::endl;
                         });

        discoveryAgent->start();

        std::cout << "Scanning for Bluetooth devices..." << std::endl;
    } else {
        std::cout << "Bluetooth is not available on this device." << std::endl;
        return -1;
    }

    return app.exec();
}
