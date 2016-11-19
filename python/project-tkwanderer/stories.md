# TkWanderer Project Stories

#### Draw a screen with tiles

##### Tile
 - Given a terminal opened in the project directory
 - When the game is ran by executing `python main.py`
 - Then it should show a tile like this: ![floor.png](Basics/week-06/floor.png)

##### Map
 - Given a terminal opened in the project directory
 - When the game is ran by executing `python mai/n.py`
 - Then it should show a map of tiles like this: ![floor map](Basics/week-06/floor-map.png)

##### Walls
 - Given the launched game
 - When the map is rendered on the screen
 - Then it should show floor ![wall.png](Basics/week-06/wall.png) and wall type tiles as well: ![full map](Basics/week-06/full-map.png)


#### Place a character on it and move with key bindings

##### Hero
 - Given the launched game
 - When the map is rendered on the screen
 - Then it should show a hero on the top-left corner: ![hero](Basics/week-06/hero-down.png)

 ![hero map](Basics/week-06/hero-map.png)

##### Move down
 - Given the launched game
 - When the "down arrow key" is pressed by the user
 - Then the hero should move down one tile

##### Move around
 - Given the launched game
 - When any of the arrow keys are pressed by the user
 - Then the hero should move to that direction

##### Hero direction
 - Given the launched game
 - When the hero is moved by the arrow keys
 - Then the hero should face the direction where he went
    - Up: ![up](Basics/week-06/hero-up.png)
    - Right: ![down](Basics/week-06/hero-right.png)
    - Down: ![down](Basics/week-06/hero-down.png)
    - Left: ![down](Basics/week-06/hero-left.png)

##### Map boundaries
 - Given the hero on any edge of the map
 - When the hero is moved by the arrow keys towards the edge
 - Then it should not move, only its direction should change if necessary

##### Walls
 - Given the hero next to a wall tile
 - When the hero is moved by the arrow keys towards the wall tile
 - Then it should not move, only its direction should change if necessary

#### Extend with different kinds of characters

##### Skeletons
 - Given the launched game
 - When the map is rendered on the screen
 - Then 3 skeletons ![Basics/week-06/skeleton.png](Basics/week-06/skeleton.png) should be on the map, somewhere on floor type tiles

##### Boss
 - Given the launched game
 - When the map is rendered on the screen
 - Then a boss ![Basics/week-06/boss.png](Basics/week-06/boss.png) should be on the map, somewhere on floor type tiles

#### Create fight & game logic

##### Stats
 - Given the launched game
 - When the map is rendered on the screen
 - Then stats should appear below the map in a white box as black strings
   - It should contain:
      - The level of the Hero
      - The max HP of the Hero
      - The current HP of the Hero
      - The DP of the Hero
      - The SP of the Hero
   - Like this: `Hero (Level 1)   HP: 8/10 | DP: 8 | SP: 6`

##### Strike

##### Level up

#### Optional features

##### Random map


   - TDD create the heroes and monsters
       - this can be done easily test driven
       - create a class for the hero
       - stats
       - strike
       - lvl UP
   - create area and gamelogic
       - randMap
       - nextArea
       - generate monsters and BOSS
