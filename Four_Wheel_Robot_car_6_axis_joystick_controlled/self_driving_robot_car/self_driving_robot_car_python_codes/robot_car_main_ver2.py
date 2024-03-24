import pygame
import serial
import sys

import time

# Initialize Pygame
pygame.init()

# Initialize the joystick
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

# Set up the serial connection to Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)  # Adjust the serial port and baud rate

try:
    while True:
        pygame.event.pump()

        # Read joystick axes
        x_axis = joystick.get_axis(0)  # Get the X-axis value (-1 to 1)
        y_axis = joystick.get_axis(1)  # Get the Y-axis value (-1 to 1)

        y1_axis = joystick.get_axis(4)  # Get the Y1-axis value (-1 to 1)
        x1_axis = joystick.get_axis(3)  # Get the X1-axis value (-1 to 1)

        center_horizontal_axis = joystick.get_axis(2)  # Get the X1-axis value (-1 to 1)

        center_vertical_axis = joystick.get_axis(5)  # Get the X1-axis value (-1 to 1)




        if y_axis == -1.0:
            data_to_send = "forward\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif y_axis == 0.999969482421875:
            data_to_send = "backward\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif x_axis == 0.999969482421875:
            data_to_send = "turn_right_forward\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif x_axis == -1.0:
            data_to_send = "turn_left_forward\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second



        else:
            data_to_send = "stop\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        print(x_axis)
        print(" ")
        print(y_axis)

        # The camera controls starts here






        if y1_axis == -1.0:
            data_to_send = "turn_camera_up\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif center_vertical_axis == 0.999969482421875:
            data_to_send = "normal_vertical_camera\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif center_horizontal_axis == 0.999969482421875:
            data_to_send = "normal_horizontal_camera\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif y1_axis == 0.999969482421875:
            data_to_send = "turn_camera_down\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif x1_axis == -1.0:
            data_to_send = "turn_camera_left\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif x1_axis == 0.999969482421875:
            data_to_send = "turn_camera_right\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        else:
            pass

        # The camera controls ends here

        if joystick.get_button(9) == 1:
            data_to_send = "front_light_on\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif joystick.get_button(6) == 1:
            data_to_send = "front_light_off\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif joystick.get_button(10) == 1:
            data_to_send = "back_light_on\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second


        elif joystick.get_button(7) == 1:
            data_to_send = "back_light_off\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif joystick.get_button(8) == 1:
            data_to_send = "horn\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        else:
            pass



        # Speed control
        if joystick.get_button(3) == 1:
            data_to_send = "speed_70\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif joystick.get_button(2) == 1:
            data_to_send = "speed_110\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif joystick.get_button(0) == 1:
            data_to_send = "speed_150\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif joystick.get_button(1) == 1:
            data_to_send = "speed_200\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        else:
            pass

        if joystick.get_button(5) == 1:
            data_to_send = "stop\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif joystick.get_button(4) == 1:
            data_to_send = "speed_0\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second






except KeyboardInterrupt:
    # Close the serial connection and quit Pygame
    ser.close()
    pygame.quit()
    sys.exit()
