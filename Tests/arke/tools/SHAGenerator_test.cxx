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

#include "../../catch/catch.hpp"
#include "arke/tools/SHAGenerator.hxx"
#include <boost/filesystem/operations.hpp>

namespace arke {

    TEST_CASE( "Simple string SHA generator", "[crypto]" ) {
        REQUIRE("A94A8FE5CCB19BA61C4C0873D391E987982FBBD3" == SHAGenerator{HashFunction::SHA1}.hashString("test"));
        REQUIRE("9F86D081884C7D659A2FEAA0C55AD015A3BF4F1B2B0B822CD15D6C15B0F00A08" == SHAGenerator{HashFunction::SHA256}.hashString("test"));
        REQUIRE("EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF" == SHAGenerator{HashFunction::SHA512}.hashString("test"));
    }

    boost::filesystem::path create_file(const std::string & file, const std::string & content) {

        boost::filesystem::path path{file};

        if(boost::filesystem::exists(path)) {
            boost::filesystem::remove(path);
        }

        boost::filesystem::ofstream sha1Stream { path };
        sha1Stream << content;
        sha1Stream.close();

        return path;
    }

    TEST_CASE( "Simple file SHA generator", "[crypto]" ) {
        REQUIRE("A94A8FE5CCB19BA61C4C0873D391E987982FBBD3" == SHAGenerator{HashFunction::SHA1}
                .hashFile(create_file("path.sha1", "test")));
        REQUIRE("9F86D081884C7D659A2FEAA0C55AD015A3BF4F1B2B0B822CD15D6C15B0F00A08" == SHAGenerator{HashFunction::SHA256}
                .hashFile(create_file("path.sha1", "test")));
        REQUIRE("EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF" == SHAGenerator{HashFunction::SHA512}
                .hashFile(create_file("path.sha1", "test")));
    }

    TEST_CASE( "Simple string SHA encoder", "[crypto]" ) {



        REQUIRE_THROWS(str(static_cast<HashFunction>(22)));

        std::stringstream ss;
        ss << HashFunction::SHA1;
        REQUIRE(ss.str() == "SHA-1");
    }

} /* namespace arke */
