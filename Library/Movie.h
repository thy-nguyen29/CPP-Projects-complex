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

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>
namespace sdds{
    class Movie{
        std::string m_title;
        int m_year;
        std::string m_desc;
    public:
        Movie();
        const std::string& title() const;
        Movie(const std::string& strMovie);

        template<typename T>
        void fixSpelling(T& spellChecker){
            spellChecker(m_desc);
           spellChecker(m_title);
        }
        
        friend std::ostream& operator << (std::ostream& os, const Movie& M);
    };
}
#endif