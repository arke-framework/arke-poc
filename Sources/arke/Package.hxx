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
 * Package.hxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_PACKAGE_HXX_
#define SOURCES_ARKE_PACKAGE_HXX_

#include <memory>

#include "Dependency.hxx"

namespace arke {

    class Package;
    using PackagePtr = std::shared_ptr<Package>;

    /// \brief Define a package
    class Package {

        private:

            /// \brief Dependency
            std::shared_ptr<Dependency> dependency_;

        public:

            /// \brief Constructor
            /// \param dependency Dependency
            Package(std::shared_ptr<Dependency> dependency);

            /// \brief Destructor
            virtual ~Package();
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_PACKAGE_HXX_ */
