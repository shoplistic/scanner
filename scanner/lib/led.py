from gpiozero import LED
from time import sleep

# red = LED(17)
# blue = LED(27)
# green = LED(22)

class Led(LED):
    # def __init__(self, pin):
    #     self.led = LED(pin)

    # def on(self):
    #     self.led.on()

    # def off(self):
    #     self.led.off()

    def timer(self, time):
        self.on()
        sleep(time)
        self.off()

red = Led(17)
green = Led(27)
blue = Led(22)
