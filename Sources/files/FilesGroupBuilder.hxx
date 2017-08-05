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
 * FilesGroupBuilder.hxx
 *
 *  Created on: 6 août 2017
 *      Author: dami
 */

#ifndef SOURCES_FILES_FILESGROUPBUILDER_HXX_
#define SOURCES_FILES_FILESGROUPBUILDER_HXX_

#include <string>
#include <set>
#include <files/HashFile.hxx>
#include <files/FilesGroup.hxx>

namespace arke {

    /// \brief Class files group builder
    class FilesGroupBuilder {

        private:

            /// \brief Files group name
            std::string name_;

            /// \brief All files in group
            std::set<HashFilePtr> files_;

        public:

            /// \brief Constructor
            FilesGroupBuilder();

            /// \brief Destructor
            virtual ~FilesGroupBuilder();

        public:

            /// \brief Set files group name
            /// \param name Name of the group
            /// \return Current builder
            FilesGroupBuilder & name(const std::string & name);

            /// \brief Append file to group
            /// \param hashFile Hash file
            /// \return Current builder
            FilesGroupBuilder & append(HashFilePtr hashFile);

            /// \return Build files group
            FilesGroupPtr build();

        public:

            /// \brief Create Files group builder from directory
            /// \param path Path directory
            static FilesGroupBuilder from(const filesystem::path & path);
    };

} /* namespace arke */

#endif /* SOURCES_FILES_FILESGROUPBUILDER_HXX_ */
