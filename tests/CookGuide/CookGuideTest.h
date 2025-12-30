#include <UnitTest++/UnitTest++.h>

#include <algorithm>

#include "../../src/CookGuide/CookGuide.h"



SUITE(CookGuideTest){
    TEST(CookGuide_Basic) {
        // Создаем тестовые данные
        std::vector<std::string> topics = {"Итальянская кухня", "Паста", "Соусы"};
        std::vector<std::string> tools = {"нож поварской", "терка", "венчик"};
        std::vector<std::string> utensils = {"сковорода", "кастрюля", "миксерная чаша"};
        std::vector<std::string> appliances = {"плита", "духовка"};
        std::vector<std::string> temps = {"Горячее", "Теплое"};
        std::vector<std::string> techniques = {"Обжарка", "Томление", "Припускание"};
        std::vector<std::string> reviews = {"Отличный гайд!", "Подробно и понятно"};
        
        // Создаем объекты существующих классов
        Date creationDate(2024, 5, 15, 0, 0, 0, true);
        Date masteryTime(0, 0, 0, 40, 0, 0, false); // 40 часов для освоения
        Certification cert("Сертификат качества", "Золотой стандарт");
        Weight weight(850, Measur::Gram); // 850 грамм
        Grade rating = Grade::z4_5; // Предполагаем, что Grade это enum
        
        // Создаем объект CookingGuide
    CookGuide guide(
        150,                        // pageCount
        "Шеф-повар Марио",          // author
        "Полное руководство по приготовлению итальянской пасты", // description
        "Искусство итальянской пасты", // name
        "Шеф-коллекция",            // seriesName
        3,                          // serialNumber
        creationDate,               // creationDate
        cert,                       // certificate
        "Русский",                  // language
        topics,                     // topics
        7,                          // difficulty
        rating,                     // rating
        reviews,                    // reviews
        weight,                     // weight
        tools,                      // requiredTools
        utensils,                   // requiredUtensils
        appliances,                 // requiredAppliances
        temps,                      // temperatureRanges
        techniques,                 // keyTechniques
        masteryTime,                // masteryTimeHours
        // Новые bool параметры (первые 12 - диетические)
        true,   // isVegetarian
        false,  // isVegan
        true,   // isGlutenFree
        false,  // isDairyFree
        true,   // isNutFree
        false,  // isLowCarb
        true,   // isKeto
        false,  // isPaleo
        true,   // isSugarFree
        false,  // isLowSodium
        true,   // isHighProtein
        false,  // isOrganicOnly
        // Мультимедиа (10)
        true,   // hasDigitalVersion
        false,  // hasAudioBook
        true,   // hasVideoTutorials
        false,  // hasMobileApp
        true,   // hasOnlineCourse
        false,  // hasPrintableWorksheets
        true,   // hasShoppingLists
        false,  // hasMealPlanners
        true,   // hasProgressTracker
        false,  // hasCommunityAccess
        // Качество (8)
        true,   // isAwardWinning
        false,  // isChefRecommended
        true,   // isCriticallyAcclaimed
        false,  // hasEditorChoice
        true,   // isCustomerFavorite
        false,  // hasMoneyBackGuarantee
        true,   // isEcoFriendly
        false   // isRecyclable
    );
        
        // Проверяем геттеры для базовых типов
        CHECK_EQUAL(150, guide.getPageCount());
        CHECK_EQUAL("Шеф-повар Марио", guide.getAuthor());
        CHECK_EQUAL("Искусство итальянской пасты", guide.getName());
        CHECK_EQUAL("Шеф-коллекция", guide.getSeriesName());
        CHECK_EQUAL(3, guide.getSerialNumber());
        CHECK_EQUAL("Русский", guide.getLanguage());
        CHECK_EQUAL(7, guide.getDifficulty());
        
        // Проверяем объекты Date
        CHECK(guide.getCreationDate() == creationDate);
        CHECK(guide.getMasteryTimeHours() == masteryTime);
        
        // Проверяем объекты классов
        CHECK(guide.getCertificate() == cert);
        CHECK(guide.getWeight() == weight);
        CHECK(guide.getRating() == rating);
        
        // Проверяем векторы
        CHECK_EQUAL(3, guide.getTopics().size());
        CHECK_EQUAL(3, guide.getRequiredTools().size());
        CHECK_EQUAL(3, guide.getRequiredUtensils().size());
        CHECK_EQUAL(2, guide.getRequiredAppliances().size());
        CHECK_EQUAL(2, guide.getTemperatureRanges().size());
        CHECK_EQUAL(3, guide.getKeyTechniques().size());
        CHECK_EQUAL(2, guide.getReviews().size());
        
        // Проверяем содержимое векторов
        CHECK(std::find(guide.getTopics().begin(), guide.getTopics().end(), 
                        "Итальянская кухня") != guide.getTopics().end());
        CHECK(std::find(guide.getRequiredTools().begin(), guide.getRequiredTools().end(), 
                        "нож поварской") != guide.getRequiredTools().end());
        CHECK(std::find(guide.getKeyTechniques().begin(), guide.getKeyTechniques().end(), 
                        "Томление") != guide.getKeyTechniques().end());

        CHECK_EQUAL(true, guide.getIsVegetarian());
        CHECK_EQUAL(false, guide.getIsVegan());
        CHECK_EQUAL(true, guide.getIsGlutenFree());
        CHECK_EQUAL(false, guide.getIsDairyFree());
        CHECK_EQUAL(true, guide.getIsNutFree());
        CHECK_EQUAL(false, guide.getIsLowCarb());
        CHECK_EQUAL(true, guide.getIsKeto());
        CHECK_EQUAL(false, guide.getIsPaleo());
        CHECK_EQUAL(true, guide.getIsSugarFree());
        CHECK_EQUAL(false, guide.getIsLowSodium());
        CHECK_EQUAL(true, guide.getIsHighProtein());
        CHECK_EQUAL(false, guide.getIsOrganicOnly());
        
        CHECK_EQUAL(true, guide.getHasDigitalVersion());
        CHECK_EQUAL(false, guide.getHasAudioBook());
        CHECK_EQUAL(true, guide.getHasVideoTutorials());
        CHECK_EQUAL(false, guide.getHasMobileApp());
        CHECK_EQUAL(true, guide.getHasOnlineCourse());
        CHECK_EQUAL(false, guide.getHasPrintableWorksheets());
        CHECK_EQUAL(true, guide.getHasShoppingLists());
        CHECK_EQUAL(false, guide.getHasMealPlanners());
        CHECK_EQUAL(true, guide.getHasProgressTracker());
        CHECK_EQUAL(false, guide.getHasCommunityAccess());
        
        CHECK_EQUAL(true, guide.getIsAwardWinning());
        CHECK_EQUAL(false, guide.getIsChefRecommended());
        CHECK_EQUAL(true, guide.getIsCriticallyAcclaimed());
        CHECK_EQUAL(false, guide.getHasEditorChoice());
        CHECK_EQUAL(true, guide.getIsCustomerFavorite());
        CHECK_EQUAL(false, guide.getHasMoneyBackGuarantee());
        CHECK_EQUAL(true, guide.getIsEcoFriendly());
        CHECK_EQUAL(false, guide.getIsRecyclable());
    }

    TEST(CookGuide_BehaviorFunctions) {
        // Подготовка тестовых данных
        std::vector<std::string> topics = {"Итальянская кухня", "Паста", "Соусы"};
        std::vector<std::string> tools = {"нож", "терка", "венчик"};
        std::vector<std::string> utensils = {"сковорода", "кастрюля"};
        std::vector<std::string> appliances = {"плита", "духовка", "миксер"};
        std::vector<std::string> temps = {"Горячее", "Теплое", "Холодное"};
        std::vector<std::string> techniques = {"Жарка", "Варка", "Запекание"};
        std::vector<std::string> reviews = {"Отличный гайд от Шеф-повара!", "Подробно и понятно"};
        
        Date creationDate(2024, 5, 15, 0, 0, 0, true);
        Date masteryTime(0, 0, 0, 40, 0, 0, false);
        Certification cert("Сертификат", "Золотой");
        Weight weight(850, Measur::Gram);
        Grade rating = Grade::z4_5;
        
        CookGuide guide(
            150, "Шеф-повар Марио", "Руководство", "Итальянская паста",
            "Шеф-коллекция", 3, creationDate, cert, "Русский",
            topics, 400, rating, reviews, weight,
            tools, utensils, appliances, temps, techniques, masteryTime
        );
        
        CHECK_EQUAL(true, guide.isSuitableForTemperature("Горячее"));
        CHECK_EQUAL(false, guide.isSuitableForTemperature("Очень горячее"));
        
        CHECK_EQUAL(true, guide.containsTechnique("Варка"));
        CHECK_EQUAL(false, guide.containsTechnique("Копчение"));

        double avgLength = guide.getAverageReviewLength();
        CHECK(avgLength > 0);
        
        CHECK_EQUAL(true, guide.isPartOfSeries());
        
        double density = guide.getInformationDensity();
        CHECK_EQUAL(50.0, density);
        
        CHECK_EQUAL(false, guide.hasAuthorReview());


        CHECK_EQUAL(100, guide.XPoverTime(Date(0, 0, 0, 10, 0, 0, false)));
    }

    TEST(CookingGuide_EdgeCases) {
        CookGuide emptyGuide(
            0, "", "", "", "", 0, Date(), Certification("Сертификат", "Золотой"), "",
            {}, 0, Grade::z1_0, {}, Weight(0, Measur::Gram),
            {}, {}, {}, {}, {}, Date(0, 0, 0, 0, 0, 0, false)
        );
        
        CHECK_EQUAL(false, emptyGuide.isSuitableForTemperature("Горячее"));
        CHECK_EQUAL(0.0, emptyGuide.getAverageReviewLength());
        CHECK_EQUAL(false, emptyGuide.isPartOfSeries());
        CHECK_EQUAL(0.0, emptyGuide.getInformationDensity());
        CHECK_EQUAL(false, emptyGuide.hasAuthorReview());
        
        std::vector<std::string> singleTopic = {"Кулинария"};
        std::vector<std::string> singleTool = {"нож"};
        std::vector<std::string> singleReview = {"Хорошо"};
        
        CookGuide simpleGuide(
            100, "Автор", "Описание", "Название",
            "", 1, Date(), Certification("Сертификат", "Золотой"), "Русский",
            singleTopic, 5, Grade::z3_0, singleReview, Weight(500, Measur::Gram),
            singleTool, {}, {}, {}, {}, Date(0, 0, 0, 10, 0, 0, false)
        );
        
        CHECK_EQUAL(100.0, simpleGuide.getInformationDensity());
        CHECK_EQUAL(false, simpleGuide.isPartOfSeries());
    }
}
