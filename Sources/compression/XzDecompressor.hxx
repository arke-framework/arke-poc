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
 * XzDecompressor.hxx
 *
 *  Created on: 13 août 2017
 *      Author: dami
 */

#ifndef SOURCES_COMPRESSION_XZDECOMPRESSOR_HXX_
#define SOURCES_COMPRESSION_XZDECOMPRESSOR_HXX_

#include <memory>
#include <boost/filesystem.hpp>

#include <lzma.h>

namespace filesystem = boost::filesystem;

namespace arke {

    class XzDecompressor;
    using XzDecompressorPtr = std::shared_ptr<XzDecompressor>;

    /// \brief Define XzDecompressor
    class XzDecompressor {

        private:

            /// \brief LZMA stream
            lzma_stream strm_;

            /// \brief Input buffer
            uint8_t inbuf_[BUFSIZ];

            /// \brief Output buffer
            uint8_t outbuf_[BUFSIZ];

        public:

            /// \brief Constructor
            /// \param destination Destination path
            XzDecompressor(filesystem::path destination);

            /// \brief Destructor
            virtual ~XzDecompressor();

            /// \brief Decompress a file to a path
            /// \param source Source path
            void decompress(filesystem::path source);
    };

} /* namespace arke */

#endif /* SOURCES_COMPRESSION_XZDECOMPRESSOR_HXX_ */
