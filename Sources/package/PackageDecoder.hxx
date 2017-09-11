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
 * PackageDecoder.hxx
 *
 *  Created on: 10 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_PACKAGE_PACKAGEDECODER_HXX_
#define SOURCES_PACKAGE_PACKAGEDECODER_HXX_

#include <memory>
#include <istream>
#include "Package.hxx"
#include "json/JSONDecoder.hxx"

namespace arke {

    class PackageDecoder;
    using PackageDecoderPtr = std::shared_ptr<PackageDecoder>;

    /// \brief Define PackageDecoder
    class PackageDecoder {

        public:

            /// \brief Decode an element from json stream
            /// \param istream Input stream containing object
            PackagePtr decode(std::istream & istream);

            /// \brief Decode an element from json object
            /// \param json JSON object
            PackagePtr decode(json & json);

    };

} /* namespace arke */

#endif /* SOURCES_PACKAGE_PACKAGEDECODER_HXX_ */
