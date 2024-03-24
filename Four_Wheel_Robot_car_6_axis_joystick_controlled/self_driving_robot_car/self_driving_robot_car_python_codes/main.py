import serial
import time
import command
# Define the serial port and baud rate
ser = serial.Serial('/dev/ttyACM0', 9600)  # Change the port as needed

try:
    while True:
        # data_to_send = "forward\n"  # Data to send to Arduino
        data_to_send = command.forward()  # Data to send to Arduino
        ser.write(data_to_send.encode())  # Send the data to Arduino
        time.sleep(3)  # Delay for 1 second

        data_to_send = command.backward()  # Data to send to Arduino
        ser.write(data_to_send.encode())  # Send the data to Arduino
        time.sleep(3)  # Delay for 1 second

        data_to_send = command.stop()  # Data to send to Arduino
        ser.write(data_to_send.encode())  # Send the data to Arduino
        time.sleep(10)  # Delay for 1 second


except KeyboardInterrupt:
    data_to_send = command.stop()  # Data to send to Arduino
    ser.write(data_to_send.encode())  # Send the data to Arduino
    ser.close()  # Close the serial connection when exiting the script
