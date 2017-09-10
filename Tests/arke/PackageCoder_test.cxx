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
 * PackageCoder_test.cxx
 *
 *  Created on: 10 sept. 2017
 *      Author: dami
 */

#include "../catch/catch.hpp"
#include <package/PackageEncoder.hxx>
#include <package/PackageDecoder.hxx>
#include <dependency/DependencyBuilder.hxx>
#include <package/PackageBuilder.hxx>
#include <sstream>

namespace arke {

    TEST_CASE( "Package encode/decode", "[package], [json]" ) {

        // Create dependecy
        auto dependency = DependencyBuilder{}
            .build();

        // Create package
        auto package = PackageBuilder{}
            .dependency(dependency)
            .build();

        // Create JSon stream
        std::stringstream ss;

        // Encode package
        PackageEncoder{}.encode(package, ss);

        // Decode package
        auto readedPackage = PackageDecoder{}.decode(ss);

        // Test same
        //REQUIRE(readedPackage);
    }
} /* namespace arke */
