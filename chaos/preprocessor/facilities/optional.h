# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_FACILITIES_OPTIONAL_H
# define CHAOS_PREPROCESSOR_FACILITIES_OPTIONAL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/core.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_IS_OPTIONAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_OPTIONAL(...) CHAOS_PP_TUPLE_IS_NIL(CHAOS_PP_TUPLE_REST((__VA_ARGS__)))
#    define CHAOS_PP_IS_OPTIONAL_ID() CHAOS_PP_IS_OPTIONAL
#    define CHAOS_PP_IS_OPTIONAL_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_OPTIONAL)
# endif
#
# /* CHAOS_PP_OPTIONAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_OPTIONAL(...) \
        CHAOS_PP_SPLIT(1, __VA_ARGS__ CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_OPTIONAL(__VA_ARGS__))(,)) \
        /**/
#    define CHAOS_PP_OPTIONAL_ID() CHAOS_PP_OPTIONAL
#    define CHAOS_PP_OPTIONAL_ CHAOS_PP_LAMBDA(CHAOS_PP_OPTIONAL_ID)()
# endif
#
# /* CHAOS_PP_NON_OPTIONAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NON_OPTIONAL(...) CHAOS_PP_SPLIT(0, __VA_ARGS__,)
#    define CHAOS_PP_NON_OPTIONAL_ID() CHAOS_PP_NON_OPTIONAL
#    define CHAOS_PP_NON_OPTIONAL_ CHAOS_PP_LAMBDA(CHAOS_PP_NON_OPTIONAL_ID)()
# endif
#
# /* CHAOS_PP_PACK_OPTIONAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PACK_OPTIONAL(...) CHAOS_IP_PACK_OPTIONAL_I(CHAOS_PP_IS_OPTIONAL(__VA_ARGS__), __VA_ARGS__)
#    define CHAOS_PP_PACK_OPTIONAL_ID() CHAOS_PP_PACK_OPTIONAL
#    define CHAOS_PP_PACK_OPTIONAL_ CHAOS_PP_LAMBDA(CHAOS_PP_PACK_OPTIONAL_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_PACK_OPTIONAL_I(opt, ...) \
        (CHAOS_PP_IIF(opt)(,,) CHAOS_PP_SPLIT(1, __VA_ARGS__ CHAOS_PP_INLINE_WHEN(opt)(,))) \
        /**/
# endif
#
# /* CHAOS_PP_EXPOSE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EXPOSE(pack) CHAOS_PP_REM pack
#    define CHAOS_PP_EXPOSE_ CHAOS_PP_LAMBDA(CHAOS_PP_EXPOSE_ID)()
# else
#    define CHAOS_PP_EXPOSE(pack) , CHAOS_PP_REM pack
# endif
#
# define CHAOS_PP_EXPOSE_ID() CHAOS_PP_EXPOSE
#
# endif
