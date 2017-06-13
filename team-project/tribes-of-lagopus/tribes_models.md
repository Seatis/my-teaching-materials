# Tribes of Lagopus models


## Building
```
{
  "id": <long>,
  "type": townhall|mine|farm|barrack>,
  "level": <int>,
  "hp": <int>
}
```
- id: unique identifier of the building
- type: type of the building. The available building types:
	- townhall: only one townhall allowed in a `Kingdom`. Certain townhall level needs for other building level upgrades
	- mine: produces gold
	- farm: produces food
	- barrack: can create `Troop`
- level: level of the building (default: 1)
- hp: health point of the building

## Troop
```
{
	"id": <long>,
	"level": <int>,
	"hp": <int>,
	"attack": <int>,
	"defence": <int>
}
```
- id: unique identifier of the troop
- level: level of the troop (default: 1)
- hp: health point of the troop
- attack: attack value of the troop
- defence: defence value of the troop


## Resource
```
{
	"type": <food|gold>,
	"amount": <int>,
	"generation": <int>
}
```
- type: type of the resource. The available types>
	- food: needs for the `Troop`s for living
	- gold: needs for buying new `Building`s or `Troop`s
- amount: sum amount of the certain resource type in `Kingdom` (default 0)
- generation: amount of certain resource automatic generation per minute. Food is produced by farms, gold is produced by mines.


## Player (user)
```
{
	"id": <long>,
	"username": <string>,
	"kingdomId": <long>
}
```
- id: unique identifier of the user
- username: name of the user
- kingdomId: the id of the user's `Kingdom`. One user can have only one Kingdom.
- avatar: URL of the user's uploaded avatar image. Can be null if it's not uploaded yet.
- points: the user's sum game points (default 0)

## Location
```
{
	"x": 1,
	"y": 1
}
```
- the kingdom's `x` location on the map
- the kingdom's `y` location on the map

## Kingdom
```
{
  "id" : <long>,
  "name" : <string>,
  "userId": <long>,
  "buildings": [list of `Building` objects],
  "resources": [list of `Resource` objects],
  "troops": [list of `Troop` objects],
  "location": [<int> x, <int> y]
}
```
- id: the unique identifier of the kingdom
- name: the name of the kingdom
- userId: the unique identifier of the user who owns this kingdom
- buildings: the list of `Building` objects found in this kingdom
- resources: the list of `Resource` objects of this kingdom. A kingdom could have maximum one food type and one gold type resources.
- troops: the list of `Troop` objects in this kingdom (default empty)
- location: a list of two integers that stores the `x` and `y` coordinate of the kingdom on the map. Can be null if the kingdom is not settled yet.

