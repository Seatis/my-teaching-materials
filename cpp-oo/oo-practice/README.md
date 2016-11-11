# Practice classes
*Practice more and more with classes*

## Objectives
 - Create more classes

## Workshop
### Cognitive Apprenticeship
#### Rocket Project
##### Create class called Rocket
Each rocket should store it's id, fuel level, and number of launches
There are 2 rocket types:

 - Falcon1
 - Falcon9

The rockets should be able to perform 3 operations:

###### Launch
It should use 1 fuel if it's a Falcon1 and 9 if it's a Falcon9, also it should
increment it's number of launches.

###### Refill
It should refill the tank of the rocket.
Tank sizes:
 - Falcon1: 3
 - Falcon9: 20

###### Get stats
It should describe the status of the rocket like: `Type: Falcon9, fuel: 11, launches: 2`


##### Create a class called SpaceX class
The class should store fuel and the rockets

The rockets should be able to perform 4 operations:

###### Add Rocket
It should be able to add new rockets to it's feet.

###### Refill by id
It should refill a rocket with the given id and substract the needed fuel from the fuel storage

###### Refill all
It should refill all the rockets and substract the needed fuel

###### Launch by id
It should launch a rocket with the given id

###### Get stats
It should describe it's status like:
```
Fuel: 100, Total launches: 1
Rockets:
Type: Falcon9, fuel: 11, launches: 1
Type: Falcon1, fuel: 3, launches: 0
```

### Exercises
#### Jukebox Project
##### Create a Song class
It should store the title and the artist of the song and also set these with it's constructor
It also should store it's rating

The songs can have 3 different genres:

 - Rock
 - Pop
 - Reggae

The Songs should be able to perform 2 operations:

##### Rate
It should add a rating to the song, it should return with false if the rating is
not between 1 and 5 true otherwise.
The Rock songs cannot have 1 as a rating.
The Reggae songs cannot ahve 5 as a rating.
Sorry for the opionated exercise :)

##### Get average rating
It should return the average of all the given ratings

##### Create a Jukebox class
It should be able to store songs

The Jukebox should be able to perform 3 operations:

##### Rate
It should rate the song with the given title and artist

##### Get artist rating
It should get the average song ratings of a given artist

##### Get genre rating
It should get the average song ratings of a given genre

##### Get top rated title
It should get the title of the top rated song

##### Get top rated genre
It shoudl get the name of the top rated genre



## Individual Workshop Review
Please follow the styleguide: [Our C++ styleguide](../../styleguide/cpp.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes palced on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?
 - Are the allocated resources deleted when necessary?
 - Is there any potential memory leak?

