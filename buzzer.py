import RPi.GPIO as GPIO
import time

buzzerPin = 8
buttonPin = 2

GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzerPin, GPIO.OUT)
GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

pwm = GPIO.PWM(buzzerPin, 440)
pwm.stop()

def tone(freq):
    pwm.ChangeFrequency(freq)
    pwm.start(50)

def noTone():
    pwm.stop()

melody = [
    (294, 0.5),
    (330, 0.2),
    (294, 0.5),
    (370, 0.75),
    (294, 0.5),
    (330, 0.2),
    (294, 0.5),
    (370, 0.75),
    (294, 0.5),
    (330, 0.2),
    (294, 0.5),
    (247, 0.5),
    (294, 0.75),
]

try:
    while True:
        if GPIO.input(buttonPin) == GPIO.LOW:
            for freq, duration in melody:
                tone(freq)
                time.sleep(duration)

            noTone()

            while GPIO.input(buttonPin) == GPIO.LOW:
                time.sleep(0.05)

        else:
            noTone()
            time.sleep(0.05)

except KeyboardInterrupt:
    pwm.stop()
    GPIO.cleanup()
