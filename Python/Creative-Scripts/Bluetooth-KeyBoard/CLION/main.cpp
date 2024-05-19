#include <windows.h>
#include <iostream>
#include <bthdef.h>
#include <Bluetoothapis.h>

#pragma comment(lib, "Bthprops.lib")

int main() {
    BLUETOOTH_FIND_RADIO_PARAMS m_bt_find_radio = { sizeof(m_bt_find_radio) };
    HANDLE m_radio = NULL;
    HBLUETOOTH_RADIO_FIND m_bt = BluetoothFindFirstRadio(&m_bt_find_radio, &m_radio);

    if (m_bt != NULL) {
        std::cout << "Bluetooth radio found." << std::endl;
        // Do something with the radio
        BluetoothFindRadioClose(m_bt);
    } else {
        std::cout << "No Bluetooth radios found." << std::endl;
    }

    return 0;
}
