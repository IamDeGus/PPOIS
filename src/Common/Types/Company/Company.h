#pragma once

#include <vector>

#include "../../I/IDateCreate.h"
#include "../../I/IDescription.h"
#include "../../I/INameable.h"

#include "../Certification/Certification.h"
#include "../Address/Address.h"
#include "../Grade/Grade.h"

class Company : public INameable, public IDescription, public IDateCreate
{
private:
    std::vector<Certification> certifications;

    int employeeCount;
    double annualRevenue;

    Address headquarters;
    Grade grade;
public:
    Company(std::vector<Certification> certifications, int employeeCount, 
            double annualRevenue, Address headquarters, Grade grade, 
            const std::string& name, const std::string& description,
            const Date& dateCreate);

    
    bool operator== (const Company other) const;
    

    std::vector<Certification> getCertification() const;
    int getEmployeeCount() const;
    double getAnnualRevenue() const;
    Address getHeadquarters() const;
    Grade getGrade() const;
};
