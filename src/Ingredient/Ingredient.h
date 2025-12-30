#pragma once

#include "../Common/I/INameable.h"
#include "../Common/Types/Date/Date.h"
#include "../Common/Types/Weight/Weight.h"

class Fridge;
class Cupboard;

class Ingredient : public INameable{
private:
    Weight weight;

    Date best_before_date;

public:
    Ingredient(const std::string &name, const Date &date, const Weight &weight);
    virtual ~Ingredient() = default;

    const Date& getDate() const;
    const Weight& getWeight() const;

    bool operator== (const Ingredient other) const;
protected:
    Weight& getWeightt();

    friend class Fridge;
    friend class Cupboard;
};
