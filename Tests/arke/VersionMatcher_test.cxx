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
#include <version/VersionMatcher.hxx>

namespace arke {

    TEST_CASE( "version matcher equals", "[version-matcher]" ) {

        VersionEquals * equals = new VersionEquals { "4.2.1" };
        REQUIRE(equals->match("4.2.1"));
        REQUIRE_FALSE(equals->match("4.2.0"));

        REQUIRE(equals->type() == MatcherType::EQUALS);

        delete equals;
    }

    TEST_CASE( "version matcher higher", "[version-matcher]" ) {

        VersionHigher * higher = new VersionHigher("4.2.1");

        REQUIRE(higher->type() == MatcherType::HIGHER);

        REQUIRE(higher->match("4.2.1"));

        REQUIRE(higher->match("4.2.1.1"));
        REQUIRE(higher->match("4.2.2"));
        REQUIRE(higher->match("4.3.1"));
        REQUIRE(higher->match("5.2.1"));
        REQUIRE(higher->match("5.0.0"));
        REQUIRE(higher->match("5.0.0.0"));
        REQUIRE(higher->match("5.0"));
        REQUIRE(higher->match("5"));

        REQUIRE_FALSE(higher->match(""));
        REQUIRE_FALSE(higher->match("4.2.0"));
        REQUIRE_FALSE(higher->match("4.2"));
        REQUIRE_FALSE(higher->match("4"));
        REQUIRE_FALSE(higher->match("4.1.1"));
        REQUIRE_FALSE(higher->match("3.2.0"));
        REQUIRE_FALSE(higher->match("3.2.1"));
        REQUIRE_FALSE(higher->match("3.3.3.3"));

        delete higher;

        VersionHigher customhiger { "4-2-1" };
        REQUIRE(customhiger.match("4-2-1"));
        REQUIRE(customhiger.match("4.2.1"));

        VersionHigher higer2 { "4.10.1" };
        REQUIRE_FALSE(higer2.match("4.2.0"));
        REQUIRE(higer2.match("4.10.1-plop"));

        VersionHigher higer3 { "b" };
        REQUIRE(higer3.match("b"));
        REQUIRE(higer3.match("c"));
        REQUIRE_FALSE(higer3.match("a"));
    }

    TEST_CASE( "version matcher pattern", "[version-matcher]" ) {

        VersionPattern * pattern1 = new VersionPattern { "4.2.*" };
        REQUIRE(pattern1->match("4.2.1"));
        REQUIRE_FALSE(pattern1->match("4.1.1"));

        REQUIRE(pattern1->type() == MatcherType::PATTERN);

        delete pattern1;

        VersionPattern pattern2 { "4.*.*" };
        REQUIRE(pattern2.match("4.2.1"));
        REQUIRE(pattern2.match("5"));
        REQUIRE(pattern2.match("5.2.1"));
        REQUIRE_FALSE(pattern2.match("3.2"));
        REQUIRE_FALSE(pattern2.match("3"));
        REQUIRE_FALSE(pattern2.match(""));
        REQUIRE_FALSE(pattern2.match("4.2"));

        VersionPattern pattern3 { "b.*" };
        REQUIRE(pattern3.match("b.b"));
        REQUIRE(pattern3.match("c"));
        REQUIRE_FALSE(pattern3.match("b"));
        REQUIRE_FALSE(pattern3.match("a.a"));
    }

} /* namespace arke */
