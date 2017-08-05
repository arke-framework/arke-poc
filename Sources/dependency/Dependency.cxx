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
 * Dependency.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include <dependency/Dependency.hxx>

namespace arke {

    Dependency::Dependency(const std::string & name, const std::string & organization) :
            name_(name), organization_(organization) {

    }

    Dependency::~Dependency() {
    }

    // Dependency id
    const std::string Dependency::id() const {
        return (organization_ + '/' + name_);
    }

    // Package name
    const std::string & Dependency::name() const {
        return name_;
    }

    // Package organization
    const std::string & Dependency::organization() const {
        return organization_;
    }

} /* namespace arke */
