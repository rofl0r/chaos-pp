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
# ifndef CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_H
# define CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/parametric.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_DELINEATE_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_PARAMETRIC(size, count, sep, ...) CHAOS_PP_DELINEATE_PARAMETRIC_S(CHAOS_PP_STATE(), size, count, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_PARAMETRIC_ID() CHAOS_PP_DELINEATE_PARAMETRIC
#    define CHAOS_PP_DELINEATE_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_PARAMETRIC_ID)()
# endif
#
# /* CHAOS_PP_DELINEATE_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_PARAMETRIC_S(s, size, count, sep, ...) \
        CHAOS_IP_DELINEATE_PARAMETRIC_I(s, size, count, sep, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_EXPOSE(CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__))) \
        /**/
#    define CHAOS_PP_DELINEATE_PARAMETRIC_S_ID() CHAOS_PP_DELINEATE_PARAMETRIC_S
#    define CHAOS_PP_DELINEATE_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_PARAMETRIC_S_ID)()
#    define CHAOS_IP_DELINEATE_PARAMETRIC_I(s, size, count, sep, macro, im) \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_PARAMETRIC_S( \
            s, CHAOS_IP_DELINEATE_PARAMETRIC_INDIRECT, size, \
            CHAOS_PP_NEXT(s), count, CHAOS_PP_EMPTY, sep, macro, CHAOS_PP_TRAMPOLINE(macro), im \
        )) \
        /**/
#    define CHAOS_IP_DELINEATE_PARAMETRIC_INDIRECT() CHAOS_IP_DELINEATE_PARAMETRIC_II
#    define CHAOS_IP_DELINEATE_PARAMETRIC_II(s, id, para, o, count, s1, s2, macro, _m, ...) \
        CHAOS_PP_IF(count)( \
            CHAOS_IP_DELINEATE_PARAMETRIC_III, CHAOS_PP_TUPLE_EAT(?) \
        )(CHAOS_PP_OBSTRUCT(), s, id, para, o, CHAOS_PP_DEC(count), s1, s2, macro, _m, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_DELINEATE_PARAMETRIC_III(_, s, id, para, o, count, s1, s2, macro, _m, ...) \
        CHAOS_PP_EXPR_S(s) _(id _()( \
            s, CHAOS_IP_DELINEATE_PARAMETRIC_INDIRECT, para, o, count, s2, s2, macro, _m, __VA_ARGS__ \
        )) \
        _m()(o, macro, count __VA_ARGS__) s1() \
        /**/
# endif
#
# endif
