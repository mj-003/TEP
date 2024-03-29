#include <iostream>
#include "CTable.h"
#include "const.h"
#include "funkcje.h"



int main() {

    allocateTable2DBlock(5, 4);
    deallocateTable2DBlock(allocateTable2DBlock(5, 4));
    std::cout<<std::endl;


    // ************ TABLICA JEDNOWYMIAROWA ************

    std::cout << " ************ TABLICA JEDNOWYMIAROWA ************" << std::endl << std::endl;
    v_alloc_table_fill_34(10);
    std::cout << std::endl;


    // ************ TABLICA DWUWYMIAROWA ************

    std::cout << "************ TABLICA DWUWYMIAROWA ************" << std::endl << std::endl;
    int **piTable;
    if (b_alloc_table_2_dim(&piTable, 3, 5)) {
        piTable[1][2] = 666;
        piTable[2][3] = 999;
    }

    print_2_dim_table(piTable, 3, 5);
    std::cout << std::endl;

    if(b_del_table_2_dim(&piTable, 3)) {
        std::cout << "tablica dwuwymiarowa usunieta" << std::endl << std::endl;
    }


    // ************ CTABLE ************

    std::cout << "************ CTABLE ************" << std::endl << std::endl;

    std::cout << "table 1: ";
    CTable table1;                                  // konstruktor domyslny

    std::cout << "table 2: ";
    CTable table2("Table2", 5);    // konstruktor z parametrami

    std::cout << "table 3: ";
    CTable *table3 = table2.pcClone();              // klonowanie obiektu - tylko te same dane

    std::cout << "table 4: ";
    CTable table4 = table2;                         // kopiowanie obiektu - ten sam wskaznik

    std::cout << "table 5: ";
    CTable table5("Table5", 6);    // konstruktor z parametrami
    std::cout << std::endl;

std::cout << "zmiana rozmiaru table2: " << std::endl;
    table2.vPrint();
    table2.bSetNewSize(8);                 // zmiana rozmiaru
    table2.vPrint();
    std::cout << std::endl;

    std::cout << "MODYFIKACJE" << std::endl;

    std::cout << "table 5: ";
    table5.vPrint();
    std::cout << std::endl;

    std::cout << "modyfikacja bez wskaznika: " << std::endl;
    v_mod_tab(table5, 4);           // kopiuje, zmiany nie wplyna na oryginalny obiekt
    std::cout << "table 5: ";
    table5.vPrint();
    std::cout << std::endl;

    std::cout << "modyfikacja ze wskaznikiem: " << std::endl;
    v_mod_tab(&table5, 4);         // nie zmienia
    std::cout << std::endl;


    // TABLICA OBIEKTOW
    std::cout << "tablica obiektow: " << std::endl;
    CTable *table_array = new CTable[3];
    table_array[0].vSetName("tab1");
    table_array[1].vSetName("tab2");
    table_array[2].vSetName("tab3");
    table_array[0].bSetNewSize(5);
    table_array[1].bSetNewSize(6);
    table_array[2].bSetNewSize(7);

    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        table_array[i].vPrint();
    }
    std::cout << std::endl;

    std::cout << "kasuje tabele" << std::endl;
    delete table3;

    std::cout << "kasuje tablice obiektow" << std::endl;
    delete [] table_array;

    return 0;

}






