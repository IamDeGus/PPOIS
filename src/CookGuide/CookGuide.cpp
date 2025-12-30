#include "CookGuide.h"

// Конструктор с инициализацией всех полей
CookGuide::CookGuide(int pages, const std::string& auth, const std::string& desc,
                     const std::string& guideName, const std::string& series, int serial,
                     const Date& creation, const Certification& cert, const std::string& lang,
                     const std::vector<std::string>& tops, int diff, const Grade& rate,
                     const std::vector<std::string>& revs, const Weight& w,
                     const std::vector<std::string>& tools,
                     const std::vector<std::string>& utensils,
                     const std::vector<std::string>& appliances,
                     const std::vector<std::string>& temps,
                     const std::vector<std::string>& techniques,
                     const Date& masteryTime,
                     bool vegetarian, bool vegan, bool glutenFree,
                     bool dairyFree, bool nutFree, bool lowCarb,
                     bool keto, bool paleo, bool sugarFree,
                     bool lowSodium, bool highProtein, bool organicOnly,
                     bool digitalVersion, bool audioBook,
                     bool videoTutorials, bool mobileApp,
                     bool onlineCourse, bool printableWorksheets,
                     bool shoppingLists, bool mealPlanners,
                     bool progressTracker, bool communityAccess,
                     bool awardWinning, bool chefRecommended,
                     bool criticallyAcclaimed, bool editorChoice,
                     bool customerFavorite, bool moneyBackGuarantee,
                     bool ecoFriendly, bool recyclable)
    : pageCount(pages), author(auth), description(desc), name(guideName),
      seriesName(series), serialNumber(serial), creationDate(creation),
      certificate(cert), language(lang), topics(tops), difficulty(diff),
      rating(rate), reviews(revs), weight(w), requiredTools(tools),
      requiredUtensils(utensils), requiredAppliances(appliances),
      temperatureRanges(temps), keyTechniques(techniques),
      masteryTimeHours(masteryTime),
      isVegetarian(vegetarian), isVegan(vegan), isGlutenFree(glutenFree),
      isDairyFree(dairyFree), isNutFree(nutFree), isLowCarb(lowCarb),
      isKeto(keto), isPaleo(paleo), isSugarFree(sugarFree),
      isLowSodium(lowSodium), isHighProtein(highProtein), isOrganicOnly(organicOnly),
      hasDigitalVersion(digitalVersion), hasAudioBook(audioBook),
      hasVideoTutorials(videoTutorials), hasMobileApp(mobileApp),
      hasOnlineCourse(onlineCourse), hasPrintableWorksheets(printableWorksheets),
      hasShoppingLists(shoppingLists), hasMealPlanners(mealPlanners),
      hasProgressTracker(progressTracker), hasCommunityAccess(communityAccess),
      isAwardWinning(awardWinning), isChefRecommended(chefRecommended),
      isCriticallyAcclaimed(criticallyAcclaimed), hasEditorChoice(editorChoice),
      isCustomerFavorite(customerFavorite), hasMoneyBackGuarantee(moneyBackGuarantee),
      isEcoFriendly(ecoFriendly), isRecyclable(recyclable) {}

int CookGuide::getPageCount() const {
    return pageCount;
}

const std::string& CookGuide::getAuthor() const {
    return author;
}

const std::string& CookGuide::getDescription() const {
    return description;
}

const std::string& CookGuide::getName() const {
    return name;
}

const std::string& CookGuide::getSeriesName() const {
    return seriesName;
}

int CookGuide::getSerialNumber() const {
    return serialNumber;
}

const Date& CookGuide::getCreationDate() const {
    return creationDate;
}

const Certification& CookGuide::getCertificate() const {
    return certificate;
}

const std::string& CookGuide::getLanguage() const {
    return language;
}

const std::vector<std::string>& CookGuide::getTopics() const {
    return topics;
}

int CookGuide::getDifficulty() const {
    return difficulty;
}

Grade CookGuide::getRating() const {
    return rating;
}

const std::vector<std::string>& CookGuide::getReviews() const {
    return reviews;
}

const Weight& CookGuide::getWeight() const {
    return weight;
}

