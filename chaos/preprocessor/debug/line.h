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
# ifndef CHAOS_PREPROCESSOR_DEBUG_LINE_H
# define CHAOS_PREPROCESSOR_DEBUG_LINE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/iteration/file.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/stringize.h>
#
# /* CHAOS_PP_LINE */
#
# define CHAOS_PP_LINE(line, file) \
    line CHAOS_PP_CAT_SHADOW(CHAOS_IP_LINE_, CHAOS_PP_ITERATION_DEPTH())(file, CHAOS_PP_FRAME_ITERATION) \
    /**/
# define CHAOS_PP_LINE_ID() CHAOS_PP_LINE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LINE_ CHAOS_PP_LAMBDA(CHAOS_PP_LINE)
# endif
#
# define CHAOS_IP_LINE_0(file, i) CHAOS_PP_PRIMITIVE_STRINGIZE(file)
# define CHAOS_IP_LINE_1(file, i) CHAOS_PP_STRINGIZE(file[i(1)])
# define CHAOS_IP_LINE_2(file, i) CHAOS_PP_STRINGIZE(file[i(1)][i(2)])
# define CHAOS_IP_LINE_3(file, i) CHAOS_PP_STRINGIZE(file[i(1)][i(2)][i(3)])
# define CHAOS_IP_LINE_4(file, i) CHAOS_PP_STRINGIZE(file[i(1)][i(2)][i(3)][i(4)])
# define CHAOS_IP_LINE_5(file, i) CHAOS_PP_STRINGIZE(file[i(1)][i(2)][i(3)][i(4)][i(5)])
#
# endif
