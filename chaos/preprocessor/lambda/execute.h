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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_EXECUTE_H
# define CHAOS_PREPROCESSOR_LAMBDA_EXECUTE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_ELEMENT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ELEMENT(...) (1, __VA_ARGS__ CHAOS_PP_EMPTY)()
#    define CHAOS_PP_ELEMENT_ CHAOS_PP_LAMBDA(CHAOS_PP_ELEMENT_ID)()
# else
#    define CHAOS_PP_ELEMENT(x) (1, x CHAOS_PP_EMPTY)()
# endif
#
# /* CHAOS_PP_OPERATOR */
#
# define CHAOS_PP_OPERATOR(op) (1, op)()
# define CHAOS_PP_OPERATOR_ID() CHAOS_PP_OPERATOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_OPERATOR_ CHAOS_PP_LAMBDA(CHAOS_PP_OPERATOR)
# endif
#
# /* CHAOS_PP_EXECUTE */
#
# define CHAOS_PP_EXECUTE(il) CHAOS_IP_EXECUTE_I il(0, ~)
# define CHAOS_PP_EXECUTE_ID() CHAOS_PP_EXECUTE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EXECUTE_ CHAOS_PP_LAMBDA(CHAOS_PP_EXECUTE_ID)()
# endif
#
# define CHAOS_IP_EXECUTE_INDIRECT() CHAOS_IP_EXECUTE_I
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_EXECUTE_I(bit, ...) CHAOS_PP_IIF(bit)(CHAOS_IP_EXECUTE_II, CHAOS_PP_TUPLE_EAT(?))(__VA_ARGS__)
#    define CHAOS_IP_EXECUTE_II(...) __VA_ARGS__() CHAOS_IP_EXECUTE_INDIRECT
# else
#    define CHAOS_IP_EXECUTE_I(bit, x) CHAOS_PP_IIF(bit)(CHAOS_IP_EXECUTE_II, CHAOS_PP_TUPLE_EAT(1))(x)
#    define CHAOS_IP_EXECUTE_II(x) x() CHAOS_IP_EXECUTE_INDIRECT
# endif
#
# endif
