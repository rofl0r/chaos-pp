<?xml version="1.0" encoding="UTF-8"?>

<!-- **************************************************************************
     *                                                                        *
     *    (C) Copyright Paul Mensonides 2003-2004.                            *
     *                                                                        *
     *    Distributed under the Boost Software License, Version 1.0.          *
     *    (See accompanying file LICENSE).                                    *
     *                                                                        *
     *    See http://chaos-pp.sourceforge.net for the most recent version.    *
     *                                                                        *
     ************************************************************************** -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:meta="λ">

	<xsl:output method="xml" indent="yes" encoding="UTF-8"/>

	<xsl:namespace-alias stylesheet-prefix="meta" result-prefix="xsl"/>

	<xsl:template match="/library">
		<meta:stylesheet version="1.0">
			<meta:output method="xml" indent="yes" encoding="UTF-8"/>
			<meta:template match="*" priority="-1">
				<meta:element name="{{name()}}">
					<meta:for-each select="@*">
						<meta:attribute name="{{name()}}"><meta:value-of select="."/></meta:attribute>
					</meta:for-each>
					<meta:apply-templates/>
				</meta:element>
			</meta:template>
			<xsl:apply-templates select="derivative-spec"/>
		</meta:stylesheet>
	</xsl:template>

	<xsl:template match="derivative-spec">
		<xsl:element name="xsl:template">
			<xsl:attribute name="match">
				<xsl:text>macro/</xsl:text>
				<xsl:if test="count(extended-usage) = 0">
					<xsl:text>/</xsl:text>
				</xsl:if>
				<xsl:text>derivative[substring-after(@id, ../@id) = '</xsl:text>
				<xsl:value-of select="@suffix"/>
				<xsl:text>']</xsl:text>
			</xsl:attribute>
			<derivative id="{{@id}}" class="{@class}">
				<xsl:apply-templates select="abstract"/>
				<xsl:choose>
					<xsl:when test="extended-usage">
						<xsl:apply-templates select="extended-usage"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:for-each select="usage">
							<meta:element name="usage">
								<meta:if test="@lang">
									<meta:attribute name="lang"><meta:value-of select="@lang"/></meta:attribute>
								</meta:if>
								<xsl:apply-templates/>
							</meta:element>
						</xsl:for-each>
					</xsl:otherwise>
				</xsl:choose>
				<xsl:for-each select="pre-para">
					<para><xsl:apply-templates/></para>
				</xsl:for-each>
				<meta:apply-templates select="para"/>
				<xsl:for-each select="post-para">
					<para><xsl:apply-templates/></para>
				</xsl:for-each>
				<meta:apply-templates select="listing"/>
				<meta:apply-templates select="derivative"/>
			</derivative>
		</xsl:element>
	</xsl:template>

	<xsl:template match="derivative-spec/extended-usage">
		<meta:for-each select="usage">
			<meta:element name="usage">
				<meta:if test="@lang">
					<meta:attribute name="lang"><meta:value-of select="@lang"/></meta:attribute>
				</meta:if>
				<meta:apply-templates select="syntax"/>
				<xsl:for-each select="pre-param">
					<xsl:element name="param">
						<xsl:for-each select="@*">
							<xsl:attribute name="{name()}"><xsl:value-of select="."/></xsl:attribute>
						</xsl:for-each>
						<xsl:apply-templates/>
					</xsl:element>
				</xsl:for-each>
				<meta:variable name="position" select="position()"/>
				<meta:copy-of select="ancestor::macro/usage[position() = $position]/param"/>
				<xsl:for-each select="post-param">
					<xsl:element name="param">
						<xsl:for-each select="@*">
							<xsl:attribute name="{name()}"><xsl:value-of select="."/></xsl:attribute>
						</xsl:for-each>
					</xsl:element>
				</xsl:for-each>
			</meta:element>
		</meta:for-each>
	</xsl:template>

	<xsl:template match="*" priority="-1">
		<xsl:element name="{name()}">
			<xsl:for-each select="@*">
				<xsl:attribute name="{name()}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:apply-templates/>
		</xsl:element>
	</xsl:template>

	<xsl:template match="current">
		<meta:element name="{{@id}}"/>
	</xsl:template>

	<xsl:template match="parent">
		<meta:element name="{{../@id}}"/>
	</xsl:template>

	<xsl:template match="sibling">
		<xsl:element name="xsl:element">
			<xsl:attribute name="name">
				<xsl:text>{concat(../@id, '</xsl:text>
				<xsl:value-of select="@suffix"/>
				<xsl:text>')}</xsl:text>
			</xsl:attribute>
		</xsl:element>
	</xsl:template>

</xsl:stylesheet>
