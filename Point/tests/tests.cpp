#include <UnitTest++/UnitTest++.h>

#include "../point.h"

TEST(Point_init) {
    Point a;

    CHECK_CLOSE(a.x, 0, 1e-9);
    CHECK_CLOSE(a.y, 0, 1e-9);
    CHECK_CLOSE(a.z, 0, 1e-9);
}

TEST(Point_init_pos) {
    Point a = {10, 6, 1};

    CHECK_CLOSE(a.x, 10, 1e-9);
    CHECK_CLOSE(a.y, 6, 1e-9);
    CHECK_CLOSE(a.z, 1, 1e-9);
}

TEST(Point_init_neg) {
    Point a = {-4, -33, -1};

    CHECK_CLOSE(a.x, -4, 1e-9);
    CHECK_CLOSE(a.y, -33, 1e-9);
    CHECK_CLOSE(a.z, -1, 1e-9);
}

TEST(Point_init_zero) {
    Point a = {0, 0, 0};

    CHECK_CLOSE(a.x, 0, 1e-9);
    CHECK_CLOSE(a.y, 0, 1e-9);
    CHECK_CLOSE(a.z, 0, 1e-9);
}


TEST(Point_add_1) {
    Point a = {3, 0, 11};
    Point b = {-6, 8, 0};

    Point c = a + b;

    CHECK_CLOSE(c.x, -3, 1e-9);
    CHECK_CLOSE(c.y, 8, 1e-9);
    CHECK_CLOSE(c.z, 11, 1e-9);
}

TEST(Point_add_2) {
    Point a = {3, 0, 11};
    Point b = {-6, 8, 0};

    a += b;

    CHECK_CLOSE(a.x, -3, 1e-9);
    CHECK_CLOSE(a.y, 8, 1e-9);
    CHECK_CLOSE(a.z, 11, 1e-9);
}

TEST(Point_diff_1) {
    Point a = {3, 0, 11};
    Point b = {-6, 8, 0};

    Point c = a - b;

    CHECK_CLOSE(c.x, 9, 1e-9);
    CHECK_CLOSE(c.y, -8, 1e-9);
    CHECK_CLOSE(c.z, 11, 1e-9);
}

TEST(Point_diff_2) {
    Point a = {3, 0, 11};
    Point b = {-6, 8, 0};

    a -= b;

    CHECK_CLOSE(a.x, 9, 1e-9);
    CHECK_CLOSE(a.y, -8, 1e-9);
    CHECK_CLOSE(a.z, 11, 1e-9);
}


TEST(Point_multiplication_1) {
    Point a = {3, 0, 11};
    int b = 2;

    Point c = a * b;

    CHECK_CLOSE(c.x, 6, 1e-9);
    CHECK_CLOSE(c.y, 0, 1e-9);
    CHECK_CLOSE(c.z, 22, 1e-9);
}

TEST(Point_multiplication_2) {
    Point a = {3, 0, 11};
    int b = 2;

    a *= b;

    CHECK_CLOSE(a.x, 6, 1e-9);
    CHECK_CLOSE(a.y, 0, 1e-9);
    CHECK_CLOSE(a.z, 22, 1e-9);
}

TEST(Point_GetLength){
    Point a = {12, -4, 3};
    CHECK_CLOSE(a.GetLength(), 13, 1e-9);
}
