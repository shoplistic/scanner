from gpiozero import Button
import status, led

sensor = Button(23)

def on():
    print('Open')
    led.on(3)
    status.blue.on()

def off():
    print('Closed')
    led.off()
    status.blue.off()

sensor.when_pressed = off
sensor.when_released = on

if sensor.is_pressed:
    off()
else:
    on()
