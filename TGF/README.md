# Terminal Game FrameWork

> Committed to building a C++ programming framework for terminal games, and at the same time for learning design patterns.

**Author:Migraine-sudo**

> **Q:how to use this framework**
>
> **A:add #include"TGF_lib.h" ahead of  your cpp code** 

### API Document

**keyboard_support.h: provide  keyboard input and react**

- Keyboard::getbit() :get Keyboard::bit

- Keyboard::recv() : using _kbhit() to check hit and store the input in Keyboard::bit.
- Keyboard::deal_keys() : this is private function,you can override it to edit the pg to react to keyborad 

**cross_platform_support.h: provide cross platform support**

- _kbhit(): Just the same like _kbhit() in windows,check the hint on keyboard
- clear_term(): clear the termianl screen
- Set windows() :set the size of terminal window (for example setwindow(28,95))

**TGF_Map.h : A template class,help developers to create a map of game more quick**

- TGF_Map::Length(): get length of map
- TGF_Map::width() :get width of map
- TGF_Map:: getbitmap(): get bitmap (the information of map construction)
- TGF_Map::insert() :you can insert your TGF_Member into map.
- TGF_Map::clear map() :clear and reset the map
- cout << TGF_Map : output for Debug

**TGF_Member : set the unit of A member, this member can be a player or a admin even just a block**

- TGF_Member::xaxi() :get the x axis of  member
- TGF_Member::yaxi() :get the y axis of  member

- TGF_Member:: chagxa():change x axis
- TGF_Member:: chagya():change y axis

**TGF_MemberList.h**

- 

### Develop Log:

**2020.1.12-1x:**build general framework

