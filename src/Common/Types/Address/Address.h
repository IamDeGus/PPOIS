#pragma once

#include <string>

class Address
{
private:
    std::string country;
    std::string region;
    std::string city;
    std::string street;
    int house;
public:
    Address(const std::string& country, const std::string& region,
            const std::string& city, const std::string& street,
            int house);

    bool operator== (const Address other) const;

    std::string getCountry() const;
    std::string getRegion() const;
    std::string getCity() const;
    std::string getStreet() const;
    int getHouse() const;
};
