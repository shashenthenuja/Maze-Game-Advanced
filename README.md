# Maze Game Advanced In C
This project is a 2D console maze game written in C programming language. The user can type the command to move the player ( W, A, S, D ). The players goal is to reach the  `x` avoiding the snake `~` to win the game.

W - UP<br>
A - LEFT<br>
S - DOWN<br>
D - RIGHT<br>
U - UNDO

## File IO & Metadata
In this advanced edition, the map is generated with data from a file input which holds the coordinates of the player, snake, walls and the borders. You can input the file using `./maze <map_file_name>` 

In the text file, there are always 3 integers on every line. The first line ***always*** contains the `<metadata_amount>`, `<map_row>`, and `<map_col>` in that order. The following lines are the coordinates of the object with the pattern `<object_row>`, `<object_col>`, and `<object_code>`. The `<object_row>` and `<object_col>` are the zero-based index location of the objects (For example, `<object_row>` of 2 refers to the third row of the map). 
| `<object_code>` | Description |
|:--:|:--:|
| 0 | *Player* |
| 1 | *Snake* |
| 2 | *Goal* |
| 3 | *Wall* |


## Undo Feature
There is a new feature to undo the players movement. The key `U` allows the player to undo the steps taken when the player moves. This mechanism is developed with linkedlists which stores player's and snake's (see below) every movement.

## Enemy
In this edition we introduce a new character `~` (tilde character) to represent the snake on the map. This snake will gradually go closer to bite the player. Once the player and the snake is on the same location, the player loses the game. 

The snake will attempt to move one step closer every time the user enters one movement command key (not including undo key). The snake cannot move in the diagonal direction. If the player goes towards the wall, that also counts as a single movement and the snake will move one step as well. The snake also cannot go through the wall.

![Maze Game Advanced](https://i.imgur.com/3dp7nDs.png)

### Indexed in Turn-It In Global Referencing Scheme

***This project should not be used for any coursework related activity and all codes have been submitted to `Turn-It In global referencing platform`, where usage of this code may be caught for Plagiarism.***
