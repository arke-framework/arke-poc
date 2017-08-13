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
 * PackageTools.hxx
 *
 *  Created on: 11 août 2017
 *      Author: dami
 */

#ifndef TESTS_ARKE_PACKAGETOOLS_HXX_
#define TESTS_ARKE_PACKAGETOOLS_HXX_

#include <iostream>
#include <boost/filesystem.hpp>

namespace filesystem = boost::filesystem;

namespace arke::test {

    /// \brief File directory generator
    class FileDirectoryGenerator {

        public:

            /// \brief Create empty file
            static filesystem::path createFile(filesystem::path path, bool removeIfExists = false) {

                if(removeIfExists && boost::filesystem::exists(path)) {
                    boost::filesystem::remove(path);
                }

                boost::filesystem::ofstream sha1Stream { path };
                sha1Stream << path.c_str();
                sha1Stream.close();

                return path;
            }
    };

    /// \brief Class to generate files group directory
    class GroupDirectoryGenerator {

        private:

            /// \brief Group name
            std::string name_;

            /// \brief Path
            filesystem::path path_;

        public:

            GroupDirectoryGenerator(const std::string & name, filesystem::path path) : name_(name), path_(path) {

                // Create path
                filesystem::create_directories(path);
            }

            filesystem::path createFile(const std::string & name) {
                return FileDirectoryGenerator::createFile(name);
            }
    };

    /// \brief Class to generate package files
    class PackageDirectoryGenerator {

        private:

            /// \brief Directory containing package files
            filesystem::path path_;

        public:

            PackageDirectoryGenerator(filesystem::path path) : path_(path) {

                // Create path
                filesystem::create_directories(path);
            }

        public:

            /// \brief Create group from directory and name
            GroupDirectoryGenerator group(const std::string & name, const std::string & directory) {
                auto newPath = path_;
                path_.append(directory);
                return GroupDirectoryGenerator{name, newPath};
            }

            /// \brief Create group from directory
            GroupDirectoryGenerator group(const std::string & directory) {
                return group(directory, directory);
            }
    };
}

#endif /* TESTS_ARKE_PACKAGETOOLS_HXX_ */
