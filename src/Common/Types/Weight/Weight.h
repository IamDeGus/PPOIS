#pragma once


#include "Measur.h"
#include <string>


class Weight
{
private:
    float volume;
    Measur measur;

public:
    Weight(float volume, Measur measur);

    static float Coefficient(Measur measur);

    bool IsValidConvert(Measur measur) const;
    float ConventerTo(Measur measur, float density=1) const;
    void ConventerMeTo(Measur measur, float density=1);


    Weight operator- (const Weight other) const;
    Weight operator+ (const Weight other) const;

    Weight& operator-= (const Weight other);
    Weight& operator+= (const Weight other);

    bool operator< (const Weight other) const;
    bool operator== (const Weight other) const;

    float   getVolume() const;
    Measur  getMeasur() const;
    
    std::string getStringWeight() const;

};
