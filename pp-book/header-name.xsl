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

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:header-name="/pp-book/header-name.xsl">

	<xsl:template name="header-name:format">
		<xsl:param name="file"/>
		<xsl:variable name="type" select="document('.library.xml')/library/@header-name-format"/>
		<xsl:choose>
			<xsl:when test="$type = 'h-char-sequence'">
				<xsl:text>&lt;</xsl:text><xsl:value-of select="$file"/><xsl:text>&gt;</xsl:text>
			</xsl:when>
			<xsl:when test="$type = 'q-char-sequence'">
				<xsl:text>"</xsl:text><xsl:value-of select="$file"/><xsl:text>"</xsl:text>
			</xsl:when>
			<xsl:otherwise>
				<xsl:message terminate="yes">Error: Unrecognized Header-Name Format</xsl:message>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

</xsl:stylesheet>
