from subprocess import call, STDOUT
from os import devnull

FNULL = open(devnull, 'w')

def on(intensity):
    call(['../i2c/i2c.out', intensity], stdout=FNULL, stderr=STDOUT)

def off():
    call(['../i2c/i2c.out', '0'], stdout=FNULL, stderr=STDOUT)
