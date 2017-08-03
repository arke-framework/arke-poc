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
 * FilesGroup.cxx
 *
 *  Created on: 3 août 2017
 *      Author: dami
 */

#include "FilesGroup.hxx"

namespace arke {

    // Constructor
    FilesGroup::FilesGroup(const std::string & name, const std::set<HashFilePtr> & files) : name_(name), files_(files) {

    }

    // Destructor
    FilesGroup::~FilesGroup() {
    }

    // group name
    const std::string & FilesGroup::name() const {
        return name_;
    }

    // All files in group
    const std::set<HashFilePtr> & FilesGroup::files() const {
        return files_;
    }

} /* namespace arke */
