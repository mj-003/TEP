//
// Created by Malwina Juchiewicz on 17/10/2023.
//

#ifndef LAB01_FUNKCJE_H
#define LAB01_FUNKCJE_H



void v_alloc_table_fill_34(int size);

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);

bool b_del_table_2_dim(int*** piTable, int iSizeX);

void print_2_dim_table(int** piTable, int iSizeX, int iSizeY);

int** allocateTable2DBlock(int sizeX, int sizeY);

void deallocateTable2DBlock(int** table2D);

#endif




