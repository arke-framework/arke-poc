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
 * GzCompressor.hxx
 *
 *  Created on: 8 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_COMPRESSION_GZCOMPRESSOR_HXX_
#define SOURCES_COMPRESSION_GZCOMPRESSOR_HXX_

#include <memory>
#include "Compressor.hxx"

namespace arke {

    class GzCompressor;
    using GzCompressorPtr = std::shared_ptr<GzCompressor>;

    /// \brief Define GzCompressor
    class GzCompressor : public Compressor {

        protected:

            // Override algorithm
            virtual void loadAlgorithm(struct archive *a) override;

        public:

            // Use mother constructors
            using Compressor::Compressor;
    };

} /* namespace arke */

#endif /* SOURCES_COMPRESSION_GZCOMPRESSOR_HXX_ */
