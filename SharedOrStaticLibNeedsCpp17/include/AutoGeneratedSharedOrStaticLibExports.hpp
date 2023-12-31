
#ifndef AUTO_GENERATED_SHARED_OR_STATIC_LIB_EXPORTS_HPP
#define AUTO_GENERATED_SHARED_OR_STATIC_LIB_EXPORTS_HPP

#ifdef TARGETSHAREDORSTATICLIB_STATIC_DEFINE
#  define SHARED_OR_STATIC_LIB_API
#  define TARGETSHAREDORSTATICLIB_NO_EXPORT
#else
#  ifndef SHARED_OR_STATIC_LIB_API
#    ifdef targetSharedOrStaticLib_EXPORTS
        /* We are building this library */
#      define SHARED_OR_STATIC_LIB_API 
#    else
        /* We are using this library */
#      define SHARED_OR_STATIC_LIB_API 
#    endif
#  endif

#  ifndef TARGETSHAREDORSTATICLIB_NO_EXPORT
#    define TARGETSHAREDORSTATICLIB_NO_EXPORT 
#  endif
#endif

#ifndef TARGETSHAREDORSTATICLIB_DEPRECATED
#  define TARGETSHAREDORSTATICLIB_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef TARGETSHAREDORSTATICLIB_DEPRECATED_EXPORT
#  define TARGETSHAREDORSTATICLIB_DEPRECATED_EXPORT SHARED_OR_STATIC_LIB_API TARGETSHAREDORSTATICLIB_DEPRECATED
#endif

#ifndef TARGETSHAREDORSTATICLIB_DEPRECATED_NO_EXPORT
#  define TARGETSHAREDORSTATICLIB_DEPRECATED_NO_EXPORT TARGETSHAREDORSTATICLIB_NO_EXPORT TARGETSHAREDORSTATICLIB_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef TARGETSHAREDORSTATICLIB_NO_DEPRECATED
#    define TARGETSHAREDORSTATICLIB_NO_DEPRECATED
#  endif
#endif

#endif /* AUTO_GENERATED_SHARED_OR_STATIC_LIB_EXPORTS_HPP */
