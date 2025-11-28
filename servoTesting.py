from gpiozero import Servo
from gpiozero import TonalBuzzer
from time import time, sleep
from gpiozero.tones import Tone

servo = Servo(7, min_pulse_width=0.5/1000, max_pulse_width=2.5/1000)
buzzer = TonalBuzzer(8)

eje1 = 90
servo.value = 0

started = False
start_time = 0

while True:
    if not started:
        start_time = time()
        started = True


    if time() - start_time >= 10:
        print("10 seconds passed!")
        started = False

        eje1 = 30
        servo.value = (eje1 - 90) / 90.0

        buzzer.play(Tone(294))
        sleep(1)
        buzzer.stop()

    sleep(0.01)
