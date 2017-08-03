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
 * FilesGroup_test.cxx
 *
 *  Created on: 3 août 2017
 *      Author: dami
 */

#include <arke/FilesGroup.hxx>
#include "../catch/catch.hpp"

namespace arke {

    TEST_CASE( "Files group", "[files]" ) {

        // Create files group directory test
        filesystem::path directory{"filesGroups"};
        filesystem::create_directories(directory);

        // Create file 1
        filesystem::path file1 = directory.append("file1");

        HashFilePtr hashFile1 = HashFile::from(file1);

        FilesGroupPtr filesGroup = std::make_shared<FilesGroup>("lib", std::set<HashFilePtr>{hashFile1});

        REQUIRE("lib" == filesGroup->name());
        REQUIRE(0 == filesGroup->files().size());
    }
} /* namespace arke */
