## Blog post entry
If you have not visited it yet, I strongly suggest checking out my blog entry explaining the code I shared in this repo:<br>
[https://www.thomaswinged.me/entry/ue-recruitment-task-1](https://www.thomaswinged.me/entry/ue-recruitment-task-1)

## Unreal Developer - recruitment task

Your task is to create a simple but effective system for handling dynamic sky and a simple mini-map system in a game based on Unreal Engine 5.

The goal of the project is to create a dynamic sky that will change its appearance.

The player will be able to control the weather by pressing the appropriate triggers located in the game world.

The triggers should be located at a certain distance from the player (outside the area of visibility).

Triggers should be visible as points on the mini-map (point of interest), and the player should be able to see a navigation point that shows live "what distance remains to the destination."
When each trigger is pressed, the weather in the game should change.

Above each trigger there should be a UI (in the game world) telling what weather is "hidden" under a given trigger.

## Main requirements:
- Implementation of the Ultra Dynamic Sky library and Map Quest PRO into the Unreal Engine 5.1 project.
- Creating a mini-map system with at least 4 points indicating triggers.
- Creation of a simple navigation system - a point directing to a specific place, indicating the current distance.
- Implementing a weather control system by pressing the appropriate triggers (e.g., sunny day, rain, storm).

**Note**: The project does not require the creation of an entire user interface or the development of a detailed storyline of the game. It is enough to create basic mechanics.
All functionality is available in the provided libraries.

You need to make the appropriate modifications and prepare everything in a separate Map (Open World).

## The project should provide:
1) Link to the GIT repository (containing the entire project) - Unreal Engine 5.1
2) Build for Windows

## Note
Due to copyrights I cannot share UltraDynamicSky or QuestMap plugin files in this repository. In order to make everything work correctly, paste content of these plugins into `Content` directory, like this:
```
Content\UltraDynamicSky\Blueprints
...
Content\QuestMap\Blueprints
...
```
