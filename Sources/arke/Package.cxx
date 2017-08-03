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
 * Package.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include "Package.hxx"

namespace arke {

    // Constructor
    Package::Package(std::shared_ptr<Dependency> dependency, std::set<FilesGroupPtr> fileGroups) : dependency_(dependency), fileGroups_(fileGroups) {

    }

    // Destructor
    Package::~Package() {

    }

    // Dependency
    std::shared_ptr<Dependency> Package::dependency() const {
        return dependency_;
    }

    // Files groups
    std::set<FilesGroupPtr> Package::fileGroups() const {
        return fileGroups_;
    }

} /* namespace arke */
