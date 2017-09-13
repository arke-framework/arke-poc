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
 * DependencyEncoder.cxx
 *
 *  Created on: 10 sept. 2017
 *      Author: dami
 */

#include "DependencyEncoder.hxx"

namespace arke {

    json DependencyEncoder::encode(DependencyPtr dependency) {

        // Init json object
        json object;

        if (dependency) {

            // Set organization
            object["organization"] = dependency->organization();

            // Set name
            object["name"] = dependency->name();
        }

        return object;
    }

} /* namespace arke */
