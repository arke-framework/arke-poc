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
 * DependencyDefinition.cxx
 *
 *  Created on: 26 juil. 2017
 *      Author: dami
 */

#include <dependency/DependencyDefinition.hxx>

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
