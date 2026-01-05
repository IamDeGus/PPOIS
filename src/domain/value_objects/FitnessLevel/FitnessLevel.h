#pragma once

#include "../../Exceptions/FitnessLevelException.h"

enum class FitnessStatus{
    NOVICE,
    APPRENTICE,
    ADVENTURER,
    CHAMPION,
    HERO,
    LEGEND,
    DIAMOND_LEGEND
};

class FitnessLevel
{
private:
    FitnessStatus status_;
    int totalScore_;

    int workoutPoints_;
    int consistencyPoints_;
    int achievementPoints_;
    int skillPoints_;

    void updateScore();
    void updateStatus();
public:
    FitnessLevel(int workoutPoints, int consistencyPoints,
                 int achievementPoints, int skillPoints);


    FitnessStatus getStatus() const;
    int getTotalScore() const;

    int getWorkoutPoints() const;
    int getConsistencyPoints() const;
    int getAchievementPoints() const;
    int getSkillPoints() const;

protected:
    void updatePoints(int workoutDelta,int consistencyDelta,
                      int achievementDelta, int skillDelta);
};
