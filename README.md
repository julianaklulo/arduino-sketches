My Arduino Sketches
=======
Hello! I'm an IoT and electronics enthusiast and these are some of my Arduino sketches.

## [Galileo Unread Email Counter](https://github.com/julianaklulo/arduino-sketches/blob/master/GalileoUnreadEmailCounter/GalileoUnreadEmailPython.ino)
Fetches the quantity of unread emails at Gmail and displays it in a LCD display. Needs to be run in a Intel Galileo board.

## [EnC's Universidade Aberta Project](https://github.com/julianaklulo/arduino-sketches/blob/master/HCSR05_RGB_LCD.ino)
Measures the distance using a HC-SR05 ultrasound sensor and uses it to fade the color of a RGB LED. Also displays the distance in a LCD display.

## [Intelligent Termometer](https://github.com/julianaklulo/arduino-sketches/blob/master/intelligentTermometer.ino)
Measures the temperature using a thermistor and uses it to fade the color of a RGB LED. If the temperature is over 38ºC, activates a buzzer. Also displays the temperature in a LCD display.

## [Morse Code Translator](https://github.com/julianaklulo/arduino-sketches/blob/master/MorseCodeTranslator.ino)
Receives a message via Bluetooth using a HC-05 Bluetooth module and translates it to Morse code. The Morse code is reproduced using a buzzer and the corresponding message is displayed in a LCD display.

## [Bluetooth Controlled Robot](https://github.com/julianaklulo/arduino-sketches/blob/master/robo_bluetooth.ino)
Controls a 2-wheeled robot using a HC-05 Bluetooth module to receive commands from an Android app. The motor's rotations are controlled using a H-Bridge L298D IC.

## [Avoid Obstacles Robot](https://github.com/julianaklulo/arduino-sketches/blob/master/robo_desvia_obstaculo.ino)
Controls a 2-wheeled robot that avoids obstacles using a HC-SR05 ultrasound sensor mounted on top of a Micro Servo Motor. When the robot encounters a obstacle ahead, it measures the distance on its left and its right and moves to the direction with the largest distance.