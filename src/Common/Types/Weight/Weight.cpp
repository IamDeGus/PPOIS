#include "Weight.h"
#include "WeightExeption.h"


Weight::Weight(float volume, Measur measur) : volume(volume), measur(measur) {}

bool Weight::IsValidConvert(Measur measur) const{
    return  (this->measur == measur) ||
            ((this->measur != Measur::Piece && measur != Measur::Piece) &&
           !((measur == Measur::Liter || measur == Measur::Milliliter) &&
            (this->measur != Measur::Liter && this->measur != Measur::Milliliter)));
}

float Weight::getVolume() const{
    return volume;
}

Measur Weight::getMeasur() const{
    return measur;
}

std::string Weight::getStringWeight() const{
    std::string result{std::to_string(static_cast<int>(volume))};
    switch (measur)
    {
    case Measur::Gram:
        result += "g"; break;
    case Measur::Kilogram:
        result += "kg"; break;
    case Measur::Milliliter:
        result += "ml"; break;
    case Measur::Liter:
        result += "l"; break;
    case Measur::Pinch:
        result += "pnch"; break;
    case Measur::Piece:
        result += "pc"; break;
    case Measur::Tablespoon:
        result += "tblspoon"; break;
    case Measur::Teaspoon:
        result += "teaspoon"; break;
    }
    return result;
}

float Weight::Coefficient(Measur measur){
    switch (measur)
    {
    case Measur::Gram:          return 1;
    case Measur::Kilogram:      return 1000;
    case Measur::Liter:         return 1000;
    case Measur::Milliliter:    return 1;
    case Measur::Pinch:         return 0.3;
    case Measur::Tablespoon:    return 15;
    case Measur::Teaspoon:      return 5;
    case Measur::Piece:         return 500;
    }

    return 1;
}

float Weight::ConventerTo(Measur measur, float density) const{
    if (!IsValidConvert(measur)){
        throw WeightException("Weight conversion failed: incompatible measures");
    }
    float k1, k2;
    k1 = Weight::Coefficient(this->measur);
    k2 = Weight::Coefficient(measur);

    return this->volume * density * k1 / k2;
}

void Weight::ConventerMeTo(Measur measur, float density){
    this->volume = ConventerTo(measur, density);
    this->measur = measur;
}

Weight Weight::operator- (const Weight other) const{
    if (this->getMeasur() != other.getMeasur()){
        throw WeightException("Weight difference failed: different measures");
    }
    float temp;
    temp = this->getVolume() - other.getVolume();
    if (temp < 0){
        throw WeightException("Weight difference failed: negative weight (" + std::to_string(temp) + ")");
    }
    Weight result(temp, this->getMeasur());
    return result;
}

Weight Weight::operator+ (const Weight other) const{
    if (this->getMeasur() != other.getMeasur()){
        throw WeightException("Weight addition failed: different measures");
    }
    float temp;
    temp = this->getVolume() + other.getVolume();

    Weight result(temp, this->getMeasur());
    return result;
}

Weight& Weight::operator-= (const Weight other){
    *this= *this - other;
    return *this;
}

Weight& Weight::operator+= (const Weight other){
    *this= *this + other;
    return *this;
}

bool Weight::operator<(const Weight other) const{
    if (this->getMeasur() != other.getMeasur()){
        throw WeightException("Weight compare failed: different measures");
    }

    return this->getVolume() < other.getVolume();
}

bool Weight::operator==(const Weight other) const
{
    if (this->getMeasur() != other.getMeasur()){
        throw WeightException("Weight compare failed: different measures");
    }

    return abs(this->volume - other.volume) < 0.001;
}
