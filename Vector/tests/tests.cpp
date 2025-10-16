#include <UnitTest++/UnitTest++.h>

#include "../vector.h"
#include "../../Point/point.h"

TEST(СonstructorAndGetter_Beg) {
    Vector a({0,9,-48},{3,-5,7});
    Point beg = a.GetBegin();

    CHECK_CLOSE(beg.x, 0, 1e-9);
    CHECK_CLOSE(beg.y, 9, 1e-9);
    CHECK_CLOSE(beg.z, -48, 1e-9);
}

TEST(СonstructorAndGetter_End) {
    Vector a({0,9,-48},{3,-5,7});
    Point end = a.GetEnd();

    CHECK_CLOSE(end.x, 3, 1e-9);
    CHECK_CLOSE(end.y, -5, 1e-9);
    CHECK_CLOSE(end.z, 7, 1e-9);
}

TEST(VectorLength) {
    Vector a({0,1,0},{4,4,0});
    CHECK_CLOSE(a.GetLength(), 5, 1e-9); // проверка длины
}

TEST(VectorAddition_1) {
    Vector a({1,1,1},{20,-3,6});
    Vector b({0,0,-1},{0,0,-1});

    Vector c = a + b;

    Point beg = c.GetBegin();
    Point end = c.GetEnd();

    CHECK_CLOSE(beg.x, 0, 1e-9);
    CHECK_CLOSE(beg.y, 0, 1e-9);
    CHECK_CLOSE(beg.z, 0, 1e-9);

    CHECK_CLOSE(end.x, 19, 1e-9);
    CHECK_CLOSE(end.y, -4, 1e-9);
    CHECK_CLOSE(end.z, 5, 1e-9);
}

TEST(VectorAddition_2) {
    Vector a({1,1,1},{20,-3,6});
    Vector b({0,0,-1},{0,0,-1});

    a += b;

    Point beg = a.GetBegin();
    Point end = a.GetEnd();

    CHECK_CLOSE(beg.x, 1, 1e-9);
    CHECK_CLOSE(beg.y, 1, 1e-9);
    CHECK_CLOSE(beg.z, 1, 1e-9);

    CHECK_CLOSE(end.x, 20, 1e-9);
    CHECK_CLOSE(end.y, -3, 1e-9);
    CHECK_CLOSE(end.z, 6, 1e-9);
}

TEST(VectorAddition_3) {
    Vector a({-1,0,8},{3,4,0});
    Vector b({3,9,2},{-3,0,5});

    Vector c = a + b;

    Point beg = c.GetBegin();
    Point end = c.GetEnd();

    CHECK_CLOSE(beg.x, 0, 1e-9);
    CHECK_CLOSE(beg.y, 0, 1e-9);
    CHECK_CLOSE(beg.z, 0, 1e-9);

    CHECK_CLOSE(end.x, -2, 1e-9);
    CHECK_CLOSE(end.y, -5, 1e-9);
    CHECK_CLOSE(end.z, -5, 1e-9);
}

TEST(VectorAddition_4) {
    Vector a({-1,0,8},{3,4,0});
    Vector b({3,9,2},{-3,0,5});

    a += b;

    Point beg = a.GetBegin();
    Point end = a.GetEnd();

    CHECK_CLOSE(beg.x, -1, 1e-9);
    CHECK_CLOSE(beg.y, 0, 1e-9);
    CHECK_CLOSE(beg.z, 8, 1e-9);

    CHECK_CLOSE(end.x, -3, 1e-9);
    CHECK_CLOSE(end.y, -5, 1e-9);
    CHECK_CLOSE(end.z, 3, 1e-9);
}



TEST(VectorDifference_1) {
    Vector a({0,0,0},{19,-4,5});
    Vector b({0,0,0},{0,0,0});

    Vector c = a - b;

    Point beg = c.GetBegin();
    Point end = c.GetEnd();

    CHECK_CLOSE(beg.x, 0, 1e-9);
    CHECK_CLOSE(beg.y, 0, 1e-9);
    CHECK_CLOSE(beg.z, 0, 1e-9);

    CHECK_CLOSE(end.x, 19, 1e-9);
    CHECK_CLOSE(end.y, -4, 1e-9);
    CHECK_CLOSE(end.z, 5, 1e-9);
}

TEST(VectorDifference_2) {
    Vector a({1,1,1},{20,-3,6});
    Vector b({0,0,-1},{0,0,-1});

    a -= b;

    Point beg = a.GetBegin();
    Point end = a.GetEnd();

    CHECK_CLOSE(beg.x, 1, 1e-9);
    CHECK_CLOSE(beg.y, 1, 1e-9);
    CHECK_CLOSE(beg.z, 1, 1e-9);

    CHECK_CLOSE(end.x, 20, 1e-9);
    CHECK_CLOSE(end.y, -3, 1e-9);
    CHECK_CLOSE(end.z, 6, 1e-9);
}

