# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_REPEAT_FROM_TO_H
# define CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_REPEAT_FROM_TO_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/parametric.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC(size, from, to, ...) CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC_S(CHAOS_PP_STATE(), size, from, to, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC_ID() CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC
#    define CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC_S(s, size, from, to, ...) \
        CHAOS_IP_REPEAT_FROM_TO_PARAMETRIC_I(s, size, from, to, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_EXPOSE(CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__))) \
        /**/
#    define CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC_S_ID() CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC_S
#    define CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_FROM_TO_PARAMETRIC_S_ID)()
#    define CHAOS_IP_REPEAT_FROM_TO_PARAMETRIC_I(s, size, from, to, macro, im) \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_PARAMETRIC_S( \
            s, CHAOS_IP_REPEAT_FROM_TO_PARAMETRIC_INDIRECT, size, \
            CHAOS_PP_NEXT(s), from, to, macro, CHAOS_PP_TRAMPOLINE(macro), im \
        )) \
        /**/
#    define CHAOS_IP_REPEAT_FROM_TO_PARAMETRIC_INDIRECT() CHAOS_IP_REPEAT_FROM_TO_PARAMETRIC_II
#    define CHAOS_IP_REPEAT_FROM_TO_PARAMETRIC_II(s, id, para, o, from, to, macro, _m, ...) \
        CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(from, to))( \
            CHAOS_IP_REPEAT_FROM_TO_PARAMETRIC_III, CHAOS_PP_TUPLE_EAT(?) \
        )(CHAOS_PP_OBSTRUCT(), s, id, para, o, from, CHAOS_PP_DEC(to), macro, _m, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_REPEAT_FROM_TO_PARAMETRIC_III(_, s, id, para, o, from, to, macro, _m, ...) \
        CHAOS_PP_EXPR_S(s) _(id _()( \
            s, CHAOS_IP_REPEAT_FROM_TO_PARAMETRIC_INDIRECT, para, o, from, to, macro, _m, __VA_ARGS__ \
        )) \
        _m()(o, macro, to __VA_ARGS__) \
        /**/
# endif
#
# endif
