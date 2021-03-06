/***
* ==++==
*
* Copyright (c) Microsoft Corporation. All rights reserved. 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* ==--==
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* stdafx.h
*
* Pre-compiled headers
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#pragma once

// Compiler bug causes unreachable code warning. TFS 601014.
#pragma warning(push)
#pragma warning(disable : 4702)
// This header is required to define _MS_WINDOWS
#include "cpprest/xxpublic.h"
#pragma warning(pop)

#ifdef _MS_WINDOWS
#define NOMINMAX
#include <Windows.h>
#endif

#include <vector>
#include <fstream>
#include <memory>
#include <stdio.h>
#include <time.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1800)
#include <ppltasks.h>
namespace pplx = Concurrency;
#if (_MSC_VER >= 1900)
#include <concrt.h>
#ifndef DEV14_EXTENSIBILITY_WRKRND
#define DEV14_EXTENSIBILITY_WRKRND
namespace pplx = Concurrency;
namespace Concurrency {
    namespace extensibility {
        typedef ::Concurrency::event event_t;
        typedef ::Concurrency::reader_writer_lock reader_writer_lock_t;
        typedef ::Concurrency::reader_writer_lock::scoped_lock scoped_rw_lock_t;
        typedef ::Concurrency::reader_writer_lock::scoped_lock_read scoped_read_lock_t;

        typedef ::Concurrency::details::_ReentrantBlockingLock recursive_lock_t;
        typedef recursive_lock_t::_Scoped_lock scoped_recursive_lock_t;
    }
}
#endif // DEV14_EXTENSIBILITY_WRKRND
#endif // _MSC_VER >= 1900
#else 
#include "pplx/pplxtasks.h"
#if defined(_MS_WINDOWS) && _MSC_VER >= 1700
#include "pplx/pplxconv.h"
#endif
#endif

#ifndef _MS_WINDOWS
#  include "pplx/threadpool.h"
#endif

#include "cpprest/asyncrt_utils.h"
#include "unittestpp.h"
#include "os_utilities.h"
