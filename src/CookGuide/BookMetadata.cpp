#include "BookMetadata.h"

BookMetadata::BookMetadata(int pages, const std::string &auth,
     const std::string &desc, const std::string &guideName,
     const std::string &series, int serial, const Date &creation,
     const Certification &cert, const std::string &lang,
     const std::vector<std::string> &tops, int diff,
     const Grade& rate, const std::vector<std::string>& revs,
     const Weight& w)
    : pageCount(pages), author(auth), description(desc), name(guideName),
      seriesName(series), serialNumber(serial), creationDate(creation),
      certificate(cert), language(lang), topics(tops), difficulty(diff),
      rating(rate), reviews(revs), weight(w) {}


int BookMetadata::getPageCount() const {
    return pageCount;
}

const std::string& BookMetadata::getAuthor() const {
    return author;
}

const std::string& BookMetadata::getDescription() const {
    return description;
}

const std::string& BookMetadata::getName() const {
    return name;
}

const std::string& BookMetadata::getSeriesName() const {
    return seriesName;
}

int BookMetadata::getSerialNumber() const {
    return serialNumber;
}

const Date& BookMetadata::getCreationDate() const {
    return creationDate;
}

const Certification& BookMetadata::getCertificate() const {
    return certificate;
}

const std::string& BookMetadata::getLanguage() const {
    return language;
}

const std::vector<std::string>& BookMetadata::getTopics() const {
    return topics;
}

int BookMetadata::getDifficulty() const
{
    return difficulty;
}


Grade BookMetadata::getRating() const {
    return rating;
}

const std::vector<std::string>& BookMetadata::getReviews() const {
    return reviews;
}

const Weight& BookMetadata::getWeight() const {
    return weight;
}

