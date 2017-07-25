/*
 * Package.hxx
 *
 *  Created on: 25 juil. 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_PACKAGE_HXX_
#define SOURCES_ARKE_PACKAGE_HXX_

#include <memory>

namespace arke {

    class Package;
    using PackagePtr = std::shared_ptr<Package>;

    /// \brief Define a package
    class Package {

        private:

        public:

            /// \brief Constructor
            Package();

            /// \brief Destructor
            virtual ~Package();
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_PACKAGE_HXX_ */
