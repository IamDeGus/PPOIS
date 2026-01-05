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
    : metadata(pages, auth, desc, guideName, series, serial, creation,
               cert, lang, tops, diff,rate, revs, w),
      required(tools, utensils, appliances), temperatureRanges(temps),
      keyTechniques(techniques), masteryTimeHours(masteryTime),
      tags(vegetarian, vegan, glutenFree, dairyFree, nutFree, lowCarb,
           keto, paleo, sugarFree, lowSodium, highProtein, organicOnly, 
           digitalVersion, audioBook, videoTutorials, mobileApp, 
           onlineCourse, printableWorksheets, shoppingLists, 
           mealPlanners, progressTracker, communityAccess, awardWinning,
           chefRecommended, criticallyAcclaimed, editorChoice, 
           customerFavorite, moneyBackGuarantee, ecoFriendly, recyclable) {}

int CookGuide::getPageCount() const {
    return metadata.getPageCount();
}

const std::string& CookGuide::getAuthor() const {
    return metadata.getAuthor();
}

const std::string& CookGuide::getDescription() const {
    return metadata.getDescription();
}

const std::string& CookGuide::getName() const {
    return metadata.getName();
}

const std::string& CookGuide::getSeriesName() const {
    return metadata.getSeriesName();
}

int CookGuide::getSerialNumber() const {
    return metadata.getSerialNumber();
}

const Date& CookGuide::getCreationDate() const {
    return metadata.getCreationDate();
}

const Certification& CookGuide::getCertificate() const {
    return metadata.getCertificate();
}

const std::string& CookGuide::getLanguage() const {
    return metadata.getLanguage();
}

const std::vector<std::string>& CookGuide::getTopics() const {
    return metadata.getTopics();
}

int CookGuide::getDifficulty() const {
    return metadata.getDifficulty();
}

Grade CookGuide::getRating() const {
    return metadata.getRating();
}

const std::vector<std::string>& CookGuide::getReviews() const {
    return metadata.getReviews();
}

const Weight& CookGuide::getWeight() const {
    return metadata.getWeight();
}

const std::vector<std::string>& CookGuide::getRequiredTools() const {
    return required.getRequiredTools();
}

const std::vector<std::string>& CookGuide::getRequiredUtensils() const {
    return required.getRequiredUtensils();
}

const std::vector<std::string>& CookGuide::getRequiredAppliances() const {
    return required.getRequiredAppliances();
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

bool CookGuide::getIsVegetarian() const { return tags.getIsVegetarian(); }
bool CookGuide::getIsVegan() const { return tags.getIsVegan(); }
bool CookGuide::getIsGlutenFree() const { return tags.getIsGlutenFree(); }
bool CookGuide::getIsDairyFree() const { return tags.getIsDairyFree(); }
bool CookGuide::getIsNutFree() const { return tags.getIsNutFree(); }
bool CookGuide::getIsLowCarb() const { return tags.getIsLowCarb(); }
bool CookGuide::getIsKeto() const { return tags.getIsKeto(); }
bool CookGuide::getIsPaleo() const { return tags.getIsPaleo(); }
bool CookGuide::getIsSugarFree() const { return tags.getIsSugarFree(); }
bool CookGuide::getIsLowSodium() const { return tags.getIsLowSodium(); }
bool CookGuide::getIsHighProtein() const { return tags.getIsHighProtein(); }
bool CookGuide::getIsOrganicOnly() const { return tags.getIsOrganicOnly(); }


bool CookGuide::getHasDigitalVersion() const { return tags.getHasDigitalVersion(); }
bool CookGuide::getHasAudioBook() const { return tags.getHasAudioBook(); }
bool CookGuide::getHasVideoTutorials() const { return tags.getHasVideoTutorials(); }
bool CookGuide::getHasMobileApp() const { return tags.getHasMobileApp(); }
bool CookGuide::getHasOnlineCourse() const { return tags.getHasOnlineCourse(); }
bool CookGuide::getHasPrintableWorksheets() const { return tags.getHasPrintableWorksheets(); }
bool CookGuide::getHasShoppingLists() const { return tags.getHasShoppingLists(); }
bool CookGuide::getHasMealPlanners() const { return tags.getHasMealPlanners(); }
bool CookGuide::getHasProgressTracker() const { return tags.getHasProgressTracker(); }
bool CookGuide::getHasCommunityAccess() const { return tags.getHasCommunityAccess(); }


bool CookGuide::getIsAwardWinning() const { return tags.getIsAwardWinning(); }
bool CookGuide::getIsChefRecommended() const { return tags.getIsChefRecommended(); }
bool CookGuide::getIsCriticallyAcclaimed() const { return tags.getIsCriticallyAcclaimed(); }
bool CookGuide::getHasEditorChoice() const { return tags.getHasEditorChoice(); }
bool CookGuide::getIsCustomerFavorite() const { return tags.getIsCustomerFavorite(); }
bool CookGuide::getHasMoneyBackGuarantee() const { return tags.getHasMoneyBackGuarantee(); }
bool CookGuide::getIsEcoFriendly() const { return tags.getIsEcoFriendly(); }
bool CookGuide::getIsRecyclable() const { return tags.getIsRecyclable(); }




bool CookGuide::isSuitableForTemperature(const std::string& temperature) const {
    return std::find(temperatureRanges.begin(), temperatureRanges.end(), temperature) 
           != temperatureRanges.end();
}

bool CookGuide::containsTechnique(const std::string& technique) const {
    return std::find(keyTechniques.begin(), keyTechniques.end(), technique) 
           != keyTechniques.end();
}

double CookGuide::getAverageReviewLength() const {
    if (metadata.getReviews().empty()) return 0.0;
    
    int totalLength = 0;
    for (const auto& review : metadata.getReviews()) {
        totalLength += review.length();
    }
    return static_cast<double>(totalLength) / metadata.getReviews().size();
}

bool CookGuide::isPartOfSeries() const {
    return !metadata.getSeriesName().empty();
}

double CookGuide::getInformationDensity() const {
    if (metadata.getTopics().empty()) return 0.0;
    return static_cast<double>(metadata.getPageCount()) / metadata.getTopics().size();
}

bool CookGuide::hasAuthorReview() const {
    for (const auto& review : metadata.getReviews()) {
        if (review.find(metadata.getAuthor()) != std::string::npos) {
            return true;
        }
    }
    return false;
}

int CookGuide::XPoverTime(Date studying) const
{
    return  metadata.getDifficulty() * studying.ConvertToSec() / masteryTimeHours.ConvertToSec();
}
