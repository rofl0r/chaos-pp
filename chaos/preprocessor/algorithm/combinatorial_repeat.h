# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_COMBINATORIAL_REPEAT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_COMBINATORIAL_REPEAT_H
#
# include <chaos/preprocessor/algorithm/for_each_product.h>
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_COMBINATORIAL_REPEAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_COMBINATORIAL_REPEAT(count, macro, ...) CHAOS_PP_COMBINATORIAL_REPEAT_S(CHAOS_PP_STATE(), count, macro, __VA_ARGS__)
#    define CHAOS_PP_COMBINATORIAL_REPEAT_ID() CHAOS_PP_COMBINATORIAL_REPEAT
#    define CHAOS_PP_COMBINATORIAL_REPEAT_ CHAOS_PP_LAMBDA(CHAOS_PP_COMBINATORIAL_REPEAT_ID)()
# endif
#
# /* CHAOS_PP_COMBINATORIAL_REPEAT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_COMBINATORIAL_REPEAT_S(s, count, macro, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_COMBINATORIAL_REPEAT_I( \
            CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), count, 1, CHAOS_PP_CALL(macro), macro, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), (CHAOS_PP_NON_OPTIONAL(__VA_ARGS__)), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__) \
        )) \
        /**/
#    define CHAOS_PP_COMBINATORIAL_REPEAT_S_ID() CHAOS_PP_COMBINATORIAL_REPEAT_S
#    define CHAOS_PP_COMBINATORIAL_REPEAT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_COMBINATORIAL_REPEAT_S_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_COMBINATORIAL_REPEAT_INDIRECT() CHAOS_IP_COMBINATORIAL_REPEAT_I
#    define CHAOS_IP_COMBINATORIAL_REPEAT_I(s, o, count, ...) \
        CHAOS_PP_IF(count)( \
            CHAOS_IP_COMBINATORIAL_REPEAT_II, CHAOS_PP_EAT \
        )(CHAOS_PP_OBSTRUCT(), s, o, count, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_COMBINATORIAL_REPEAT_II(_, s, o, count, size, _m, macro, g, acc, pd) \
        CHAOS_PP_EXPR_S _(s)( \
            CHAOS_PP_FOR_EACH_PRODUCT_S _( \
                CHAOS_PP_NEXT(s), CHAOS_IP_COMBINATORIAL_REPEAT_III, acc, o, size, _m, macro, pd \
            ) \
            CHAOS_IP_COMBINATORIAL_REPEAT_INDIRECT _()( \
                CHAOS_PP_NEXT(s), o, CHAOS_PP_DEC(count), CHAOS_PP_INC(size), _m, macro, g, acc(g), pd \
            ) \
        ) \
        /**/
#    define CHAOS_IP_COMBINATORIAL_REPEAT_III(s, product, o, size, _m, macro, pd) \
        CHAOS_PP_OBSTRUCT(_m)()(o, macro, size, product CHAOS_PP_EXPOSE(pd)) \
        /**/
# endif
#
# endif
