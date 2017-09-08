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
 * Compressor.hxx
 *
 *  Created on: 8 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_COMPRESSION_COMPRESSOR_HXX_
#define SOURCES_COMPRESSION_COMPRESSOR_HXX_

#include <memory>
#include <archive.h>
#include <boost/filesystem.hpp>

namespace filesystem = boost::filesystem;

namespace arke {

    class Compressor;
    using CompressorPtr = std::shared_ptr<Compressor>;

    /// \brief Define Compressor
    class Compressor {

        private:

            /// /brief source
            filesystem::path source_;

            /// \brief Add generic entry
            /// \param entry Entry path
            void addEntry(filesystem::path entry, struct archive * a);

            /// \brief Add file entry
            /// \param entry Entry path
            void addFileEntry(filesystem::path entry, struct archive * a);

            /// \brief Add directory entry
            /// \param entry Entry path
            void addDirectoryEntry(filesystem::path entry, struct archive * a);

        protected:

            /// \brief Load algorithm to use
            virtual void loadAlgorithm(struct archive *a) = 0;

        public:

            /// \brief Constructor
            /// \param source Source path
            Compressor(filesystem::path source);

            virtual ~Compressor();

            /// \brief Compress a path to an XZ file
            /// \param destination Destination path
            void compress(filesystem::path destination);
    };

} /* namespace arke */

#endif /* SOURCES_COMPRESSION_COMPRESSOR_HXX_ */
