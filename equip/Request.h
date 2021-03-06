/* mbed Microcontroller Library
 * Copyright (c) 2006-2015 ARM Limited
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
 */

#ifndef __EQUIP_REQUEST_H__
#define __EQUIP_REQUEST_H__

#include "cborg/Cbor.h"

#include <string>

namespace Equip {

/**
 * An encapulation of a request from a client, requests have at least a method and path
 * and likely a body. This should be a familar concept to thos that have used HTTP.
 **/
class Request
{
public:
    enum {
        TAG = 0x4010
    };

    typedef enum {
        GET,
        PUT,
        POST
    } method_t;

    Request(Cborg& _decoder)
        : decoder(_decoder)
    {
    }

    uint32_t getID() // const - todo: encoder methods should be const
    {
        uint32_t retval;
        if (decoder.find(ShortKeyId).getUnsigned(&retval))
            return retval;
        else return 0;
    }

    uint32_t getMethod() // const - todo: encoder methods should be const
    {
        uint32_t retval;
        if (decoder.find(ShortKeyMethod).getUnsigned(&retval))
            return retval;
        else return 0;
    }

    std::string getURL() // const - todo: encoder methods should be const
    {
        std::string retval;
        decoder.find(ShortKeyUrl).getString(retval);
        return retval;
    }

    Cborg getBody() // const - todo: encoder methods should be const
    {
        return decoder.find(ShortKeyBody);
    }


private:
    Cborg decoder;

};

}

#endif // __EQUIP_REQUEST_H__
