
#include <bits/stdc++.h>
#include "word_list.hpp"



#ifndef __UTILS_HPP__
#define __UTILS_HPP__

struct sort_pred {
    bool operator()(const std::pair<string,int> &left, const std::pair<string,int> &right) {
        return left.second > right.second;
    }
};

using namespace std;

struct FINAL_STRUCTURE
{
    string word;    // contains each of the word
    int len;        // contains the length of each word
    int flag;       // contains the flag of used/ not used
};


class utils
{
public:
    vector <FINAL_STRUCTURE> DICT_STRUCTURE; // The dictionary structure that will be used
    vector <pair<string,int>> MY_DICT;
    void create_vector();
    void make_dict();
    void print_dict();
};



void utils::create_vector()
{
    for(auto i:WORDS)
     {
         //cout<<i<<endl;
         // to take the data into the dictionary
         MY_DICT.push_back(make_pair(i,i.length()));
     }
}


void utils::make_dict()
{
    FINAL_STRUCTURE temp;
    sort(MY_DICT.begin(), MY_DICT.end(), sort_pred());
    for(auto i:MY_DICT)
    {
        temp.word = i.first;
        temp.len = i.second;
        temp.flag = 0;
        DICT_STRUCTURE.push_back(temp);
    }
}

void utils::print_dict()
{
    /*
    for(auto i:MY_DICT)
        cout<<i.first<<" "<<i.second<<endl;
    */
    for(auto i:DICT_STRUCTURE)
    {
        cout<<i.word<<" "<<i.len<<" "<<i.flag<<endl;
    }
}

#endif
