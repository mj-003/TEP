#ifndef CTABLE_H
#define CTABLE_H

#include <string>
#include <iostream>

static const std::string DEFAULT_NAME = "default";
static const int DEFAULT_SIZE = 10;
static const int DEFAULT_VALUE = -1;

class CTable {
public:
    CTable();
    CTable(std::string sName, int iTableLen);
    CTable(CTable &pcOther);
    ~CTable();

    void vSetName(std::string sName);
    bool bSetNewSize(int iTableLen);
    CTable* pcClone();
    std::string vGetName();
    int iGetSize();
    void vPrint();

private:
    std::string s_name;
    int i_size;
    int* pi_table;
};

void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);

#endif
