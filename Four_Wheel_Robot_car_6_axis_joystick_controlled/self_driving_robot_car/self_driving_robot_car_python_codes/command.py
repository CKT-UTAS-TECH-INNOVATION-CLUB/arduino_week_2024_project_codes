def command(cmd):
    return cmd + "\n"


def forward():
    return command("forward")


def backward():
    return command("backward")


def stop():
    return command("stop")


def set_speed(spd):
    return command(str(spd))
