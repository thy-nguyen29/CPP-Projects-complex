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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>
#include <iomanip>
#include "SpellChecker.h"
#include "Movie.h"

namespace sdds
{
	class Book
	{
        std::string m_author;
        std::string m_title;
        std::string m_country;
        size_t m_year;
        double m_price;
        std::string m_description;
    public:
        Book();
        Book(const std::string& strBook);
        Book(const Book& B);
        Book(Book&& B) noexcept;
        Book& operator = (const Book& B);
        Book& operator = (Book&& B) noexcept;
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        ~Book();
        
        template<typename T>
        void fixSpelling(T& spellChecker){
           // spellChecker(m_title);
            spellChecker(m_description);
        }

        friend std::ostream& operator << (std::ostream& os, const Book& B);
	};




}







#endif

