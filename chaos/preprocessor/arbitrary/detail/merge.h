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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_MERGE_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_MERGE_H
#
# include <chaos/preprocessor/arbitrary/detail/is_shorter.h>
# include <chaos/preprocessor/arbitrary/detail/namespace.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/machine.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/seq/detail/close.h>
# include <chaos/preprocessor/seq/reverse.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xMERGE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xMERGE(s, p, x, y, op, def, dir, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xIS_SHORTER)), p ## x, p ## y, 0xCHAOS(0xARBITRARY(0xMERGE2)), p ## x, p ## y, op, def, dir, k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xMERGE2(s, p, bit, x, y, op, def, dir, k, ...) \
        (, k, CHAOS_IP_MERGE_AP_ ## bit(, p ## x, p ## y, op, def, dir), p ## __VA_ARGS__) \
        /**/
#    define CHAOS_IP_MERGE_AP_0(p, x, y, op, def, dir) CHAOS_IP_MERGE_AP_I(, CHAOS_PP_SEQ_BINARY_TRANSFORM(p ## x,), p ## y,, op, def, dir)
#    define CHAOS_IP_MERGE_AP_1(p, x, y, op, def, dir) CHAOS_IP_MERGE_AP_I(, CHAOS_PP_SEQ_BINARY_TRANSFORM(p ## y,), p ## x, CHAOS_IP_MERGE_AP_S, op, def, dir)
#    define CHAOS_IP_MERGE_AP_S(a, b) (b, a)
#    define CHAOS_IP_MERGE_AP_F(res, x) res x
#    define CHAOS_IP_MERGE_AP_R(res, x) x res
#    define CHAOS_IP_MERGE_AP_I(p, seq, z, swap, op, def, dir) \
        CHAOS_PP_EXPAND(CHAOS_PP_EAT CHAOS_PP_SPLIT( \
            0, \
            CHAOS_PP_EXPAND( \
                CHAOS_IP_MERGE_AP_II seq, CHAOS_PP_SEQ_REVERSE(p ## z)(def), swap, op, def, CHAOS_PP_IIF(dir)(CHAOS_IP_MERGE_AP_F, CHAOS_IP_MERGE_AP_R) \
                CHAOS_PP_SEQ_CLOSE(seq) \
            ) \
        )) \
        /**/
#    define CHAOS_IP_MERGE_AP_INDIRECT() CHAOS_IP_MERGE_AP_II
#    define CHAOS_IP_MERGE_AP_II(id, n) id(?)(CHAOS_PP_OBSTRUCT(CHAOS_IP_MERGE_AP_III) CHAOS_PP_LPAREN() n, CHAOS_IP_MERGE_AP_INDIRECT)
#    define CHAOS_IP_MERGE_AP_III(...) CHAOS_IP_MERGE_AP_IV(__VA_ARGS__)
#    define CHAOS_IP_MERGE_AP_IV(n, res, z, swap, op, def, dir) \
        dir(res, (op) swap(n, CHAOS_PP_SEQ_FIRST(z))), CHAOS_PP_SEQ_REST(z)(def), swap, op, def, dir \
        /**/
# endif
#
# endif
