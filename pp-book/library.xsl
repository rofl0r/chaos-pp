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

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:output method="xml" indent="yes" encoding="UTF-8"/>

	<xsl:param name="source"/>

	<xsl:template match="/library">
		<library name="{@name}" url="{@url}" header-name-format="{@header-name-format}" macro-prefix="{@macro-prefix}">
			<xsl:apply-templates select="document | directory | header">
				<xsl:with-param name="path" select="''"/>
			</xsl:apply-templates>
		</library>
	</xsl:template>

	<xsl:template match="directory">
		<xsl:param name="path"/>
		<xsl:apply-templates select="directory | header">
			<xsl:with-param name="path" select="concat($path, @name, '/')"/>
		</xsl:apply-templates>
	</xsl:template>

	<xsl:template match="document">
		<xsl:param name="path"/>
		<document path="{$path}{@id}">
			<xsl:copy-of select="item"/>
		</document>
	</xsl:template>

	<xsl:template match="header">
		<xsl:param name="path"/>
		<header name="{$path}{@name}"/>
		<xsl:apply-templates mode="remote" select="document(concat($source, '/', $path, substring-before(@name, '.'), '.xml'))/header/macro">
			<xsl:with-param name="path" select="concat($path, @name)"/>
		</xsl:apply-templates>
	</xsl:template>

	<xsl:template mode="remote" match="macro | derivative">
		<xsl:param name="path"/>
		<xsl:param name="type" select="'primary'"/>
		<macro id="{@id}" header="{$path}" type="{$type}">
			<xsl:call-template name="extract-groups"/>
		</macro>
		<xsl:apply-templates mode="remote" select="derivative | alias">
			<xsl:with-param name="path" select="$path"/>
			<xsl:with-param name="type" select="'secondary'"/>
		</xsl:apply-templates>
	</xsl:template>

	<xsl:template mode="remote" match="alias">
		<xsl:param name="path"/>
		<alias id="{@id}" aliased-id="{../@id}" header="{$path}" type="alias"/>
	</xsl:template>

	<xsl:template name="extract-groups">
		<xsl:param name="text" select="@group"/>
		<xsl:choose>
			<xsl:when test="contains($text, ' ')">
				<group id="{substring-before($text, ' ')}"/>
				<xsl:call-template name="extract-groups">
					<xsl:with-param name="text" select="substring-after($text, ' ')"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:when test="string-length($text)">
				<group id="{$text}"/>
			</xsl:when>
		</xsl:choose>
	</xsl:template>

</xsl:stylesheet>
