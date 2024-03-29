#ifndef LAB01_CTABLE_H
#define LAB01_CTABLE_H


#include <string>
#include <iostream>
#include "CTable.h"



CTable::CTable() {
    s_name = DEFAULT_NAME;
    pi_table = new int[DEFAULT_SIZE];
    i_size = DEFAULT_SIZE;
    std::cout << "bezp: '" << s_name << "'" << std::endl;
}

CTable::CTable (std::string sName, int iTableLen) {
    s_name = sName;
    pi_table = new int[iTableLen];
    i_size = iTableLen;
    std::cout << "parametr: '" << s_name << "'" << std::endl;
}

CTable::CTable(CTable &pcOther) {
    i_size = pcOther.i_size;
    pi_table = new int[i_size];
    // std::copy(pcOther.pi_table, pcOther.pi_table + i_size, pi_table);
    for (int i = 0; i < i_size; i++) {
        pi_table[i] = pcOther.pi_table[i];
    }
    s_name = pcOther.s_name + "_copy";
    std::cout << "kopiuj: '" << s_name << "'" << std::endl;
}

CTable::~CTable() {
    delete [] pi_table;
    std::cout << "usuwam: '" << s_name << "'" << std::endl;
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int newSize) {
    if (newSize <= 0) {
        return false;
    }
    int* pi_new_table = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        if (i < i_size) {
            pi_new_table[i] = pi_table[i];
        }
        else {
            pi_new_table[i] = DEFAULT_VALUE;
        }
    }

    delete [] pi_table;
    pi_table = pi_new_table;
    i_size = newSize;
    return true;
}

CTable* CTable::pcClone() {         // tworzy nowy obiekt bedacy kopia obiektu
    return new CTable(*this);
}

std::string CTable::vGetName() {
    return s_name;
}

int CTable::iGetSize() {
    return i_size;
}

void CTable::vPrint() {
    for (int i = 0; i < i_size; i++) {
        std::cout << pi_table[i] << ' ';
    }
    std::cout << std::endl;
}

void v_mod_tab(CTable* pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
    std::cout<<"zmodyfikowana (wskaznik):" << std::endl;
    pcTab->vPrint();
}

void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
    std::cout<<"zmodyfikowana (obiekt):" << std::endl;
    cTab.vPrint();
}





#endif //LAB01_CTABLE_H
