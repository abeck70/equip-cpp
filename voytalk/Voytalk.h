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

#ifndef __VOYTALK_H__
#define __VOYTALK_H__


#include "voytalk/VoytalkCoda.h"
#include "voytalk/VoytalkIntent.h"
#include "voytalk/VoytalkIntentInvocation.h"
#include "voytalk/VoytalkParameters.h"
#include "voytalk/VoytalkRequest.h"
#include "voytalk/VoytalkResponse.h"

#include "cbor/Cbor.h"

typedef CborMap VoytalkResource;

#endif // __VOYTALK_H__