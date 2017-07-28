/*
 * DependencyDefinition.hxx
 *
 *  Created on: 26 juil. 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_DEPENDENCYDEFINITION_HXX_
#define SOURCES_ARKE_DEPENDENCYDEFINITION_HXX_

#include <string>
#include <memory>

namespace arke {

    class DependencyDefinition;
    using DependencyDefinitionPtr = std::shared_ptr<DependencyDefinition>;

    /// \brief Dependency definition
    class DependencyDefinition {

        private:

            /// \brief Dependency id
            std::string id_;

            /// \brief Version matcher
            std::string version_;

        public:

            /// \brief Dependency constructor
            /// \param id Dependency id
            /// \param version Version matcher
            DependencyDefinition(const std::string & id, const std::string & version);

            /// \brief Destructor
            virtual ~DependencyDefinition();

            /// \return Dependency id
            const std::string id() const;

            /// \return Version matcher
            const std::string version() const;
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_DEPENDENCYDEFINITION_HXX_ */
