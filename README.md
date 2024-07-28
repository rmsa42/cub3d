# Cub3D [42 Project]
This 42 project challenges us to create a game using a raycaster algorithm.

## Table of Contents
1. [Overview](#overview)
2. [Project Structure](#project-structure)
3. [Dependencies](#dependencies)
4. [How to Use](#how-to-use)
5. [Contributing](#contributing)

## Overview
Cub3D is a game built in c using the raycaster algorithm. The main goal is to use the same render technique from Wolfenstein 3D.

A gif of the bonus part

![ezgif com-optimize](https://github.com/user-attachments/assets/48f28aa4-e1c7-4e89-ba07-446433ac83be)


### Commands
`W`: Move foward

`S`: Move backward

`A`: Strafe left

`D`: Strafe right

`Left Arrow`: Rotate the camera to the left

`Right Arrow`: Rotate the camera to the right

In the bonus we also have:

`Spacebar or Left Mouse Button`: Fire a projectile

`E`: Open/Close doors

### Maps
Cub3D will read files with the `.cub` extension as maps.

A map will define the in-game layout, sprites and colors

It will define the sprites for every side of the wall: `NO`, `SO`, `WE`, `EA`.

The colors for the floor, `F`, and ceiling, `C` in rgb format.

The last it is the in-game layout, `1` for walls, `0` for path.

It will also have the player spwan: `N`, `S`, `E`, `W`. The player will spwan looking at one direction wich is represent by the letter.

Map example:
```bash
NO ./sprites/north_wall.xpm
SO ./sprites/south_wall.xpm
WE ./sprites/wall.xpm
EA ./sprites/east_wall.xpm
F 255,255,255
C 0,0,0

11111111
1000E001
10010001
10000101
10000001
11111111
```

In the bonus part we have more representing the in-game layout like, `D` for closed doors, `C` for coins, `e` for enemies, `H` for collectible hearts and `P` for closed special doors.

Map bonus Example:
```bash
WE ./sprites/wall3.xpm
NO ./sprites/wall3.xpm
SO ./sprites/wall3.xpm
EA ./sprites/wall3.xpm
C 0,0,0
F 123,123,123

111111111111
1C000000000111111
1000e000000000P11
11100000000000111
111100000e0000111
1111111D111111111   111111111111111111111111
1C0000000000000001  10e0000000000000000000C1
10000000e0000000001 100eeeee000000H000011111
10000000000000000001100000000000000000001111
111111111110e000000D00000CCCCCCCCCCC00W00001
1111111111111110000110000000000000000000C111
11111111111111111111111111111111111111111111
```

## Project Structure
- `cub3d/`: Main directory containing the source code, header files, and Makefile.
  - `src/`: Source code Directory.
  - `include/`: Headers Directory.
  - `maps/`: Game Maps.
  - `sprites/`: Game Sprites
  - `Makefile`: Build automation script

## Dependencies
- [MiniLibX](https://github.com/42Paris/minilibx-linux)

## How to Use
1. Clone the repository.
2. Navigate to the `cub3d` directory: `cd cub3d`.
3. Compile the game: `make`.
4. Run the binary: `./cub3D maps/valid/exmaple.cub`.

If you want to see the bonus part, you compile with `make bonus` in step 3 and choose a map from `maps_bonus/`

## Bonus
If you want to see more in detail about our bonus, we made a separete git repository with all the commits from the bonus.
[Link](https://github.com/rmsa42/cub3d_bonus)

## Contributing
I welcome contributions. If you have any bug fix or improvement, feel free to submit a pull request on the repository.
