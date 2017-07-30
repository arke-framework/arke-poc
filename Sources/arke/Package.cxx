/*
 * Package.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include "Package.hxx"

namespace arke {

    // Constructor
    Package::Package(std::shared_ptr<Dependency> dependency) : dependency_(dependency) {

    }

    // Destructor
    Package::~Package() {

    }

} /* namespace arke */
