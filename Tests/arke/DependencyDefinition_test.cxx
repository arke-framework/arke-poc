/*
 * DependencyDefinition_test.cxx
 *
 *  Created on: 26 juil. 2017
 *      Author: dami
 */

#include "../catch/catch.hpp"
#include <arke/DependencyDefinition.hxx>

namespace arke {

    TEST_CASE( "Simple test dependency definition", "[dependency-definition]" ) {

        DependencyDefinition & dependencyDefinition = *new DependencyDefinition { "org/dependency", "1.2.3" };

        REQUIRE("org/dependency" == dependencyDefinition.id());
        REQUIRE("1.2.3" == dependencyDefinition.version());

        delete &dependencyDefinition;
    }

} /* namespace arke */
