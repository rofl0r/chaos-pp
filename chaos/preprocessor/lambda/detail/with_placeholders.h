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
# ifdef CHAOS_PP_INCLUDE
# line 1 CHAOS_PP_INCLUDE
# undef CHAOS_PP_INCLUDE
#
# define CHAOS_PP_IS_WITH_PLACEHOLDERS 1
# include CHAOS_PP_PLACEHOLDERS(1)
# include __FILE__
# include CHAOS_PP_PLACEHOLDERS(0)
# undef CHAOS_PP_IS_WITH_PLACEHOLDERS
#
# endif
