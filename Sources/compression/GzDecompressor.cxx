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
 * GzDecompressor.cxx
 *
 *  Created on: 8 sept. 2017
 *      Author: dami
 */

#include "GzDecompressor.hxx"

namespace arke {

    void GzDecompressor::loadAlgorithm(struct archive *a) {
        archive_read_support_compression_gzip(a);
        archive_read_support_format_gnutar(a);
    }

} /* namespace arke */
