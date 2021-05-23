# Zork

## Author
 Armando González Arias  
 [LinkedIn](https://www.linkedin.com/in/armandojaga/)  
 [Twitter](https://twitter.com/armandojaga)  
 [Email](mailto:me@armando.dev)  

 ## GitHub repository

All the code is located in my personal github repository:  
https://github.com/armandojaga/zork

## About
This is my take on Zork for admission to the Advanced Programming for AAA Video Games program.

You are a regular developer who went on a cruise to recharge batteries from your tiring work, you were enjoying the trip but then there was a sudden storm that sunk the ship and you ended up stranded on an unknown, seemenly inhabited island, now you have find a way to get back home.

## Commands

Here is the list of the available commands in the game, along with a description on how to use them.

You have to enter commands to instruct the character on what to do.  
What you see in parenthesis is a shortcut for the command, you can enter either the full command or the shortucut, 
followed by the target parameter, insde "*{}*" are optional parameters, "|" indicates that you can use one or the other.

The format is: **command (*shorcut*) [*target*]**

Available commands:  

**[direction]** : travel to the specified direction 
 - north (*n*)
 - south (*s*)
 - east (*e*)
 - west (*w*)
 - northeast (*ne*)
 - northwest (*nw*)
 - southeast (*se*)
 - southwest (*sw*)
 - up (*u*)
 - down (*d*)  

**go [*direction*]** : travels to the specified direction  
**attack (*kill*) [*enemy*] {with [weapon]}** : attacks a particular enemy  
**take [*item|all*]** : adds an item to the player's inventory, use "*all*" to add all available items in the scene  
**drop [*item|all*]** : removes a particular item from the player's inventory, use "*all*" to remove all items  
**inventory (*i*)** : shows the items in the player's inventory  
**open [*item*]** : opens an item that contains other items  
**look** : looks around at current scene  
**eat [**item**]**: eats a particular item  
**help** : displays this help  

## Guide

The objective of the game is to collect **three** pieces of a broken radio to call for help.  
Refer to the [map][map] below for reference.

You start in the *Shore*, from there you can only go east to the *Forest trail*, 
where you find your first enemy, a *Snake*, you can either kill it or continue east 
to the *Cabin*, this snake drops the **Speaker** when killed.  
There is a *Chest* but it's locked, you need a key to open it, go down to the *Water well* to take the key and once you have it go back up and open the chest to reveal a *Sword* and a *Lamp*, take them both.
You need the *Lamp* to see in dark places, like the *Cave* that is located to the east of the *Cabin*.  
Go east from the *Cave* with the *Lamp* and the swin your inventory and you'll find a *Bear*, kill it and it will drop the **Radio**.  
Go back west to the *Cabin* and head northwest to the *Forest*, fom here you can go up the three to the *Tree top* and take the *Bow* and *Arrow*.  
Climb down the tree to the *Forest* and head to the *Deep forest* in the northeast, here you'll find a *Goblin*, kill it and it will drop the **Antenna**, the final item you need to call for help and escape the island, back to your home.


### TL;DR
These are the commands you need to play to beat the game:  
- go east
- go east
- go down
- take key
- go up
- open chest
- take all
- go east
- kill bear with sword #(**repeat until dead**)
- take radio
- go west
- go northwest
- *take herb*
- *eat herb*
- go up
- take all
- go down
- go norteast
- attack goblin with bow
- attack goblin with sword #(**repeat until dead**)
- take antenna
- go soutwest
- go south
- attack snake with sword
- take speaker

Following that you will be rescued and go back home.

## Map 
[map]: #map "Map"

![My Zork map](resources/map.PNG)

## Notes
The code was built using the **10.0.17763.0** version of the *Windows SDK*.

The scenes in the game are build from **.scene** config files, this is the format used:  

>id  
>name  
>short_desciption  
>long_description  
>[DARK]  
>#PATHS#  
>direction|scene_id  
>[...]  
>#ITEMS#  
>[name|type|magnitude|container]  
>[...]  
>#FOES#  
>[name|description|health|damage][|item|...]  
>[...]  

**[]** indicates an optional line of field  
**...** indicates repetition  

**At least one path must be indicated**