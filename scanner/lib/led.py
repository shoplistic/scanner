import pigpio

pwm_pin = 18 # GPIO Pin
freq = 5100 # Frequency (Hz)
# dc = 0 # Duty cycle (%)

pi = pigpio.pi()

def on(intensity):
    pi.hardware_PWM(pwm_pin, freq, 1e4 * (intensity % 100))

def off():
    pi.hardware_PWM(pwm_pin, 0, 0)
