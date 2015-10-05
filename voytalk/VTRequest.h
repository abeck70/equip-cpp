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

#ifndef __VOYTALKREQUEST_H__
#define __VOYTALKREQUEST_H__

#include "cborg/Cbor.h"

#include <string>

class VTRequest
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

    VTRequest(Cborg& _decoder)
        : decoder(_decoder)
    {
    }

    uint32_t getID()
    {
        uint32_t retval;
        if (decoder.find("id").getUnsigned(&retval))
            return retval;
        else return 0;
    }

    uint32_t getMethod()
    {
        uint32_t retval;
        if (decoder.find("method").getUnsigned(&retval))
            return retval;
        else return 0;
    }

    std::string getURL()
    {
        std::string retval;
        decoder.find("url").getString(retval);
        return retval;
    }

    Cborg getBody()
    {
        return decoder.find("body");
    }


private:
    Cborg& decoder;

};

#endif // __VOYTALKREQUEST_H__
