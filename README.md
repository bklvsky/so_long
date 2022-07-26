# So_long

My first game project for school 21, campus of Ecole 42. A small 2D maze game with animated sprites and enemies, using educational graphic library MiniLibX, a simplified version of the Xlib.  

## Usage

This version is only available for Linux.  
Run `make bonus` in the project directory to create an executable.  
Then `./so_long ./maps/bonus_maps/map.ber` to run the game.

## About the project  
The player’s goal is to collect every collectible present on the map, then escape,  
chosing the shortest possible route.
There are also enemies, that make the player lose and simple stop motion animation.
You can move around the maze using  W A S D keys. Also it is possible to rotate a point of view with a mouse.
To exit press on the red cross of the window or an ESC button.

![screenshot_1](/.screenshot/screenshot-frog.jpg)

The game requires a configuration file in .ber format. There are a few maps in the ./maps directory with different map structures and textures. They can be adjusted and modified as you need.
`1` and `0` mean walls and empty space accordingly; `H` and `V` are enemies, moving in different directions; `E` is an escape door; and `C` is a collectible sprite.

## Summary
It was my first graphical project; I learned to work with textures and animation in low-level programming.  
I definitely had a lot of fun, doing it.

![screenshot_2](/.screenshot/screenshot.jpg)
