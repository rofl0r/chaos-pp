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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_DEFAULT_H
# define CHAOS_PREPROCESSOR_FACILITIES_DEFAULT_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_DEFAULT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DEFAULT(def, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_OPTIONAL(__VA_ARGS__))( \
            def, CHAOS_PP_NON_OPTIONAL(CHAOS_PP_OPTIONAL(__VA_ARGS__)) \
        ) \
        /**/
#    define CHAOS_PP_DEFAULT_ID() CHAOS_PP_DEFAULT
#    define CHAOS_PP_DEFAULT_ CHAOS_PP_LAMBDA(CHAOS_PP_DEFAULT_ID)()
# endif
#
# /* CHAOS_PP_DEFAULT_AT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DEFAULT_AT(i, def, ...) CHAOS_PP_DEFAULT_AT_BYPASS(CHAOS_PP_LIMIT_EXPR, i, def, __VA_ARGS__)
#    define CHAOS_PP_DEFAULT_AT_ID() CHAOS_PP_DEFAULT_AT
#    define CHAOS_PP_DEFAULT_AT_ CHAOS_PP_LAMBDA(CHAOS_PP_DEFAULT_AT_ID)()
# endif
#
# /* CHAOS_PP_DEFAULT_AT_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DEFAULT_AT_BYPASS(s, i, def, ...) \
        CHAOS_PP_IF(i)( \
            CHAOS_PP_EXPR_S(s)(CHAOS_IP_DEFAULT_AT_I( \
                CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), CHAOS_PP_DEC(i), def, __VA_ARGS__ \
            )), \
            CHAOS_PP_NON_OPTIONAL(__VA_ARGS__) \
        ) \
        /**/
#    define CHAOS_PP_DEFAULT_AT_BYPASS_ID() CHAOS_PP_DEFAULT_AT_BYPASS
#    define CHAOS_PP_DEFAULT_AT_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_DEFAULT_AT_BYPASS_ID)()
#    define CHAOS_IP_DEFAULT_AT_INDIRECT() CHAOS_IP_DEFAULT_AT_I
#    define CHAOS_IP_DEFAULT_AT_I(_, s, i, def, ...) \
        CHAOS_PP_IF _(i)( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_DEFAULT_AT_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_DEC(i), def, CHAOS_PP_OPTIONAL _(__VA_ARGS__) \
            )), \
            CHAOS_PP_DEFAULT _(def, __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
