# Analysis and Synthesis of Algorithms

**Faculty of Natural Sciences and Mathematics**

**University of Sarajevo**

## Project – Topic 2

**Minel Salihagić**

### Project Description

This project involves the implementation of a program designed to find the shortest distance between two points within a maze. The maze is defined via a text file containing information about the maze's structure, and the Lee algorithm is used to calculate the distance between points. The program can also visualize the shortest path within the maze.

### Features

- **Loading the Maze:**  
  The program allows loading the maze from a text file. The maze structure is defined by the number of rows and the positions of the passages within each row. Walls are denoted by zeroes (`0`), while passages are denoted by ones (`1`).

- **Finding the Shortest Distance:**  
  After loading the maze, the program uses the Lee algorithm to find the shortest distance between two points within the maze. The user can specify the start and end positions using characters and coordinates within the maze.

- **Reconstructing the Shortest Path:**  
  The program can reconstruct the shortest path between the start and end positions within the maze.

- **Printing the Maze:**  
  After finding the shortest distance and reconstructing the path, the program prints the maze's state, with the start position marked as 'P' and the end position as 'K'.

- **Input Validation:**  
  The program validates the input to ensure that the start and end positions are within the maze's bounds and that the file is in the correct format.

### Conclusion

This program enables the loading of a maze from a text file and the finding of the shortest distance between points within the maze using the Lee algorithm. The results are clearly displayed on the screen, and the shortest path is marked within the maze for easier interpretation. The program also validates the input to ensure the start and end positions are within the maze's bounds.

---

## Documentation

### Function: `napraviMatricu`

This function loads the maze from a text file, the name of which is passed as a parameter. The maze is defined by the number of rows and the positions of the passages within each row.

- **Parameters:**
  - `filename`: The name of the file containing the maze definition.
  - `slovo_broj`: A reference to a vector of pairs mapping row characters to their corresponding row numbers.

- **Returns:**  
  A matrix representing the binary maze, where each position is marked with `0` for walls and `1` for passages.

### Function: `udaljenost`

This function uses the Lee algorithm to find the shortest distance between two points within the maze.

- **Parameters:**
  - `prviZid`: Character representing the row in which the start position is located.
  - `pozicijaPrvog`: Position within the row for the start point.
  - `drugiZid`: Character representing the row in which the end position is located.
  - `pozicijaDrugog`: Position within the row for the end point.

- **Functionality:**  
  The function works by adding each valid position in the maze to a queue, starting from the start position. For each position in the matrix, it records the distance from the start position, initially set to `0`, and increments by `1` with each step. Additionally, it creates a matrix of positions called `parent`, which records the parent of each position within the maze, aiding in reconstructing the shortest path from start to end.

### Function: `jeLiValidna`

This function checks if a given position within the vector of vectors is valid, meaning it is within the matrix and the value at that coordinate is `1`, indicating a passage.

### Structure: `pozicija`

This structure represents a single point or position within the matrix. It has attributes `x` and `y`, representing the row and column numbers. The constructor and operator `==` are implemented to check if two positions have the same coordinates.

Other functions in the program handle input validation, path reconstruction, maze printing, and other auxiliary tasks.

