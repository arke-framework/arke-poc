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
 * HashFile.hxx
 *
 *  Created on: 1 août 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_HASHFILE_HXX_
#define SOURCES_ARKE_HASHFILE_HXX_

#include <memory>
#include <string>
#include <boost/filesystem.hpp>

namespace arke {

    namespace filesystem = boost::filesystem;

    class HashFile;
    using HashFilePtr = std::shared_ptr<HashFile>;

    /// \brief Define HashFile
    class HashFile {

        private:

            /// \brief Hash
            std::string hash_;

            /// \brief Path
            filesystem::path path_;

            /// \brief Constructor
            /// \param hash File hash
            /// \param path File path
            explicit HashFile(const std::string & hash,
                              const filesystem::path & path);

        public:

            /// \brief Destructor
            virtual ~HashFile();

        public:

            /// \return Hash
            const std::string & hash() const;

            /// \return Path
            const filesystem::path path() const;

        public:

            /// \brief Create hash file from path
            /// \param path File path
            /// \return Hash file containing hash
            static std::shared_ptr<HashFile> from(const filesystem::path & path);
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_HASHFILE_HXX_ */
