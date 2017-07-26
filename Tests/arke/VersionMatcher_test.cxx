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
 * VersionMatcher_test.cxx
 *
 *  Created on: 26 juil. 2017
 *      Author: dami
 */

#include "../catch/catch.hpp"
#include <arke/VersionMatcher.hxx>

namespace arke {

    TEST_CASE( "version matcher equals", "[version-matcher]" ) {

        VersionEquals equals{"4.2.1"};
        REQUIRE(equals.match("4.2.1"));
        REQUIRE_FALSE(equals.match("4.2.0"));
    }

    TEST_CASE( "version matcher higher", "[version-matcher]" ) {

        VersionHigher higer{"4.2.1"};

        REQUIRE(higer.match("4.2.1"));

        REQUIRE(higer.match("4.2.1.1"));
        REQUIRE(higer.match("4.2.2"));
        REQUIRE(higer.match("4.3.1"));
        REQUIRE(higer.match("5.2.1"));
        REQUIRE(higer.match("5.0.0"));
        REQUIRE(higer.match("5.0.0.0"));
        REQUIRE(higer.match("5.0"));
        REQUIRE(higer.match("5"));

        REQUIRE_FALSE(higer.match(""));
        REQUIRE_FALSE(higer.match("4.2.0"));
        REQUIRE_FALSE(higer.match("4.2"));
        REQUIRE_FALSE(higer.match("4"));
        REQUIRE_FALSE(higer.match("4.1.1"));
        REQUIRE_FALSE(higer.match("3.2.0"));
        REQUIRE_FALSE(higer.match("3.2.1"));
        REQUIRE_FALSE(higer.match("3.3.3.3"));

        VersionHigher customhiger{"4-2-1"};
        REQUIRE(customhiger.match("4-2-1"));
        REQUIRE(customhiger.match("4.2.1"));

        VersionHigher higer2{"4.10.1"};
        REQUIRE_FALSE(higer2.match("4.2.0"));
        REQUIRE(higer2.match("4.10.1-plop"));

        VersionHigher higer3{"b"};
        REQUIRE(higer3.match("b"));
        REQUIRE(higer3.match("c"));
        REQUIRE_FALSE(higer3.match("a"));
    }

    TEST_CASE( "version matcher patter", "[version-matcher]" ) {

        VersionPattern higer1{"4.2.*"};
        REQUIRE(higer1.match("4.2.1"));
        REQUIRE_FALSE(higer1.match("4.1.1"));

        VersionPattern higer2{"4.*.*"};
        REQUIRE(higer2.match("4.2.1"));
        REQUIRE(higer2.match("5"));
        REQUIRE(higer2.match("5.2.1"));
        REQUIRE_FALSE(higer2.match("3.2"));
        REQUIRE_FALSE(higer2.match("3"));
        REQUIRE_FALSE(higer2.match(""));
        REQUIRE_FALSE(higer2.match("4.2"));


        VersionPattern higer3{"b.*"};
        REQUIRE(higer3.match("b.b"));
        REQUIRE(higer3.match("c"));
        REQUIRE_FALSE(higer3.match("b"));
        REQUIRE_FALSE(higer3.match("a.a"));
    }

} /* namespace arke */
