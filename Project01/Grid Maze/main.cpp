#include <iostream>
#include <ctime>
#include <unistd.h>

#include "make_grid.hpp"


using namespace std;

int main()
{
    /*
    make_grid a(10);
    //char char_ = a.get_random_character_A_Z();
    //usleep(4300);
    //cout<<char_<<" ";

    a.make_matrix();
    a.display_matrix();
    */
    /*
    utils u;
    cout<<"LOADING DATA... HANG ON!!!"<<endl;
    u.create_vector();
    u.make_dict();
    u.print_dict();
    */

    make_grid a(10);
    a.make_puzzle();
    //a.test_r01();

}
