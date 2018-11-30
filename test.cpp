//Audriana Pohlman
//A04909450
//Due: 12.07.2018

#include <iostream>

using namespace std;

//each pixel holds 3 color values
struct Pixels {
    int red;
    int green;
    int blue;
};

/* before main is number value 2D array for testing the algorithm,
 * after main is the one that needs dynamics allocation */


void convertToPicture(int image[][5]) {
    for(int y = 0; y < 4; y++) {
        for (int x = 0; x < 5; x++) {
            cout << image[y][x] << " ";
        } // end x for loop
        cout << endl;
    } // end y for loop
    cout << endl << endl;

return;
}

void rotateRight(int original[][4]) {
    int rotated[4][5];
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 4; x++) {
            rotated[x][3-y] = original[y][x];
        } // end x  for loop
    } // end y for loop

    convertToPicture(rotated);
return;
}

int main () {
    int original[5][4];
    int counter = 0;
    for(int y = 0; y < 5; y++) {
        for (int x = 0; x < 4; x++) {
            original[y][x] = counter;
            counter++;
        } // end x for loop
    } // end y for loop

    convertToPicture(original[5][4]);
    //rotateRight(original);

    cout << "end of program";
return 0;
}

/*
void convertToPicture(int image[][columns]) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; x++) {
            cout << image[i][j] << " ";
        } // end i for loop
        cout << endl;
    } // end j for loop
    cout << endl << endl;

return;
}
//square only
void rotateRight(int original[][columns], columns, rows) {
    int rotated[columns][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            rotated[i][j] = original[rows-1-j][i];
        } // end i for loop
    } // end j for loop

    convertToPicture(rotated);
return;
}
//maybe rectangle
void rotateRight(int original[][rows], columns, rows) {
    int rotated[columns][rows]

    for(int j = 1; j < rows; j++) {
        for(int i = m - 1, k = 0; i >= 0, k < m; i--, k++) {
            rotated[j][k] = original[j][i];
        } //end inner for
    } //end outer for
*/
