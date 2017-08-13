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
 * XzCompressor.hxx
 *
 *  Created on: 12 août 2017
 *      Author: dami
 */

#ifndef SOURCES_COMPRESSION_XZCOMPRESSOR_HXX_
#define SOURCES_COMPRESSION_XZCOMPRESSOR_HXX_

#include <memory>
#include <boost/filesystem.hpp>

#include <lzma.h>

namespace filesystem = boost::filesystem;

namespace arke {

    class XzCompressor;
    using XzCompressorPtr = std::shared_ptr<XzCompressor>;

    /// \brief Define XzCompressor
    class XzCompressor {

        private:

            /// \brief LZMA stream
            lzma_stream strm_;

        public:

            /// \brief Constructor
            /// \param destination Destination path
            XzCompressor(filesystem::path destination);

            /// \brief Destructor
            virtual ~XzCompressor();

            /// \brief Compress a file to a path
            /// \param source Source path
            void compress(filesystem::path source);
    };

} /* namespace arke */

#endif /* SOURCES_COMPRESSION_XZCOMPRESSOR_HXX_ */
