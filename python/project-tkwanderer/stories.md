# TkWanderer Project Stories

#### Draw a screen with tiles

##### Tile
 - Given a terminal opened in the project directory
 - When the game is ran by executing `python main.py`
 - Then it should show a tile like this: ![floor.png](assets/floor.png)

##### Map
 - Given a terminal opened in the project directory
 - When the game is ran by executing `python mai/n.py`
 - Then it should show a map of tiles like this: ![floor map](assets/floor-map.png)

##### Walls
 - Given the launched game
 - When the map is rendered on the screen
 - Then it should show floor ![wall.png](assets/wall.png) and wall type tiles as well: ![full map](assets/full-map.png)


#### Place a character on it and move with key bindings

##### Hero
 - Given the launched game
 - When the map is rendered on the screen
 - Then it should show a hero on the top-left corner: ![hero](assets/hero-down.png)

 ![hero map](assets/hero-map.png)

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
    - Up: ![up](assets/hero-up.png)
    - Right: ![down](assets/hero-right.png)
    - Down: ![down](assets/hero-down.png)
    - Left: ![down](assets/hero-left.png)

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
 - Then 3 skeletons ![skeleton.png](assets/skeleton.png) should be on the map, somewhere on floor type tiles

##### Boss
 - Given the launched game
 - When the map is rendered on the screen
 - Then a boss ![boss.png](assets/boss.png) should be on the map, somewhere on floor type tiles

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
