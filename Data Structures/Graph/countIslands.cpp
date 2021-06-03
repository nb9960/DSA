#include <bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5

// to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col, bool visited[][COL]){
    // row number is in range, column number is in range and value is 1 and not yet visited
    return (row >= 0) && (row < ROW) && 
          (col >= 0) && (col < COL) && 
          (M[row][col] && !visited[row][col]);
}

// utility fn to do DFS for a 2D boolean matrix.
// It only considers 8 neighbors as adjacent vertices
void DFS(int M[][COL], int row, int col, bool visited[][COL], int* size){
  // These arrays are used to get row & column numbers of 8 neighbours of a given cell
  static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
  static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

  // Mark this cell as visited
  visited[row][col] = true;
  (*size)++;

  // Recur for all connected neighbours
  for (int k = 0; k < 8; ++k)
      if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
          DFS(M, row + rowNbr[k], col + colNbr[k], visited, size);
}

void countIslands(int M[][COL]){
  // array to mark visited cells
  bool visited[ROW][COL];
  memset(visited, 0, sizeof(visited));
  // traverse through all cells of matrix
  int count =0;
  
  for(int i=0;i<ROW;i++){
    for(int j=0;j<COL;j++){
      if(M[i][j] && !visited[i][j]){
        int size=0;
        DFS(M,i,j,visited, &size);
        count++;
        cout<<size<<endl;
      }
    }
  }
  cout << "Number of islands is: " << count<<endl;
}

int main(){
  int M[][COL] = {{ 1, 1, 0, 0, 0 },
                  { 0, 1, 0, 0, 1 },
                  { 1, 0, 0, 1, 1 },
                  { 0, 0, 0, 0, 0 },
                  { 1, 0, 1, 0, 1 } };
 
  countIslands(M);
  return 0;
}