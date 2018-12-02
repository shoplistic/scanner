from gpiozero import Button
import status, led

switch = Button(23)

def onp():
    print('Open')
    led.on(3)
    status.blue.on()

def onr():
    print('Closed')
    led.off()
    status.blue.off()

switch.when_pressed = onp
switch.when_released = onr
is_pressed = switch.is_pressed
