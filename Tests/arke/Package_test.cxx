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
 * Dependency_test.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include "../catch/catch.hpp"
#include <dependency/Dependency.hxx>
#include <dependency/DependencyBuilder.hxx>
#include <package/Package.hxx>
#include <package/PackageBuilder.hxx>

namespace arke {

    TEST_CASE( "Simple test package", "[package]" ) {

        PackageBuilder & packageBuilder = *new PackageBuilder { };

        PackagePtr package = packageBuilder.dependency(DependencyBuilder { }.organizationName("org").name("package").build()).build();

        REQUIRE(package);

        REQUIRE("org" == package->dependency()->organization());
        REQUIRE("package" == package->dependency()->name());
        REQUIRE("org/package" == package->dependency()->id());

        REQUIRE(0 == package->fileGroups().size());

        delete &packageBuilder;
    }

    TEST_CASE( "Package with files", "[package]" ) {

         PackagePtr package = PackageBuilder {}
             .dependency(DependencyBuilder { }.organizationName("org").name("package").build())
             //std::set<FilesGroupPtr>{

             //}
             .build();

         REQUIRE(package);

         REQUIRE("org" == package->dependency()->organization());
         REQUIRE("package" == package->dependency()->name());
         REQUIRE("org/package" == package->dependency()->id());

         REQUIRE(0 == package->fileGroups().size());
    }

    TEST_CASE( "Test error package", "[package]" ) {
        REQUIRE_THROWS(PackageBuilder {}.build());
    }

} /* namespace arke */
