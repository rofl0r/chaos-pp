<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xso=".">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
<xsl:namespace-alias stylesheet-prefix="xso" result-prefix="xsl"/>

<xsl:template match="/register">
	<xso:stylesheet version="1.0">
		<xsl:apply-templates select="document"/>
		<xso:template match="link" priority="-1">
			<A style="unknown" href="{{$root}}/unknown.html"><xso:value-of select="@id"/></A>
			<xso:message terminate="yes">warning: reference to unknown symbol: "<xso:value-of select="@id"/>"</xso:message>
		</xso:template>
	</xso:stylesheet>
</xsl:template>

<xsl:template match="/register/document">
	<xsl:apply-templates select="item"/>
</xsl:template>

<xsl:template match="/register/document/item">
	<xso:template match="link[@id = '{@value}']">
		<A href="{{$root}}/{../@id}.html"><xsl:value-of select="@value"/></A>
	</xso:template>
</xsl:template>

</xsl:stylesheet>
