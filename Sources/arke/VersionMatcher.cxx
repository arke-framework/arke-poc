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
 * VersionMatcher.cxx
 *
 *  Created on: 26 juil. 2017
 *      Author: dami
 */

#include "VersionMatcher.hxx"
#include <boost/algorithm/string.hpp>

#include <algorithm>
#include <sstream>
#include <set>

namespace arke {

    // Destructor
    VersionMatcher::~VersionMatcher() {

    }

    // Decode a version to a list of elements
    std::vector<std::string> VersionMatcher::decode(const std::string & version) {

        std::vector<std::string> versions;

        static std::set SEPARATORS = {'.', ',', '-', '_', '/', '\\'};

        std::stringstream ss;

        // Browse all
        for (auto c : version) {

            // Test if char is a separator
            if (SEPARATORS.find(c) == SEPARATORS.end()) {
                ss << c;
            } else {
                // Add
                versions.push_back(ss.str());

                // Reset stream
                ss = std::stringstream{};
            }
        }

        auto value = ss.str();
        if (!value.empty()) {
            versions.push_back(value);
        }

        return versions;
    }

    VersionEquals::VersionEquals(const std::string & version) : version_(version) {

    }

    // Match version
    bool VersionEquals::match(const std::string & version) const {
        return version_ == version;
    }

    // Type of matcher
    MatcherType VersionEquals::type() const  {
        return MatcherType::EQUALS;
    }

    // Constructor with separator
    VersionHigher::VersionHigher(const std::string & version) : versions_(VersionHigher::decode(version)) {

    }

    // Match version
    bool VersionHigher::match(const std::string & version) const {

        // Decode current version
        std::vector<std::string> versions = VersionHigher::decode(version);

        // Find it
        auto reference_versions = versions_.begin();
        auto current_versions = versions.begin();

        // Go throw its
        while (reference_versions != versions_.end() && current_versions != versions.end()) {

            try {
                // Get int
                int reference = stoi(*reference_versions);
                int current =  stoi(*current_versions);

                if (reference < current) {
                    return true;
                } else if (reference > current) {
                    return false;
                }
            } catch(...) {
                if (*reference_versions < *current_versions) {
                   return true;
               } else if (*reference_versions > *current_versions) {
                   return false;
               }
            }

            // Next
            ++reference_versions;
            ++current_versions;
        }

        return reference_versions == versions_.end();
    }

    // Type of matcher
    MatcherType VersionHigher::type() const  {
        return MatcherType::HIGHER;
    }

    // Constructor with separator
    VersionPattern::VersionPattern(const std::string & version) : versions_(VersionHigher::decode(version)) {

    }

    // Match version
    bool VersionPattern::match(const std::string & version) const {

        // Decode current version
        std::vector<std::string> versions = VersionHigher::decode(version);

        // Find it
        auto reference_versions = versions_.begin();
        auto current_versions = versions.begin();

        // Go throw its
        while (reference_versions != versions_.end() && current_versions != versions.end()) {

            // Test *
            if (*reference_versions != "*") {

                try {
                    // Get int
                    int reference = stoi(*reference_versions);
                    int current =  stoi(*current_versions);

                    if (reference < current) {
                        return true;
                    } else if (reference > current) {
                        return false;
                    }
                } catch(...) {
                    if (*reference_versions < *current_versions) {
                       return true;
                   } else if (*reference_versions > *current_versions) {
                       return false;
                   }
                }
            }

            // Next
            ++reference_versions;
            ++current_versions;
        }

        return reference_versions == versions_.end();
    }

    // Type of matcher
    MatcherType VersionPattern::type() const  {
        return MatcherType::PATTERN;
    }

} /* namespace arke */
