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

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:copyright="/pp-book/copyright.xsl" xmlns:lookup="/pp-book/lookup.xsl" xmlns:spacing="/pp-book/spacing.xsl" xmlns:whitespace="/pp-book/whitespace.xsl">

	<xsl:import href="copyright.xsl"/>
	<xsl:import href="lookup.xsl"/>
	<xsl:import href="spacing.xsl"/>
	<xsl:import href="whitespace.xsl"/>

	<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

	<xsl:include href=".symbol.xsl"/>
	<xsl:include href="common.xsl"/>

	<xsl:variable name="root" select="'.'"/>

	<xsl:template match="code/text() | snippet/text()">
		<xsl:call-template name="whitespace:clean">
			<xsl:with-param name="text" select="."/>
		</xsl:call-template>
	</xsl:template>

	<xsl:template match="*" priority="-2">
		<xsl:call-template name="lookup:unknown-entity"/>
	</xsl:template>

	<xsl:template match="/document">
		<html>
			<head>
				<title><xsl:value-of select="@id"/> - <xsl:value-of select="document('.library.xml')/library/@name"/></title>
				<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
			</head>
			<body>
				<xsl:for-each select="section">
					<xsl:if test="preceding-sibling::section">
						<hr/>
					</xsl:if>
					<xsl:if test="@id">
						<h4><xsl:value-of select="@id"/></h4>
					</xsl:if>
					<xsl:call-template name="spacing:apply">
						<xsl:with-param name="depth">
							<xsl:value-of select="count(@id)"/>
						</xsl:with-param>
					</xsl:call-template>
				</xsl:for-each>
			</body>
			<xsl:call-template name="copyright:insert"/>
		</html>
	</xsl:template>

</xsl:stylesheet>
