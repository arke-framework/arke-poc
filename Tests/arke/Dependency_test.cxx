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

        DependencyBuilder & dependencyBuilder = *new DependencyBuilder { };
        REQUIRE_THROWS(dependencyBuilder.build());

        dependencyBuilder.name("package1");
        REQUIRE_THROWS(dependencyBuilder.build());

        dependencyBuilder.organizationName("org");

        DependencyPtr dependency = dependencyBuilder.build();

        REQUIRE(dependency->id() == "org/package1");
        REQUIRE(dependency->organization() == "org");
        REQUIRE(dependency->name() == "package1");

        delete &dependencyBuilder;
    }

} /* namespace arke */
