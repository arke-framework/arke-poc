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
 * FilesGroup.hxx
 *
 *  Created on: 3 août 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_FILESGROUP_HXX_
#define SOURCES_ARKE_FILESGROUP_HXX_

#include <memory>
#include "HashFile.hxx"
#include <set>
#include <string>

namespace arke {

    class FilesGroup;
    using FilesGroupPtr = std::shared_ptr<FilesGroup>;

    /// \brief Group files and set a directory name
    class FilesGroup {

        private:

            /// \brief group name
            std::string name_;

            /// \brief All files in group
            std::set<HashFilePtr> files_;

        public:

            /// \brief Files group
            /// \param name Group name
            /// \param files All files
            explicit FilesGroup(const std::string & name, const std::set<HashFilePtr> & files);

            /// \brief Destructor
            virtual ~FilesGroup();

            /// \return group name
            const std::string & name() const;

            /// \return All files in group
            const std::set<HashFilePtr> & files() const;
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_FILESGROUP_HXX_ */
