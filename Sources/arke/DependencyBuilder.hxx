/*
 * DependencyBuilder.hxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_DEPENDENCYBUILDER_HXX_
#define SOURCES_ARKE_DEPENDENCYBUILDER_HXX_

#include "Dependency.hxx"

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
            DependencyBuilder & organizationName(const std::string & name);

            /// \brief Build valid dependency
            /// \return Dependency builder neve invalid
            DependencyPtr build();
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_DEPENDENCYBUILDER_HXX_ */
