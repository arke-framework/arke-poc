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
 * Compressor.cxx
 *
 *  Created on: 8 sept. 2017
 *      Author: dami
 */

#include "Compressor.hxx"

#include <archive_entry.h>
#include <exception>

namespace arke {

    Compressor::Compressor(filesystem::path source) : source_(source) {
    }

    Compressor::~Compressor() {
    }

    void Compressor::addEntry(filesystem::path entry, struct archive * a) {

        // Test file exists
        if (!filesystem::exists(entry)) {
            throw std::runtime_error{std::string{"Entry does not exist "} + entry.c_str()};
        }

        // Test directory
        if (filesystem::is_directory(entry)) {
            addDirectoryEntry(entry, a);
        // Test is regular file
        } else if (filesystem::is_regular(entry)) {
            addFileEntry(entry, a);
        } else {
            throw std::runtime_error{std::string{"Unable to compress this file type"} + archive_error_string(a)};
        }
    }

    // Add file entry
    void Compressor::addFileEntry(filesystem::path entryPath, struct archive * a) {

        struct stat st;

        // Find file stat
        stat(entryPath.c_str(), &st);

        // Create entry
        struct archive_entry *entry = archive_entry_new();

        // Set entry headers
        archive_entry_set_pathname(entry, entryPath.c_str());
        archive_entry_set_size(entry, st.st_size);
        archive_entry_set_filetype(entry, AE_IFREG);
        archive_entry_set_perm(entry, 0644);
        archive_write_header(a, entry);

        // Create read buffer
        char buff[8192];

        // Open file
        filesystem::fstream inputStream {entryPath};

        while(!inputStream.eof()) {

            // Read some data
            auto size = inputStream.readsome(buff, 8192);
            if (size == 0) {
                break;
            }

            // Write data
            archive_write_data(a, buff, size);
        }

        archive_entry_free(entry);
    }

    // Add directory entry
    void Compressor::addDirectoryEntry(filesystem::path entry, struct archive * a) {

        // Parse all files form folder and add entries
        for (auto & x : filesystem::directory_iterator(entry)) {
            addEntry(x, a);
        }
    }

    // Compress a file to a path
    void Compressor::compress(filesystem::path destination) {

        // Create archive writer
        struct archive *a = archive_write_new();

        // Set archive type
        loadAlgorithm(a);

        // Open archive
        archive_write_open_filename(a, destination.c_str());

        // Add root entry
        addEntry(source_, a);

        // Close archive
        archive_write_close(a);

        // Free archive memory
        archive_write_free(a);
    }

} /* namespace arke */
