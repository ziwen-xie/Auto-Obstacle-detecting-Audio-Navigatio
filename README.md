# HARDWARE
##Content
The respotory contains the Arduino code for the car.
## Inspiration
I saw people with visual impairments using crutch to detect possible hazards carefully and trying to avoid them on the road. Before every step, they need to use the crutch to detect around for a large radius. This time I had a chance to work with the robot car, after making it move, I was thinking maybe I can add more functions to make it help with more real life problems. Thus I tried to design this Auto Obstacle-detecting Audio Navigation Car. Hoping that the complete functionalized car can serve as a guiding role, help detecting the road hazards and warn user. 

## What it does
After open the battery, it will be activated to start, the speaker will play a short melody to indicate that it has started, the car will then detecting the distance to the obstacles and choose the right way. It will then send out a signal to the speaker and let speaker have different sound indicating the car is turn in different location.
## How we built it
This car was built on the assembled robot car kit. With the ultrasonic sensing module, it can be coded to detect the distance to obstacle using the ultrasonic module. I then connected a speaker to the ELEGOO shield board, as well as a resistor on breadboard to reduce the impact of current passing through the IO pin( The speaker is 8ohm and I calculated that if without the help of the resistor it will receive a rather large current and will have the possibility to make it stop function, so connected it with a 500ohm resistor)
## Challenges we ran into
The volume of the speaker is still too small, especially under the effect that when the car is activated the noise of the motor is rather big and could make the sound of the speaker unclear. 
## Accomplishments that we're proud of
I am proud that it works successfully. 
## What we learned
I learned the work mechanism of a robot car after assembly it by myself, I also understand the mechanism of different module functions that make a robot car interactive with environments. I practiced my technique in writing Arduino code and practice the design procedure. 
## What's next for Auto Obstacle-detecting Audio Navigation Car
1. Add amplifiers to the speaker to make greater volume. 
2. improve the obstacle detecting algorithms to make it more functionalized.
3. Change the music into vocal instructions to make it more user friendly.
4. add wireless function to make it possible to send signal to earphones
