/*
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
            Dependency(const std::string & name, const std::string & organization);

        public:

            virtual ~Dependency();

        public:

            /// \return Dependency ID that is composed of organization / dependency name
            const std::string id() const;
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_DEPENDENCY_HXX_ */
