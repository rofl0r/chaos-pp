# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_NAMES_H
# define CHAOS_PREPROCESSOR_NAMES_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bitor.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/recursion/auto_rec.h>
#
# /* CHAOS_PP_SCOPE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SCOPE \
        CHAOS_PP_IIF(CHAOS_PP_IS_NULLARY(CHAOS_IP_SCOPE_0(, ())))( \
            CHAOS_IP_SCOPE_0, CHAOS_PP_CAT(CHAOS_IP_SCOPE_, CHAOS_PP_AUTO_REC(CHAOS_IP_SCOPE_P, 16)) \
        ) \
        /**/
#    define CHAOS_PP_SCOPE_ID() CHAOS_PP_SCOPE
#    define CHAOS_PP_SCOPE_ CHAOS_PP_LAMBDA(CHAOS_PP_SCOPE_ID)()
#    define CHAOS_IP_SCOPE_P(n) CHAOS_PP_IS_NULLARY(CHAOS_IP_SCOPE_ ## n(, ()))
#    define CHAOS_IP_SCOPE_0(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_1(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_2(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_3(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_4(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_5(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_6(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_7(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_8(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_9(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_10(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_11(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_12(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_13(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_14(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_15(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_SCOPE_16(p, ...) p ## __VA_ARGS__
# endif
#
# /* CHAOS_PP_EXTERN */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EXTERN(p, ...) p ## __VA_ARGS__
#    define CHAOS_PP_EXTERN_ID() CHAOS_PP_EXTERN
#    define CHAOS_PP_EXTERN_ CHAOS_PP_LAMBDA(CHAOS_PP_EXTERN_ID)()
# endif
#
# /* CHAOS_PP_PREFIX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PREFIX(id) \
        CHAOS_PP_IIF( \
            CHAOS_PP_BITOR \
                (CHAOS_PP_IS_NULLARY(CHAOS_IP_SCOPE_0(, ()))) \
                (CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY(CHAOS_PP_EXTERN(, ())))) \
        )(id, CHAOS_PP_ ## id) \
        /**/
#    define CHAOS_PP_PREFIX_ID() CHAOS_PP_PREFIX
#    define CHAOS_PP_PREFIX_ CHAOS_PP_LAMBDA(CHAOS_PP_PREFIX_ID)()
# endif
#
# endif
