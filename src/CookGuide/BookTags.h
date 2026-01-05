#pragma once



class BookTags
{
private:
    bool isVegetarian;
    bool isVegan;
    bool isGlutenFree;
    bool isDairyFree;
    bool isNutFree;
    bool isLowCarb;
    bool isKeto;
    bool isPaleo;
    bool isSugarFree;
    bool isLowSodium;
    bool isHighProtein;
    bool isOrganicOnly;

    bool hasDigitalVersion;
    bool hasAudioBook;
    bool hasVideoTutorials;
    bool hasMobileApp;
    bool hasOnlineCourse;
    bool hasPrintableWorksheets;
    bool hasShoppingLists;
    bool hasMealPlanners;
    bool hasProgressTracker;
    bool hasCommunityAccess;

    bool isAwardWinning;
    bool isChefRecommended;
    bool isCriticallyAcclaimed;
    bool hasEditorChoice;
    bool isCustomerFavorite;
    bool hasMoneyBackGuarantee;
    bool isEcoFriendly;
    bool isRecyclable;
public:
    BookTags(bool vegetarian = false, bool vegan = false, bool glutenFree = false,
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
};

