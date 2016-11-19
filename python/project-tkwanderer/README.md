# Project: TkWanderer - The Tkinter RPG game

Build a hero based walking on tiles and killing monsters type of game. Heroes and monsters have levels and stats depending on their levels.

### Workshop: Plan your work
- Go through the [project specification](specification.md).
- Create a Trello board for your work and add the [project stories](stories.md).

#### Form groups and plan your application together.
**Plan your architecture.**   
In your architecture you should consider the following components:
- Models
    - GameObject
        - Character
            - Monster
            - Hero
            - types
        - Area
        - Tile
            - EmptyTile
            - NotEmptyTile
- GameLogic
    - current hero
    - current area
- MainLoop
    - handling events
    - current game

Now that you see the big picture, **go through the stories together** and break them down into tasks:
  - To classes
  - To methods
  - To data and actions
Try to estimate the time needed for each task and story.   
While working on them later, track your time spent on each.
