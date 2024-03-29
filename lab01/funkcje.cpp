//
// Created by Malwina Juchiewicz on 17/10/2023.
//

#include <iostream>
#include "funkcje.h"
#include "const.h"


void v_alloc_table_fill_34(int size){
    if (size <= 0) {
        std::cout << "niepoprawny rozmiar" << std::endl;
        return;
    }

    int* table_ptr = new int[size];
    for (int i = 0; i < size; i++) {
        table_ptr[i] = FILL_VAL;
    }

    for (int i = 0; i < size; i++) {
        std::cout << table_ptr[i] << ' ';
    }
    delete[] table_ptr;
    std::cout << std::endl;
}

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
    if (iSizeX <= 0 || iSizeY <= 0 || piTable == nullptr) {
        std::cout << "nie zaalokowano" << std::endl;
        return false;
    }

    *piTable = new int* [iSizeX];
    for (int i = 0; i < iSizeX; i++) {
        (*piTable)[i] = new int[iSizeY];
    }
    return true;
}

bool b_del_table_2_dim(int*** piTable, int iSizeX) {
    if (iSizeX <= 0) {
        std::cout << "nie mozna usunac" << std::endl;
        return false;
    }

    for (int i = 0; i < iSizeX; i++) {
        delete[] (*piTable)[i];
    }
    delete[] *piTable;
    return true;
}

void print_2_dim_table(int** piTable, int iSizeX, int iSizeY) {
    if (iSizeX <= 0 || iSizeY <= 0 || piTable == nullptr) {
        return;
    }

    for (int i = 0; i < iSizeX; i++) {
        for (int j = 0; j < iSizeY; j++) {
            std::cout << piTable[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int** allocateTable2DBlock(int sizeX, int sizeY) {
    if (sizeX <= 0 || sizeY <= 0) {
        return nullptr;
    }

    int** piTable = new int* [sizeX];
    int* bigTab = new int [sizeX * sizeY];

    for (int i = 0; i < sizeX; i++) {
        piTable[i] = &bigTab[i * sizeY];

        for (int j = 0; j < sizeY; j++) {
            std::cout << &piTable[i][j] << ' ';
        }
        std::cout<<std::endl;
    }
    return piTable;
}

void deallocateTable2DBlock(int** table2D) {
    delete [] table2D[0];
    delete [] table2D;
    std::cout << "tablica usunieta" << std::endl;
}


