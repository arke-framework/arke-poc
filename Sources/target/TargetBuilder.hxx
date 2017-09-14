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
 * PackageBuilder.hxx
 *
 *  Created on: 14 sept. 2017
 *      Author: dami
 */

#ifndef SOURCES_TARGET_TARGETBUILDER_HXX_
#define SOURCES_TARGET_TARGETBUILDER_HXX_

#include <memory>
#include "Target.hxx"

namespace arke {

    class TargetBuilder;
    using TargetBuilderPtr = std::shared_ptr<TargetBuilder>;

    /// \brief Define TargetBuilder
    class TargetBuilder {
        public:

            /// \brief Build the target
            TargetPtr build();
    };

} /* namespace arke */

#endif /* SOURCES_TARGET_TARGETBUILDER_HXX_ */
