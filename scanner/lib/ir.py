from subprocess import call

def on(intensity):
    call(['../i2c/i2c.out', intensity])

def off():
    call(['../i2c/i2c.out', '0'])
