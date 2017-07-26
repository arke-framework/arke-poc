/*
 * DependencyBuilder.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include "DependencyBuilder.hxx"

#include <exception>

namespace arke {

    DependencyBuilder::DependencyBuilder() {

    }

    DependencyBuilder::~DependencyBuilder() {
    }

    DependencyBuilder& DependencyBuilder::name(const std::string& name) {
        this->name_ = name;
        return *this;
    }

    DependencyBuilder& DependencyBuilder::organizationName(const std::string& name) {
        this->organizationName_ = name;
        return *this;
    }

    // Build dependency
    DependencyPtr DependencyBuilder::build() {
        if (name_.empty()) {
            throw new std::invalid_argument{"Unable to create dependency without name"};
        }
        if (name_.empty()) {
            throw new std::invalid_argument{"Unable to create dependency without organization name"};
        }
        return DependencyPtr{new Dependency{name_, organizationName_}};
    }

} /* namespace arke */
