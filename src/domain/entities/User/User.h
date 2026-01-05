#pragma once

#include <string>
#include <set>
#include <memory>

#include "../../value_objects/Date/Date.h"
#include "UserRole.h"
#include "AccountStatus.h"
#include "UserValidator.h"

class User
{
private:
    std::shared_ptr<UserValidator> validator_;

    const int userID_;
    std::string email_;
    std::string username_;
    std::string passwordHash_; 

    bool isActive_;

    UserRole role_;
    AccountStatus status_;
    const Date createdAt_;

    std::set<int> deviceIds_;

public:
    User(int userID, std::string email, std::string username, 
         std::string passwordHash, bool isActive, UserRole role,
         AccountStatus status,  Date createdAt, std::set<int> deviceIds);

    bool changePassword(const std::string& oldPass, const std::string& newPass);
    bool updateEmail(const std::string& newEmail);
    bool connectDevice(int deviceId);
    bool disconnectDevice(int deviceId);

    int getUserID() const;
    std::string getEmail() const;
    std::string getUsername() const;
    bool getIsActive() const;
    UserRole getRole() const;
    AccountStatus getStatus() const;
    Date getCreatedAt() const;
    std::set<int> getDeviceIds() const;

protected:
    std::string getPasswordHash_() const;   

    void updateRole();
    void updateStatus();

    void updateIsActive();
};
