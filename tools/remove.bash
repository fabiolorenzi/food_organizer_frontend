#!/bin/bash

echo "Start remove script"

buildFolder="/home/florenzi/Desktop/food_organizer_frontend/build"
if [ -d "$buildFolder" ]
then
    rm -r "/home/florenzi/Desktop/food_organizer_frontend/build"
    echo "Removed build folder"
fi

proFile="/home/florenzi/Desktop/food_organizer_frontend/food_organizer_frontend.pro"
if [ -f "$proFile" ]
then
    rm "/home/florenzi/Desktop/food_organizer_frontend/food_organizer_frontend.pro"
    echo "Removed pro file"
fi

makeFile="/home/florenzi/Desktop/food_organizer_frontend/Makefile"
if [ -f "$makeFile" ]
then
    rm "/home/florenzi/Desktop/food_organizer_frontend/Makefile"
    echo "Removed make file"
fi

stashFile="/home/florenzi/Desktop/food_organizer_frontend/.qmake.stash"
if [ -f "$stashFile" ]
then
    rm "/home/florenzi/Desktop/food_organizer_frontend/.qmake.stash"
    echo "Removed .qmake.stash file"
fi

echo "Remove script has finished the execution"