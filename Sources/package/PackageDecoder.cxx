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
 * PackageDecoder.cxx
 *
 *  Created on: 10 sept. 2017
 *      Author: dami
 */

#include "PackageDecoder.hxx"
#include "PackageBuilder.hxx"

namespace arke {

    // Decode an element from json stream
    PackagePtr PackageDecoder::decode(std::istream & istream) {

        // Read JSON
        json jsonObject;

        // Read from istream
        std::cin >> jsonObject;

        return decode(jsonObject);
    }

    // Decode an element from json object
    PackagePtr PackageDecoder::decode(json & json) {

        // Test valid object
        if(!json.is_object()) {
            // FIXME Logs
            return PackagePtr{};
        }

        // Create object
        PackageBuilder packageBuilder{};

        return packageBuilder.build();
    }

} /* namespace arke */
