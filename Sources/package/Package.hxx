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
#include <set>

#include <dependency/Dependency.hxx>
#include <files/FilesGroup.hxx>

namespace arke {

    class Package;
    using PackagePtr = std::shared_ptr<Package>;

    /// \brief Define a package
    class Package {

            // Package builder
            friend class PackageBuilder;

        private:

            /// \brief Dependency
            std::shared_ptr<Dependency> dependency_;

            /// \brief Files groups
            std::set<FilesGroupPtr> fileGroups_;

            /// \brief Constructor
            /// \param dependency Dependency
            /// \param fileGroups Set of files groups
            explicit Package(std::shared_ptr<Dependency> dependency, std::set<FilesGroupPtr> fileGroups);

        public:

            /// \brief Destructor
            virtual ~Package();

        public:

            /// \return Dependency
            std::shared_ptr<Dependency> dependency() const;

            /// \return Files groups
            std::set<FilesGroupPtr> fileGroups() const;
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_PACKAGE_HXX_ */
