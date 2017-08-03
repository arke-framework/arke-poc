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
 * HashFile.cxx
 *
 *  Created on: 1 août 2017
 *      Author: dami
 */

#include "HashFile.hxx"
#include "tools/SHAGenerator.hxx"

namespace arke {

    // Constructor
    HashFile::HashFile(const std::string & hash, const filesystem::path & path) : hash_(hash), path_(path) {
    }

    // Destructor
    HashFile::~HashFile() {
    }

    // Hash
    const std::string & HashFile::hash() const {
        return hash_;
    }

    // Path
    const filesystem::path HashFile::path() const {
        return path_;
    }

    // Create hash file from path
    std::shared_ptr<HashFile> HashFile::from(const filesystem::path & path) {
        return std::shared_ptr<HashFile> { new HashFile { SHAGenerator { HashFunction::SHA256 }.hashFile(path), path } };
    }

} /* namespace arke */
