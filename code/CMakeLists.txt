# use clion to run whole project
cmake_minimum_required(VERSION 3.27)
project(Dungeon)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
include_directories(.)

add_executable(Dungeon
        Dungeon.cpp
        Dungeon.h
        GameCharacter.cpp
        GameCharacter.h
        Item/Item.cpp
        Item/Item.h
        main.cpp
        Monster.cpp
        Monster.h
        NPC.cpp
        NPC.h
        Object.cpp
        Object.h
        Player.cpp
        Player.h
        Room.cpp
        Room.h
        CreateEverything.cpp
        CreateEverything.h
        Item/Currency.cpp
        Item/Currency.h
        Item/Consume.cpp
        Item/Consume.h
        Item/Weapon.cpp
        Item/Weapon.h)
