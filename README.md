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

```cpp
vector<vector<int>> napraviMatricu(const string& filename, vector<pair<char, int>>& slovo_broj);
