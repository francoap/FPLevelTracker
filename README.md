# FPLevelTracker
Level metadata tracking plugin for Unreal Engine 4

## Setup

1. Set FPWorldSettings as the default world settings class in **Project Settings -> Engine -> General Settings **
2. Restart the editor

## How to use

You can add/edit custom metadata for the current loaded level in the "Level Tracker" category inside World Settings panel.
You can go to **Project Settings -> Plugins -> FP Level Tracker** to setup the paths you want to scan for levels.
You can use the **Get All Levels Tracker Data** blueprint node to get an array with metadata structures for all the scanned levels.
