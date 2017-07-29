/*
 * Dependency_test.cxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#include "../../catch/catch.hpp"
#include "arke/tools/SHAGenerator.hxx"

namespace arke {

    TEST_CASE( "Simple test SHA generator", "[crypto]" ) {
        REQUIRE("A94A8FE5CCB19BA61C4C0873D391E987982FBBD3" == SHAGenerator{HashFunction::SHA1}.hashString("test"));
        REQUIRE("9F86D081884C7D659A2FEAA0C55AD015A3BF4F1B2B0B822CD15D6C15B0F00A08" == SHAGenerator{HashFunction::SHA256}.hashString("test"));
        REQUIRE("EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF" == SHAGenerator{HashFunction::SHA512}.hashString("test"));
    }

} /* namespace arke */
