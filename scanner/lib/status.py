from gpiozero import LED
from time import sleep

class Led(LED):

    def timer(self, time):
        self.on()
        sleep(time)
        self.off()

red = Led(17)
green = Led(27)
blue = Led(22)
