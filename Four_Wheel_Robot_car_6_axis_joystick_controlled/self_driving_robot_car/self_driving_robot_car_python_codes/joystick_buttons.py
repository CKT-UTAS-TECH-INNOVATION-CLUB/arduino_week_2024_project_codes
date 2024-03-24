import pygame
pygame.init()
pygame.joystick.init()

# Check if any joysticks are connected
if pygame.joystick.get_count() == 0:
    print("No joysticks detected.")
    pygame.quit()
    exit()
joystick = pygame.joystick.Joystick(0)  # Use joystick at index 0
joystick.init()
running = True

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Check button presses
    for i in range(joystick.get_numbuttons()):
        if joystick.get_button(i) == 1:
            print(f"Button {i} pressed")

    # Add your game logic here

pygame.quit()
