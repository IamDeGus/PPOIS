#include "BookTags.h"

BookTags::BookTags(bool vegetarian, bool vegan, bool glutenFree, 
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
    : isVegetarian(vegetarian), isVegan(vegan), isGlutenFree(glutenFree),
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
      isEcoFriendly(ecoFriendly), isRecyclable(recyclable){}



bool BookTags::getIsVegetarian() const { return isVegetarian; }
bool BookTags::getIsVegan() const { return isVegan; }
bool BookTags::getIsGlutenFree() const { return isGlutenFree; }
bool BookTags::getIsDairyFree() const { return isDairyFree; }
bool BookTags::getIsNutFree() const { return isNutFree; }
bool BookTags::getIsLowCarb() const { return isLowCarb; }
bool BookTags::getIsKeto() const { return isKeto; }
bool BookTags::getIsPaleo() const { return isPaleo; }
bool BookTags::getIsSugarFree() const { return isSugarFree; }
bool BookTags::getIsLowSodium() const { return isLowSodium; }
bool BookTags::getIsHighProtein() const { return isHighProtein; }
bool BookTags::getIsOrganicOnly() const { return isOrganicOnly; }


bool BookTags::getHasDigitalVersion() const { return hasDigitalVersion; }
bool BookTags::getHasAudioBook() const { return hasAudioBook; }
bool BookTags::getHasVideoTutorials() const { return hasVideoTutorials; }
bool BookTags::getHasMobileApp() const { return hasMobileApp; }
bool BookTags::getHasOnlineCourse() const { return hasOnlineCourse; }
bool BookTags::getHasPrintableWorksheets() const { return hasPrintableWorksheets; }
bool BookTags::getHasShoppingLists() const { return hasShoppingLists; }
bool BookTags::getHasMealPlanners() const { return hasMealPlanners; }
bool BookTags::getHasProgressTracker() const { return hasProgressTracker; }
bool BookTags::getHasCommunityAccess() const { return hasCommunityAccess; }


bool BookTags::getIsAwardWinning() const { return isAwardWinning; }
bool BookTags::getIsChefRecommended() const { return isChefRecommended; }
bool BookTags::getIsCriticallyAcclaimed() const { return isCriticallyAcclaimed; }
bool BookTags::getHasEditorChoice() const { return hasEditorChoice; }
bool BookTags::getIsCustomerFavorite() const { return isCustomerFavorite; }
bool BookTags::getHasMoneyBackGuarantee() const { return hasMoneyBackGuarantee; }
bool BookTags::getIsEcoFriendly() const { return isEcoFriendly; }
bool BookTags::getIsRecyclable() const { return isRecyclable; }


