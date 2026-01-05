#pragma once

#include "../../value_objects/Height/Height.h"
#include "../../value_objects/Weight/Weight.h"
#include "../../value_objects/Circumference/Circumference.h"
#include "../../value_objects/MetricHistory/MetricHistory.h"
#include "../../value_objects/BodyFat/BodyFatCategory.h"
#include "../../value_objects/BodyFat/BodyFatPercentage.h"


class PhysicalProfile
{
private:
    Height height_;
    Weight weight_;

    Circumference neck_;
    Circumference biceps_;
    Circumference chest_;
    Circumference waist_;
    Circumference hips_;
    Circumference thigh_;
    Circumference calf_;

    BodyFatPercentage fatPct_;
    BodyFatCategory fatCtgr_;

    MetricHistory<Weight> weightH_;
    MetricHistory<BodyFatPercentage> fatPctH_;
    MetricHistory<Weight> weightH_;
    MetricHistory<Weight> weightH_;

public:
    PhysicalProfile();
    

    
};
