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
#include <files/HashFile.hxx>

#include "PackageTools.hxx"

namespace arke {

    TEST_CASE( "Hash file", "[crypto]" ) {

        auto path = test::FileDirectoryGenerator::createFile("file1.txt", true);
        auto hashFile = HashFile::from(path);

        REQUIRE("55AE75D991C770D8F3EF07CBFDE124FFCE9C420DA5DB6203AFAB700B27E10CF9" == hashFile->hash());
        REQUIRE("file1.txt" == hashFile->path());
    }

} /* namespace arke */
