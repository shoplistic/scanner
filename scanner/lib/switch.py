from gpiozero import Button
import ir
import led

switch = Button(23)

def onp():
    print('Open')
    ir.on('50')
    led.blue.on()

def onr():
    print('Closed')
    ir.off()
    led.blue.off()

switch.when_pressed = onp
switch.when_released = onr
is_pressed = switch.is_pressed
