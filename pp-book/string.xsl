<?xml version="1.0" encoding="UTF-8"?>

<!-- **************************************************************************
     *                                                                        *
     *    (C) Copyright Paul Mensonides 2003-2005.                            *
     *                                                                        *
     *    Distributed under the Boost Software License, Version 1.0.          *
     *    (See accompanying file LICENSE).                                    *
     *                                                                        *
     *    See http://chaos-pp.sourceforge.net for the most recent version.    *
     *                                                                        *
     ************************************************************************** -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:string="/pp-book/string.xsl">

	<xsl:template name="string:capitalize">
		<xsl:param name="text"/>
		<xsl:value-of select="concat(translate(substring($text, 1, 1), 'abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'), substring($text, 2))"/>
	</xsl:template>

</xsl:stylesheet>
