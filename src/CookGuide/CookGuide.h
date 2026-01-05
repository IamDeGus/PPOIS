#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "../Common/Types/Date/Date.h"
#include "../Common/Types/Temperature/Temperature.h"


#include "BookMetadata.h"
#include "RequiredData.h"
#include "BookTags.h"

class CookGuide
{
private:
    BookMetadata metadata;
    RequiredData required;
    
    std::vector<std::string> temperatureRanges;
    std::vector<std::string> keyTechniques;
    
    Date masteryTimeHours;

    BookTags tags;

public:
    CookGuide(int pages, const std::string& auth, const std::string& desc,
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
             bool vegetarian = false, bool vegan = false, bool glutenFree = false,
             bool dairyFree = false, bool nutFree = false, bool lowCarb = false,
             bool keto = false, bool paleo = false, bool sugarFree = false,
             bool lowSodium = false, bool highProtein = false, bool organicOnly = false,
             bool digitalVersion = false, bool audioBook = false,
             bool videoTutorials = false, bool mobileApp = false,
             bool onlineCourse = false, bool printableWorksheets = false,
             bool shoppingLists = false, bool mealPlanners = false,
             bool progressTracker = false, bool communityAccess = false,
             bool awardWinning = false, bool chefRecommended = false,
             bool criticallyAcclaimed = false, bool editorChoice = false,
             bool customerFavorite = false, bool moneyBackGuarantee = false,
             bool ecoFriendly = false, bool recyclable = false);

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
    const std::vector<std::string>& getRequiredTools() const;
    const std::vector<std::string>& getRequiredUtensils() const;
    const std::vector<std::string>& getRequiredAppliances() const;
    const std::vector<std::string>& getTemperatureRanges() const;
    const std::vector<std::string>& getKeyTechniques() const;
    const Date& getMasteryTimeHours() const;

    bool getIsVegetarian() const;
    bool getIsVegan() const;
    bool getIsGlutenFree() const;
    bool getIsDairyFree() const;
    bool getIsNutFree() const;
    bool getIsLowCarb() const;
    bool getIsKeto() const;
    bool getIsPaleo() const;
    bool getIsSugarFree() const;
    bool getIsLowSodium() const;
    bool getIsHighProtein() const;
    bool getIsOrganicOnly() const;
    
    bool getHasDigitalVersion() const;
    bool getHasAudioBook() const;
    bool getHasVideoTutorials() const;
    bool getHasMobileApp() const;
    bool getHasOnlineCourse() const;
    bool getHasPrintableWorksheets() const;
    bool getHasShoppingLists() const;
    bool getHasMealPlanners() const;
    bool getHasProgressTracker() const;
    bool getHasCommunityAccess() const;
    
    bool getIsAwardWinning() const;
    bool getIsChefRecommended() const;
    bool getIsCriticallyAcclaimed() const;
    bool getHasEditorChoice() const;
    bool getIsCustomerFavorite() const;
    bool getHasMoneyBackGuarantee() const;
    bool getIsEcoFriendly() const;
    bool getIsRecyclable() const;


    bool isSuitableForTemperature(const std::string& temperature) const;
    bool containsTechnique(const std::string& technique) const;
    double getAverageReviewLength() const;
    bool isPartOfSeries() const;
    double getInformationDensity() const;
    bool hasAuthorReview() const;
    
    int XPoverTime(Date studying) const;
};
