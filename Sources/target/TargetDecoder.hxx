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
 * TargetDecoder.hxx
 *
 *  Created on: 14 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_TARGET_TARGETDECODER_HXX_
#define SOURCES_TARGET_TARGETDECODER_HXX_

#include <memory>
#include "json/JSONDecoder.hxx"
#include "Target.hxx"

namespace arke {

    class TargetDecoder;
    using TargetDecoderPtr = std::shared_ptr<TargetDecoder>;

    /// \brief Define TargetDecoder
    struct TargetDecoder {

        // \brief Decode a target from a object
        TargetPtr decode(const json & object);
    };

} /* namespace arke */

#endif /* SOURCES_TARGET_TARGETDECODER_HXX_ */
