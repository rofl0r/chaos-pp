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

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

	<xsl:template match="code | em | sub | sup | var">
		<xsl:element name="{name()}">
			<xsl:apply-templates/>
		</xsl:element>
	</xsl:template>

	<xsl:template match="x-var">
		<var class="external"><xsl:apply-templates/></var>
	</xsl:template>

	<xsl:template match="assoc">
		<a href="{@id}"><xsl:apply-templates/></a>
	</xsl:template>

	<xsl:template match="library-assoc">
		<a href="{$root}/{@id}"><xsl:apply-templates/></a>
	</xsl:template>

</xsl:stylesheet>
