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

<!-- requirements: $root -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:header-name="/pp-book/header-name.xsl" xmlns:lookup="/pp-book/lookup.xsl">

	<xsl:import href="header-name.xsl"/>

	<xsl:template name="lookup:unknown-entity-base">
		<xsl:param name="text"/>
		<code><a class="unknown" href="{$root}/unknown.html"><xsl:value-of select="$text"/></a></code>
	</xsl:template>

	<xsl:template name="lookup:unknown-entity">
		<xsl:param name="node" select="."/>
		<xsl:choose>
			<xsl:when test="contains(name($node), '.')">
				<xsl:call-template name="lookup:unknown-entity-base">
					<xsl:with-param name="text">
						<xsl:call-template name="header-name:format">
							<xsl:with-param name="file" select="translate(name($node), '-', '/')"/>
						</xsl:call-template>
					</xsl:with-param>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:call-template name="lookup:unknown-entity-base">
					<xsl:with-param name="text" select="concat(document('.library.xml')/library/@macro-prefix, name($node))"/>
				</xsl:call-template>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template name="lookup:manual">
		<xsl:param name="id" select="@id"/>
		<xsl:choose>
			<xsl:when test="contains($id, '.')">
				<xsl:variable name="nodeset" select="document('.library.xml')/library/header[@name = $id]"/>
				<xsl:variable name="format">
					<xsl:call-template name="header-name:format">
						<xsl:with-param name="file" select="$id"/>
					</xsl:call-template>
				</xsl:variable>
				<xsl:choose>
					<xsl:when test="$nodeset">
						<code><a class="header" href="{$root}/{substring-before($nodeset[1]/@name, '.')}.html"><xsl:value-of select="$format"/></a></code>
					</xsl:when>
					<xsl:otherwise>
						<xsl:call-template name="lookup:unknown-entity-base">
							<xsl:with-param name="text" select="$format"/>
						</xsl:call-template>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>
			<xsl:otherwise>
				<xsl:variable name="nodeset" select="document('.library.xml')/library/macro[@id = $id]"/>
				<xsl:choose>
					<xsl:when test="$nodeset">
						<code><a class="{$nodeset[1]/@type}" href="{$root}/{substring-before($nodeset[1]/@header, '.')}.html#{$id}"><xsl:value-of select="concat(document('.library.xml')/library/@macro-prefix, $id)"/></a></code>
					</xsl:when>
					<xsl:otherwise>
						<xsl:call-template name="lookup:unknown-entity-base">
							<xsl:with-param name="text" select="concat(document('.library.xml')/library/@macro-prefix, $id)"/>
						</xsl:call-template>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

</xsl:stylesheet>
