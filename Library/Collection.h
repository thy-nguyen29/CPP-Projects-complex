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

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include<iostream>
#include<string.h>
#include "Movie.h"
#include "SpellChecker.h"
#include "Book.h"

namespace sdds{
    template<typename T>
    class Collection{
        std::string m_name{};
        T* m_collection{};
        size_t m_size{};
        void (*m_observer)(const Collection<T>&, const T&);

        public:
            Collection(const std::string& name){
                this->m_name = name;
                this->m_collection = nullptr;
                this->m_size = 0;
                this->m_observer = nullptr;
            }

            Collection(const Collection& C) = delete;
            Collection& operator = (const Collection& C) = delete;
            Collection(Collection&& C) = delete;
            Collection& operator = (Collection&& C) = delete;
            ~Collection(){
                delete[] this->m_collection;
                this->m_collection = nullptr;
            }

            const std::string& name() const{
                return this->m_name;
            }

            size_t size() const{
                return this->m_size;
            }

            void setObserver(void (*observer)(const Collection<T>&, const T&)){
                this->m_observer = observer;
            }

            Collection<T>& operator+=(const T& item){
                bool found = false;
                for(size_t i = 0; i < this->m_size; i++){
                    if(this->m_collection[i].title() == item.title()){
                        found = true;
                        break;
                    }
                }

                if(!found){
                    T* temp = new T[this->m_size + 1];
                    for(size_t i = 0; i < this->m_size; i++){
                        temp[i] = this->m_collection[i];
                    }
                    temp[this->m_size] = item;
                    this->m_size++;
                    delete[] this->m_collection;
                    this->m_collection = temp;
                    temp = nullptr;
                    if(this->m_observer != nullptr){
                        this->m_observer(*this, item);
                    }
                }
                return *this;
            }

            T& operator[](size_t idx) const{
                if(idx >= this->m_size || idx < 0){
                    throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(this->m_size) + "] items.");
                }
                return this->m_collection[idx];
            }

            T* operator[](const std::string& title) const{
                for(size_t i = 0; i < this->m_size; i++){
                    if(this->m_collection[i].title() == title){
                        return &this->m_collection[i];
                    }
                }
                return nullptr;
            }

            friend std::ostream& operator<<(std::ostream& os, const Collection<T>& C){
                for(size_t i = 0; i < C.m_size; i++){
                    os << C.m_collection[i] << std::endl;
                }
                return os;
            }
    };
}

#endif