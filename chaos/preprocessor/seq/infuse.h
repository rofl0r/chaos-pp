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
# ifndef CHAOS_PREPROCESSOR_SEQ_INFUSE_H
# define CHAOS_PREPROCESSOR_SEQ_INFUSE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/detail/close.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_SEQ_INFUSE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_INFUSE(seq, ...) \
        CHAOS_PP_SPLIT(0, CHAOS_PP_EXPAND( \
            CHAOS_IP_SEQ_INFUSE_I(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq,), __VA_ARGS__) \
        )) \
        /**/
#    define CHAOS_PP_SEQ_INFUSE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_INFUSE_ID)()
#    define CHAOS_IP_SEQ_INFUSE_I(bin, ...) CHAOS_IP_SEQ_INFUSE_A bin, __VA_ARGS__ CHAOS_PP_SEQ_CLOSE(bin)
#    define CHAOS_IP_SEQ_INFUSE_A(m, ...) m(?)(CHAOS_IP_SEQ_INFUSE_B CHAOS_PP_DEFER(CHAOS_PP_LPAREN)()(__VA_ARGS__), CHAOS_IP_SEQ_INFUSE_A_ID)
#    define CHAOS_IP_SEQ_INFUSE_B(...) CHAOS_IP_SEQ_INFUSE_C(__VA_ARGS__)
#    define CHAOS_IP_SEQ_INFUSE_C(x, res, ...) (__VA_ARGS__, CHAOS_PP_TUPLE_REM(?) x)() res, __VA_ARGS__
# else
#    define CHAOS_PP_SEQ_INFUSE(seq, data) \
        CHAOS_PP_SPLIT(0, CHAOS_PP_EXPAND( \
            CHAOS_IP_SEQ_INFUSE_I(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~), data) \
        ))() \
        /**/
#    define CHAOS_IP_SEQ_INFUSE_I(bin, data) CHAOS_IP_SEQ_INFUSE_A bin CHAOS_PP_EMPTY CHAOS_PP_DEFER(CHAOS_PP_COMMA)() data CHAOS_PP_SEQ_CLOSE(bin)
#    define CHAOS_IP_SEQ_INFUSE_A(m, x) m(2)(CHAOS_IP_SEQ_INFUSE_B CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() x, CHAOS_IP_SEQ_INFUSE_A_ID)
#    define CHAOS_IP_SEQ_INFUSE_B(x, im) CHAOS_IP_SEQ_INFUSE_C(x, im)
#    define CHAOS_IP_SEQ_INFUSE_C(x, res, data) (data, x)() res, data
# endif
#
# define CHAOS_PP_SEQ_INFUSE_ID() CHAOS_PP_SEQ_INFUSE
#
# define CHAOS_IP_SEQ_INFUSE_A_ID() CHAOS_IP_SEQ_INFUSE_A
#
# endif
