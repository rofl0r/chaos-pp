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
# ifndef CHAOS_PREPROCESSOR_TUPLE_FOR_EACH_I_H
# define CHAOS_PREPROCESSOR_TUPLE_FOR_EACH_I_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TUPLE_FOR_EACH_I */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_FOR_EACH_I(macro, ...) CHAOS_PP_TUPLE_FOR_EACH_I_S(CHAOS_PP_STATE(), macro, __VA_ARGS__)
#    define CHAOS_PP_TUPLE_FOR_EACH_I_ID() CHAOS_PP_TUPLE_FOR_EACH_I
#    define CHAOS_PP_TUPLE_FOR_EACH_I_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_FOR_EACH_I_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_FOR_EACH_I_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_FOR_EACH_I_S(s, macro, ...) CHAOS_IP_TUPLE_FOR_EACH_I_I(s, macro, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__))
#    define CHAOS_PP_TUPLE_FOR_EACH_I_S_ID() CHAOS_PP_TUPLE_FOR_EACH_I_S
#    define CHAOS_PP_TUPLE_FOR_EACH_I_S_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_FOR_EACH_I_S_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_FOR_EACH_I_I(s, macro, tuple, pd) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_FOR_EACH_I_1( \
            CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), macro, CHAOS_PP_TRAMPOLINE(macro), tuple, 0, pd \
        )) \
        /**/
#    define CHAOS_IP_TUPLE_FOR_EACH_I_INDIRECT(n) CHAOS_IP_TUPLE_FOR_EACH_I_ ## n
#    define CHAOS_IP_TUPLE_FOR_EACH_I_1(s, o, macro, _m, tuple, n, pd) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_BATCH(10, tuple))( \
            CHAOS_IP_TUPLE_FOR_EACH_I_1_I, CHAOS_IP_TUPLE_FOR_EACH_I_2 \
        )(s, o, macro, _m, tuple, n, pd) \
        /**/
#    define CHAOS_IP_TUPLE_FOR_EACH_I_1_I(s, o, macro, _m, tuple, n, pd) \
        CHAOS_IP_TUPLE_FOR_EACH_I_1_II(s, o, macro, _m, CHAOS_PP_TUPLE_REM_CTOR(?, CHAOS_PP_TUPLE_BATCH(10, tuple)), CHAOS_PP_TUPLE_SANS_BATCH(10, tuple), n, pd) \
        /**/
#    define CHAOS_IP_TUPLE_FOR_EACH_I_1_II(...) CHAOS_IP_TUPLE_FOR_EACH_I_1_III(CHAOS_PP_OBSTRUCT(), __VA_ARGS__)
#    define CHAOS_IP_TUPLE_FOR_EACH_I_1_III(_, s, o, macro, _m, a, b, c, d, e, f, g, h, i, j, tuple, n, pd) \
        _m()(o, macro, n, a CHAOS_PP_EXPOSE(pd)) \
        _m()(o, macro, CHAOS_PP_INC(n), b CHAOS_PP_EXPOSE(pd)) \
        _m()(o, macro, CHAOS_PP_INC(CHAOS_PP_INC(n)), c CHAOS_PP_EXPOSE(pd)) \
        _m()(o, macro, CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(n))), d CHAOS_PP_EXPOSE(pd)) \
        _m()(o, macro, CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(n)))), e CHAOS_PP_EXPOSE(pd)) \
        _m()(o, macro, CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(n))))), f CHAOS_PP_EXPOSE(pd)) \
        _m()(o, macro, CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(n)))))), g CHAOS_PP_EXPOSE(pd)) \
        _m()(o, macro, CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(n))))))), h CHAOS_PP_EXPOSE(pd)) \
        _m()(o, macro, CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(n)))))))), i CHAOS_PP_EXPOSE(pd)) \
        _m()(o, macro, CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(n))))))))), j CHAOS_PP_EXPOSE(pd)) \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FOR_EACH_I_INDIRECT _(1)( \
            CHAOS_PP_NEXT(s), o, macro, _m, tuple, CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(CHAOS_PP_INC(n)))))))))), pd \
        )) \
        /**/
#    define CHAOS_IP_TUPLE_FOR_EACH_I_2(s, o, macro, _m, tuple, n, pd) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            CHAOS_IP_TUPLE_FOR_EACH_I_2_I, CHAOS_PP_EAT \
        )(CHAOS_PP_OBSTRUCT(), s, o, macro, _m, tuple, n, pd) \
        /**/
#    define CHAOS_IP_TUPLE_FOR_EACH_I_2_I(_, s, o, macro, _m, tuple, n, pd) \
        _m()(o, macro, n, CHAOS_PP_TUPLE_FIRST(tuple) CHAOS_PP_EXPOSE(pd)) \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FOR_EACH_I_INDIRECT _(2)( \
            CHAOS_PP_NEXT(s), o, macro, _m, CHAOS_PP_TUPLE_REST(tuple), CHAOS_PP_INC(n), pd \
        )) \
        /**/
# endif
#
# endif
