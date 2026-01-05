#include "FitnessLevel.h"

void FitnessLevel::updateScore()
{
    double result{1};
    result = (
        (1 + double(consistencyPoints_) / 1000) *
        (workoutPoints_ + 10 * skillPoints_) + 
        achievementPoints_
    );
    
    totalScore_ = int(result);
}

void FitnessLevel::updateStatus()
{
    if (totalScore_ < 500)
        status_ = FitnessStatus::NOVICE; return;
    if (totalScore_ < 1500)
        status_ = FitnessStatus::APPRENTICE; return;
    if (totalScore_ < 3000)
        status_ = FitnessStatus::ADVENTURER; return;
    if (totalScore_ < 5000)
        status_ = FitnessStatus::CHAMPION; return;
    if (totalScore_ < 7000)
        status_ = FitnessStatus::HERO; return;
    if (totalScore_ < 10000)
        status_ = FitnessStatus::LEGEND; return;

    status_ = FitnessStatus::DIAMOND_LEGEND; return;
}

FitnessLevel::FitnessLevel(int workoutPoints, int consistencyPoints,
                           int achievementPoints, int skillPoints)
    : workoutPoints_(workoutPoints), consistencyPoints_(consistencyPoints),
      achievementPoints_(achievementPoints), skillPoints_(skillPoints)
{
    if (
        workoutPoints_ < 0 ||
        consistencyPoints_ < 0 ||
        achievementPoints_ < 0 ||
        skillPoints_ < 0)
        throw FitnessLevelException("Create failed: incorrect value");
    
    updateScore();
    updateStatus();
}


FitnessStatus FitnessLevel::getStatus() const
{
    return status_;
}

int FitnessLevel::getTotalScore() const
{
    return totalScore_;
}


int FitnessLevel::getWorkoutPoints() const
{
    return workoutPoints_;
}

int FitnessLevel::getConsistencyPoints() const
{
    return consistencyPoints_;
}

int FitnessLevel::getAchievementPoints() const
{
    return achievementPoints_;
}

int FitnessLevel::getSkillPoints() const
{
    return skillPoints_;
}


void FitnessLevel::updatePoints(int workoutDelta, int consistencyDelta, 
                                int achievementDelta, int skillDelta)
{
    workoutPoints_ += workoutDelta;
    consistencyPoints_ += consistencyDelta;
    achievementPoints_ += achievementDelta;
    skillPoints_ += skillDelta;

    updateScore();
    updateStatus();
}
