NAME
----
RougeLove

VERSION
-------
1.0
[Note: Executable can be found in the Debug folder]

DESCRIPTION
-----------
This is a Console roguelike RPG game in which you need to control the character to explore the maze to find your love and face all the enemies in your way.
The objective of the game is to reach the exit space and maintain the highest HP.

INSTRUCTION
-----------
Before playing this game, you should include the two dll files listed above(libtcod-VS.dll,SDL.dll). [Note: These dll files are included with the game as well]
To play this game, press arrow keys to control the character to move arround;
press space key to kill the monsters.

API
---
libtcod

EXTERNAL RESOURCES
------------------
libtcod-VS.dll,SDL.dll
(URL: http://roguecentral.org/doryen/libtcod/download/ )

Environment Setup for Visual Studio 	{VERY IMPORTANT}
(URL: http://daraprogramming.blogspot.com/2014/08/setting-up-libtcod-151-with-visual.html) 

REFERENCE
---------
RogueBasin, ASCII Generator
(URL: http://www.roguebasin.com/index.php?title=Main_Page, http://www.network-science.de/ascii/)

BONUSES & EXTRAS
----------------

47] Created own implementation of a stack based list which stores template objects

53] Kind of implemented globals in a singleton design pattern. We did not want multiple global objects having same values since they create redundancy. Hence we have one class with all public static members.

54] All Main game objects can easily be thrown in a text file and read if a counter is set. Like Player and player position, Enemies and their postion and Map is already being read from a text file.

55] Game uses a component system where the main GameObjects are Player and Enemies. These along with the map are updated and rendered separately.






