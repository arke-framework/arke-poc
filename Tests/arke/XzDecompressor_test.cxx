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
 * XzDecompressor_test.cxx
 *
 *  Created on: 13 août 2017
 *      Author: dami
 */

#include <compression/XzDecompressor.hxx>
#include "../catch/catch.hpp"

#include "PackageTools.hxx"

namespace arke {

    TEST_CASE( "Test XZ decompressor", "[compression]" ) {

        // Create compressor
        XzDecompressor decompressor{"file1_not_compressed.txt.xz"};

        // Compress
        decompressor.decompress("destination1");
    }
} /* namespace arke */