TEST(VectorDifference_3) {
    Vector a({-1,0,8},{3,4,0});
    Vector b({3,9,2},{-3,0,5});

    Vector c = a - b;

    Point beg = c.GetBegin();
    Point end = c.GetEnd();

    CHECK_CLOSE(beg.x, 0, 1e-9);
    CHECK_CLOSE(beg.y, 0, 1e-9);
    CHECK_CLOSE(beg.z, 0, 1e-9);

    CHECK_CLOSE(end.x, 10, 1e-9);
    CHECK_CLOSE(end.y, 13, 1e-9);
    CHECK_CLOSE(end.z, -11, 1e-9);
}

TEST(VectorDifference_4) {
    Vector a({-1,0,8},{3,4,0});
    Vector b({3,9,2},{-3,0,5});

    a -= b;

    Point beg = a.GetBegin();
    Point end = a.GetEnd();

    CHECK_CLOSE(beg.x, -1, 1e-9);
    CHECK_CLOSE(beg.y, 0, 1e-9);
    CHECK_CLOSE(beg.z, 8, 1e-9);

    CHECK_CLOSE(end.x, 9, 1e-9);
    CHECK_CLOSE(end.y, 13, 1e-9);
    CHECK_CLOSE(end.z, -3, 1e-9);
}


TEST(CrossProduct_1) {
    Vector a({-1,0,8},{3,4,0});
    Vector b({3,9,2},{-3,0,5});

    Vector c = a * b;

    Point beg = c.GetBegin();
    Point end = c.GetEnd();

    CHECK_CLOSE(beg.x, 0, 1e-9);
    CHECK_CLOSE(beg.y, 0, 1e-9);
    CHECK_CLOSE(beg.z, 0, 1e-9);

    CHECK_CLOSE(end.x, -60, 1e-9);
    CHECK_CLOSE(end.y, 36, 1e-9);
    CHECK_CLOSE(end.z, -12, 1e-9);
}

TEST(CrossProduct_2) {
    Vector a({-1,0,8},{3,4,0});
    Vector b({3,9,2},{-3,0,5});

    a *= b;

    Point beg = a.GetBegin();
    Point end = a.GetEnd();

    CHECK_CLOSE(beg.x, -1, 1e-9);
    CHECK_CLOSE(beg.y, 0, 1e-9);
    CHECK_CLOSE(beg.z, 8, 1e-9);

    CHECK_CLOSE(end.x, -61, 1e-9);
    CHECK_CLOSE(end.y, 36, 1e-9);
    CHECK_CLOSE(end.z, -4, 1e-9);
}


TEST(VectorDivision_1) {
    Vector a({1,1,1},{33,5,19});
    Vector b({0,0,0},{1,2,3});

    Vector c = a / b;

    Point beg = c.GetBegin();
    Point end = c.GetEnd();

    CHECK_CLOSE(beg.x, 0, 1e-9);
    CHECK_CLOSE(beg.y, 0, 1e-9);
    CHECK_CLOSE(beg.z, 0, 1e-9);

    CHECK_CLOSE(end.x, 32, 1e-9);
    CHECK_CLOSE(end.y, 2, 1e-9);
    CHECK_CLOSE(end.z, 6, 1e-9);
}

TEST(VectorDivision_2) {
    Vector a({1,1,1},{33,5,19});
    Vector b({0,0,0},{1,2,3});

    a /= b;

    Point beg = a.GetBegin();
    Point end = a.GetEnd();

    CHECK_CLOSE(beg.x, 1, 1e-9);
    CHECK_CLOSE(beg.y, 1, 1e-9);
    CHECK_CLOSE(beg.z, 1, 1e-9);

    CHECK_CLOSE(end.x, 33, 1e-9);
    CHECK_CLOSE(end.y, 3, 1e-9);
    CHECK_CLOSE(end.z, 7, 1e-9);
}

TEST(VectorDivisionError) {
    Vector a({1,1,1},{33,5,19});
    Vector b({0,0,-5},{0,2,-5});

    CHECK_THROW(a / b, std::exception);
}

TEST(Cosine_1) {
    Vector a({3, 0, 1}, {5, 0, 1});
    Vector b({0, 0, 1}, {6, 0, 1});

    CHECK_CLOSE(a^b, 1, 1e-9);
}

TEST(Cosine_2) {
    Vector a({3, 0, 1}, {5, 0, 1});
    Vector b({0, 0, 1}, {0, 6, 1});

    CHECK_CLOSE(a^b, 0, 1e-9);
}

TEST(Cosine_3) {
    Vector a({0, 0, 0}, {-1, 0, 0});
    Vector b({0, 0, 0}, {1, 0, 0});

    CHECK_CLOSE(a^b, -1, 1e-9);
}

