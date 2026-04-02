#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>

class IPv4PrefixSet {
private:
    std::vector<std::pair<uint32_t, uint8_t>> prefix; 

public:
    bool add(const uint32_t& base, const uint8_t maskLenght) {
        if (maskLenght > 32) {
            return false; 
        }
        for (const auto& element : prefix) {
            if (element.first == base && element.second == maskLenght) {
                return false;
            }
        }

        prefix.push_back(std::make_pair(base, maskLenght));
            return true;
    }

    bool del(const uint32_t& base, const uint8_t maskLength) {
        if (maskLength > 32) {
            return false; 
        }
        for (auto wskaznik = prefix.begin(); wskaznik != prefix.end(); ++wskaznik) {
            if (wskaznik->first == base && wskaznik->second == maskLength) {
                prefix.erase(wskaznik);
                return true;
            }
        }
        return false;
    }
    int check(const uint32_t& ip) {
        int maksymalna_dlugosc_maski = -1;
        for(const auto& element : prefix) {
            uint32_t maska = (element.second == 0) ? 0 :(0xFFFFFFFF << (32 - element.second));
            if ((ip & maska) == (element.first & maska)) {
                if (element.second > maksymalna_dlugosc_maski) {
                    maksymalna_dlugosc_maski = element.second;
                }
            }

        }
        return maksymalna_dlugosc_maski;
    }


};
