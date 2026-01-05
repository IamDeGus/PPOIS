#pragma once

#include <string>
#include <vector>
#include "../Common/Types/Date/Date.h"
#include "../Common/Types/Grade/Grade.h"
#include "../Common/Types/Weight/Weight.h"
#include "../Common/Types/Certification/Certification.h"

class BookMetadata
{
private:
    int pageCount;
    std::string author;
    std::string description;
    std::string name;
    std::string seriesName;

    int serialNumber;
    Date creationDate;
    
    Certification certificate;
    std::string language;
    std::vector<std::string> topics;

    int difficulty;

    Grade rating;
    std::vector<std::string> reviews;

    Weight weight;

public:
    BookMetadata(int pages, const std::string& auth, const std::string& desc,
             const std::string& guideName, const std::string& series, int serial,
             const Date& creation, const Certification& cert, const std::string& lang,
             const std::vector<std::string>& tops, int diff, const Grade& rate,
             const std::vector<std::string>& revs, const Weight& w);
    
    int getPageCount() const;
    const std::string& getAuthor() const;
    const std::string& getDescription() const;
    const std::string& getName() const;
    const std::string& getSeriesName() const;
    int getSerialNumber() const;
    const Date& getCreationDate() const;
    const Certification& getCertificate() const;
    const std::string& getLanguage() const;
    const std::vector<std::string>& getTopics() const;
    int getDifficulty() const;
    Grade getRating() const;
    const std::vector<std::string>& getReviews() const;
    const Weight& getWeight() const;
};
