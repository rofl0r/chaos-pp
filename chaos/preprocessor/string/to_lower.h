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
# ifndef CHAOS_PREPROCESSOR_STRING_TO_LOWER_H
# define CHAOS_PREPROCESSOR_STRING_TO_LOWER_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/string/spec.h>
#
# /* CHAOS_PP_TO_LOWER */
#
# define CHAOS_PP_TO_LOWER(c) CHAOS_PP_SPLIT(0, CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TO_LOWER_, c))
# define CHAOS_PP_TO_LOWER_ID() CHAOS_PP_TO_LOWER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TO_LOWER_ CHAOS_PP_LAMBDA(CHAOS_PP_TO_LOWER_ID)()
# endif
#
# define CHAOS_IP_TO_LOWER__ _, _
# define CHAOS_IP_TO_LOWER_0 0, 0
# define CHAOS_IP_TO_LOWER_1 1, 1
# define CHAOS_IP_TO_LOWER_2 2, 2
# define CHAOS_IP_TO_LOWER_3 3, 3
# define CHAOS_IP_TO_LOWER_4 4, 4
# define CHAOS_IP_TO_LOWER_5 5, 5
# define CHAOS_IP_TO_LOWER_6 6, 6
# define CHAOS_IP_TO_LOWER_7 7, 7
# define CHAOS_IP_TO_LOWER_8 8, 8
# define CHAOS_IP_TO_LOWER_9 9, 9
# define CHAOS_IP_TO_LOWER_a a, A
# define CHAOS_IP_TO_LOWER_b b, B
# define CHAOS_IP_TO_LOWER_c c, C
# define CHAOS_IP_TO_LOWER_d d, D
# define CHAOS_IP_TO_LOWER_e e, E
# define CHAOS_IP_TO_LOWER_f f, F
# define CHAOS_IP_TO_LOWER_g g, G
# define CHAOS_IP_TO_LOWER_h h, H
# define CHAOS_IP_TO_LOWER_i i, I
# define CHAOS_IP_TO_LOWER_j j, J
# define CHAOS_IP_TO_LOWER_k k, K
# define CHAOS_IP_TO_LOWER_l l, L
# define CHAOS_IP_TO_LOWER_m m, M
# define CHAOS_IP_TO_LOWER_n n, N
# define CHAOS_IP_TO_LOWER_o o, O
# define CHAOS_IP_TO_LOWER_p p, P
# define CHAOS_IP_TO_LOWER_q q, Q
# define CHAOS_IP_TO_LOWER_r r, R
# define CHAOS_IP_TO_LOWER_s s, S
# define CHAOS_IP_TO_LOWER_t t, T
# define CHAOS_IP_TO_LOWER_u u, U
# define CHAOS_IP_TO_LOWER_v v, V
# define CHAOS_IP_TO_LOWER_w w, W
# define CHAOS_IP_TO_LOWER_x x, X
# define CHAOS_IP_TO_LOWER_y y, Y
# define CHAOS_IP_TO_LOWER_z z, Z
# define CHAOS_IP_TO_LOWER_A a, A
# define CHAOS_IP_TO_LOWER_B b, B
# define CHAOS_IP_TO_LOWER_C c, C
# define CHAOS_IP_TO_LOWER_D d, D
# define CHAOS_IP_TO_LOWER_E e, E
# define CHAOS_IP_TO_LOWER_F f, F
# define CHAOS_IP_TO_LOWER_G g, G
# define CHAOS_IP_TO_LOWER_H h, H
# define CHAOS_IP_TO_LOWER_I i, I
# define CHAOS_IP_TO_LOWER_J j, J
# define CHAOS_IP_TO_LOWER_K k, K
# define CHAOS_IP_TO_LOWER_L l, L
# define CHAOS_IP_TO_LOWER_M m, M
# define CHAOS_IP_TO_LOWER_N n, N
# define CHAOS_IP_TO_LOWER_O o, O
# define CHAOS_IP_TO_LOWER_P p, P
# define CHAOS_IP_TO_LOWER_Q q, Q
# define CHAOS_IP_TO_LOWER_R r, R
# define CHAOS_IP_TO_LOWER_S s, S
# define CHAOS_IP_TO_LOWER_T t, T
# define CHAOS_IP_TO_LOWER_U u, U
# define CHAOS_IP_TO_LOWER_V v, V
# define CHAOS_IP_TO_LOWER_W w, W
# define CHAOS_IP_TO_LOWER_X x, X
# define CHAOS_IP_TO_LOWER_Y y, Y
# define CHAOS_IP_TO_LOWER_Z z, Z
#
# /* CHAOS_PP_STRING_TO_LOWER */
#
# define CHAOS_PP_STRING_TO_LOWER(string) CHAOS_PP_STRING_TO_LOWER_BYPASS(CHAOS_PP_LIMIT_EXPR, string)
# define CHAOS_PP_STRING_TO_LOWER_ID() CHAOS_PP_STRING_TO_LOWER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_TO_LOWER_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_TO_LOWER_ID)()
# endif
#
# /* CHAOS_PP_STRING_TO_LOWER_BYPASS */
#
# define CHAOS_PP_STRING_TO_LOWER_BYPASS(s, string) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_STRING_TO_LOWER_I( \
        CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), string \
    )) \
    /**/
# define CHAOS_PP_STRING_TO_LOWER_BYPASS_ID() CHAOS_PP_STRING_TO_LOWER_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_TO_LOWER_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_TO_LOWER_BYPASS_ID)()
# endif
#
# define CHAOS_IP_STRING_TO_LOWER_INDIRECT() CHAOS_IP_STRING_TO_LOWER_I
# define CHAOS_IP_STRING_TO_LOWER_I(_, s, string) \
    CHAOS_PP_INLINE_WHEN _(CHAOS_PP_STRING_IS_CONS(string))( \
        CHAOS_PP_TO_LOWER _(CHAOS_PP_STRING_FIRST _(string)) \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_STRING_TO_LOWER_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_STRING_REST _(string) \
        )) \
    ) \
    /**/
#
# endif
