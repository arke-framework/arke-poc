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
 * HashFile_test.cxx
 *
 *  Created on: 1 août 2017
 *      Author: dami
 */

#include "../catch/catch.hpp"
#include <arke/HashFile.hxx>

#include <iostream>

namespace arke {

    TEST_CASE( "Hash file", "[crypto]" ) {

        boost::filesystem::path path{"file1.txt"};

        if(boost::filesystem::exists(path)) {
            boost::filesystem::remove(path);
        }

        boost::filesystem::ofstream sha1Stream { path };
        sha1Stream << "test";
        sha1Stream.close();

        auto hashFile = HashFile::from(path);

        REQUIRE("9F86D081884C7D659A2FEAA0C55AD015A3BF4F1B2B0B822CD15D6C15B0F00A08" == hashFile->hash());
        REQUIRE("file1.txt" == hashFile->path());
    }

} /* namespace arke */
