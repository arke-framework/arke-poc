/*
 * DependencyDefinition.cxx
 *
 *  Created on: 26 juil. 2017
 *      Author: dami
 */

#include "DependencyDefinition.hxx"

namespace arke {

    // Constructor
    DependencyDefinition::DependencyDefinition(const std::string & id, const std::string & version) :
            id_(id), version_(version) {

    }

    // Destructor
    DependencyDefinition::~DependencyDefinition() {
    }

    // Dependency id
    const std::string DependencyDefinition::id() const {
        return id_;
    }

    // Version matcher
    const std::string DependencyDefinition::version() const {
        return version_;
    }

} /* namespace arke */
