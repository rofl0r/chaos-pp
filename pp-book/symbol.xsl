<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:meta=".">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
<xsl:namespace-alias stylesheet-prefix="meta" result-prefix="xsl"/>

<xsl:include href="header-name.xsl"/>

<xsl:param name="library"/>

<xsl:template match="/library">
	<meta:stylesheet version="1.0">
		<xsl:variable name="macro-prefix" select="document($library)/library/@macro-prefix"/>
		<xsl:for-each select="macro">
			<meta:template match="{@id}" name="{@id}">
				<CODE><A href="{{$root}}/{substring-before(@header, '.')}.html#{@id}" class="{@type}"><xsl:value-of select="concat($macro-prefix, @id)"/></A></CODE>
			</meta:template>
		</xsl:for-each>
		<xsl:for-each select="alias">
			<meta:template match="{@id}" name="{@id}">
				<CODE><A href="{{$root}}/{substring-before(@header, '.')}.html#{@aliased-id}"><xsl:value-of select="concat($macro-prefix, @id)"/></A></CODE>
			</meta:template>
		</xsl:for-each>
		<xsl:for-each select="header">
			<meta:template match="{translate(@name, '/', '-')}">
				<CODE><A href="{{$root}}/{substring-before(@name, '.')}.html" class="HEADER"><xsl:call-template name="header-name"><xsl:with-param name="header-name" select="@name"/></xsl:call-template></A></CODE>
			</meta:template>
		</xsl:for-each>
		<meta:template match="link" priority="-1">
			<meta:message terminate="yes">[error: reference to unknown symbol "<meta:value-of select="@id"/>"]</meta:message>
		</meta:template>
		<xsl:for-each select="document/item">
			<meta:template match="link[@id = '{@value}']">
				<A href="{{$root}}/{../@path}.html"><xsl:value-of select="@value"/></A>
			</meta:template>
		</xsl:for-each>
	</meta:stylesheet>
</xsl:template>

</xsl:stylesheet>
