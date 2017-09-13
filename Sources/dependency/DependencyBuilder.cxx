/*
 * Copyright 2017 dami
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * DependencyBuilder.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include <dependency/DependencyBuilder.hxx>

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

    DependencyBuilder& DependencyBuilder::organization(const std::string& organization) {
        this->organizationName_ = organization;
        return *this;
    }

    // Build dependency
    DependencyPtr DependencyBuilder::build() {
        if (name_.empty()) {
            throw new std::invalid_argument { "Unable to create dependency without name" };
        }
        if (organizationName_.empty()) {
            throw new std::invalid_argument { "Unable to create dependency without organization name" };
        }
        return DependencyPtr { new Dependency { name_, organizationName_ } };
    }

} /* namespace arke */
