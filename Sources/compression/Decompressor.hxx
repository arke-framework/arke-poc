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
 * Decompressor.hxx
 *
 *  Created on: 8 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_COMPRESSION_DECOMPRESSOR_HXX_
#define SOURCES_COMPRESSION_DECOMPRESSOR_HXX_

#include <memory>
#include <boost/filesystem.hpp>
#include <archive.h>

namespace filesystem = boost::filesystem;

namespace arke {

    class Decompressor;
    using DecompressorPtr = std::shared_ptr<Decompressor>;

    /// \brief Define Decompressor
    class Decompressor {

        private:

            // Source file path
            filesystem::path source_;

        protected:

            /// \brief Load algorithm to use
            virtual void loadAlgorithm(struct archive *a) = 0;

        public:

            /// \brief Constructor
            /// \param source Source file path
            Decompressor(filesystem::path source);

            /// \brief Destructor
            virtual ~Decompressor();

            /// \brief Decompress a file to a path
            /// \param destination Destinantion path
            void decompress(filesystem::path destination);
    };

} /* namespace arke */

#endif /* SOURCES_COMPRESSION_DECOMPRESSOR_HXX_ */
