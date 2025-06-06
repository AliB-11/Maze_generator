# 🧩 Kruskal Maze Generator

This project generates perfect mazes using **Kruskal's algorithm** implemented in C and visualizes them using **Python's PIL (Pillow)** library. The generated maze is a minimum spanning tree over a grid, ensuring all cells are connected with no cycles.

---

## Maze image output (exemplar)
![maze](https://github.com/user-attachments/assets/c6fba916-d17a-4dbe-9174-30bd56a93183)

---

## Description

The project is divided into two main parts:

1. **Maze Generator (C)**  
   Implements a randomized Kruskal's algorithm on an `N x N` grid. The maze is output to `output/mst.txt` as a matrix of wall indicators (`top left bottom right`), where:
   - `1` = wall is **open** (passage exists)
   - `0` = wall is **closed** (wall exists)

2. **Maze Visualizer (Python)**  
   Reads the maze data from `mst.txt` and uses Pillow to draw and save the maze as an image (`maze.png`). The visualizer adds padding so outer borders are fully visible and opens the entrance and exit of the maze.

---


## 🛠️ Technologies Used

- **C (maze generation)**
- **CMake (build system)**
- **Python 3.12+**
- **PIL / Pillow (visualization)**


---

## 🚀 How to Run

Clone the Repository

mkdir build 

cd build

cmake ..

cmake --build . 

./Debug/maze_generator.exe


Ensure Python is installed and Pillow is available:

pip install pillow


Then run the visualizer:

python visualize.py


This generates a maze image:

maze.png

