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
 * JSONEncoder.hxx
 *
 *  Created on: 10 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_JSON_JSONENCODER_HXX_
#define SOURCES_JSON_JSONENCODER_HXX_

#include <memory>
#include <ostream>
#include "json.hpp"

namespace arke {

    using json = nlohmann::json;

    /// \brief Define JSONEncoder
    template<class Element>
    class JSONEncoder {

        public:

            /// \brief Destructor
            virtual ~JSONEncoder() {}

            /*
            /// \brief Encode an element to stream
            /// \param element Element to encode
            /// \param ostream Output stream
            virtual void encode(std::shared_ptr<Element> element, std::ostream & ostream) {

                //if (element) {
                //    ostream << *element;
                //}
            }

            /// \brief Encode an element to stream
            /// \param element Element to encode
            /// \return JSON object
            virtual json encode(std::shared_ptr<Element> element) = 0;
            */
    };

} /* namespace arke */

#endif /* SOURCES_JSON_JSONENCODER_HXX_ */
