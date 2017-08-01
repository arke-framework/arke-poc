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
 * SHAGenerator.cxx
 *
 *  Created on: 29 juil. 2017
 *      Author: dami
 */

#include "SHAGenerator.hxx"

#include <botan/hash.h>
#include <botan/hex.h>

#include <boost/filesystem/fstream.hpp>
#include <iostream>

namespace arke {

    // enum to string
    std::string str(HashFunction hashFunction) {
        switch(hashFunction) {
            case HashFunction::SHA1:
                return "SHA-1";
            case HashFunction::SHA256:
                return "SHA-256";
            case HashFunction::SHA512:
                return "SHA-512";
        }
        throw std::runtime_error{"Unable to encode hash function"};
    }

    // Override <<
    std::ostream & operator<<(std::ostream & ostream, const HashFunction & hashFunction) {
        ostream << str(hashFunction);
        return ostream;
    }

    SHAGenerator::SHAGenerator(HashFunction hashFunction) : hash_(hashFunction) {
    }

    // Generate SHA of file
    std::string SHAGenerator::hashFile(const path & path) const {



        // Create hash function
        std::unique_ptr<Botan::HashFunction> hash = Botan::HashFunction::create(str(hash_));

        // Create internal buffer
        std::vector<uint8_t> buffer(2048);

        // Read stream
        filesystem::ifstream stream(path);

        // If good read other
        while(stream.good()) {

            // Read stream to buffer
            stream.read(reinterpret_cast<char*>(buffer.data()), buffer.size());

            // Read count
            size_t readcount = stream.gcount();

            //update hash computations with read data
            hash->update(buffer.data(),readcount);
        }

        // Encode hash result
        return Botan::hex_encode(hash->final());
    }

    // Generate SHA of file
    std::string SHAGenerator::hashString(const std::string & strToEncode) const {

        // Create hash function
        std::unique_ptr<Botan::HashFunction> hash = Botan::HashFunction::create(str(hash_));

        // Create internal buffer
        std::vector<uint8_t> buffer(2048);

        // Read stream
        filesystem::ifstream stream(path);

        //update hash computations with read data
        hash->update(reinterpret_cast<const uint8_t*>(strToEncode.c_str()), strToEncode.length());

        // Encode hash result
        return Botan::hex_encode(hash->final());
    }

} /* namespace arke */
