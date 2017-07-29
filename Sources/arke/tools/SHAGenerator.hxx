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
 * SHAGenerator.hxx
 *
 *  Created on: 29 juil. 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_TOOLS_SHAGENERATOR_HXX_
#define SOURCES_ARKE_TOOLS_SHAGENERATOR_HXX_

#include <memory>
#include <boost/filesystem.hpp>
using namespace boost;
using namespace filesystem;

namespace arke {

    class SHAGenerator;
    using SHAGeneratorPtr = std::shared_ptr<SHAGenerator>;

    /// \brief Hash function
    enum class HashFunction {

        /// \brief SHA 1
        SHA1,

        /// \brief SHA 256
        SHA256,

        /// \brief SHA 512
        SHA512,
    };

    /// \brief Convert enum to string
    /// \param hashFunction Hash function
    /// \return String containing hash function denomination
    std::string str(HashFunction hashFunction);

    // Override <<
    std::ostream & operator<<(std::ostream & ostream, const HashFunction & hashFunction);

    /// \brief Define SHAGenerator
    class SHAGenerator {

        private:

            /// \brief Hash function
            HashFunction hash_;

        public:

            /// \brief Constructor
            /// \param hashFunction Hash function
            SHAGenerator(HashFunction hashFunction);

            /// \brief Generate SHA of file
            /// \return String containing SHA
            std::string hashFile(const path & path) const;

            /// \brief Generate SHA of string
            /// \param str String to hash
            /// \return String containing SHA
            std::string hashString(const std::string & str) const;
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_TOOLS_SHAGENERATOR_HXX_ */