TEST(CosineError) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {0, 0, 0});

    CHECK_THROW(a ^ b, std::exception);
}

TEST(СomparisonEQ_1) {
    Vector a({0, -4, 5}, {1, 2, 3});
    Vector b({0, -4, 5}, {1, 2, 3});

    CHECK_EQUAL(a == b, true);
}

TEST(СomparisonEQ_2) {
    Vector a({0, -4, 5}, {1, 2, 3});
    Vector b = a;

    CHECK_EQUAL(a == b, true);
}

TEST(СomparisonEQ_3) {
    Vector a({0, -4, 5}, {1, 2, 3});
    Vector b = a;
    a += a;

    CHECK_EQUAL(a == b, false);
}

TEST(СomparisonEQ_4) {
    Vector a({0, -4, 5}, {1, 2, 3});
    Vector b = a;
    b *= 5;
    b += b;

    b -= (a * 9);

    CHECK_EQUAL(a == b, true);
}

TEST(СomparisonEQ_5) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({-1, -2, -3}, {0, 0, 0});

    CHECK_EQUAL(a == b, true);
}

TEST(СomparisonEQ_6) {
    Vector a({0, 0, 0}, {1.00001, 2.00002, 3.00003});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_EQUAL(a == b, false);
}

TEST(СomparisonLT_1) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {2, 4, 6});

    CHECK_EQUAL(a < b, true);
}

TEST(СomparisonLT_2) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_EQUAL(a < b, false);
}

TEST(СomparisonLT_3) {
    Vector a({0, 0, 0}, {2, 4, 6});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_EQUAL(a < b, false);
}

TEST(СomparisonGT_1) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {2, 4, 6});

    CHECK_EQUAL(a > b, false);
}

TEST(СomparisonGT_2) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_EQUAL(a > b, false);
}

TEST(СomparisonGT_3) {
    Vector a({0, 0, 0}, {2, 4, 6});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_EQUAL(a > b, true);
}

TEST(СomparisonLE_1) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {2, 4, 6});

    CHECK_EQUAL(a <= b, true);
}

TEST(СomparisonLE_2) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_EQUAL(a <= b, true);
}

TEST(СomparisonLE_3) {
    Vector a({0, 0, 0}, {2, 4, 6});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_EQUAL(a <= b, false);
}

TEST(СomparisonGE_1) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {2, 4, 6});

    CHECK_EQUAL(a >= b, false);
}

TEST(СomparisonGE_2) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_EQUAL(a >= b, true);
}

TEST(СomparisonGE_3) {
    Vector a({0, 0, 0}, {2, 4, 6});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_EQUAL(a >= b, true);
}

TEST(СomparisonNE_1) {
    Vector a({0, -4, 5}, {1, 2, 3});
    Vector b({0, -4, 5}, {1, 2, 3});

    CHECK_EQUAL(a != b, false);
}

TEST(СomparisonNE_2) {
    Vector a({0, 0, 0}, {1, 2, 3});
    Vector b({0, 0, 0}, {3, 6, 9});

    CHECK_EQUAL(a != b, true);
}

TEST(СomparisonError_1) {
    Vector a({0, 0, 0}, {1, 3, 2});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_THROW(a == b, std::exception);
}

TEST(СomparisonError_2) {
    Vector a({0, 0, 0}, {1, 3, 2});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_THROW(a != b, std::exception);
}

TEST(СomparisonError_3) {
    Vector a({0, 0, 0}, {1, 3, 2});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_THROW(a < b, std::exception);
}

TEST(СomparisonError_4) {
    Vector a({0, 0, 0}, {1, 3, 2});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_THROW(a > b, std::exception);
}

TEST(СomparisonError_5) {
    Vector a({0, 0, 0}, {1, 3, 2});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_THROW(a >= b, std::exception);
}

TEST(СomparisonError_6) {
    Vector a({0, 0, 0}, {1, 3, 2});
    Vector b({0, 0, 0}, {1, 2, 3});

    CHECK_THROW(a <= b, std::exception);
}

TEST(VectorOutput) {
    Vector a({5,4,3},{2,1,0});
    std::ostringstream oss;
    oss << a;

    CHECK_EQUAL("({5,4,3},{2,1,0})", oss.str()); 
}

TEST(VectorInput) {
    Vector a;
    std::istringstream iss("5 4 3 2 1 0");

    iss >> a;

    Point beg = a.GetBegin();
    Point end = a.GetEnd();

    CHECK_CLOSE(beg.x, 5, 1e-9);
    CHECK_CLOSE(beg.y, 4, 1e-9);
    CHECK_CLOSE(beg.z, 3, 1e-9);

    CHECK_CLOSE(end.x, 2, 1e-9);
    CHECK_CLOSE(end.y, 1, 1e-9);
    CHECK_CLOSE(end.z, 0, 1e-9);
}
