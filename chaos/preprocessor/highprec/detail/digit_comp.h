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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_DIGIT_COMP_H
# define CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_DIGIT_COMP_H
#
# include <chaos/preprocessor/highprec/detail/digit.h>
#
# /* CHAOS_PP_DIGIT_COMP */
#
# define CHAOS_PP_DIGIT_COMP(a, b) \
    CHAOS_PP_DIGIT(a, CHAOS_PP_DIGIT(b, ( \
        (1, 0, 0, 0, 0, 0, 0, 0, 0, 0), \
        (2, 1, 0, 0, 0, 0, 0, 0, 0, 0), \
        (2, 2, 1, 0, 0, 0, 0, 0, 0, 0), \
        (2, 2, 2, 1, 0, 0, 0, 0, 0, 0), \
        (2, 2, 2, 2, 1, 0, 0, 0, 0, 0), \
        (2, 2, 2, 2, 2, 1, 0, 0, 0, 0), \
        (2, 2, 2, 2, 2, 2, 1, 0, 0, 0), \
        (2, 2, 2, 2, 2, 2, 2, 1, 0, 0), \
        (2, 2, 2, 2, 2, 2, 2, 2, 1, 0), \
        (2, 2, 2, 2, 2, 2, 2, 2, 2, 1) \
    ))) \
    /**/
#
# endif
