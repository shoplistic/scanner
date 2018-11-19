from gpiozero import Button
import ir

def onp():
    print('Open')
    ir.on('50')

def onr():
    print('Closed')
    ir.off()

switch = Button(18)
switch.when_pressed = onp
switch.when_released = onr
is_pressed = switch.is_pressed
