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
 * XzDecompressor.cxx
 *
 *  Created on: 13 août 2017
 *      Author: dami
 */

#include "XzDecompressor.hxx"

#include <string>
#include <archive.h>
#include <archive_entry.h>

#include <exception>

namespace arke {

    // Init compressor
    XzDecompressor::XzDecompressor(filesystem::path source) : source_(source) {

    }

    // Destructor
    XzDecompressor::~XzDecompressor() {

    }

    // Compress a file to a path
    void XzDecompressor::decompress(filesystem::path destination) {

        if (!filesystem::exists(source_)) {
            throw std::runtime_error{std::string{"File does not exist, "} + source_.c_str()};
        }

        // create read archive pointer
        struct archive *a = archive_read_new();

        // Set to tar + xz
        archive_read_support_compression_xz(a);
        archive_read_support_format_gnutar(a);

        // Open file
        int r = archive_read_open_filename(a, source_.c_str(), 16384);
        if (r != ARCHIVE_OK) {
            throw std::runtime_error{std::string{"Unable to open file " } + archive_error_string(a)};
        }

        // Entry pointer
        struct archive_entry * entry = nullptr;

        // Write to disk like an archive without compression
        struct archive *ext = archive_write_disk_new();

        // Set flag
        int flags = ARCHIVE_EXTRACT_TIME;
        flags |= ARCHIVE_EXTRACT_PERM;
        flags |= ARCHIVE_EXTRACT_ACL;
        flags |= ARCHIVE_EXTRACT_FFLAGS;
        archive_write_disk_set_options(ext, flags);

        while(true) {

            // Read header
            r = archive_read_next_header(a, &entry);

            // No entry found
            if (r == ARCHIVE_EOF) {
                break;
            }

            // Error
            if (r != ARCHIVE_OK) {
               throw std::runtime_error{archive_error_string(a)};
            }

            // Find path entry
            filesystem::path pathEntry = destination;
            pathEntry.append(archive_entry_pathname(entry));

            archive_entry_set_pathname(entry, pathEntry.c_str());

            // Write headers
            r = archive_write_header(ext, entry);
            if (r != ARCHIVE_OK) {
                throw std::runtime_error{archive_error_string(a)};
            }

            // Copy data from archive to disk
            const void *buff;
            size_t size = 0;
            int64_t offset = 0;
            for (;;) {

                // Read form archive
                r = archive_read_data_block(a, &buff, &size, &offset);

                // End of file
                if (r == ARCHIVE_EOF) {
                    break;
                }

                // Error
                if (r != ARCHIVE_OK) {
                    throw std::runtime_error{archive_error_string(a)};
                }

                // Write to disk
                r = archive_write_data_block(ext, buff, size, offset);

                // Error
                if (r != ARCHIVE_OK) {
                    throw std::runtime_error{archive_error_string(a)};
                }
            }
        }

        archive_read_close(a);
        archive_read_free(a);

        archive_write_close(ext);
        archive_write_free(ext);
    }

} /* namespace arke */
