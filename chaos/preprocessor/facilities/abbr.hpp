# /* (C) Copyright Paul Mensonides 2003 */
#
# ifndef CHAOS_PREPROCESSOR_FACILITIES_ABBR_HPP
# define CHAOS_PREPROCESSOR_FACILITIES_ABBR_HPP
#
# include <chaos/preprocessor/config.hpp>
# include <chaos/preprocessor/lambda/ops.hpp>
#
# /* CHAOS_PP_ABBR */
#
# define CHAOS_PP_ABBR(id) CHAOS_PP_ ## id
# define CHAOS_PP_ABBR_ID() CHAOS_PP_ABBR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ABBR_ CHAOS_PP_LAMBDA(CHAOS_PP_ABBR)
# endif
#
# endif
