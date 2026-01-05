#include "Address.h"


Address::Address(const std::string& country, const std::string& region,
        const std::string& city, const std::string& street,
        int house) 
        : country(country), region(region),
            city(city), street(street), house(house) {};

bool Address::operator== (const Address other) const{
    return this->country == other.country &&
            this->region == other.region &&
            this->city == other.city &&
            this->street == other.street &&
            this->house == other.house;
}

std::string Address::getCountry() const {return country;};
std::string Address::getRegion() const {return region;};
std::string Address::getCity() const {return city;};
std::string Address::getStreet() const {return street;};
int Address::getHouse() const {return house;};

