import bluetooth

# Your Bluetooth adapter needs to be in HID mode
server_sock = bluetooth.BluetoothSocket(bluetooth.L2CAP)

bt_addr = 'YOUR_BT_ADAPTER_ADDRESS'
port = 0x1001

server_sock.bind((bt_addr, port))
server_sock.listen(1)

client_sock, client_info = server_sock.accept()
print('Accepted connection from', client_info)

try:
    while True:
        # You would need to capture key presses here and send them over Bluetooth
        data = input("Type a message: ")
        client_sock.send(data)
finally:
    print("Disconnected.")

    client_sock.close()
    server_sock.close()
