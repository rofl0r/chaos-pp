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

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:meta="λ" xmlns:header-name="/pp-book/header-name.xsl" xmlns:string="/pp-book/string.xsl">

	<xsl:import href="header-name.xsl"/>
	<xsl:import href="string.xsl"/>

	<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
	<xsl:namespace-alias stylesheet-prefix="meta" result-prefix="xsl"/>

	<xsl:template match="/library">
		<meta:stylesheet version="1.0">
			<meta:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>
			<xsl:for-each select="header">
				<meta:template match="{translate(@name, '/', '-')}">
					<code><a href="{{$root}}/{substring-before(@name, '.')}.html" class="header"><xsl:call-template name="header-name:format"><xsl:with-param name="file" select="@name"/></xsl:call-template></a></code>
				</meta:template>
			</xsl:for-each>
			<xsl:for-each select="macro">
				<meta:template match="{@id}" name="{@id}">
					<code><a href="{{$root}}/{substring-before(@header, '.')}.html#{@id}" class="{@type}"><xsl:value-of select="concat(/library/@macro-prefix, @id)"/></a></code>
				</meta:template>
			</xsl:for-each>
			<xsl:for-each select="alias">
				<meta:template match="{@id}" name="{@id}">
					<code><a href="{{$root}}/{substring-before(@header, '.')}.html#{@aliased-id}" class="alias"><xsl:value-of select="concat(/library/@macro-prefix, @id)"/></a></code>
				</meta:template>
			</xsl:for-each>
			<meta:template match="link" priority="-1">
				<a class="unknown" href="{{$root}}/unknown.html"><meta:value-of select="@id"/></a>
			</meta:template>
			<xsl:for-each select="document/item">
				<meta:template match="link[@id = '{@value}']">
					<a href="{{$root}}/{../@path}.html"><xsl:value-of select="@value"/></a>
				</meta:template>
				<xsl:variable name="capitalized">
					<xsl:call-template name="string:capitalize">
						<xsl:with-param name="text" select="@value"/>
					</xsl:call-template>
				</xsl:variable>
				<xsl:if test="@value != $capitalized">
					<meta:template match="link[@id = '{$capitalized}']">
						<a href="{{$root}}/{../@path}.html"><xsl:value-of select="$capitalized"/></a>
					</meta:template>
				</xsl:if>
			</xsl:for-each>
		</meta:stylesheet>
	</xsl:template>

</xsl:stylesheet>
