# GHP Arduino Knock Sensor
-----------
Description
-----------


A simple Arduino program using a Keyes KY-031 Knock Impact Sensor. The program increments a counter every time the sensor is activated. Inspired by FizzBuzz, the program lights up LEDs based on specified divisibility. For example, a certain LED might light up on knocks 3, 6, 9, and so on.

------------
Guide
------------
##### The Hardware

Wire up your sensor. Connect it to VCC, GND, and a digital pin.
Hook up a couple of LEDs to digital pins.

![Wiring](https://i.imgur.com/pkajAoP.png)

##### The Software

You can download and modify the code from the repository if you want. Outlined below is the functionality of the software.

First, some values are defined. Pin numbers for the sensor as well as the LEDs are first (this example uses 4 LEDs). Then some variables are created for the counter as well as the Knock State. Initialize the counter to -1 if you want the first knock to be knock 1. Initialize the knock states both as zero.

In `setup()`, set your LEDs `pinMode` to `OUTPUT` and the sensor as `INPUT`. Specify a baud rate of 9600 for your serial monitor.

In `loop()`, read the knock sensor's input. If this knock state (either high or low) is different from the previous knock state, then add to the counter and print some stuff to the serial monitor. Otherwise, print out something saying that a knock isn't detected. After this, update the value of  `lastKnockState`.

Next you need to do the conditional statements for the LEDs. The basic framework of this is:

~~~~
if (knockCounter % 2 == 0) {
  digitalWrite(ledPin, HIGH);
} else {
  digitalWrite(ledPin, LOW);
}
~~~~

In the above example, the LED wired to pin `ledPin` will light up for every even numbered knock (because of the `% 2 == 0`). In the example code uploaded here, I have created another function, `light()`, which takes parameters for the ledPin and the modifier. This makes adding more LEDs much easier, as each new LED will require something like this:

`light(ledPin0, 3)`

Assuming `ledPin0` has already been defined as some integer for a pin number, this simply passes the values for the pin number and divisor into that conditional above. So this would light up the LED at pin `ledPin0` for every knock divisible by 3 (i.e. 3rd, 6th, 9th, etc).

-------
Contributors
-------

Anthony Romaniello (Software), Efrain Hernandez (Hardware)
