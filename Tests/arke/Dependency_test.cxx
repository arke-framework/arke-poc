/*
 * Dependency_test.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include "../catch/catch.hpp"
#include "arke/Dependency.hxx"
#include "arke/DependencyBuilder.hxx"

namespace arke {

    TEST_CASE( "Simple test dependency", "[dependency]" ) {

        DependencyPtr dependency = DependencyBuilder { }.name("package1").organizationName("org").build();

        REQUIRE(dependency->id() == "org/package1");
    }

} /* namespace arke */
