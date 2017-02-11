#include "includes/user_service.h"

UserService::UserService(std::string name) : service_name_(name) {
    std::cout << "UserService Constructor" << std::endl;
}

// UserService::UserService(const UserService &rhs) : UserService_name(rhs) {
//
// }

UserService::~UserService() {
    std::cout << "UserService Destructor" << std::endl;
}