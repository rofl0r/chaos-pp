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
# ifndef CHAOS_PREPROCESSOR_DETECTION_IS_EMPTY_H
# define CHAOS_PREPROCESSOR_DETECTION_IS_EMPTY_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IS_EMPTY */
#
# define CHAOS_PP_IS_EMPTY(id) \
    CHAOS_PP_IS_NULLARY(CHAOS_PP_PRIMITIVE_CAT_SHADOW(CHAOS_IP_IS_EMPTY_, id CHAOS_IP_IS_EMPTY_I)) \
    /**/
# define CHAOS_PP_IS_EMPTY_ID() CHAOS_PP_IS_EMPTY
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_EMPTY_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_EMPTY)
# endif
#
# define CHAOS_IP_IS_EMPTY_CHAOS_IP_IS_EMPTY_I ()
#
# /* CHAOS_PP_IS_EMPTY_NON_FUNCTION */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_EMPTY_NON_FUNCTION(...) \
        CHAOS_PP_IIF_SHADOW(CHAOS_PP_IS_VARIADIC(__VA_ARGS__))( \
            0, \
            CHAOS_PP_IS_NULLARY(CHAOS_IP_IS_EMPTY_NON_FUNCTION_C __VA_ARGS__ ()) \
        ) \
        /**/
#    define CHAOS_PP_IS_EMPTY_NON_FUNCTION_ID() CHAOS_PP_IS_EMPTY_NON_FUNCTION
#    define CHAOS_PP_IS_EMPTY_NON_FUNCTION_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_EMPTY_NON_FUNCTION)
#    define CHAOS_IP_IS_EMPTY_NON_FUNCTION_C() ()
# endif
#
# endif
