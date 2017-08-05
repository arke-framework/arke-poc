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

#include <files/FilesGroup.hxx>
#include <files/FilesGroupBuilder.hxx>
#include "../catch/catch.hpp"
#include <fstream>
#include <map>

namespace arke {

    TEST_CASE( "Files group", "[files]" ) {

        // Create files group directory test
        filesystem::path directory{"filesGroups"};
        filesystem::create_directories(directory);

        // Create file 1
        filesystem::path file1 = filesystem::path{directory}.append("file1");
        std::ofstream{file1.c_str()};
        auto hashFile1 = HashFile::from(file1);

        // Create file 2
        filesystem::path file2 = filesystem::path{directory}.append("file2");
        std::ofstream{file2.c_str()};
        auto hashFile2 = HashFile::from(file2);

        // Create file 3
        filesystem::path file3 = filesystem::path{directory}.append("file3");
        std::ofstream{file3.c_str()};
        auto hashFile3 = HashFile::from(file3);

        FilesGroup * filesGroup = new FilesGroup{"lib", std::set<HashFilePtr>{
            hashFile1, hashFile2, hashFile3
        }};

        REQUIRE("lib" == filesGroup->name());
        REQUIRE(3 == filesGroup->files().size());

        std::map<std::string, HashFilePtr> hashFiles{
            {hashFile1->path().string(), hashFile1},
            {hashFile2->path().string(), hashFile2},
            {hashFile3->path().string(), hashFile3}
        };

        auto it = filesGroup->files().begin();

        auto filePtr1 = hashFiles.at((*it)->path().string());
        REQUIRE(filePtr1->hash() == (*it)->hash());
        REQUIRE(filePtr1->path() == (*it)->path());
        hashFiles.erase(filePtr1->path().string());

        ++it;
        auto filePtr2 = hashFiles.at((*it)->path().string());
        REQUIRE(filePtr2->hash() == (*it)->hash());
        REQUIRE(filePtr2->path() == (*it)->path());
        hashFiles.erase(filePtr2->path().string());

        ++it;
        auto filePtr3 = hashFiles.at((*it)->path().string());
        REQUIRE(filePtr3->hash() == (*it)->hash());
        REQUIRE(filePtr3->path() == (*it)->path());
        hashFiles.erase(filePtr3->path().string());

        REQUIRE(hashFiles.empty());

        auto filesGroup1 = FilesGroupBuilder::from(directory).name("lib").build();
        REQUIRE(3 == filesGroup1->files().size());

        delete filesGroup;

        REQUIRE_THROWS(FilesGroupBuilder::from("invalid"));
    }

    TEST_CASE( "Files group builder", "[files]" ) {
        FilesGroupBuilder * builder = new FilesGroupBuilder{};
        delete builder;
    }
} /* namespace arke */
