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
# include <chaos/preprocessor/arbitrary/detail/scan.h>
# include <chaos/preprocessor/arbitrary/detail/special.h>
# include <chaos/preprocessor/arbitrary/detail/swap.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/seq/reverse.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/elem.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_FMERGE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_FMERGE(x, y, op, def) \
        CHAOS_PP_SCAN(1)(CHAOS_PP_EAT CHAOS_PP_SPLIT( \
            0, \
            CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_IS_SHORTER(x, y))( \
                CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_FMERGE_A y(00), CHAOS_PP_SEQ_REVERSE(x), op, def, CHAOS_PP_SWAP CHAOS_PP_SPECIAL_CLOSE(y)), \
                CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_FMERGE_A x(00), CHAOS_PP_SEQ_REVERSE(y), op, def, CHAOS_PP_SPECIAL_CLOSE(x)) \
            ) \
        )) \
        /**/
# else
#    define CHAOS_PP_ARBITRARY_FMERGE(x, y, op, def) \
        CHAOS_PP_SCAN(1)(CHAOS_PP_EAT CHAOS_PP_TUPLE_ELEM( \
            5, 0, \
            (CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_IS_SHORTER(x, y))( \
                CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_FMERGE_A y(00) CHAOS_PP_DEFER(CHAOS_PP_TUPLE_REM)(5)(CHAOS_PP_EMPTY, CHAOS_PP_SEQ_REVERSE(x), op, def, CHAOS_PP_SWAP) CHAOS_PP_SPECIAL_CLOSE(y)), \
                CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_FMERGE_A x(00) CHAOS_PP_DEFER(CHAOS_PP_TUPLE_REM)(5)(CHAOS_PP_EMPTY, CHAOS_PP_SEQ_REVERSE(y), op, def, CHAOS_PP_NO_SWAP) CHAOS_PP_SPECIAL_CLOSE(x)) \
            )) \
        )()) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_ARBITRARY_FMERGE_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_FMERGE_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_ARBITRARY_FMERGE_B)
#    define CHAOS_IP_ARBITRARY_FMERGE_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_FMERGE_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_ARBITRARY_FMERGE_A)
#    define CHAOS_IP_ARBITRARY_FMERGE_I(...) CHAOS_IP_ARBITRARY_FMERGE_II(__VA_ARGS__)
#    define CHAOS_IP_ARBITRARY_FMERGE_II(digit, res, y, op, def, swap) \
        (op) swap(digit, CHAOS_PP_SEQ_HEAD(y)) res, CHAOS_PP_SEQ_TAIL(y(def)), op, def, swap \
        /**/
# else
#    define CHAOS_IP_ARBITRARY_FMERGE_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_FMERGE_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_ARBITRARY_FMERGE_B)
#    define CHAOS_IP_ARBITRARY_FMERGE_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_FMERGE_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_ARBITRARY_FMERGE_A)
#    define CHAOS_IP_ARBITRARY_FMERGE_I(digit, im) CHAOS_IP_ARBITRARY_FMERGE_II(digit, im)
#    define CHAOS_IP_ARBITRARY_FMERGE_II(digit, res, y, op, def, swap) \
        (op) swap(digit, CHAOS_PP_SEQ_HEAD(y)) res, CHAOS_PP_SEQ_TAIL(y(def)), op, def, swap \
        /**/
# endif
#
# /* CHAOS_PP_ARBITRARY_RMERGE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_RMERGE(x, y, op, def) \
        CHAOS_PP_SPLIT( \
            0, \
            CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_IS_SHORTER(x, y))( \
                CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_RMERGE_A y(00) CHAOS_PP_EAT, CHAOS_PP_SEQ_REVERSE(x), op, def, CHAOS_PP_SWAP CHAOS_PP_SPECIAL_CLOSE(y)), \
                CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_RMERGE_A x(00) CHAOS_PP_EAT, CHAOS_PP_SEQ_REVERSE(y), op, def, CHAOS_PP_SPECIAL_CLOSE(x)) \
            ) \
        ) \
        /**/
# else
#    define CHAOS_PP_ARBITRARY_RMERGE(x, y, op, def) \
        CHAOS_PP_TUPLE_ELEM( \
            5, 0, \
            (CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_IS_SHORTER(x, y))( \
                CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_RMERGE_A y(00) CHAOS_PP_DEFER(CHAOS_PP_TUPLE_REM)(5)(CHAOS_PP_EAT, CHAOS_PP_SEQ_REVERSE(x), op, def, CHAOS_PP_SWAP) CHAOS_PP_SPECIAL_CLOSE(y)), \
                CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_RMERGE_A x(00) CHAOS_PP_DEFER(CHAOS_PP_TUPLE_REM)(5)(CHAOS_PP_EAT, CHAOS_PP_SEQ_REVERSE(y), op, def, CHAOS_PP_NO_SWAP) CHAOS_PP_SPECIAL_CLOSE(x)) \
            )) \
        ) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_ARBITRARY_RMERGE_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_RMERGE_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_ARBITRARY_RMERGE_B)
#    define CHAOS_IP_ARBITRARY_RMERGE_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_RMERGE_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_ARBITRARY_RMERGE_A)
#    define CHAOS_IP_ARBITRARY_RMERGE_I(...) CHAOS_IP_ARBITRARY_RMERGE_II(__VA_ARGS__)
#    define CHAOS_IP_ARBITRARY_RMERGE_II(digit, res, y, op, def, swap) \
        res(op) swap(digit, CHAOS_PP_SEQ_HEAD(y)), CHAOS_PP_SEQ_TAIL(y(def)), op, def, swap \
        /**/
# else
#    define CHAOS_IP_ARBITRARY_RMERGE_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_RMERGE_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_ARBITRARY_RMERGE_B)
#    define CHAOS_IP_ARBITRARY_RMERGE_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_RMERGE_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_ARBITRARY_RMERGE_A)
#    define CHAOS_IP_ARBITRARY_RMERGE_I(digit, im) CHAOS_IP_ARBITRARY_RMERGE_II(digit, im)
#    define CHAOS_IP_ARBITRARY_RMERGE_II(digit, res, y, op, def, swap) \
        res(op) swap(digit, CHAOS_PP_SEQ_HEAD(y)), CHAOS_PP_SEQ_TAIL(y(def)), op, def, swap \
        /**/
# endif
#
# endif
