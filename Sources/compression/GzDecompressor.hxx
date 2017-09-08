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
 * GzDecompressor.hxx
 *
 *  Created on: 8 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_COMPRESSION_GZDECOMPRESSOR_HXX_
#define SOURCES_COMPRESSION_GZDECOMPRESSOR_HXX_

#include <memory>
#include "Decompressor.hxx"

namespace arke {

    class GzDecompressor;
    using GzDecompressorPtr = std::shared_ptr<GzDecompressor>;

    /// \brief Define GzDecompressor
    class GzDecompressor : public Decompressor {

        protected:

            // Override algorithm
            virtual void loadAlgorithm(struct archive *a) override;

        public:

            // Use mother constructors
            using Decompressor::Decompressor;
    };

} /* namespace arke */

#endif /* SOURCES_COMPRESSION_GZDECOMPRESSOR_HXX_ */
