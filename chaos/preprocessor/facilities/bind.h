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
# ifndef CHAOS_PREPROCESSOR_BIND_H
# define CHAOS_PREPROCESSOR_BIND_H
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
# /* CHAOS_PP_BIND */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BIND \
        CHAOS_PP_IIF(CHAOS_PP_IS_NULLARY(CHAOS_IP_BIND_0(, ())))( \
            CHAOS_IP_BIND_0, CHAOS_PP_CAT(CHAOS_IP_BIND_, CHAOS_PP_AUTO_REC(CHAOS_IP_BIND_P, 16)) \
        ) \
        /**/
#    define CHAOS_PP_BIND_ID() CHAOS_PP_BIND
#    define CHAOS_PP_BIND_ CHAOS_PP_LAMBDA(CHAOS_PP_BIND_ID)()
#    define CHAOS_IP_BIND_P(n) CHAOS_PP_IS_NULLARY(CHAOS_IP_BIND_ ## n(, ()))
#    define CHAOS_IP_BIND_0(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_1(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_2(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_3(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_4(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_5(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_6(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_7(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_8(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_9(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_10(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_11(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_12(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_13(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_14(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_15(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_BIND_16(p, ...) p ## __VA_ARGS__
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
#    define CHAOS_PP_PREFIX(id) CHAOS_PP_ALTERNATE(id, CHAOS_PP_)
#    define CHAOS_PP_PREFIX_ID() CHAOS_PP_PREFIX
#    define CHAOS_PP_PREFIX_ CHAOS_PP_LAMBDA(CHAOS_PP_PREFIX_ID)()
# endif
#
# /* CHAOS_PP_ALTERNATE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ALTERNATE(id, pre) \
        CHAOS_PP_IIF_SHADOW( \
            CHAOS_PP_BITOR \
                (CHAOS_PP_IS_NULLARY(CHAOS_IP_BIND_0(, ()))) \
                (CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY(CHAOS_PP_EXTERN(, ())))) \
        )(id, pre ## id) \
        /**/
#    define CHAOS_PP_ALTERNATE_ID() CHAOS_PP_ALTERNATE
#    define CHAOS_PP_ALTERNATE_ CHAOS_PP_LAMBDA(CHAOS_PP_ALTERNATE)
# endif
#
# endif
