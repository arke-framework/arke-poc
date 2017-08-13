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

namespace arke {

    // Init compressor
    XzDecompressor::XzDecompressor(filesystem::path destination) {

        // Create
        lzma_stream strm_ = LZMA_STREAM_INIT;

        // Init decoder
        lzma_ret ret = lzma_stream_decoder(&strm_, UINT64_MAX, LZMA_CONCATENATED);
        if (ret != LZMA_OK) {
            throw std::runtime_error { "Unable to init LZMA decoder" };
        }

        strm_.next_in = NULL;
        strm_.avail_in = 0;
        strm_.next_out = outbuf_;
        strm_.avail_out = sizeof(outbuf_);
    }

    // Destructor
    XzDecompressor::~XzDecompressor() {

        // End
        lzma_end(&strm_);
    }

    // Compress a file to a path
    void XzDecompressor::decompress(filesystem::path source) {

        /*
        // When LZMA_CONCATENATED flag was used when initializing the decoder,
        // we need to tell lzma_code() when there will be no more input.
        // This is done by setting action to LZMA_FINISH instead of LZMA_RUN
        // in the same way as it is done when encoding.
        //
        // When LZMA_CONCATENATED isn't used, there is no need to use
        // LZMA_FINISH to tell when all the input has been read, but it
        // is still OK to use it if you want. When LZMA_CONCATENATED isn't
        // used, the decoder will stop after the first .xz stream. In that
        // case some unused data may be left in strm_.next_in.
        lzma_action action = LZMA_RUN;

        while (true) {

            if (strm_.avail_in == 0) { // && !feof(infile)) {
                //strm_.next_in = inbuf;
                //strm_.avail_in = fread(inbuf, 1, sizeof(inbuf),
                //        infile);

                //if (ferror(infile)) {
                //    fprintf(stderr, "%s: Read error: %s\n",
                //            inname, strerror(errno));
                //    return false;
                //}

                // Once the end of the input file has been reached,
                // we need to tell lzma_code() that no more input
                // will be coming. As said before, this isn't required
                // if the LZMA_CONATENATED flag isn't used when
                // initializing the decoder.
                //if (feof(infile)) {
                //    action = LZMA_FINISH;
                //}
            }

            lzma_ret ret = lzma_code(&strm_, action);

            if (strm_.avail_out == 0 || ret == LZMA_STREAM_END) {

                // Xrite size
                ssize_t write_size = sizeof(outbuf_) - strm_.avail_out;

                //if (fwrite(outbuf, 1, write_size, outfile) != write_size) {
                //    fprintf(stderr, "Write error: %s\n",
                //            strerror(errno));
                //    return false;
                //}

                strm_.next_out = outbuf_;
                strm_.avail_out = sizeof(outbuf_);
            }

            if (ret != LZMA_OK) {
                // Once everything has been decoded successfully, the
                // return value of lzma_code() will be LZMA_STREAM_END.
                //
                // It is important to check for LZMA_STREAM_END. Do not
                // assume that getting ret != LZMA_OK would mean that
                // everything has gone well or that when you aren't
                // getting more output it must have successfully
                // decoded everything.
                if (ret == LZMA_STREAM_END) {
                    return;
                }

                // It's not LZMA_OK nor LZMA_STREAM_END,
                // so it must be an error code. See lzma/base.h
                // (src/liblzma/api/lzma/base.h in the source package
                // or e.g. /usr/include/lzma/base.h depending on the
                // install prefix) for the list and documentation of
                // possible values. Many values listen in lzma_ret
                // enumeration aren't possible in this example, but
                // can be made possible by enabling memory usage limit
                // or adding flags to the decoder initialization.
                const char *msg;
                switch (ret) {
                    case LZMA_MEM_ERROR:
                        msg = "Memory allocation failed";
                        break;

                    case LZMA_FORMAT_ERROR:
                        // .xz magic bytes weren't found.
                        msg = "The input is not in the .xz format";
                        break;

                    case LZMA_OPTIONS_ERROR:
                        // For example, the headers specify a filter
                        // that isn't supported by this liblzma
                        // version (or it hasn't been enabled when
                        // building liblzma, but no-one sane does
                        // that unless building liblzma for an
                        // embedded system). Upgrading to a newer
                        // liblzma might help.
                        //
                        // Note that it is unlikely that the file has
                        // accidentally became corrupt if you get this
                        // error. The integrity of the .xz headers is
                        // always verified with a CRC32, so
                        // unintentionally corrupt files can be
                        // distinguished from unsupported files.
                        msg = "Unsupported compression options";
                        break;

                    case LZMA_DATA_ERROR:
                        msg = "Compressed file is corrupt";
                        break;

                    case LZMA_BUF_ERROR:
                        // Typically this error means that a valid
                        // file has got truncated, but it might also
                        // be a damaged part in the file that makes
                        // the decoder think the file is truncated.
                        // If you prefer, you can use the same error
                        // message for this as for LZMA_DATA_ERROR.
                        msg = "Compressed file is truncated or "
                                "otherwise corrupt";
                        break;

                    default:
                        // This is most likely LZMA_PROG_ERROR.
                        msg = "Unknown error, possibly a bug";
                        break;
                }

                //fprintf(stderr, "%s: Decoder error: "
                //        "%s (error code %u)\n",
                //        inname, msg, ret);

                throw std::runtime_error { "" };
            }
        }
        */
    }

} /* namespace arke */
