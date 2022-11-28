# toyCar
Made a toy car out of an arduino nano, sound sensor, motors, batteries, etc. 
Turns right when clapped twice, left when clapped three times, and reverse when clapped four times times. 

# Logistics
Timer activates when sound sensor detects a loud spike in noise from a clap.
If another intense volume is detected within a predefined time duration then timer is reset to detect more potential claps. 

Two H-bridge L298N Motor Drive is connected to two motors each. The motors rotate clockwise and counterclockwise to turn the car back and forth.
One motor rotates while the other doesn’t in order to pivot the car left/right across the motionless wheel.
