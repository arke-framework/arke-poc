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
 *  Created on: 5 août 2017
 *      Author: dami
 */

#ifndef SOURCES_PACKAGE_PACKAGEBUILDER_HXX_
#define SOURCES_PACKAGE_PACKAGEBUILDER_HXX_

#include <package/Package.hxx>
#include <files/FilesGroup.hxx>

namespace arke {

    /// \brief Package builder
    class PackageBuilder {

        private:

            /// \brief Dependency
            DependencyPtr dependency_;

            /// \brief Files groups
            std::set<FilesGroupPtr> fileGroups_;
        public:

            /// \brief Constructor
            PackageBuilder();

            /// \brief Destructor
            virtual ~PackageBuilder();

        public:

            /// \brief Set dependency
            /// \param dependency Dependency
            /// \return this builder
            PackageBuilder & dependency(DependencyPtr dependency);

            /// \return Build package
            PackagePtr build();
    };

} /* namespace arke */

#endif /* SOURCES_PACKAGE_PACKAGEBUILDER_HXX_ */
