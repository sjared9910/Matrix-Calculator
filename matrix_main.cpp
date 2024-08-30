#include "matrix_header.h"
#include "menu_header.h"

// Details: Matrix calculator that can do multiple matrix operations including
// addition, subtraction, multiplication by either a constant or another matrix, 
// power of a matrix, transpose, determinant, and inverse. 

using namespace std;

int main()
{
    int state = 1;
    int counter = 1;

    //Provides calculator menu and operations, switches state
    //based on operation choosen from menu_move function counter location
    while (true)
    {
        switch (state)
        {
        case 1:
            counter = 1;
            state = menu_move(counter);
            continue;
        case 2:
            add_update();
            state = 1;
            continue;
        case 3:
            sub_update();
            state = 1;
            continue;
        case 4:
            mul_update();
            state = 1;
            continue;
        case 5:
            pow_update();
            state = 1;
            continue;
        case 6:
            trans_update();
            state = 1;
            continue;
        case 7:
            det_update();
            state = 1;
            continue;
        case 8:
            inverse_update();
            state = 1;
            continue;
        case 9:
            about_update();
            state = 1;
            continue;
        case 10:
            return 1;
        }
    }
}
