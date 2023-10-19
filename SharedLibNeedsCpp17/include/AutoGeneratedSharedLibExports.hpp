
#ifndef AUTO_GENERATED_SHAREDLIB_EXPORTS_HPP
#define AUTO_GENERATED_SHAREDLIB_EXPORTS_HPP

#ifdef TARGETSHAREDLIB_STATIC_DEFINE
#  define SHAREDLIB_API
#  define TARGETSHAREDLIB_NO_EXPORT
#else
#  ifndef SHAREDLIB_API
#    ifdef targetSharedLib_EXPORTS
        /* We are building this library */
#      define SHAREDLIB_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define SHAREDLIB_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef TARGETSHAREDLIB_NO_EXPORT
#    define TARGETSHAREDLIB_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef TARGETSHAREDLIB_DEPRECATED
#  define TARGETSHAREDLIB_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef TARGETSHAREDLIB_DEPRECATED_EXPORT
#  define TARGETSHAREDLIB_DEPRECATED_EXPORT SHAREDLIB_API TARGETSHAREDLIB_DEPRECATED
#endif

#ifndef TARGETSHAREDLIB_DEPRECATED_NO_EXPORT
#  define TARGETSHAREDLIB_DEPRECATED_NO_EXPORT TARGETSHAREDLIB_NO_EXPORT TARGETSHAREDLIB_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef TARGETSHAREDLIB_NO_DEPRECATED
#    define TARGETSHAREDLIB_NO_DEPRECATED
#  endif
#endif

#endif /* AUTO_GENERATED_SHAREDLIB_EXPORTS_HPP */
