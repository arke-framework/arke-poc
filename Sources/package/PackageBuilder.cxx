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
 * PackageBuilder.cxx
 *
 *  Created on: 5 août 2017
 *      Author: dami
 */

#include <package/PackageBuilder.hxx>

namespace arke {

    // Constructor
    PackageBuilder::PackageBuilder() {

    }

    // Destructor
    PackageBuilder::~PackageBuilder() {
    }


    // Set dependency
    PackageBuilder & PackageBuilder::dependency(DependencyPtr dependency) {
        this->dependency_ = dependency;
        return *this;
    }

    // Build package
    PackagePtr PackageBuilder::build() {

        PackagePtr package;

        if (!dependency_) {
            throw std::runtime_error{"No dependency set"};
        }

        return std::shared_ptr<Package>{
            new Package{dependency_, fileGroups_}
        };
    }

} /* namespace arke */
