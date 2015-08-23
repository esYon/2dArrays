//  main.cpp
//  CSCI15 LAB1
//
//  Created by John Holman on 8/21/15.
//  Copyright (c) 2015 John Holman. All rights reserved.
//
#include <iostream>
#include <iomanip> //use iomanip to keep rows at 8 values per
using namespace std;

const int cols = 8;
const int rows = 8;

void printArray(int a[][cols], int rows);

void fillArray1 (int a[][cols], int rows);  // row by row with ascending numbers, starting with 1 in position a[0][0].

void fillArray2 (int a[][cols], int rows);  // column by column with ascending numbers,  starting with 1 in position a[0][0].

void fillArray3 (int a[][cols], int rows);  // clockwise spiral, moving inwards. Ascending numbers starting with 1 in position a[0][0]

int main() {
    
    int a[rows][cols] = {0};
    
    fillArray1(a, rows);
    fillArray2(a, rows);
    fillArray3(a, rows);
    
    return 0;
}

void printArray(int a[][cols], int rows) {
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void fillArray1(int a[][cols], int rows) {
    
    int counter = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           
            a[i][j] = counter;
            counter++;
        }
    }
    printArray(a, rows);
}

void fillArray2(int a[][cols], int rows){
    
    int counter = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            a[j][i] = counter;
            counter++;
        }
    }
    printArray(a, rows);
}

void fillArray3(int a[][cols], int rows) {
    
    int counter = 1;
    int tRows = 0;
    int bRows = rows - 1;
    int lCols = 0;
    int rCols = cols - 1;
    int dir = 0;
    
    
    while (dir <= 4 && counter <= rows*cols) {
    if (dir == 0) {
    {
        for (int i = lCols; i <= rCols && counter <= rows*cols; i++) {
            a[tRows][i] = counter;
            counter++;
        }
        cout << endl;
        tRows++;
        dir = 1;
    }
    
    if (dir == 1)
        for (int j = tRows; j <= bRows && counter <=rows*cols; j++) {
            a[j][rCols] = counter;
            counter++;
        }
        rCols--;
        dir = 2;
    
    if (dir == 2)
        for (int u = rCols; u >= lCols && counter <=rows*cols; u--) {
            a[bRows][u] = counter;
            counter++;
        }
        bRows--;
        dir = 3;
    
    if (dir == 3)
        for (int v = bRows; v >= tRows && counter <= rows*cols;  v--) {
            a[v][lCols] = counter;
            counter++;
        }
        lCols++;
        dir = 0;
        }
    }
    printArray(a, rows);
}


