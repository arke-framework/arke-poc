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
 * DependencyBuilder.hxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_DEPENDENCYBUILDER_HXX_
#define SOURCES_ARKE_DEPENDENCYBUILDER_HXX_

#include <dependency/Dependency.hxx>

namespace arke {

    /// \brief Dependency builder
    class DependencyBuilder {

        private:

            /// \brief dependency name
            std::string name_;

            /// \brief Organization name
            std::string organizationName_;

        public:

            /// \brief Constructor
            DependencyBuilder();

            /// \brief Destructor
            virtual ~DependencyBuilder();

        public:

            /// \brief Set dependency name
            /// \param name Dependency name
            /// \return CUrrent builder
            DependencyBuilder & name(const std::string & name);

            /// \brief Set organization name
            /// \param name Dependency name
            /// \return CUrrent builder
            DependencyBuilder & organization(const std::string & name);

            /// \brief Build valid dependency
            /// \return Dependency builder neve invalid
            DependencyPtr build();
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_DEPENDENCYBUILDER_HXX_ */
