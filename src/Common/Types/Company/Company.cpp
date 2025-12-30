#include "Company.h"


Company::Company(std::vector<Certification> certifications, int employeeCount, 
        double annualRevenue, Address headquarters, Grade grade, 
        const std::string& name, const std::string& description,
        const Date& dateCreate) 
        : employeeCount(employeeCount), annualRevenue(annualRevenue), 
            headquarters(headquarters), grade(grade), certifications(certifications),
            INameable(name), IDescription(description),
            IDateCreate(dateCreate) {};


bool Company::operator== (const Company other) const{
    return this->certifications == other.certifications &&
            this->employeeCount == other.employeeCount &&
            this->annualRevenue == other.annualRevenue &&
            this->headquarters == other.headquarters &&
            this->grade == other.grade &&
            this->getName() == other.getName() &&
            this->getDescription() == other.getDescription() &&
            this->getDateCreate() == other.getDateCreate();
}


std::vector<Certification> Company::getCertification() const {return certifications;};
int Company::getEmployeeCount() const {return employeeCount;};
double Company::getAnnualRevenue() const {return annualRevenue;};
Address Company::getHeadquarters() const {return headquarters;};
Grade Company::getGrade() const {return grade;};

