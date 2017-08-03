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
 * Dependency.hxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_DEPENDENCY_HXX_
#define SOURCES_ARKE_DEPENDENCY_HXX_

#include <string>
#include <memory>

namespace arke {

    class Dependency;
    using DependencyPtr = std::shared_ptr<Dependency>;

    /// \brief Define a dependency
    class Dependency {

            friend class DependencyBuilder;

        private:

            /// \brief Dependency name
            std::string name_;

            /// \brief Organization name
            std::string organization_;

            /// \brief Constructor with all parameters
            /// \param name Dependency name
            /// \param organization Organization name
            explicit Dependency(
                    const std::string & name,
                    const std::string & organization);

        public:

            /// \brief Destructor
            virtual ~Dependency();

        public:

            /// \return Dependency ID that is composed of organization / dependency name
            const std::string id() const;

            /// \return Package name
            const std::string & name() const;

            /// \return Package organization
            const std::string & organization() const;
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_DEPENDENCY_HXX_ */
