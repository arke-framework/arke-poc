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
 * PackageEncoder.hxx
 *
 *  Created on: 10 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_PACKAGE_PACKAGEENCODER_HXX_
#define SOURCES_PACKAGE_PACKAGEENCODER_HXX_

#include <memory>
#include <ostream>
#include "json/JSONEncoder.hxx"
#include "Package.hxx"

namespace arke {

    class PackageEncoder;
    using PackageEncoderPtr = std::shared_ptr<PackageEncoder>;

    /// \brief Define PackageEncoder
    class PackageEncoder : public JSONEncoder<Package> {

        public:

            /// \brief Encode an element to stream
            /// \param element Element to encode
            /// \param ostream Output stream
            void encode(PackagePtr element, std::ostream & ostream);

            /// \brief Encode package to stream
            /// \param package Pointer containing package
            /// \return Json object
            json encode(PackagePtr package);
    };

} /* namespace arke */

#endif /* SOURCES_PACKAGE_PACKAGEENCODER_HXX_ */