/*
 * Dependency_test.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include "../catch/catch.hpp"
#include "arke/Dependency.hxx"
#include "arke/DependencyBuilder.hxx"
#include "arke/Package.hxx"

namespace arke {

    TEST_CASE( "Simple test package", "[package]" ) {

        Package & package = *new Package { DependencyBuilder { }.organizationName("org").name("package").build() };

        REQUIRE(&package);

        delete &package;
    }

} /* namespace arke */
