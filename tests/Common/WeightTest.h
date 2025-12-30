#include <UnitTest++/UnitTest++.h>

#include "../../src/Common/Types/Weight/Weight.h"   
#include "../../src/Common/Exeptions/WeightExeption.h"

SUITE(WeightTest)
{
    TEST(Weight_ConstructorAndGetters)
    {
        Weight weight(1, Measur::Kilogram);

        CHECK_CLOSE(1, weight.getVolume(), 0.001);
        CHECK(Measur::Kilogram == weight.getMeasur());
    }

    TEST(Weight_getStringWeight)
    {
        Weight weight1(1, Measur::Gram);
        Weight weight2(1, Measur::Kilogram);
        Weight weight3(1, Measur::Milliliter);
        Weight weight4(1, Measur::Liter);
        Weight weight5(1, Measur::Pinch);
        Weight weight6(1, Measur::Piece);
        Weight weight7(1, Measur::Tablespoon);
        Weight weight8(1, Measur::Teaspoon);

        CHECK_EQUAL("1g", weight1.getStringWeight());
        CHECK_EQUAL("1kg", weight2.getStringWeight());
        CHECK_EQUAL("1ml", weight3.getStringWeight());
        CHECK_EQUAL("1l", weight4.getStringWeight());
        CHECK_EQUAL("1pnch", weight5.getStringWeight());
        CHECK_EQUAL("1pc", weight6.getStringWeight());
        CHECK_EQUAL("1tblspoon", weight7.getStringWeight());
        CHECK_EQUAL("1teaspoon", weight8.getStringWeight());
    }

    TEST(Weight_Coefficient)
    {
        CHECK_CLOSE(1, Weight::Coefficient(Measur::Gram), 0.001);
        CHECK_CLOSE(1000, Weight::Coefficient(Measur::Kilogram), 0.001);
        CHECK_CLOSE(1000, Weight::Coefficient(Measur::Liter), 0.001);
        CHECK_CLOSE(1, Weight::Coefficient(Measur::Milliliter), 0.001);
        CHECK_CLOSE(0.3, Weight::Coefficient(Measur::Pinch), 0.001);
        CHECK_CLOSE(15, Weight::Coefficient(Measur::Tablespoon), 0.001);
        CHECK_CLOSE(5, Weight::Coefficient(Measur::Teaspoon), 0.001);
        CHECK_CLOSE(500, Weight::Coefficient(Measur::Piece), 0.001);
    }

    TEST(Weight_Exception)
    {
        Weight weight1(1, Measur::Kilogram);
        Weight weight2(1, Measur::Liter);
        Weight weight3(1, Measur::Piece);
        Weight weight4(2, Measur::Kilogram);

        CHECK_THROW(weight1.ConventerTo(Measur::Piece), WeightException);
        CHECK_THROW(weight1 - weight2, WeightException);
        CHECK_THROW(weight1 + weight2, WeightException);
        CHECK_THROW(weight1 - weight4, WeightException);
        CHECK_THROW(weight1 < weight2, WeightException);
        CHECK_THROW(weight1 == weight2, WeightException);
    }



}
