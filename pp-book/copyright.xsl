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

<!-- requirements: $root -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:copyright="/pp-book/copyright.xsl">

	<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

	<xsl:template name="copyright:address-from-name">
		<xsl:param name="name"/>
		<xsl:choose>
			<xsl:when test="$name = 'Paul Mensonides'">
				<a href="mailto:pmenso57@users.sourceforge.net">Paul Mensonides</a>
			</xsl:when>
			<xsl:when test="$name = 'Vesa Karvonen'">
				<a href="mailto:vesa_karvonen@users.sourceforge.net">Vesa Karvonen</a>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$name"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template name="copyright:inject-name">
		<xsl:param name="name"/>
		<xsl:param name="date"/>
		<xsl:text>© Copyright </xsl:text>
		<xsl:call-template name="copyright:address-from-name">
			<xsl:with-param name="name" select="$name"/>
		</xsl:call-template>
		<xsl:text> </xsl:text>
		<xsl:value-of select="$date"/>
	</xsl:template>

	<xsl:template name="copyright:insert">
		<xsl:param name="author" select="/*/@author"/>
		<xsl:param name="date" select="/*/@date"/>
		<xsl:if test="$author != '' and $date != ''">
			<hr/>
			<address>
				<xsl:call-template name="copyright:inject-name">
					<xsl:with-param name="name" select="$author"/>
					<xsl:with-param name="date" select="$date"/>
				</xsl:call-template>
			</address>
			<xsl:if test="/*/secondary-author">
				<address>
					<xsl:for-each select="/*/secondary-author">
						<xsl:sort select="@name"/>
						<xsl:call-template name="copyright:inject-name">
							<xsl:with-param name="name" select="@name"/>
							<xsl:with-param name="date" select="@date"/>
						</xsl:call-template>
					</xsl:for-each>
				</address>
			</xsl:if>
			<xsl:variable name="url" select="document('.library.xml')/library/@url"/>
			<address>
				Distributed under the <a href="{$root}/license.html">Boost Software License, Version 1.0</a>.
				See <a href="{$url}"><xsl:value-of select="$url"/></a> for the most recent version of this document.
			</address>
		</xsl:if>
	</xsl:template>

</xsl:stylesheet>
