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
# ifndef CHAOS_PREPROCESSOR_RECURSION_PARAMETRIC_H
# define CHAOS_PREPROCESSOR_RECURSION_PARAMETRIC_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PARAMETRIC(id, size, ...) CHAOS_PP_PARAMETRIC_S(CHAOS_PP_STATE(), id, size, __VA_ARGS__)
#    define CHAOS_PP_PARAMETRIC_ID() CHAOS_PP_PARAMETRIC
#    define CHAOS_PP_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_PARAMETRIC_ID)()
# endif
#
# /* CHAOS_PP_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PARAMETRIC_S(s, id, size, ...) CHAOS_IP_PARAMETRIC_I(s, id, CHAOS_PP_BUFFER(s, size), __VA_ARGS__)
#    define CHAOS_PP_PARAMETRIC_S_ID() CHAOS_PP_PARAMETRIC_S
#    define CHAOS_PP_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_PARAMETRIC_S_ID)()
#    define CHAOS_IP_PARAMETRIC_I(s, id, buf, ...) \
        CHAOS_IP_PARAMETRIC_C(buf, CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(buf), s, id, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_PARAMETRIC_INDIRECT() CHAOS_IP_PARAMETRIC_A
#    define CHAOS_IP_PARAMETRIC_A(s, id, para, ...) CHAOS_IP_PARAMETRIC_B(CHAOS_PP_TUPLE_REM(?) para, s, id, __VA_ARGS__)
#    define CHAOS_IP_PARAMETRIC_B(...) CHAOS_IP_PARAMETRIC_C(__VA_ARGS__)
#    define CHAOS_IP_PARAMETRIC_C(buf, ...) \
        CHAOS_PP_IIF(CHAOS_PP_BITAND(CHAOS_PP_IS_VALID(buf))(CHAOS_PP_NOT_EQUAL(buf, CHAOS_PP_LIMIT_EXPR)))( \
            CHAOS_IP_PARAMETRIC_D, CHAOS_IP_PARAMETRIC_E \
        )(CHAOS_PP_OBSTRUCT, buf, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_PARAMETRIC_D(_, buf, o, shelf, s, id, ...) \
        id()(CHAOS_PP_NEXT(s), CHAOS_IP_PARAMETRIC_INDIRECT, (CHAOS_PP_NEXT(buf), o, shelf), __VA_ARGS__) \
        /**/
#    define CHAOS_IP_PARAMETRIC_E(_, buf, o, shelf, s, id, ...) \
        CHAOS_PP_EXPR_S _()(o)(id _()()(CHAOS_PP_NEXT(o), CHAOS_IP_PARAMETRIC_INDIRECT, (CHAOS_PP_NEXT(shelf), o, shelf), __VA_ARGS__)) \
        /**/
# endif
#
# endif
