//
// Created by mawolny on 14.12.2021.
//

#ifndef UNTITLED_PACKAGE_HPP
#define UNTITLED_PACKAGE_HPP
 
class Package {

public:
    Package() {};

    Package(ElementID);
    Package(Package&&);
    Package& operator = (Package&&);
    const ElementID get_id();

private:
    
};

#endif //UNTITLED_PACKAGE_HPP