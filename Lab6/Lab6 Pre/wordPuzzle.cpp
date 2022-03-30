#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "hashTable.h"
#include "timer.h"



#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
bool readInDict(string filename, hashTable &table);
bool dirInVec(vector<string> vec, string dir);

int main(int argc, char * argv[]){
  string dict = argv[1];
  string grid = argv[2];

  hashTable table(30000);

  readInDict(dict,table);

  int row;
  int col;

  if(! readInGrid(grid,row,col)){
      cout<<"File open failed";
    }

  string direction[8] = {"N","NE","E","SE","S","SW","W","NW"};
  int count = 0;
  timer t;
  t.start();
  vector<string> dirvec;

  for(int i =0;i<row;i++){
    for(int j =0;j<col;j++){
      for(int d =0;d<8;d++){
	for(int f =3;f<23;f++){
	  string words = getWordInGrid(i,j,d,f,row,col);
	  if (table.find(words) == true){
	    string dir = direction[d]+to_string(i)+to_string(j);
	    if(dirInVec(dirvec,dir)==false){
	      dirvec.push_back(dir);
	      count +=1;
	      cout<<direction[d]<<" ("<<i<<", "<<j<<"): "<<words<<endl;
	    }
	  }
    
	}
    
      }
    
    }
    
  }
  t.stop();
  cout<<count<<" words found"<<endl;
  return 0;
}

bool dirInVec(vector<string> vec, string dir){
  for(int i =0;i<vec.size();i++){
    if(dir == vec[i]){
      return true;
    }
  }
  return false;
}



bool readInDict(string filename, hashTable &table){
  string line;
  string word;
  ifstream file(filename);
  if (!file.is_open()) {
    return false;
  }
  while (getline(file,line)){
    word = line;
    table.insert(word);
  }



  file.close();
  return true;

}


//from getWordInGrid.cpp//
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
  

    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }

    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}
