/*This part of the header file contains the code for the maze, the definition of the maker functions*/


#ifndef __MAKE_GRID_HPP__
#define __MAKE_GRID_HPP__



#include <bits/stdc++.h>
#include <cstdlib>
#include <unistd.h>
#include <ctime>

#include "word_list.hpp"
#include "utils.hpp"

#define NUM 20

using namespace std;

class make_grid
{
private:
    char my_matrix[NUM][NUM];
    utils u;
    int SIZE;

public:
    char get_random_character_A_Z();
    int get_random_number_0_size();
    int get_random_number_0_1();    // 0 for down and 1 for right
    make_grid(int);
    //~make_grid();
    void display_matrix();
    void make_matrix();
    void make_puzzle();
    void test_r01();
};


void make_grid::test_r01()
{
    for(int i=0;i<100;i++)
        cout<<get_random_number_0_1()<<" ";
}

int make_grid::get_random_number_0_size()
{
    int r = rand() % (SIZE - 0);
    return r;
}

int make_grid::get_random_number_0_1()
{
    int r = rand() % (2);
    return r;
}

char make_grid::get_random_character_A_Z()
{
    // between 60 for A and 95 for Z

    int r = rand() % (90 - 65) + 65;
    return (char)r;
}

make_grid::make_grid(int get_size=0)
{
    SIZE = get_size;
    srand(time(NULL));
    cout << "\033[2J\033[1;1H";
    cout<<"Const created!"<<endl;
    cout<<"LOADING DATA... HANG ON!!!"<<endl;
    u.create_vector();
    u.make_dict();
    u.print_dict();
}

void make_grid::make_matrix()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            my_matrix[i][j]=get_random_character_A_Z();
            //cout<<my_matrix[i][j]<<endl;
        }
    }
}
void make_grid::display_matrix()
{
    int i,j;
    cout<<endl;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            cout<<my_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void make_grid::make_puzzle()
{
    // make the actual puzzle according to the algorithm
    make_matrix();
    int r,i,j,diff;
    string temp;
    FINAL_STRUCTURE *ptr;
    /*
    r = get_random_number_0_size();
    cout<<r<<endl;
    r = get_random_number_0_size();
    cout<<r<<endl;
    */
    for(i=0;i<SIZE;i++)
    {
        r = get_random_number_0_size();
        cout<<"random number got => "<<r;
        for(auto iter:u.DICT_STRUCTURE)
        {
            if(iter.len == r && iter.flag==0)
            {
                iter.flag=1;
                temp = iter.word;
                cout<<"Changed for "<<temp<<" flag => "<<iter.flag<<" len => "<<iter.len<<endl;
                break;
            }

            if(iter.len < r)
            {
                (*ptr).flag = 1;
                cout<<"Changed for "<<(*ptr).word<<" flag => "<<(*ptr).flag<<" len => "<<(*ptr).len<<endl;
                break;
            }
            temp = iter.word; // previous word
            ptr = &iter;

        }
        // the word has been got
        diff = r-temp.length();
        cout<<"***** ";
        int k=0;
        cout<<temp<<endl;
        int r01;
        r01 = get_random_number_0_1();
        cout<<"r01 = "<<r01<<endl;
        if(r01==0)
        {
            // go right
            for(j = r-diff;j<=SIZE-(r-diff);j++)
            {
                my_matrix[i][j]=temp[k++];
                //cout<<my_matrix[i][j]<<" ";
            }
        }
        else // r01==1
        {
            // go down
            for(j = r-diff;j<=SIZE-(r-diff);j++)
            {
                my_matrix[j][i]=temp[k++];
                //cout<<my_matrix[i][j]<<" ";
            }
        }


        display_matrix();

        u.print_dict();
        char ch;
        cout<<"enter any key to continue"<<endl;
        cin>>ch;
    }
}

#endif /*__MAKE_GRID_H__*/