const std::vector<std::string>& CookGuide::getRequiredTools() const {
    return requiredTools;
}

const std::vector<std::string>& CookGuide::getRequiredUtensils() const {
    return requiredUtensils;
}

const std::vector<std::string>& CookGuide::getRequiredAppliances() const {
    return requiredAppliances;
}

const std::vector<std::string>& CookGuide::getTemperatureRanges() const {
    return temperatureRanges;
}

const std::vector<std::string>& CookGuide::getKeyTechniques() const {
    return keyTechniques;
}

const Date& CookGuide::getMasteryTimeHours() const {
    return masteryTimeHours;
}

bool CookGuide::getIsVegetarian() const { return isVegetarian; }
bool CookGuide::getIsVegan() const { return isVegan; }
bool CookGuide::getIsGlutenFree() const { return isGlutenFree; }
bool CookGuide::getIsDairyFree() const { return isDairyFree; }
bool CookGuide::getIsNutFree() const { return isNutFree; }
bool CookGuide::getIsLowCarb() const { return isLowCarb; }
bool CookGuide::getIsKeto() const { return isKeto; }
bool CookGuide::getIsPaleo() const { return isPaleo; }
bool CookGuide::getIsSugarFree() const { return isSugarFree; }
bool CookGuide::getIsLowSodium() const { return isLowSodium; }
bool CookGuide::getIsHighProtein() const { return isHighProtein; }
bool CookGuide::getIsOrganicOnly() const { return isOrganicOnly; }


bool CookGuide::getHasDigitalVersion() const { return hasDigitalVersion; }
bool CookGuide::getHasAudioBook() const { return hasAudioBook; }
bool CookGuide::getHasVideoTutorials() const { return hasVideoTutorials; }
bool CookGuide::getHasMobileApp() const { return hasMobileApp; }
bool CookGuide::getHasOnlineCourse() const { return hasOnlineCourse; }
bool CookGuide::getHasPrintableWorksheets() const { return hasPrintableWorksheets; }
bool CookGuide::getHasShoppingLists() const { return hasShoppingLists; }
bool CookGuide::getHasMealPlanners() const { return hasMealPlanners; }
bool CookGuide::getHasProgressTracker() const { return hasProgressTracker; }
bool CookGuide::getHasCommunityAccess() const { return hasCommunityAccess; }


bool CookGuide::getIsAwardWinning() const { return isAwardWinning; }
bool CookGuide::getIsChefRecommended() const { return isChefRecommended; }
bool CookGuide::getIsCriticallyAcclaimed() const { return isCriticallyAcclaimed; }
bool CookGuide::getHasEditorChoice() const { return hasEditorChoice; }
bool CookGuide::getIsCustomerFavorite() const { return isCustomerFavorite; }
bool CookGuide::getHasMoneyBackGuarantee() const { return hasMoneyBackGuarantee; }
bool CookGuide::getIsEcoFriendly() const { return isEcoFriendly; }
bool CookGuide::getIsRecyclable() const { return isRecyclable; }




bool CookGuide::isSuitableForTemperature(const std::string& temperature) const {
    return std::find(temperatureRanges.begin(), temperatureRanges.end(), temperature) 
           != temperatureRanges.end();
}

bool CookGuide::containsTechnique(const std::string& technique) const {
    return std::find(keyTechniques.begin(), keyTechniques.end(), technique) 
           != keyTechniques.end();
}

double CookGuide::getAverageReviewLength() const {
    if (reviews.empty()) return 0.0;
    
    int totalLength = 0;
    for (const auto& review : reviews) {
        totalLength += review.length();
    }
    return static_cast<double>(totalLength) / reviews.size();
}

bool CookGuide::isPartOfSeries() const {
    return !seriesName.empty();
}

double CookGuide::getInformationDensity() const {
    if (topics.empty()) return 0.0;
    return static_cast<double>(pageCount) / topics.size();
}

bool CookGuide::hasAuthorReview() const {
    for (const auto& review : reviews) {
        if (review.find(author) != std::string::npos) {
            return true;
        }
    }
    return false;
}

int CookGuide::XPoverTime(Date studying) const
{
    return  difficulty * studying.ConvertToSec() / masteryTimeHours.ConvertToSec();
}
