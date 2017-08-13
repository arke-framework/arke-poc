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
 * XzCompressor.cxx
 *
 *  Created on: 12 août 2017
 *      Author: dami
 */

#include "XzCompressor.hxx"

#include <exception>

namespace arke {

    // Init compressor
    XzCompressor::XzCompressor(filesystem::path destination) {

        // Create
        lzma_stream strm_ = LZMA_STREAM_INIT;

        // Init decoder
        lzma_ret ret = lzma_stream_decoder(&strm_, UINT64_MAX, LZMA_CONCATENATED);
        if (ret != LZMA_OK) {
            throw std::runtime_error{"Unable to init LZMA decoder"};
        }
    }

    // Destructor
    XzCompressor::~XzCompressor() {

        // End
        lzma_end(&strm_);
    }

    // Compress a file to a path
    void XzCompressor::compress(filesystem::path source) {

    }

} /* namespace arke */
