#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
/////////////////////////////////////////////////////////////////////////////////////////
typedef std::string                     T_str;
typedef std::pair   < int,  int     >   T_cell;
typedef std::set    < T_cell        >   T_cells;
/////////////////////////////////////////////////////////////////////////////////////////
void    go_to_cell_with_cells_and_visited_cells
    (
        T_cell                  cell,
        T_cells     const   &   cells,
        T_cells             &   visited_cells
    )
{
    visited_cells.insert( cell );
 
    for (
            auto
            adj_cell_it     =   cells.begin     ();
            adj_cell_it     !=  cells.end       ();
            ++adj_cell_it
        )
    {
        if  (
                    visited_cells.count( *adj_cell_it )     ==  0
 
                &&  (
                                abs( cell.first     -   adj_cell_it->first      )
                            +   abs( cell.second    -   adj_cell_it->second     )
                        ==  1
                    )
            )
        {
            go_to_cell_with_cells_and_visited_cells
                (
                    *adj_cell_it,
                    cells,
                    visited_cells
                );
        }
    }//for
}
/////////////////////////////////////////////////////////////////////////////////////////
int     get_islands_count_of( T_cells   const   &   cells )
{
    int         res_count   =   0;
    T_cells     visited_cells;
 
    for (
            auto
            cell_it     =   cells.begin     ();
            cell_it     !=  cells.end       ();
            ++cell_it
        )
    {
        if  (
                visited_cells.count( *cell_it )     ==  0
            )
        {
            ++res_count;
 
            go_to_cell_with_cells_and_visited_cells
                (
                    *cell_it,
                    cells,
                    visited_cells
                );
        }
    }//for
 
    return  res_count;
}
/////////////////////////////////////////////////////////////////////////////////////////
int     main()
{
 
    const   T_str   INPUT_FILENAME      =   "input.txt";
    const   T_str   OUTPUT_FILENAME     =   "output.txt";
 
    std::ifstream   ifile( INPUT_FILENAME );
    T_cells     cells;
 
    if( !ifile )
    {
        std::cout   <<  "Невозможно прочитать данные из файла."
                    <<  std::endl;
    }
    else
    {
        int     matr_dim    =   0;
        ifile   >>  matr_dim;
 
        for( int  i = 0; i < matr_dim; ++i )
        {
            for( int  j = 0; j < matr_dim; ++j )
            {
                int     cell_val    =   0;
                ifile   >>  cell_val;
 
                if( cell_val )
                {
                    cells.insert    (
                                        T_cell( i, j )
                                    );
                }
            }//for
        }//for
 
        std::ofstream   ofile( OUTPUT_FILENAME );
        ofile   <<  get_islands_count_of( cells );
    }//else
 
    return 0;
}