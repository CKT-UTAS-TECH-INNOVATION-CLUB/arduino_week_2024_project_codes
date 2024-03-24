import pygame
import serial
import sys
import command
import time

# Initialize Pygame
pygame.init()

# Set up the Pygame window
screen = pygame.display.set_mode((400, 400))
pygame.display.set_caption("Virtual Joystick")

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# Initialize the serial connection to Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)  # Adjust the serial port and baud rate

# Create a virtual joystick position
joystick_x = 0
joystick_y = 0

try:
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        # Read the virtual joystick position
        keys = pygame.key.get_pressed()
        if keys[pygame.K_UP]:

            joystick_y = -1
            data_to_send = "forward\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif keys[pygame.K_DOWN]:

            joystick_y = 1
            data_to_send = "backward\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        else:
            joystick_y = 0

        if keys[pygame.K_LEFT]:

            joystick_x = -1
            data_to_send = "stop\n"  # Data to send to Arduino
            ser.write(data_to_send.encode())  # Send the data to Arduino
            time.sleep(0.5)  # Delay for 1 second

        elif keys[pygame.K_RIGHT]:
            joystick_x = 1
        else:
            joystick_x = 0

        # Send motor control commands to Arduino
        left_motor_speed = int(255 * joystick_y)
        right_motor_speed = int(255 * joystick_x)

        command = f"{left_motor_speed},{right_motor_speed}\n"
        ser.write(command.encode())

except KeyboardInterrupt:
    # Send a stop command and close the serial connection when quitting
    ser.write("0,0\n".encode())
    ser.close()
    pygame.quit()
    sys.exit()
