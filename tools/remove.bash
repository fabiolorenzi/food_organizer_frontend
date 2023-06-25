#!/bin/bash

echo "Start remove script"

buildFolder="/home/florenzi/Desktop/food_organizer_frontend/build"
if [ -d "$buildFolder" ]
then
    rm -r "/home/florenzi/Desktop/food_organizer_frontend/build"
fi

proFile="/home/florenzi/Desktop/food_organizer_frontend/food_organizer_frontend.pro"
if [ -f "$proFile" ]
then
    rm "/home/florenzi/Desktop/food_organizer_frontend/food_organizer_frontend.pro"
fi

makeFile="/home/florenzi/Desktop/food_organizer_frontend/Makefile"
if [ -f "$makeFile" ]
then
    rm "/home/florenzi/Desktop/food_organizer_frontend/Makefile"
fi

stashFile="/home/florenzi/Desktop/food_organizer_frontend/.qmake.stash"
if [ -f "$stashFile" ]
then
    rm "/home/florenzi/Desktop/food_organizer_frontend/.qmake.stash"
fi

echo "Remove script has finished the execution"