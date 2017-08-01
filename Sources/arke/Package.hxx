/*
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
