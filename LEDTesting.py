import RPi.GPIO as GPIO
import time

buttonPin = 3
redPin = 9
greenPin = 10
bluePin = 11

GPIO.setmode(GPIO.BCM)
GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(redPin, GPIO.OUT)
GPIO.setup(greenPin, GPIO.OUT)
GPIO.setup(bluePin, GPIO.OUT)

counter = 0

def set_color(r, g, b):
    GPIO.output(redPin, r)
    GPIO.output(greenPin, g)
    GPIO.output(bluePin, b)

try:
    while True:
        buttonState = GPIO.input(buttonPin)
        
        if buttonState == GPIO.LOW:
            counter += 1
            if counter > 4:
                counter = 0
            time.sleep(0.25)
            
        if counter == 0:
            set_color(0, 0, 0)
        elif counter == 1:
            set_color(1, 0, 0)
        elif counter == 2:
            set_color(0, 1, 0)
        elif counter == 3:
            set_color(0, 0, 1)
        elif counter == 4:
            set_color(1, 0, 1)
        
        time.sleep(0.01)

except KeyboardInterrupt:
    set_color(0, 0, 0)
    GPIO.cleanup()
