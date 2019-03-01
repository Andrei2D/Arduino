# What is GoodGameBoi ?

It's a one-game mini game console containing Asteroid Storm, programmed on an Arduino microcontroller. It's reacreating the feeling of the retro brick game console, which is personally a childhood symbol, while giving a modular experience (parts being able to swap out) and a swell feeling, provided by the sodering and arrangement.

# How to play the game ?

The logic of the game put boards you on a spaceship armed with lasers and the goal tells you to destroy all the asteroids, without getting hit or letting anyone get past you. 
You can either jump in the game or modify the difficulty for one that better represents your skill, but not before checking the highscores that already exist to know what you have to beat. 
You have 3 lives and your score calculates by adding the three resulted scores. The goal is the obtain a score as high as possible.
Moving is made by the joystick left and right and shooting from either left or right bezzel is made by pressing the coresponding on the right.
    
# Other game mechanics
A new row of asteroids spawns every 1.5 seconds or faster with a random amount of asteroids, both depending on the difficulty. Missing asteroids is penalised for a short period of time, preventing you from shooting. Shooting and moving is posible.

# Componets

 * Arduino Nano
 * Joystick
 * Push buttons
 * LCD 1602A-1 
 * 8x8 LED matrix
 * MAX7219 matrix driver
 * PCB 70 * 140 mm
 
# Code details

The code is organised on 3 major parts: 
* IO's management 
* Game layering
* Game implementation

IO management consists of classes either build around existent, such as LiquidCrystal, on top of which extra functionalities were added for easing the use, either build to replace an exitent mechanic with drawbacks, such as MillisWait replacing the delay() function and sharing the functionality when used corectly or build to control a specific element, such as buttons or a joystick.

Game layering consists the way the game was interpreted: as multiple entities with different behaviors but a common property, being a bit matrix. 

Game implementation consists of using and organising all the parts above in convenient manner and mainly on states switching from one into another.


# Demo


	
