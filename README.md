## First Person Shotter Real Life
Build a game in  C++ Unreal Engine manuplating a wepeon in real time based on the accelorometer and magnetometer data from the mobile.
I build a flutter udp client app which sends acclerometer and magnetometer data to specified IP Address and Port number.
This raw data is being recived by the UDP server in Unreal Engine and based on the values the sensors orientation of the gun is manuplated.
i am thinking of making something like where user can where a VR headset and see around in a 360 degree 3D enviorment and hold a mobile and point it in a 3D world and the gun's orientation will be manuplated based on mobile's orientation user can also shoot  the bots in game.

## Motivation
One Day I was just playing around with my little brother he was pointing his hand making  gun guesture against me and yelling the gun shooting noices.
so i thought why not make someting similar to this so i came up with an idea  of  using a mobile as a gun and manuplating the gun object in the game based on mobile's orientation.


## Build status
game crashing sometimes can't figure out why .


## Video


https://user-images.githubusercontent.com/47350008/116870515-8e597100-abc7-11eb-9d1b-bd6558f16733.mp4


## Tech/framework used
Ex. -
<li>
<ul><b>C++</b></ul>
<ul><b>Unreal Engine</b></ul>
</li>

## Features
this project uses UDP for low latancy data trasefer between devices.



## Installation
getting unreal engine ready https://docs.unrealengine.com/en-US/Basics/InstallingUnrealEngine/index.html
build the flutter udp client app https://github.com/USAMAWIZARD/send-sensordata-with-udp-flutter 


## How to use?

<b>clone this repository build it using unreal </b>
<b>clone udp client app repository (https://github.com/USAMAWIZARD/send-sensordata-with-udp-flutter)  build it with flutter </b>

start the app and enter the ip address and port number and click send.


## Contribute

All the contiributions are wellcome

## Credits
https://forums.unrealengine.com


## License
(MIT, Apache etc)

MIT © [USAMAWIZARD]()
