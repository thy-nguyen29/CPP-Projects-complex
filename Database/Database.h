/*
*****************************************************************************
                          Workshop - #8 - part2
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Mar 25, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <string>
#include <memory>
#include <array>
#include <fstream>
#include <iomanip>


namespace sdds
{
    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    template<typename T>
    class Database
    {
    private:
        static std::shared_ptr<Database<T>> instance;

        size_t m_entries = 0;
        std::array<std::string, 20> keys{};
        std::array<T, 20> values{};
        std::string m_filename{};

        Database(const std::string& filename) {
            std::cout << "[" << this << "] ";
            std::cout << "Database(const std::string&)" << std::endl;
            std::ifstream file(filename);
            if (file.is_open())
            {
                m_filename = filename;
                m_entries = 0;
                for (size_t i = 0; i < keys.size(); i++) {
                    std::string line, key;
                    T value;
                    if (!file.eof())
                    {
                        file >> key;
                        file >> value;
                        encryptDecrypt(value);
                        replaceUnderscores(key);
                        keys[i] = key;
                        values[i] = value;
                        m_entries++;
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                throw std::invalid_argument("Can't open file!");
            }
            file.close();
        };
        static void replaceUnderscores(std::string& str) {
            std::replace(str.begin(), str.end(), '_', ' ');
        };

        void encryptDecrypt(T& value) {};

    public:
        static std::shared_ptr<Database<T>> getInstance(const std::string& filename) {
            if (instance == nullptr) {
                instance = std::shared_ptr<Database<T>>(new Database<T>(filename));
            }
            return instance;
        };

        Err_Status GetValue(const std::string& key, T& value) const {
            auto it = std::find(keys.begin(), keys.end(), key);
            if (it == keys.end()) {
                return Err_Status::Err_NotFound;
            }
            value = values[std::distance(keys.begin(), it)];
            return Err_Status::Err_Success;
        };


        Err_Status SetValue(const std::string& key, const T& value) {
            auto it = std::find_if(keys.begin(), keys.end(), [](const auto& k) {
                return k.empty(); });

            if (it == keys.end()) {
                return Err_Status::Err_OutOfMemory;
            }   
            *it = key;
            values[std::distance(keys.begin(), it)] = value;
            m_entries++;
            return Err_Status::Err_Success;
        };

        ~Database() {
            std::cout << "[" << this << "] " << "~Database()\n";
            std::ofstream backup(m_filename + ".bkp.txt");
            for (size_t i = 0; i < m_entries; i++)
            {
                T encryptedVal = values[i];
                encryptDecrypt(encryptedVal);
                backup << std::left << std::setw(25) << keys[i] << " -> " << encryptedVal << "\n";
            }
            backup.close();
        };
    };

    template<>
    void Database<std::string>::encryptDecrypt(std::string& value) {
        const char secret[]{ "secret encryption key" };
        for (size_t i = 0; i < value.size(); i++) {
            for (char k : secret) {
                value[i] = value[i] ^ k;
            }
        }

    };

    template<>
    void Database<long long>::encryptDecrypt(long long& value) {
        const char secret[]{ "super secret encryption key" };
        char* bytes = reinterpret_cast<char*>(&value);
        for (size_t i = 0; i < sizeof(long long); i++) {
            for (char k : secret) {
                bytes[i] ^= k;
            }
        }

    };

    template<typename T>
    std::shared_ptr<Database<T>> Database<T>::instance = nullptr;
}

#endif // !SDDS_DATABASE_H