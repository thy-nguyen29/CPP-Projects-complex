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
#include "Book.h"
#include "SpellChecker.h"
using namespace std;
namespace sdds
{
    Book::Book() {
        this->m_author = '\0';
        this->m_title = '\0';
        this->m_country = '\0';
        this->m_year = 0;
        this->m_price = 0;
        this->m_description = '\0';
    
    };

    Book::Book(const std::string& strBook) {
        string temp = strBook;
        int index{};

        //author
        temp.erase(0, temp.find_first_not_of(' ')); 
        index = temp.find(',');
        m_author = temp.substr(0, index);
        m_author.erase(m_author.find_last_not_of(' ') + 1);
        temp.erase(0, index + 1);

        //title
        temp.erase(0, temp.find_first_not_of(' '));
        index = temp.find(',');
        m_title = temp.substr(0, index);
        m_title.erase(m_title.find_last_not_of(' ') + 1);
        temp.erase(0, index + 1);

        //country
        
        
        temp.erase(0, temp.find_first_not_of(' '));
        index = temp.find(',');
        m_country = temp.substr(0, index);
        m_country.erase(m_country.find_last_not_of(' ') + 1);
        temp.erase(0, index + 1);

        //price
        index = temp.find(',');
        m_price = std::stod(temp.substr(0, index));
        temp.erase(0, index + 1);

        //year
        index = temp.find(',');
        m_year = std::stoul(temp.substr(0, index));
        temp.erase(0, index + 1);

        //description
        temp.erase(0, temp.find_first_not_of(' '));
        index = temp.find('\n');
        m_description = temp.substr(0, index);
        m_description.erase(m_description.find_last_not_of(' ') + 1);
        temp.erase(0, index + 1);
    };

    Book::Book(const Book& B) {
        operator = (B);
    };

    Book::Book(Book&& B) noexcept {
        operator = (move(B));
    };
    Book& Book::operator = (const Book& B) {
        if (this != &B) {
            this->m_author = B.m_author;
            this->m_title = B.m_title;
            this->m_country = B.m_country;
            this->m_year = B.m_year;
            this->m_price = B.m_price;
            this->m_description = B.m_description;
        }
        return *this;
    };

    Book& Book::operator = (Book&& B) noexcept {
        if (this != &B) {
            this->m_author = B.m_author;
            this->m_title = B.m_title;
            this->m_country = B.m_country;
            this->m_year = B.m_year;
            this->m_price = B.m_price;
            this->m_description = B.m_description;

            B.m_author ='\0';
            B.m_title = '\0';
            B.m_country = '\0';
            B.m_year = 0;
            B.m_price = 0;
            B.m_description = '\0';
        }
        return *this;
    };
    Book::~Book() {};

    const std::string& Book::title() const {
        return this->m_title;
    };

    const std::string& Book::country() const {
        return this->m_country;
    };
    const size_t& Book::year() const {
        return this->m_year;
    };
    double& Book::price()  {
        return m_price;
    };
   

    std::ostream& operator << (std::ostream& os, const Book& B) {
        os << setw(20) << B.m_author << " | ";
        os << setw(22) << B.title() << " | ";
        os << setw(5) << B.country() << " | ";
        os << setw(4) << B.year() << " | ";
        os << setw(6) << fixed << setprecision(2) << B.m_price << " | ";
        os << B.m_description;
        return os;
    };

   
}