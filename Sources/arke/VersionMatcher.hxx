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
 * VersionMatcher.hxx
 *
 *  Created on: 26 juil. 2017
 *      Author: dami
 */

#ifndef SOURCES_ARKE_VERSIONMATCHER_HXX_
#define SOURCES_ARKE_VERSIONMATCHER_HXX_

#include <memory>
#include <vector>
#include <any>
#include <string>

namespace arke {

    class VersionMatcher;
    using VersionMatcherPtr = std::shared_ptr<VersionMatcher>;

    /// \brief Define matcher type
    enum class MatcherType : int {

        /// Version equals
        EQUALS,

        /// Version higher (or equals) than
        HIGHER,

        /// Version match pattern
        PATTERN
    };

    /// \brief Define VersionMatcher
    class VersionMatcher {

        protected:

            /// \brief decode a version to parts
            /// \param version
            /// \return Parts of url
            static std::vector<std::string> decode(const std::string & version);

        public:

            /// \brief Destructor
            virtual ~VersionMatcher();

            /// \brief Match version
            /// \param version Version to test
            /// \return True if version match
            virtual bool match(const std::string & version) const = 0;

            /// \return Type of matcher
            virtual MatcherType type() const = 0;
    };

    /// \brief Version equals
    class VersionEquals : public VersionMatcher {

        private:

            /// \brief Version that match
            std::string version_;

        public:

            /// \brief COnstructor with version
            /// \param version Version to find
            VersionEquals(const std::string & version);

            /// \brief Match version
            /// \param version Version to test
            /// \return True if version match
            virtual bool match(const std::string & version) const override;

            /// \return Type of matcher
            virtual MatcherType type() const override;
    };

    /// \brief Version higher or equals than version
    class VersionHigher : public VersionMatcher {

        private:

            /// \brief Decomposed versions
            std::vector<std::string> versions_;

        public:

            /// \brief Constructor with separator
            /// \param version Base version
            VersionHigher(const std::string & version);

            /// \brief Match version
            /// \param version Version to test
            /// \return True if version match
            virtual bool match(const std::string & version) const override;

            /// \return Type of matcher
            virtual MatcherType type() const override;
    };

    /// \brief Version match pattern using separator
    class VersionPattern : public VersionMatcher {

        private:

            /// \brief Decomposed versions
            std::vector<std::string> versions_;

        public:

            /// \brief Constructor with separator
            /// \param version Base version
            VersionPattern(const std::string & version);

            /// \brief Match version
            /// \param version Version to test
            /// \return True if version match
            virtual bool match(const std::string & version) const override;

            /// \return Type of matcher
            virtual MatcherType type() const override;
    };

} /* namespace arke */

#endif /* SOURCES_ARKE_VERSIONMATCHER_HXX_ */
