<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xso="http://chaos-pp.sourceforge.net">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
<xsl:namespace-alias stylesheet-prefix="xso" result-prefix="xsl"/>

<xsl:template match="/lookup">
	<xsl:element name="xsl:stylesheet" namespace="http://www.w3.org/1999/XSL/Transform">
		<xsl:attribute name="version">1.0</xsl:attribute>
		<xsl:apply-templates select="header"/>
	</xsl:element>
</xsl:template>

<xsl:template match="/lookup/header">
	<xso:template match="{translate(@src, '/', '-')}.hpp"><a class="header" href="{{$root}}/reference/{@src}.html">&lt;chaos/preprocessor/<xsl:value-of select="@src"/>.hpp&gt;</a></xso:template>
	<xsl:apply-templates select="symbol"/>
</xsl:template>

<xsl:template match="/lookup/header/symbol">
	<xso:template match="{@id}"><a class="symbol" href="{{$root}}/reference/{../@src}.html#{@id}">CHAOS_PP_<xsl:value-of select="@id"/></a></xso:template>
</xsl:template>

</xsl:stylesheet>
