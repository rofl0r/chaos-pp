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
# ifndef CHAOS_PREPROCESSOR_STRING_CORE_H
# define CHAOS_PREPROCESSOR_STRING_CORE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_unless.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_empty.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_STRING */
#
# define CHAOS_PP_STRING CHAOS_PP_STRING
#
# /* CHAOS_PP_STRING_TAG */
#
# define CHAOS_PP_STRING_TAG(tag) tag
# define CHAOS_PP_STRING_TAG_ID() CHAOS_PP_STRING_TAG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_TAG_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_TAG)
# endif
#
# /* CHAOS_PP_STRING_NIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_NIL()
#    define CHAOS_PP_STRING_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_NIL)
# else
#    define CHAOS_PP_STRING_NIL() ()
# endif
#
# define CHAOS_PP_STRING_NIL_ID() CHAOS_PP_STRING_NIL
#
# /* CHAOS_PP_STRING_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_CONS(string, x) x string
#    define CHAOS_PP_STRING_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_CONS_ID)()
# else
#    define CHAOS_PP_STRING_CONS(string, x) x CHAOS_PP_INLINE_WHEN(CHAOS_PP_STRING_IS_NIL(string))(CHAOS_PP_EMPTY) string
# endif
#
# define CHAOS_PP_STRING_CONS_ID() CHAOS_PP_STRING_CONS
#
# /* CHAOS_PP_STRING_ITEM */
#
# define CHAOS_PP_STRING_ITEM(x) x
# define CHAOS_PP_STRING_ITEM_ID() CHAOS_PP_STRING_ITEM
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_ITEM_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_ITEM_ID)()
# endif
#
# /* CHAOS_PP_STRING_HEAD */
#
# define CHAOS_PP_STRING_HEAD(string) \
    CHAOS_PP_SPLIT( \
        0, CHAOS_PP_EXPAND( \
            CHAOS_IP_STRING_HEAD_I CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_STRING_, string) \
        ) \
    ) \
    /**/
# define CHAOS_PP_STRING_HEAD_ID() CHAOS_PP_STRING_HEAD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_HEAD_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_HEAD_ID)()
# endif
#
# define CHAOS_IP_STRING_HEAD_I(x) x, ~
#
# /* CHAOS_PP_STRING_TAIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_TAIL(string) \
        CHAOS_PP_SPLIT( \
            1, CHAOS_PP_EXPAND( \
                CHAOS_IP_STRING_TAIL_I CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_STRING_, string) \
            ) \
        ) \
        /**/
#    define CHAOS_PP_STRING_TAIL_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_TAIL_ID)()
# else
#    define CHAOS_PP_STRING_TAIL(string) \
        CHAOS_IP_STRING_TAIL_II(CHAOS_PP_SPLIT( \
            1, CHAOS_PP_EXPAND( \
                CHAOS_IP_STRING_TAIL_I CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_STRING_, string) \
            ) \
        )) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_STRING_TAIL_I(x) x,
# else
#    define CHAOS_IP_STRING_TAIL_I(x) x, ()
#    define CHAOS_IP_STRING_TAIL_II(r) \
        CHAOS_PP_INLINE_UNLESS(CHAOS_PP_IS_EMPTY(CHAOS_PP_EMPTY r))( \
            CHAOS_PP_EMPTY \
        ) r \
        /**/
# endif
#
# /* CHAOS_PP_STRING_IS_CONS */
#
# define CHAOS_PP_STRING_IS_CONS(string) CHAOS_PP_COMPL(CHAOS_PP_STRING_IS_NIL(string))
# define CHAOS_PP_STRING_IS_CONS_ID() CHAOS_PP_STRING_IS_CONS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_IS_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_IS_CONS)
# endif
#
# /* CHAOS_PP_STRING_IS_NIL */
#
# define CHAOS_PP_STRING_IS_NIL(string) CHAOS_PP_IS_NULLARY(string())
# define CHAOS_PP_STRING_IS_NIL_ID() CHAOS_PP_STRING_IS_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_IS_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_IS_NIL)
# endif
#
# define CHAOS_IP_STRING__ (_)
# define CHAOS_IP_STRING_0 (0)
# define CHAOS_IP_STRING_1 (1)
# define CHAOS_IP_STRING_2 (2)
# define CHAOS_IP_STRING_3 (3)
# define CHAOS_IP_STRING_4 (4)
# define CHAOS_IP_STRING_5 (5)
# define CHAOS_IP_STRING_6 (6)
# define CHAOS_IP_STRING_7 (7)
# define CHAOS_IP_STRING_8 (8)
# define CHAOS_IP_STRING_9 (9)
# define CHAOS_IP_STRING_a (a)
# define CHAOS_IP_STRING_b (b)
# define CHAOS_IP_STRING_c (c)
# define CHAOS_IP_STRING_d (d)
# define CHAOS_IP_STRING_e (e)
# define CHAOS_IP_STRING_f (f)
# define CHAOS_IP_STRING_g (g)
# define CHAOS_IP_STRING_h (h)
# define CHAOS_IP_STRING_i (i)
# define CHAOS_IP_STRING_j (j)
# define CHAOS_IP_STRING_k (k)
# define CHAOS_IP_STRING_l (l)
# define CHAOS_IP_STRING_m (m)
# define CHAOS_IP_STRING_n (n)
# define CHAOS_IP_STRING_o (o)
# define CHAOS_IP_STRING_p (p)
# define CHAOS_IP_STRING_q (q)
# define CHAOS_IP_STRING_r (r)
# define CHAOS_IP_STRING_s (s)
# define CHAOS_IP_STRING_t (t)
# define CHAOS_IP_STRING_u (u)
# define CHAOS_IP_STRING_v (v)
# define CHAOS_IP_STRING_w (w)
# define CHAOS_IP_STRING_x (x)
# define CHAOS_IP_STRING_y (y)
# define CHAOS_IP_STRING_z (z)
# define CHAOS_IP_STRING_A (A)
# define CHAOS_IP_STRING_B (B)
# define CHAOS_IP_STRING_C (C)
# define CHAOS_IP_STRING_D (D)
# define CHAOS_IP_STRING_E (E)
# define CHAOS_IP_STRING_F (F)
# define CHAOS_IP_STRING_G (G)
# define CHAOS_IP_STRING_H (H)
# define CHAOS_IP_STRING_I (I)
# define CHAOS_IP_STRING_J (J)
# define CHAOS_IP_STRING_K (K)
# define CHAOS_IP_STRING_L (L)
# define CHAOS_IP_STRING_M (M)
# define CHAOS_IP_STRING_N (N)
# define CHAOS_IP_STRING_O (O)
# define CHAOS_IP_STRING_P (P)
# define CHAOS_IP_STRING_Q (Q)
# define CHAOS_IP_STRING_R (R)
# define CHAOS_IP_STRING_S (S)
# define CHAOS_IP_STRING_T (T)
# define CHAOS_IP_STRING_U (U)
# define CHAOS_IP_STRING_V (V)
# define CHAOS_IP_STRING_W (W)
# define CHAOS_IP_STRING_X (X)
# define CHAOS_IP_STRING_Y (Y)
# define CHAOS_IP_STRING_Z (Z)
#
# endif
