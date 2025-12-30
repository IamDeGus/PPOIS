#pragma once


#include "Grade.h"
#include "../../Exeptions/TypeExeption.h"


class GradeHelper
{
public:
    static bool GradeAlessB(Grade A, Grade B)
    {
        int a{GradeToInt(A)}, b{GradeToInt(B)};
        return a <= b;
    };

    static int GradeToInt(Grade grade)
    {
        switch (grade)
        {
        case Grade::z5_0: return 10;
        case Grade::z4_5: return 9;
        case Grade::z4_0: return 8;
        case Grade::z3_5: return 7;
        case Grade::z3_0: return 6;
        case Grade::z2_5: return 5;
        case Grade::z2_0: return 4;
        case Grade::z1_5: return 3;
        case Grade::z1_0: return 2;    
        }

        throw TypeException("Convert failed : non-standard grade");
    }
};
