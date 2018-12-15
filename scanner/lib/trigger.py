from gpiozero import Button
import status, led

sensor = Button(24)

def on():
    print('Open')
    led.on(3)
    status.blue.on()

def off():
    print('Closed')
    led.off()
    status.blue.off()

sensor.when_pressed = on
sensor.when_released = off
