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
 * FilesGroupBuilder.cxx
 *
 *  Created on: 6 août 2017
 *      Author: dami
 */

#include <files/FilesGroupBuilder.hxx>

namespace arke {

    // Constructor
    FilesGroupBuilder::FilesGroupBuilder() {
    }

    // Destructor
    FilesGroupBuilder::~FilesGroupBuilder() {
    }

    // Set files group name
    FilesGroupBuilder & FilesGroupBuilder::name(const std::string & name) {
            this->name_ = name;
            return *this;
    }

    // Append file to group
    FilesGroupBuilder & FilesGroupBuilder::append(HashFilePtr hashFile) {
        if (hashFile) {
            this->files_.insert(hashFile);
        }
        return *this;
    }

    // Create Files group builder from directory
    FilesGroupBuilder FilesGroupBuilder::from(const filesystem::path & path) {

        // Test directory
        if (!filesystem::exists(path) || !filesystem::is_directory(path)) {
            throw std::runtime_error{"Path is not a directory"};
        }

        // Create builder
        FilesGroupBuilder filesGroupBuilder{};

        // Read all files
        for(auto& p: filesystem::directory_iterator(path)) {
            filesGroupBuilder.append(HashFile::from(p));
        }

        return filesGroupBuilder;
    }

    // Build files group
    FilesGroupPtr FilesGroupBuilder::build() {
        return FilesGroupPtr{new FilesGroup{name_, files_}};
    }

} /* namespace arke */
