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
#include "SpellChecker.h"
using namespace std;
namespace sdds{
    SpellChecker::SpellChecker(const char* filename){
        ifstream ifs;
        ifs.open(filename);
        if(!ifs.is_open()){
            throw "Bad file name!";
        }else{
            int i = 0;
            while(!ifs.eof()){
                string line;
                ifs >> line;
                if(line == ""){
                    break;
                }else{
                    m_badWords[i] = line;
                    ifs >> line;
                    m_goodWords[i] = line;
                    i++;
                }
            }

            for(int j = 0; j < 6; j++){
                m_numReplaced[j] = 0;
            }
        }
    }
    void SpellChecker::operator()(std::string& text){
        for(int i = 0; i < 6; i++){
            size_t pos = 0;
            while ((pos = text.find(m_badWords[i], pos)) != string::npos) {
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                m_numReplaced[i] += 1;
                pos += m_goodWords[i].length();
            }
        }
    }
    void SpellChecker::showStatistics(std::ostream& out) const{
        out << "Spellchecker Statistics" << endl;
        for(int i = 0; i < 6; i++){
            out << setw(15) << right << m_badWords[i] << ": " << m_numReplaced[i] << " replacements" << endl;
        }
    }
}