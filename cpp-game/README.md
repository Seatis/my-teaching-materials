# Project: The RPG game

Build a hero based walking on tiles and killing monsters type of game. Heroes and monsters have levels and stats depending on their levels.

### Workshop: Plan your work
#### 1. Go through the [project specification](specification.md).
#### 2. Create a Trello board for your work and add the [project stories](stories.md).

#### 3. Form groups and plan your application together.
Plan your architecture. In your architecture you should consider the following components:
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

#### 4. Create task breakdown in Trello together.
Now that you see the big picture, **go through the stories together** and break them down into tasks:
  - To classes
  - To methods
  - To data and actions
Try to estimate the time needed for each task and story.   
While working on them later, track your time spent on each.
