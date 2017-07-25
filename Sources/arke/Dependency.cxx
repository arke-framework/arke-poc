/*
 * Dependency.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include "Dependency.hxx"

namespace arke {

    Dependency::Dependency(const std::string & name, const std::string & organization) : name_(name), organization_(organization) {

    }

    Dependency::~Dependency() {
    }

    // Dependency id
    const std::string Dependency::id() const {
        return (organization_ + '/' + name_);
    }

} /* namespace arke */
