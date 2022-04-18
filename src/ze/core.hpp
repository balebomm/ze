#ifndef ZE_CORE_HPP
#define ZE_CORE_HPP

#if defined(_WIN32)
#   ifdef ZE_EXPORT
#       define ZE_API __declspec(dllexport)
#   elif defined(ZE_SHARED)
#       define ZE_API __declspec(dllimport)
#   endif
#else
#   if defined(ZE_EXPORT) || defined(ZE_SHARED)
#       if defined(__GNUC__) || defined(__clang__)
#           define ZE_API __attribute__((visibility("default")))
#       endif
#   endif
#endif
#ifndef ZE_API
#   define ZE_API
#endif

namespace ze {
    void ZE_API run_server();
}

#endif // ZE_CORE_HPP