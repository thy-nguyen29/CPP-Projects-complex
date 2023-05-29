/*
*****************************************************************************
                          Workshop - #5 - Part2
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Feb 19, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Movie.h"
#include "SpellChecker.h"
using namespace std;
namespace sdds{
    Movie::Movie(){
        this->m_title = "";
        this->m_year = 0;
        this->m_desc = "";
    }
    const std::string& Movie::title() const{
        return this->m_title;
    }
    Movie::Movie(const std::string& strMovie){
        //TITLE,YEAR,DESCRIPTION
        string temp = strMovie;
        int index{};
        //title
        temp.erase(0, temp.find_first_not_of(' ')); //____Hello
        index = temp.find(',');
        m_title = temp.substr(0, index);
        m_title.erase(m_title.find_last_not_of(' ') + 1);
        temp.erase(0, index + 1);

        //year
        index = temp.find(',');
        m_year = std::stoul(temp.substr(0, index));
        temp.erase(0, index + 1);
        //description
        temp.erase(0, temp.find_first_not_of(' '));
        index = temp.find('\n');
        m_desc = temp.substr(0, index);
    }

    std::ostream& operator << (std::ostream& os, const Movie& M){
        os << setw(40) << M.m_title << " | " << setw(4) << M.m_year << " | " << M.m_desc;
        return os;
    }
}
