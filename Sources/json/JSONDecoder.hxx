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
 * JSONDecoder.hxx
 *
 *  Created on: 10 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_JSON_JSONDECODER_HXX_
#define SOURCES_JSON_JSONDECODER_HXX_

#include <memory>
#include <istream>
#include "json.hpp"

namespace arke {

    using json = nlohmann::json;

    /// \brief Define JSONDecoder
    template<class Element>
    class JSONDecoder {

        public:

            // Virtual destructor
            virtual ~JSONDecoder() {}

        public:
    };

} /* namespace arke */

#endif /* SOURCES_JSON_JSONDECODER_HXX_ */