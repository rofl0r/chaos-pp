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

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:whitespace="/pp-book/whitespace.xsl">

	<xsl:variable name="whitespace:horizontal-tab">
		<xsl:text>	</xsl:text>
	</xsl:variable>

	<xsl:variable name="whitespace:newline">
<xsl:text>
</xsl:text>
	</xsl:variable>

	<xsl:template name="whitespace:clean">
		<xsl:param name="text"/>
		<xsl:variable name="sans-horizontal-tabs" select="translate(., $whitespace:horizontal-tab, '')"/>
		<xsl:variable name="sans-leading-newlines">
			<xsl:choose>
				<xsl:when test="count(preceding-sibling::node()) - count(preceding-sibling::comment())">
					<xsl:value-of select="$sans-horizontal-tabs"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:call-template name="whitespace:remove-leading-newlines">
						<xsl:with-param name="text" select="$sans-horizontal-tabs"/>
					</xsl:call-template>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>
		<xsl:choose>
			<xsl:when test="count(following-sibling::node()) - count(following-sibling::comment())">
				<xsl:value-of select="$sans-leading-newlines"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:call-template name="whitespace:remove-trailing-whitespace">
					<xsl:with-param name="text" select="$sans-leading-newlines"/>
				</xsl:call-template>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template name="whitespace:remove-leading-newlines">
		<xsl:param name="text"/>
		<xsl:choose>
			<xsl:when test="starts-with($text, '&#xa;') or starts-with($text, '&#xd;')">
				<xsl:call-template name="whitespace:remove-leading-newlines">
					<xsl:with-param name="text" select="substring($text, 2)"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:when test="starts-with($text, $whitespace:newline)">
				<xsl:call-template name="whitespace:remove-leading-newlines">
					<xsl:with-param name="text" select="substring($text, string-length($whitespace:newline) + 1)"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$text"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template name="whitespace:remove-trailing-whitespace">
		<xsl:param name="text"/>
		<xsl:variable name="double" select="substring($text, string-length($text) - 1)"/>
		<xsl:variable name="single" select="substring($double, 2)"/>
		<xsl:choose>
			<xsl:when test="$double = $whitespace:newline">
				<xsl:call-template name="whitespace:remove-trailing-whitespace">
					<xsl:with-param name="text" select="substring($text, 1, string-length(text) - 2)"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:when test="$single = ' ' or $single = $whitespace:horizontal-tab or $single = $whitespace:newline or $single = '&#xa;' or $single = '&#xd;'">
				<xsl:call-template name="whitespace:remove-trailing-whitespace">
					<xsl:with-param name="text" select="substring($text, 1, string-length($text) - 1)"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$text"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

</xsl:stylesheet>
